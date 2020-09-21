// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SIMPLEPENDULUMFRICTION_H
#define SIMPLEPENDULUMFRICTION_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class SimplePendulumFriction : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    SimplePendulumFriction ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    TriMesh* CreateFloor ();
    Polypoint* CreatePath ();
    Node* CreatePendulum ();
    void DoPhysical ();

    // the scene graph
    NodePtr m_spkScene, m_spkPendulum;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    // physics
    PhysicsModule m_kModule;

    // controlled frame rate
    float m_fLastIdle;
};

WM4_REGISTER_INITIALIZE(SimplePendulumFriction);

#endif
