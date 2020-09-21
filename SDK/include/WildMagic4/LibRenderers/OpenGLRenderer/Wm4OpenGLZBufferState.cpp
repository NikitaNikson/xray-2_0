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

GLenum OpenGLRenderer::ms_aeZBufferCompare[ZBufferState::CF_QUANTITY] =
{
    GL_NEVER,
    GL_LESS,
    GL_EQUAL,
    GL_LEQUAL,
    GL_GREATER,
    GL_NOTEQUAL,
    GL_GEQUAL,
    GL_ALWAYS
};

//----------------------------------------------------------------------------
void OpenGLRenderer::SetZBufferState (ZBufferState* pkState)
{
    Renderer::SetZBufferState(pkState);

    if (pkState->Enabled)
    {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(ms_aeZBufferCompare[pkState->Compare]);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
        glDepthFunc(GL_ALWAYS);
    }

    if (pkState->Writable)
    {
        glDepthMask(GL_TRUE);
    }
    else
    {
        glDepthMask(GL_FALSE);
    }
}
//----------------------------------------------------------------------------
