// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4QUATERNIONARRAY_H
#define WM4QUATERNIONARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Quaternion.h"

namespace Wm4
{
typedef TSharedArray<Quaternionf> QuaternionfArray;
typedef Pointer<QuaternionfArray> QuaternionfArrayPtr;
WM4_REGISTER_STREAM(QuaternionfArray);

typedef TSharedArray<Quaterniond> QuaterniondArray;
typedef Pointer<QuaterniondArray> QuaterniondArrayPtr;
WM4_REGISTER_STREAM(QuaterniondArray);
}

#endif
