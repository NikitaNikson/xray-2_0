// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4OPENGLBITMAPFONT_H
#define WM4OPENGLBITMAPFONT_H

#include "Wm4OpenGLRendererLIB.h"

namespace Wm4
{

class WM4_RENDERER_ITEM BitmapFontChar
{
public:
    BitmapFontChar (int iXOrigin, int iYOrigin, int iXSize, int iYSize,
        const unsigned char* aucBitmap)
    {
        XOrigin = iXOrigin;
        YOrigin = iYOrigin;
        XSize = iXSize;
        YSize = iYSize;
        Bitmap = aucBitmap;
    }

    int XOrigin, YOrigin, XSize, YSize;
    const unsigned char* Bitmap;
};

class WM4_RENDERER_ITEM BitmapFont
{
public:
    BitmapFont (const char* acName, int iQuantity,
        const BitmapFontChar* const* pkChars)
    {
        Name = acName;
        Quantity = iQuantity;
        Chars = pkChars;
    }

    const char* Name;
    int Quantity;
    const BitmapFontChar* const* Chars;
};

extern const BitmapFont g_kVerdana_S16B0I0;

}

#endif
