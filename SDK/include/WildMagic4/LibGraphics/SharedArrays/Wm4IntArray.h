// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4INTARRAY_H
#define WM4INTARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"

namespace Wm4
{
typedef TSharedArray<int> IntArray;
typedef Pointer<IntArray> IntArrayPtr;
WM4_REGISTER_STREAM(IntArray);
}

#endif
