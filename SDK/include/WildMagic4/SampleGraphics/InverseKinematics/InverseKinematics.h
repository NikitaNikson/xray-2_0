// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef INVERSEKINEMATICS_H
#define INVERSEKINEMATICS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class InverseKinematics : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    InverseKinematics ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    TriMesh* CreateCube ();
    Polyline* CreateRod ();
    TriMesh* CreateGround ();
    void UpdateRod ();
    bool Transform (unsigned char ucKey);

    NodePtr m_spkScene, m_spkIKSystem, m_spkGoal, m_spkJoint0, m_spkJoint1;
    WireframeStatePtr m_spkWireframe;
    PolylinePtr m_spkRod;
    VertexColor3EffectPtr m_spkVCEffect;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(InverseKinematics);

#endif
