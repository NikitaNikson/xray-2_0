// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "ImViewer.h"
#include "Wm4Imagics.h"

WM4_WINDOW_APPLICATION(ImViewer);

//----------------------------------------------------------------------------
ImViewer::ImViewer ()
    :
    WindowApplication2("ImViewer",0,0,256,256,
        ColorRGBA(0.9f,0.9f,0.9f,1.0f))
{
    m_bMouseDown = false;
    m_iZ = 0;
    m_aiBound = 0;
    m_akData = 0;
    m_afData = 0;
    m_iSliceQuantity = 0;
    memset(m_acPixelStr,0,PIXEL_STR_SIZE);

    // For the Mac, to select files to display since there is no concept of
    // command-line parameters.
    m_bLaunchFileDialog = true;
}
//----------------------------------------------------------------------------
bool ImViewer::OnPrecreate ()
{
    if (!WindowApplication2::OnPrecreate())
    {
        return false;
    }

    char* acFilename = 0;
    Application::TheCommand->Filename(acFilename);
    if (!acFilename)
    {
        // input filename must be specified on the command line
        return false;
    }

    // load the image data
    int iRTTI, iSizeOf;
    char* acData = 0;
    bool bLoaded = Lattice::LoadRaw(acFilename,m_iDimensions,m_aiBound,
        m_iQuantity,iRTTI,iSizeOf,acData);
    WM4_DELETE[] acFilename;
    if (!bLoaded)
    {
        WM4_DELETE[] acData;
        return false;
    }

    // Set window size based on image size.  Adjust height to allow for
    // status bar.  The window width is chosen so that rows are multiples
    // of 4 bytes.
    m_iHeight = m_aiBound[1];
    if (m_iHeight < 128)
    {
        m_iHeight = 128;
    }

    int iStatusHeight = 20;
    m_iHeight += iStatusHeight;

    m_iWidth = m_aiBound[0];
    if (m_iWidth < 256)
    {
        m_iWidth = 256;
    }

    int iRem = (m_iWidth % 4);
    if (iRem > 0)
    {
        m_iWidth += 4-iRem;
    }

    // The application image is stored differently depending on the input
    // image format.
    int i;
    if (iRTTI == Ergb5::GetRTTI())
    {
        m_akData = WM4_NEW Color[m_iQuantity];
        unsigned short* ausData = (unsigned short*)acData;
        for (i = 0; i < m_iQuantity; i++)
        {
            unsigned char ucR = GetRed16(ausData[i]);
            unsigned char ucG = GetGreen16(ausData[i]);
            unsigned char ucB = GetBlue16(ausData[i]);
            m_akData[i] = Color(ucR,ucG,ucB);
        }
    }
    else if (iRTTI == Ergb8::GetRTTI())
    {
        m_akData = WM4_NEW Color[m_iQuantity];
        unsigned int* auiData = (unsigned int*)acData;
        for (i = 0; i < m_iQuantity; i++)
        {
            unsigned char ucR = GetRed24(auiData[i]);
            unsigned char ucG = GetGreen24(auiData[i]);
            unsigned char ucB = GetBlue24(auiData[i]);
            m_akData[i] = Color(ucR,ucG,ucB);
        }
    }
    else if (iRTTI == Efloat::GetRTTI())
    {
        m_afData = WM4_NEW float[m_iQuantity];
        size_t uiSize = m_iQuantity*sizeof(float);
        System::Memcpy(m_afData,uiSize,acData,uiSize);
    }
    else
    {
        m_afData = WM4_NEW float[m_iQuantity];
        ImageConvert(m_iQuantity,iRTTI,acData,Efloat::GetRTTI(),m_afData);
    }
    WM4_DELETE[] acData;

    // compute min, max and range of float images
    if (m_afData)
    {
        m_fMin = m_afData[0];
        m_fMax = m_fMin;
        for (i = 1; i < m_iQuantity; i++)
        {
            if (m_afData[i] < m_fMin)
            {
                m_fMin = m_afData[i];
            }
            else if (m_afData[i] > m_fMax )
            {
                m_fMax = m_afData[i];
            }
        }
        m_fRange = m_fMax - m_fMin;
        if (m_fRange > 0.0f)
        {
            m_fInvRange = 1.0f/m_fRange;
        }
        else
        {
            m_fInvRange = 0.0f;
        }
    }

    // we only need memory to hold the active slice
    m_iSliceQuantity = m_aiBound[0]*m_aiBound[1];

    return true;
}
//----------------------------------------------------------------------------
bool ImViewer::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

    CopySliceToScreen();
    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void ImViewer::OnTerminate ()
{
    WM4_DELETE[] m_akData;
    WM4_DELETE[] m_afData;
    WM4_DELETE[] m_aiBound;
    WindowApplication2::OnTerminate();
}
//----------------------------------------------------------------------------
bool ImViewer::OnSpecialKeyDown (int iKey, int iX, int iY)
{
    if (m_iDimensions != 3)
    {
        return false;
    }

    if (iKey == KEY_UP_ARROW)
    {
        // up-arrow pressed, go to next image slize
        if (m_iZ < m_aiBound[2] - 1)
        {
            m_iZ++;
            CopySliceToScreen();
            if (m_bMouseDown)
            {
                ReadPixelValue(iX,iY);
            }
            OnDisplay();
        }
        return true;
    }

    if (iKey == KEY_DOWN_ARROW)
    {
        // down-arrow pressed, go to previous image slice
        if (m_iZ > 0)
        {
            m_iZ--;
            CopySliceToScreen();
            if (m_bMouseDown)
            {
                ReadPixelValue(iX,iY);
            }
            OnDisplay();
        }
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
bool ImViewer::OnMouseClick (int iButton, int iState, int iX, int iY,
    unsigned int)
{
    if (iButton == MOUSE_LEFT_BUTTON)
    {
        if (iState == MOUSE_DOWN)
        {
            m_bMouseDown = true;
            ReadPixelValue(iX,iY);
            OnDisplay();
            return true;
        }
        if (iState == MOUSE_UP)
        {
            m_bMouseDown = false;
            ReadPixelValue(-1,-1);
            OnDisplay();
            return true;
        }
    }
    return false;
}
//----------------------------------------------------------------------------
bool ImViewer::OnMotion (int, int iX, int iY, unsigned int)
{
    if (m_bMouseDown)
    {
        ReadPixelValue(iX,iY);
        OnDisplay();
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
void ImViewer::CopySliceToScreen ()
{
    ClearScreen();

    int iX, iY;

    if (m_afData)
    {
        if (m_fRange > 0.0f)
        {
            float* afSlice = &m_afData[m_iZ*m_iSliceQuantity];
            for (iY = 0; iY < m_aiBound[1]; iY++)
            {
                for (iX = 0; iX < m_aiBound[0]; iX++)
                {
                    int i = iX+m_aiBound[0]*iY;
                    float fGray = 255.0f*(afSlice[i]-m_fMin)*m_fInvRange;
                    unsigned char ucGray = (unsigned char)(fGray);
                    m_akScreen[Index(iX,iY)] = Color(ucGray,ucGray,ucGray);
                }
            }
        }
    }
    else
    {
        Color* akSlice = &m_akData[m_iZ*m_iSliceQuantity];
        for (iY = 0; iY < m_aiBound[1]; iY++)
        {
            for (iX = 0; iX < m_aiBound[0]; iX++)
            {
                int i = iX+m_aiBound[0]*iY;
                m_akScreen[Index(iX,iY)] = akSlice[i];
            }
        }
    }
}
//----------------------------------------------------------------------------
void ImViewer::ReadPixelValue (int iX, int iY)
{
    if (0 <= iX && iX < m_aiBound[0] && 0 <= iY && iY < m_aiBound[1])
    {
        int iIndex = iX + m_aiBound[0]*iY;
        if (m_afData)
        {
            float* afSlice = &m_afData[m_iZ*m_iSliceQuantity];
            float fValue = afSlice[iIndex];
            if (m_iDimensions == 2)
            {
                System::Sprintf(m_acPixelStr,PIXEL_STR_SIZE,"(%d,%d) %f",iX,
                    iY,fValue);
            }
            else
            {
                System::Sprintf(m_acPixelStr,PIXEL_STR_SIZE,"(%d,%d,%d) %f",
                    iX,iY,m_iZ,fValue);
            }
        }
        else
        {
            Color* akSlice = &m_akData[m_iZ*m_iSliceQuantity];
            Color kValue = akSlice[iIndex];
            if (m_iDimensions == 2)
            {
                System::Sprintf(m_acPixelStr,PIXEL_STR_SIZE,
                    "(%d,%d) r=%d g=%d b=%d",iX,iY,(int)kValue.r,
                    (int)kValue.g,(int)kValue.b);
            }
            else
            {
                System::Sprintf(m_acPixelStr,PIXEL_STR_SIZE,
                    "(%d,%d,%d) r=%d g=%d b=%d",iX,iY,m_iZ,(int)kValue.r,
                    (int)kValue.g,(int)kValue.b);
            }
        }
    }
    else
    {
        int iLength = (int)strlen(m_acPixelStr);
        if(iLength > 0)
        {
            memset(m_acPixelStr,' ',iLength);
        }
    }
}
//----------------------------------------------------------------------------
void ImViewer::ScreenOverlay ()
{
    if (m_bMouseDown)
    {
        m_pkRenderer->Draw(4,m_iHeight-4,ColorRGBA::BLACK,m_acPixelStr);
    }
}
//----------------------------------------------------------------------------
