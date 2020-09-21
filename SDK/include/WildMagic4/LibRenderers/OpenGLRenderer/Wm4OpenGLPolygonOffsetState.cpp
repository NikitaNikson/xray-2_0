// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4OpenGLRendererPCH.h"
#include "Wm4OpenGLRenderer.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void OpenGLRenderer::SetPolygonOffsetState (PolygonOffsetState* pkState)
{
    Renderer::SetPolygonOffsetState(pkState);

    if (pkState->FillEnabled)
    {
        glEnable(GL_POLYGON_OFFSET_FILL);
    }
    else
    {
        glDisable(GL_POLYGON_OFFSET_FILL);
    }

    if (pkState->LineEnabled)
    {
        glEnable(GL_POLYGON_OFFSET_LINE);
    }
    else
    {
        glDisable(GL_POLYGON_OFFSET_LINE);
    }

    if (pkState->PointEnabled)
    {
        glEnable(GL_POLYGON_OFFSET_POINT);
    }
    else
    {
        glDisable(GL_POLYGON_OFFSET_POINT);
    }

    glPolygonOffset(pkState->Scale,pkState->Bias);
}
//----------------------------------------------------------------------------
