// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MACSOFTRENDERER_H
#define WM4MACSOFTRENDERER_H

#include <Carbon/Carbon.h>
#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftRenderer.h"

namespace Wm4
{

class WM4_RENDERER_ITEM MacSoftRenderer : public SoftRenderer
{
public:
    MacSoftRenderer (WindowRef pkWindow, FrameBuffer::FormatType eFormat,
        FrameBuffer::DepthType eDepth, FrameBuffer::StencilType eStencil,
        FrameBuffer::BufferingType eBuffering,
        FrameBuffer::MultisamplingType eMultisampling, int iWidth,
        int iHeight);

    virtual ~MacSoftRenderer ();

    // back buffer handling
    virtual void ClearBackBuffer ();
    virtual void DisplayBackBuffer ();

    // text drawing
    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic);
    virtual void UnloadFont (int iFontID);
    virtual bool SelectFont (int iFontID);
    virtual void Draw (int iX, int iY, const ColorRGBA& rkColor,
        const char* acText);

    // 2D drawing
    virtual void Draw (const unsigned char* aucBuffer);

    // Enable or disable which color channels will be written to the color
    // buffer.
    virtual void SetColorMask (bool bAllowRed, bool bAllowGreen,
        bool bAllowBlue, bool bAllowAlpha);

private:
    virtual void ClearSubBackBuffer (int iXMin, int iYMin, int iXMax,
        int iYMax);

    virtual void SetColorBuffer (int iX, int iY, int iIndex,
        const ColorRGBA& rkColor);

    WindowRef m_pkWindow;
    unsigned int* m_auiData;
    CGContextRef m_pkContext;
};

}

#endif


