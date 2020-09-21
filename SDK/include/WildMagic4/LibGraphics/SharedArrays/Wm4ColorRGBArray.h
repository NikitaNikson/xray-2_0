// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4COLORRGBARRAY_H
#define WM4COLORRGBARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4ColorRGB.h"

namespace Wm4
{
typedef TSharedArray<ColorRGB> ColorRGBArray;
typedef Pointer<ColorRGBArray> ColorRGBArrayPtr;
WM4_REGISTER_STREAM(ColorRGBArray);
}

#endif
