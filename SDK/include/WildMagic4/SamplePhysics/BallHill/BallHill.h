// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BALLHILL_H
#define BALLHILL_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class BallHill : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BallHill ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    TriMesh* CreateGround ();
    TriMesh* CreateHill ();
    TriMesh* CreateBall ();
    Polyline* CreatePath ();
    void DoPhysical ();
    Vector3f UpdateBall ();

    // scene graph
    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkBall;
    PolylinePtr m_spkPath;
    float m_fRadius;
    int m_iNextPoint;
    Culler m_kCuller;

    // physics
    PhysicsModule m_kModule;
};

WM4_REGISTER_INITIALIZE(BallHill);

#endif
