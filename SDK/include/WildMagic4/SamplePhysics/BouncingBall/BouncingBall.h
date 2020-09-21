// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BOUNCINGBALL_H
#define BOUNCINGBALL_H

#include "Wm4WindowApplication3.h"
#include "DeformableBall.h"
using namespace Wm4;

class BouncingBall : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BouncingBall ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateBall ();
    void CreateFloor ();
    void CreateWall ();
    void DoPhysical ();
    void DoVisual ();

    // representation of body
    DeformableBall* m_pkBall;

    // simulated clock
    float m_fSimTime, m_fSimDelta;

    // the scene graph
    NodePtr m_spkScene, m_spkBall;
    TriMeshPtr m_spkFloor, m_spkWall;
    WireframeStatePtr m_spkWireframeState;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(BouncingBall);

#endif
