// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ApplicationPCH.h"
#include "Wm4WindowApplication.h"
using namespace Wm4;

//----------------------------------------------------------------------------
WindowApplication::WindowApplication (const char* acWindowTitle,
    int iXPosition, int iYPosition, int iWidth, int iHeight,
    const ColorRGBA& rkBackgroundColor)
    :
    m_acWindowTitle(acWindowTitle),
    m_iXPosition(iXPosition),
    m_iYPosition(iYPosition),
    m_iWidth(iWidth),
    m_iHeight(iHeight),
    m_kBackgroundColor(rkBackgroundColor)
{
    m_iWindowID = 0;
    m_pkRenderer = 0;

    // Default buffer parameters.  These may be overridden by the derived
    // class constructor.  Current hardware seems to pack a 24-bit depth
    // buffer and 8-bit stencil buffer into a 32-bit buffer, so I suggest
    // not overriding these.  Perhaps the only one you should is the
    // multisampling value.
    m_eFormat = FrameBuffer::FT_FORMAT_RGBA;
    m_eDepth = FrameBuffer::DT_DEPTH_24;
    m_eStencil = FrameBuffer::ST_STENCIL_8;
    m_eBuffering = FrameBuffer::BT_BUFFERED_DOUBLE;
    m_eMultisampling = FrameBuffer::MT_SAMPLING_NONE;
}
//----------------------------------------------------------------------------
WindowApplication::~WindowApplication ()
{
}
//----------------------------------------------------------------------------
int WindowApplication::Run (int iQuantity, char** apcArgument)
{
    WindowApplication* pkTheApp = (WindowApplication*)TheApplication;
    return pkTheApp->Main(iQuantity,apcArgument);
}
//----------------------------------------------------------------------------
bool WindowApplication::OnInitialize ()
{
    m_pkRenderer->SetClearColor(m_kBackgroundColor);

    // Now that the renderer has been created, provide the program loaders
    // with the information needed to load the correct programs.
    Program::RendererType = m_pkRenderer->GetExtension();
    Program::CommentChar = m_pkRenderer->GetCommentCharacter();

    return true;
}
//----------------------------------------------------------------------------
void WindowApplication::OnTerminate ()
{
    // Notify the program loaders that the renderer is going away.
    Program::RendererType = "";
    Program::CommentChar = 0;

    WM4_DELETE m_pkRenderer;
    m_pkRenderer = 0;
}
//----------------------------------------------------------------------------
void WindowApplication::OnMove (int iX, int iY)
{
    m_iXPosition = iX;
    m_iYPosition = iY;
}
//----------------------------------------------------------------------------
void WindowApplication::OnResize (int iWidth, int iHeight)
{
    if (iWidth > 0 && iHeight > 0)
    {
        if (m_pkRenderer)
        {
            m_pkRenderer->Resize(iWidth,iHeight);
        }

        m_iWidth = iWidth;
        m_iHeight = iHeight;
    }
}
//----------------------------------------------------------------------------
