// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4Dx9RendererPCH.h"
#include "Wm4Dx9Renderer.h"
using namespace Wm4;

//----------------------------------------------------------------------------
int Dx9Renderer::LoadFont (const char* acFace, int iSize, bool bBold,
    bool bItalic)
{
    // Find the first unused font location
    int iLoc;
    for (iLoc = 0; iLoc < (int)m_kFontArray.size(); iLoc++)
    {
        if (!m_kFontArray[iLoc])
        {
            break;
        }
    }

    LPD3DXFONT pqFont;
    DWORD dwWeight = (bBold ? FW_BOLD : FW_REGULAR);

    ms_hResult = D3DXCreateFont(
        m_pqDevice,                     // pDevice
        iSize,                          // Height
        0,                              // Width
        dwWeight,                       // Weight
        0,                              // MipLevels
        (DWORD)bItalic,                 // Italic
        DEFAULT_CHARSET,                // CharSet
        OUT_DEFAULT_PRECIS,             // OutputPrecision
        ANTIALIASED_QUALITY,            // Quality
        VARIABLE_PITCH,                 // PitchAndFamily
        acFace,                         // pFaceName
        &pqFont);                       // ppFont

    assert(SUCCEEDED(ms_hResult));

    // Put into the font array.
    if (iLoc == (int)m_kFontArray.size())
    {
        m_kFontArray.push_back(pqFont);
    }
    else
    {
        m_kFontArray[iLoc] = pqFont;
    }

    return iLoc;
}
//----------------------------------------------------------------------------
void Dx9Renderer::UnloadFont (int iFontID)
{
    // You may not unload the default font (id = 0).
    if (1 <= iFontID && iFontID < (int)m_kFontArray.size())
    {
        m_kFontArray[iFontID]->Release();
    }
}
//----------------------------------------------------------------------------
bool Dx9Renderer::SelectFont (int iFontID)
{
    if (0 <= iFontID && iFontID < (int)m_kFontArray.size())
    {
        if (m_kFontArray[iFontID])
        {
            m_iFontID = iFontID;
            return true;
        }
    }
    return false;
}
//----------------------------------------------------------------------------
void Dx9Renderer::Draw (int iX, int iY, const ColorRGBA& rkColor,
    const char* acText)
{
    assert(acText);
    if (!acText)
    {
        return;
    }

    RECT kText;
    kText.bottom = iY;
    kText.top = iY;
    kText.left = iX;
    kText.right = iX;

    D3DCOLOR kColor = D3DCOLOR_COLORVALUE(rkColor.R(),rkColor.G(),rkColor.B(),
        rkColor.A());

    ms_hResult = m_kFontArray[m_iFontID]->DrawText(
        0,                                  // pSprite
        acText,                             // pString
        -1,                                 // Count
        &kText,                             // pRect
        DT_LEFT | DT_BOTTOM | DT_CALCRECT,  // Format
        kColor);                            // Color
    assert(SUCCEEDED(ms_hResult));

    ms_hResult = m_kFontArray[m_iFontID]->DrawText(
        0,
        acText,
        -1,
        &kText,
        DT_LEFT | DT_BOTTOM,
        kColor);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
