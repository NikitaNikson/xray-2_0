// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MATRIX4ARRAY_H
#define WM4MATRIX4ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Matrix4.h"

namespace Wm4
{
typedef TSharedArray<Matrix4f> Matrix4fArray;
typedef Pointer<Matrix4fArray> Matrix4fArrayPtr;
WM4_REGISTER_STREAM(Matrix4fArray);

typedef TSharedArray<Matrix4d> Matrix4dArray;
typedef Pointer<Matrix4dArray> Matrix4dArrayPtr;
WM4_REGISTER_STREAM(Matrix4dArray);
}

#endif
