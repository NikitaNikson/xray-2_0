// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4IKGOAL_H
#define WM4IKGOAL_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Spatial.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM IKGoal : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    IKGoal (Spatial* pkTarget, Spatial* pkEffector, float fWeight);

    SpatialPtr GetTarget ();
    SpatialPtr GetEffector ();
    float Weight;  // default = 1.0f

    Vector3f GetTargetPosition () const;
    Vector3f GetEffectorPosition () const;

protected:
    IKGoal ();

    SpatialPtr m_spkTarget;
    SpatialPtr m_spkEffector;
};

WM4_REGISTER_STREAM(IKGoal);
typedef Pointer<IKGoal> IKGoalPtr;
#include "Wm4IKGoal.inl"

}

#endif
