// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VECTOR3ARRAY_H
#define WM4VECTOR3ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Vector3.h"

namespace Wm4
{
typedef TSharedArray<Vector3f> Vector3fArray;
typedef Pointer<Vector3fArray> Vector3fArrayPtr;
WM4_REGISTER_STREAM(Vector3fArray);

typedef TSharedArray<Vector3d> Vector3dArray;
typedef Pointer<Vector3dArray> Vector3dArrayPtr;
WM4_REGISTER_STREAM(Vector3dArray);
}

#endif