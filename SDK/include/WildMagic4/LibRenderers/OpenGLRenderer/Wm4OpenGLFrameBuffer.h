// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4OPENGLFRAMEBUFFER_H
#define WM4OPENGLFRAMEBUFFER_H

#include "Wm4OpenGLRendererLIB.h"
#include "Wm4OpenGLRenderer.h"
#include "Wm4Main.h"
#include "Wm4FrameBuffer.h"

namespace Wm4
{

class WM4_RENDERER_ITEM OpenGLFrameBuffer : public FrameBuffer
{
    WM4_DECLARE_INITIALIZE;

public:
    OpenGLFrameBuffer (FormatType eFormat, DepthType eDepth,
        StencilType eStencil, BufferingType eBuffering,
        MultisamplingType eMultisampling, Renderer* pkRenderer,
        Texture* pkTarget);

    virtual ~OpenGLFrameBuffer ();

    bool InitializeBuffer ();
    void TerminateBuffer ();

    virtual void Enable ();
    virtual void Disable ();
    virtual void CopyToTexture (bool bFillImage);
    virtual void CopyTo (VertexBuffer* pkVBuffer, bool bCopyToSystemMemory);

protected:
    GLuint m_uiFrameBufferID;
    GLuint m_uiDepthBufferID;
    GLuint m_uiStencilBufferID;
    GLuint m_uiTargetID;
    bool m_bEnabled;

    // TO DO.  What about buffering and multisampling?

    // factory functions
    static FrameBuffer* Create (FormatType eFormat, DepthType eDepth,
        StencilType eStencil, BufferingType eBuffering,
        MultisamplingType eMultisampling, Renderer* pkRenderer,
        Texture* pkTarget);

    static void Destroy (FrameBuffer* pkBuffer);
};

WM4_REGISTER_INITIALIZE(OpenGLFrameBuffer);

}

#endif
