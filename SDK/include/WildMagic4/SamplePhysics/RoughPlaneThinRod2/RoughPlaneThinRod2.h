// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef ROUGHPLANETHINROD2_H
#define ROUGHPLANETHINROD2_H

#include "Wm4WindowApplication2.h"
#include "PhysicsModule.h"
using namespace Wm4;

class RoughPlaneThinRod2 : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    RoughPlaneThinRod2 ();

    virtual bool OnInitialize ();
    virtual void OnIdle ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    PhysicsModule m_kModule;
};

WM4_REGISTER_INITIALIZE(RoughPlaneThinRod2);

#endif
