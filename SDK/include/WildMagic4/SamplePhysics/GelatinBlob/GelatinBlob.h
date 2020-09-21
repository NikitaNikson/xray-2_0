// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef GELATINBLOB_H
#define GELATINBLOB_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class GelatinBlob : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    GelatinBlob ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // a mass-spring system
    PhysicsModule* m_pkModule;
    void DoPhysical ();

    // scene graph
    void CreateSphere ();
    void CreateSprings ();
    void CreateSegments ();
    void CreateScene ();
    NodePtr m_spkScene, m_spkTrnNode, m_spkSegments;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkIcosahedron;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(GelatinBlob);

#endif
