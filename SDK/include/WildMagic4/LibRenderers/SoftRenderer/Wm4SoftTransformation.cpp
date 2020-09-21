// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4SoftRendererPCH.h"
#include "Wm4SoftRenderer.h"
#include "Wm4Camera.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void SoftRenderer::OnViewportChange ()
{
    int iPortL, iPortR, iPortT, iPortB;
    if (m_pkCamera)
    {
        // 3D applications use cameras.
        int iWidth, iHeight;
        m_pkCamera->GetViewport(iPortL,iPortR,iPortT,iPortB,iWidth,iHeight);
        if (iWidth == 0 || iHeight == 0)
        {
            iPortL = 0;
            iPortB = 0;
            iPortR = m_iWidth;
            iPortT = m_iHeight;
        }
    }
    else
    {
        // 2D applications do not use cameras.
        iPortL = 0;
        iPortB = 0;
        iPortR = m_iWidth;
        iPortT = m_iHeight;
    }

    m_fXCoeff0 = 0.5f*(iPortR + iPortL);
    m_fXCoeff1 = 0.5f*(iPortR - iPortL);
    m_fYCoeff0 = 0.5f*(2*m_iHeight - iPortT - iPortB);
    m_fYCoeff1 = 0.5f*(iPortB - iPortT);
}
//----------------------------------------------------------------------------
void SoftRenderer::OnDepthRangeChange ()
{
    if (m_pkCamera)
    {
        m_pkCamera->GetDepthRange(m_fMinDepth,m_fMaxDepth);
        if (m_fMinDepth < 0.0f)
        {
            m_fMinDepth = 0.0f;
        }
        else if (m_fMinDepth > 1.0f)
        {
            m_fMinDepth = 1.0f;
        }

        if (m_fMaxDepth < 0.0f)
        {
            m_fMaxDepth = 0.0f;
        }
        else if (m_fMaxDepth > 1.0f)
        {
            m_fMaxDepth = 1.0f;
        }
    }
    else
    {
        m_fMinDepth = 0.0f;
        m_fMaxDepth = 1.0f;
    }

    m_fRangeDepth = m_fMaxDepth - m_fMinDepth;
}
//----------------------------------------------------------------------------
