// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VECTOR2ARRAY_H
#define WM4VECTOR2ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Vector2.h"

namespace Wm4
{
typedef TSharedArray<Vector2f> Vector2fArray;
typedef Pointer<Vector2fArray> Vector2fArrayPtr;
WM4_REGISTER_STREAM(Vector2fArray);

typedef TSharedArray<Vector2d> Vector2dArray;
typedef Pointer<Vector2dArray> Vector2dArrayPtr;
WM4_REGISTER_STREAM(Vector2dArray);
}

#endif
