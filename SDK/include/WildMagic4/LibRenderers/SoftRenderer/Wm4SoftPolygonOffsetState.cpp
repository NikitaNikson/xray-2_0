// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4SoftRendererPCH.h"
#include "Wm4SoftRenderer.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void SoftRenderer::SetPolygonOffsetState (PolygonOffsetState* pkState)
{
    // The LineEnabled and PointEnabled members are ignored by the software
    // renderer.

    Renderer::SetPolygonOffsetState(pkState);

    if (pkState->FillEnabled)
    {
        m_fPolygonOffsetScale = pkState->Scale;

        // TO DO.  The renderer currently always creates a 24-bit depth
        // buffer.  If the precision changes, the adjustment to depth bias
        // must depend on the bits of precision.  The divisor is 2^n for n
        // bits of precision.
        m_fPolygonOffsetBias = pkState->Bias/16777216.0f;
    }
    else
    {
        m_fPolygonOffsetScale = 0.0f;
        m_fPolygonOffsetBias = 0.0f;
    }
}
//----------------------------------------------------------------------------
