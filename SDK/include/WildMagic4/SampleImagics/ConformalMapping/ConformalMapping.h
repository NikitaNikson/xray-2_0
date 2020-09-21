// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CONFORMALMAPPING_H
#define CONFORMALMAPPING_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ConformalMapping : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ConformalMapping ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ScaleToCube (float fExtreme);
    void PseudocolorVertices ();
    void DoMapping ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    NodePtr m_spkMeshTree, m_spkSphereTree;
    TriMeshPtr m_spkMesh;
    TriMeshPtr m_spkSphere;
    Culler m_kCuller;

    float m_fExtreme;
};

WM4_REGISTER_INITIALIZE(ConformalMapping);

#endif
