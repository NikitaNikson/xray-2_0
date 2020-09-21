// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef FOUCAULTPENDULUM_H
#define FOUCAULTPENDULUM_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class FoucaultPendulum : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    FoucaultPendulum ();

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
    PolypointPtr m_spkPath;
    int m_iNextPoint;
    float m_fColorDiff;
    Culler m_kCuller;

    // physics
    PhysicsModule m_kModule;
};

WM4_REGISTER_INITIALIZE(FoucaultPendulum);

#endif
