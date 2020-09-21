// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef ROPE_H
#define ROPE_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;


class Rope : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Rope ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // The masses are located at the control points of a spline curve.  The
    // control points are connected by a mass-spring system.
    BSplineCurve3f* m_pkSpline;
    PhysicsModule* m_pkModule;
    void DoPhysical ();

    // scene graph
    void CreateSprings ();
    void CreateRope ();
    void CreateScene ();
    static float Radial (float) { return 0.025f; }
    NodePtr m_spkScene, m_spkTrnNode;
    WireframeStatePtr m_spkWireframe;
    TubeSurfacePtr m_spkRope;
    Culler m_kCuller;

    // controlled frame rate
    float m_fLastIdle;
};

WM4_REGISTER_INITIALIZE(Rope);

#endif
