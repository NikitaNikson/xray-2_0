// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef ROUGHPLANESOLIDBOX_H
#define ROUGHPLANESOLIDBOX_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class RoughPlaneSolidBox : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    RoughPlaneSolidBox ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    Node* CreateBox ();
    TriMesh* CreateRamp ();
    TriMesh* CreateGround();
    void InitializeModule ();
    void MoveBox ();
    void DoPhysical ();

    NodePtr m_spkScene, m_spkBox;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    PhysicsModule m_kModule;
    bool m_bDoUpdate;
};

WM4_REGISTER_INITIALIZE(RoughPlaneSolidBox);

#endif
