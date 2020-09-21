// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MATRIX3ARRAY_H
#define WM4MATRIX3ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Matrix3.h"

namespace Wm4
{
typedef TSharedArray<Matrix3f> Matrix3fArray;
typedef Pointer<Matrix3fArray> Matrix3fArrayPtr;
WM4_REGISTER_STREAM(Matrix3fArray);

typedef TSharedArray<Matrix3d> Matrix3dArray;
typedef Pointer<Matrix3dArray> Matrix3dArrayPtr;
WM4_REGISTER_STREAM(Matrix3dArray);
}

#endif
