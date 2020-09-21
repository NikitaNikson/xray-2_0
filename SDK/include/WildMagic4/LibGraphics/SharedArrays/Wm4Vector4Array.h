// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VECTOR4ARRAY_H
#define WM4VECTOR4ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Vector4.h"

namespace Wm4
{
typedef TSharedArray<Vector4f> Vector4fArray;
typedef Pointer<Vector4fArray> Vector4fArrayPtr;
WM4_REGISTER_STREAM(Vector4fArray);

typedef TSharedArray<Vector4d> Vector4dArray;
typedef Pointer<Vector4dArray> Vector4dArrayPtr;
WM4_REGISTER_STREAM(Vector4dArray);
}

#endif
