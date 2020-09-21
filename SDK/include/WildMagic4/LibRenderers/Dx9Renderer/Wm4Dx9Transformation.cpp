// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4Dx9RendererPCH.h"
#include "Wm4Dx9Renderer.h"
#include "Wm4Camera.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void Dx9Renderer::OnViewportChange ()
{
    // DirectX defines the full-sized viewport to have origin at the upper
    // left corner of the screen.  Wild Magic uses the OpenGL convention that
    // iPortB specifies the relative distance from the bottom of the screen.
    // DirectX needs a specification of relative distance from the top of
    // the screen, which is H - iPortT.
    int iViewX, iViewY, iViewW, iViewH;

    if (m_pkCamera)
    {
        // 3D applications use cameras.
        int iPortL, iPortR, iPortT, iPortB, iWidth, iHeight;
        m_pkCamera->GetViewport(iPortL,iPortR,iPortT,iPortB,iWidth,iHeight);
        if (iWidth > 0 && iHeight > 0)
        {
            iViewX = iPortL;
            iViewY = m_iHeight - iPortT;
            iViewW = iPortR - iPortL;
            iViewH = iPortT - iPortB;
        }
        else
        {
            iViewX = 0;
            iViewY = 0;
            iViewW = m_iWidth;
            iViewH = m_iHeight;
        }
    }
    else
    {
        // 2D applications do not use cameras.
        iViewX = 0;
        iViewY = 0;
        iViewW = m_iWidth;
        iViewH = m_iHeight;
    }

    D3DVIEWPORT9 kViewport;
    kViewport.X = (DWORD)iViewX;
    kViewport.Y = (DWORD)iViewY;
    kViewport.Width = (DWORD)iViewW;
    kViewport.Height = (DWORD)iViewH;
    kViewport.MinZ = 0.0f;
    kViewport.MaxZ = 1.0f;

    ms_hResult = m_pqDevice->SetViewport(&kViewport);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnDepthRangeChange ()
{
    D3DVIEWPORT9 kViewport;
    ms_hResult = m_pqDevice->GetViewport(&kViewport);
    assert(SUCCEEDED(ms_hResult));

    if (m_pkCamera)
    {
        m_pkCamera->GetDepthRange(kViewport.MinZ,kViewport.MaxZ);
    }
    else
    {
        kViewport.MinZ = 0.0f;
        kViewport.MaxZ = 1.0f;
    }

    ms_hResult = m_pqDevice->SetViewport(&kViewport);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
