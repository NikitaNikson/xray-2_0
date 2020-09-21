// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "NURBSCurveExample.h"

WM4_WINDOW_APPLICATION(NURBSCurveExample);

const int g_iSize = 256;

//----------------------------------------------------------------------------
NURBSCurveExample::NURBSCurveExample ()
    :
    WindowApplication2("NURBSCurveExample",0,0,g_iSize,g_iSize,
        ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
    m_pkSpline = 0;
    m_pkCircle = 0;
    m_akCtrlPoint = 0;
    m_akTarget = 0;
    m_fH = 0.5f*g_iSize;
    m_fD = 0.0625f*g_iSize;
    m_fSimTime = 0.0f;
    m_fSimDelta = 0.05f;
    m_bDrawControlPoints = false;
}
//----------------------------------------------------------------------------
bool NURBSCurveExample::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

    InitialConfiguration();
    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void NURBSCurveExample::OnTerminate ()
{
    WM4_DELETE m_pkSpline;
    WM4_DELETE m_pkCircle;
    WM4_DELETE[] m_akCtrlPoint;
    WM4_DELETE[] m_akTarget;
    WindowApplication2::OnTerminate();
}
//----------------------------------------------------------------------------
void NURBSCurveExample::OnDisplay ()
{
    ClearScreen();

    const int iCurveThick = 0;
    Color kCurveColor(0,0,0);
    const int iControlThick = 2;
    Color kControlColor(128,128,128);

    int iMax = 2048;
    int i, iX, iY, iDX, iDY;
    float fT;
    Vector2f kPos;

    // draw spline
    for (i = 0; i <= iMax; i++)
    {
        fT = i/(float)iMax;
        kPos = m_pkSpline->GetPosition(fT);
        iX = int(kPos.X()+0.5f);
        iY = g_iSize-1-int(kPos.Y()+0.5f);
        for (iDY = -iCurveThick; iDY <= iCurveThick; iDY++)
        {
            for (iDX = -iCurveThick; iDX <= iCurveThick; iDX++)
            {
                SetPixel(iX+iDX,iY+iDY,kCurveColor);
            }
        }
    }

    // draw circle
    if (m_pkCircle)
    {
        for (i = 0; i <= iMax; i++)
        {
            // draw point
            fT = i/(float)iMax;
            kPos = m_pkCircle->GetPosition(fT);
            iX = int(kPos.X()+0.5f);
            iY = g_iSize-1-int(kPos.Y()+0.5f);
            for (iDY = -iCurveThick; iDY <= iCurveThick; iDY++)
            {
                for (iDX = -iCurveThick; iDX <= iCurveThick; iDX++)
                {
                    SetPixel(iX+iDX,iY+iDY,kCurveColor);
                }
            }
        }
    }

    // draw control points
    if (m_bDrawControlPoints)
    {
        iMax = m_pkSpline->GetNumCtrlPoints();
        for (i = 0; i < iMax; i++)
        {
            const Vector2f& rkCtrl = m_pkSpline->GetControlPoint(i);
            iX = int(rkCtrl.X()+0.5f);
            iY = g_iSize-1-int(rkCtrl.Y()+0.5f);
            for (iDY = -iControlThick; iDY <= iControlThick; iDY++)
            {
                for (iDX = -iControlThick; iDX <= iControlThick; iDX++)
                {
                    SetPixel(iX+iDX,iY+iDY,kControlColor);
                }
            }
        }

        if (m_pkCircle)
        {
            iMax = m_pkCircle->GetNumCtrlPoints();
            for (i = 0; i < iMax; i++)
            {
                const Vector2f& rkCtrl = m_pkCircle->GetControlPoint(i);
                iX = int(rkCtrl.X()+0.5f);
                iY = g_iSize-1-int(rkCtrl.Y()+0.5f);
                for (iDY = -iControlThick; iDY <= iControlThick; iDY++)
                {
                    for (iDX = -iControlThick; iDX <= iControlThick; iDX++)
                    {
                        SetPixel(iX+iDX,iY+iDY,kControlColor);
                    }
                }
            }
        }
    }

    WindowApplication2::OnDisplay();
}
//----------------------------------------------------------------------------
bool NURBSCurveExample::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication2::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'g':
        if (m_fSimTime <= 1.0f)
        {
            DoSimulation1();
        }
        else if (m_fSimTime <= 2.0f)
        {
            DoSimulation2();
        }
        else
        {
            InitialConfiguration();
        }
        return true;
    case '0':
        InitialConfiguration();
        OnDisplay();
        return true;
    case 'c':
        m_bDrawControlPoints = !m_bDrawControlPoints;
        OnDisplay();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void NURBSCurveExample::DoSimulation1 ()
{
    m_fSimTime += m_fSimDelta;

    float fT = m_fSimTime, fOmT = 1.0f-fT;
    int iMax = m_pkSpline->GetNumCtrlPoints();
    for (int i = 0; i < iMax; i++)
    {
        if (i == 2 || i == 10)
        {
            float fTmpT = Mathf::Pow(fT,1.5f);
            float fOmTmpT = 1.0f - fTmpT;
            m_pkSpline->SetControlPoint(i,
                fOmTmpT*m_akCtrlPoint[i] + fTmpT*m_akTarget[i]);
        }
        else
        {
            m_pkSpline->SetControlPoint(i,
                fOmT*m_akCtrlPoint[i] + fT*m_akTarget[i]);
        }
    }

    OnDisplay();
}
//----------------------------------------------------------------------------
void NURBSCurveExample::DoSimulation2 ()
{
    m_fSimTime += m_fSimDelta;

    if (!m_pkCircle)
    {
        NextConfiguration();
    }
    else
    {
        // curve evolves to a line segment
        float fT = m_fSimTime - 1.0f, fOmT = 1.0f - fT;
        Vector2f kCtrl = fOmT*m_pkSpline->GetControlPoint(2) +
            fT*m_pkSpline->GetControlPoint(1);
        m_pkSpline->SetControlPoint(2,kCtrl);

        // circle floats up a little bit
        int iMax = m_pkCircle->GetNumCtrlPoints();
        for (int i = 0; i < iMax; i++)
        {
            kCtrl = m_pkCircle->GetControlPoint(i)+Vector2f::UNIT_Y;
            m_pkCircle->SetControlPoint(i,kCtrl);
        }
    }

    OnDisplay();
}
//----------------------------------------------------------------------------
void NURBSCurveExample::InitialConfiguration ()
{
    m_fSimTime = 0.0f;
    WM4_DELETE m_pkSpline;
    WM4_DELETE m_pkCircle;
    WM4_DELETE[] m_akCtrlPoint;
    WM4_DELETE[] m_akTarget;
    m_pkCircle = 0;

    int iNumCtrlPoints = 13;
    int iDegree = 2;
    m_akCtrlPoint = WM4_NEW Vector2f[iNumCtrlPoints];
    m_akTarget = WM4_NEW Vector2f[iNumCtrlPoints];
    int i;
    for (i = 0; i < iNumCtrlPoints; i++)
    {
        m_akCtrlPoint[i] = Vector2f(0.125f*g_iSize+0.0625f*g_iSize*i,
            0.0625f*g_iSize);
    }

    m_akTarget[ 0] = m_akCtrlPoint[ 0];
    m_akTarget[ 1] = m_akCtrlPoint[ 6];
    m_akTarget[ 2] = Vector2f(m_akCtrlPoint[6].X(),m_fH-m_fD);
    m_akTarget[ 3] = Vector2f(m_akCtrlPoint[5].X(),m_fH-m_fD);
    m_akTarget[ 4] = Vector2f(m_akCtrlPoint[5].X(),m_fH);
    m_akTarget[ 5] = Vector2f(m_akCtrlPoint[5].X(),m_fH+m_fD);
    m_akTarget[ 6] = Vector2f(m_akCtrlPoint[6].X(),m_fH+m_fD);
    m_akTarget[ 7] = Vector2f(m_akCtrlPoint[7].X(),m_fH+m_fD);
    m_akTarget[ 8] = Vector2f(m_akCtrlPoint[7].X(),m_fH);
    m_akTarget[ 9] = Vector2f(m_akCtrlPoint[7].X(),m_fH-m_fD);
    m_akTarget[10] = Vector2f(m_akCtrlPoint[6].X(),m_fH-m_fD);
    m_akTarget[11] = m_akCtrlPoint[ 6];
    m_akTarget[12] = m_akCtrlPoint[12];

    float* afWeight = WM4_NEW float[iNumCtrlPoints];
    for (i = 0; i < iNumCtrlPoints; i++)
    {
        afWeight[i] = 1.0f;
    }

    float fModWeight = 0.3f;
    afWeight[3] = fModWeight;
    afWeight[5] = fModWeight;
    afWeight[7] = fModWeight;
    afWeight[9] = fModWeight;

    m_pkSpline = WM4_NEW NURBSCurve2f(iNumCtrlPoints,m_akCtrlPoint,afWeight,
        iDegree,false,true);

    WM4_DELETE[] afWeight;
}
//----------------------------------------------------------------------------
void NURBSCurveExample::NextConfiguration ()
{
    WM4_DELETE[] m_akTarget;
    m_akTarget = 0;

    int iNumCtrlPoints = 5+9;
    int iDegree = 2;
    WM4_DELETE[] m_akCtrlPoint;
    m_akCtrlPoint = WM4_NEW Vector2f[iNumCtrlPoints];
    float* afWeight = WM4_NEW float[iNumCtrlPoints];

    // spline
    m_akCtrlPoint[0] = m_pkSpline->GetControlPoint(0);
    m_akCtrlPoint[1] = m_pkSpline->GetControlPoint(1);
    m_akCtrlPoint[2] = 0.5f*(m_pkSpline->GetControlPoint(1) +
        m_pkSpline->GetControlPoint(2));
    m_akCtrlPoint[3] = m_pkSpline->GetControlPoint(11);
    m_akCtrlPoint[4] = m_pkSpline->GetControlPoint(12);

    // circle
    int i, j;
    for (i = 2, j = 5; i <= 10; i++, j++)
    {
        m_akCtrlPoint[j] = m_pkSpline->GetControlPoint(i);
    }

    for (i = 0; i < iNumCtrlPoints; i++)
    {
        afWeight[i] = 1.0f;
    }

    afWeight[ 6] = m_pkSpline->GetControlWeight(3);
    afWeight[ 8] = m_pkSpline->GetControlWeight(5);
    afWeight[10] = m_pkSpline->GetControlWeight(7);
    afWeight[12] = m_pkSpline->GetControlWeight(9);

    WM4_DELETE m_pkSpline;
    m_pkSpline = WM4_NEW NURBSCurve2f(5,m_akCtrlPoint,afWeight,iDegree,false,
        true);

    m_pkCircle = WM4_NEW NURBSCurve2f(9,&m_akCtrlPoint[5],&afWeight[5],
        iDegree,true,false);

    WM4_DELETE[] afWeight;
}
//----------------------------------------------------------------------------
