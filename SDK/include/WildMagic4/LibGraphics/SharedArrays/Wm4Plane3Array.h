// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PLANE3ARRAY_H
#define WM4PLANE3ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Plane3.h"

namespace Wm4
{
typedef TSharedArray<Plane3f> Plane3fArray;
typedef Pointer<Plane3fArray> Plane3fArrayPtr;
WM4_REGISTER_STREAM(Plane3fArray);

typedef TSharedArray<Plane3d> Plane3dArray;
typedef Pointer<Plane3dArray> Plane3dArrayPtr;
WM4_REGISTER_STREAM(Plane3dArray);
}

#endif
