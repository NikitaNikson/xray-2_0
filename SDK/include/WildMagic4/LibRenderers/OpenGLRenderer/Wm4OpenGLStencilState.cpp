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

GLenum OpenGLRenderer::ms_aeStencilCompare[StencilState::CF_QUANTITY] =
{
    GL_NEVER,     // StencilState::CF_NEVER
    GL_LESS,      // StencilState::CF_LESS
    GL_EQUAL,     // StencilState::CF_EQUAL
    GL_LEQUAL,    // StencilState::CF_LEQUAL
    GL_GREATER,   // StencilState::CF_GREATER
    GL_NOTEQUAL,  // StencilState::CF_NOTEQUAL
    GL_GEQUAL,    // StencilState::CF_GEQUAL
    GL_ALWAYS     // StencilState::CF_ALWAYS
};

GLenum OpenGLRenderer::ms_aeStencilOperation[StencilState::OT_QUANTITY] =
{
    GL_KEEP,      // StencilState::OT_KEEP
    GL_ZERO,      // StencilState::OT_ZERO
    GL_REPLACE,   // StencilState::OT_REPLACE
    GL_INCR,      // StencilState::OT_INCREMENT
    GL_DECR,      // StencilState::OT_DECREMENT
    GL_INVERT     // StencilState::OT_INVERT
};

//----------------------------------------------------------------------------
void OpenGLRenderer::SetStencilState (StencilState* pkState)
{
    Renderer::SetStencilState(pkState);

    if (pkState->Enabled)
    {
        glEnable(GL_STENCIL_TEST);

        glStencilFunc(ms_aeStencilCompare[pkState->Compare],
            (GLint)pkState->Reference,pkState->Mask);

        glStencilMask(pkState->WriteMask);

        glStencilOp(ms_aeStencilOperation[pkState->OnFail],
            ms_aeStencilOperation[pkState->OnZFail],
            ms_aeStencilOperation[pkState->OnZPass]);
    }
    else
    {
        glDisable(GL_STENCIL_TEST);
    }
}
//----------------------------------------------------------------------------
