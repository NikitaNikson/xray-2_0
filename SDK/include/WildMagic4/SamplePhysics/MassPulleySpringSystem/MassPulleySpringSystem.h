// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef MASSPULLEYSPRINGSYSTEM_H
#define MASSPULLEYSPRINGSYSTEM_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class MassPulleySpringSystem : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    MassPulleySpringSystem ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    TriMesh* CreateFloor ();
    TubeSurface* CreateCable ();
    TriMesh* CreateMass (float fRadius);
    void CreatePulley ();
    void CreateSpring ();
    TubeSurface* CreateHelix ();

    void DoPhysical ();
    void UpdatePulley ();
    void UpdateCable ();
    void UpdateHelix ();

    // root of scene and floor mesh
    NodePtr m_spkScene;
    TriMeshPtr m_spkFloor;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    // assembly to parent the cable root and pulley root
    NodePtr m_spkAssembly;

    // cable modeled as a tube surface, masses attached to ends
    NodePtr m_spkCableRoot;
    BSplineCurve3f* m_pkCableSpline;
    TubeSurfacePtr m_spkCable;
    static float CableRadial (float);
    TriMeshPtr m_spkMass1, m_spkMass2;

    // node to parent the pulley and spring
    NodePtr m_spkPulleyRoot;

    // pulley modeled as a disk with thickness
    NodePtr m_spkPulley;
    TriMeshPtr m_spkPlate0, m_spkPlate1, m_spkCylinder;
    TextureEffectPtr m_spkMetal;

    // Spring modeled as a tube surface in the shape of a helix, then attached
    // to a U-bracket to hold the pulley disk.
    NodePtr m_spkSpring;
    TriMeshPtr m_spkSide0, m_spkSide1, m_spkTop;
    BSplineCurve3f* m_pkHelixSpline;
    TubeSurfacePtr m_spkHelix;
    static float HelixRadial (float);

    PhysicsModule m_kModule;

    // controlled frame rate
    float m_fLastIdle;
};

WM4_REGISTER_INITIALIZE(MassPulleySpringSystem);

#endif
