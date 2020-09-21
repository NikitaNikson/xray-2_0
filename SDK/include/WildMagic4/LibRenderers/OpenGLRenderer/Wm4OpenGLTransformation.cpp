// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4OpenGLRendererPCH.h"
#include "Wm4OpenGLRenderer.h"
#include "Wm4Camera.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void OpenGLRenderer::OnViewportChange ()
{
    // OpenGL defines the full-sized viewport to have origin at the lower
    // left corner of the screen.  The iPortB value specifies the relative
    // distance from the bottom of the screen.  Wild Magic also uses this
    // convention, but DirectX does not, in which case iPortB is computed
    // differently for DirectX.
    int iViewX, iViewY, iViewW, iViewH;

    if (m_pkCamera)
    {
        // 3D applications use cameras.
        int iPortL, iPortR, iPortT, iPortB, iWidth, iHeight;
        m_pkCamera->GetViewport(iPortL,iPortR,iPortT,iPortB,iWidth,iHeight);
        if (iWidth > 0 && iHeight > 0)
        {
            iViewX = iPortL;
            iViewY = iPortB;
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

    glViewport(iViewX,iViewY,iViewW,iViewH);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnDepthRangeChange ()
{
    if (m_pkCamera)
    {
        float fPortN, fPortF;
        m_pkCamera->GetDepthRange(fPortN,fPortF);
        glDepthRange((GLclampd)fPortN,(GLclampd)fPortF);
    }
    else
    {
        glDepthRange(0.0,1.0);
    }
}
//----------------------------------------------------------------------------
