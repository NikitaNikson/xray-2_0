// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef GELATINCUBE_H
#define GELATINCUBE_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class GelatinCube : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    GelatinCube ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // The masses are located at the control points of a spline surface.
    // The control points are connected in a mass-spring system.
    BSplineVolumef* m_pkSpline;
    PhysicsModule* m_pkModule;
    void DoPhysical ();

    // scene graph
    void CreateSprings ();
    void CreateBox ();
    void CreateScene ();
    NodePtr m_spkScene, m_spkTrnNode;
    WireframeStatePtr m_spkWireframe;
    BoxSurfacePtr m_spkBox;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(GelatinCube);

#endif
