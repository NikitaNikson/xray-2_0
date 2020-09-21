// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4GLXRENDERER_H
#define WM4GLXRENDERER_H

#include "Wm4OpenGLRendererLIB.h"
#include "Wm4OpenGLRenderer.h"
#include "GTglxExtensions.h"

namespace Wm4
{

class WM4_RENDERER_ITEM GlxRenderer : public OpenGLRenderer
{
public:
    // construction and destruction
    GlxRenderer (Display* pkDisplay, FrameBuffer::FormatType eFormat,
        FrameBuffer::DepthType eDepth, FrameBuffer::StencilType eStencil,
        FrameBuffer::BufferingType eBuffering,
        FrameBuffer::MultisamplingType eMultisampling, int iWidth,
        int iHeight);

    virtual void Activate ();
    virtual bool IsActive () const;
    virtual void ToggleFullscreen ();
    virtual bool BeginScene ();
    virtual void DisplayBackBuffer ();
    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic) { return -1; }
    virtual void UnloadFont (int iFontID) { /**/ }

    Display* GetDisplay () { return m_pkDisplay; }
    XVisualInfo* GetVisual () { return m_pkVisual; }
    Window GetWindow () { return m_ulWindow; }
    GLXContext GetContext () { return m_kContext; }

private:
    // context handling
    virtual void SaveContext ();
    virtual void RestoreContext ();

    // window parameters
    Display* m_pkDisplay;
    XVisualInfo* m_pkVisual;
    Window m_ulWindow;
    GLXContext m_kContext;

    // for switching contexts
    Display* m_pkSaveDisplay;
    Window m_ulSaveWindow;
    GLXContext m_kSaveContext;

    // fullscreen/window support
    int m_iSaveWidth, m_iSaveHeight;

    bool m_bIsConstructed;

// internal use
public:
    // For the application layer and pbuffers.
    void FinishConstruction (Window ulWindow);
    bool IsConstructed () const { return m_bIsConstructed; }
};

}

#endif


