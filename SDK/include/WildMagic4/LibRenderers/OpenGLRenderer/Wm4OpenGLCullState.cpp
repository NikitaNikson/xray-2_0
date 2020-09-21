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

GLenum OpenGLRenderer::ms_aeFrontFace[CullState::FT_QUANTITY] =
{
    GL_CCW,
    GL_CW
};

GLenum OpenGLRenderer::ms_aeCullFace[CullState::CT_QUANTITY] =
{
    GL_FRONT,
    GL_BACK
};

//----------------------------------------------------------------------------
void OpenGLRenderer::SetCullState (CullState* pkState)
{
    Renderer::SetCullState(pkState);

    if (pkState->Enabled)
    {
        glEnable(GL_CULL_FACE);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }

    glFrontFace(ms_aeFrontFace[pkState->FrontFace]);

    if (!m_bReverseCullFace)
    {
        glCullFace(ms_aeCullFace[pkState->CullFace]);
    }
    else
    {
        if (ms_aeCullFace[pkState->CullFace] == GL_BACK)
        {
            glCullFace(GL_FRONT);
        }
        else
        {
            glCullFace(GL_BACK);
        }
    }
}
//----------------------------------------------------------------------------
