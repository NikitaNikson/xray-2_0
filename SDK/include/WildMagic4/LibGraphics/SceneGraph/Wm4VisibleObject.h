// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VISIBLEOBJECT_H
#define WM4VISIBLEOBJECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class Effect;
class Spatial;

class WM4_GRAPHICS_ITEM VisibleObject
{
public:
    Spatial* Object;
    Effect* GlobalEffect;

    bool IsDrawable () const;
};

#include "Wm4VisibleObject.inl"

}

#endif
