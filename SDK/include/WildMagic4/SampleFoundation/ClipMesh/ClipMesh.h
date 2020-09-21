// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CLIPMESH_H
#define CLIPMESH_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ClipMesh : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ClipMesh ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void Update ();

    // A torus.
    std::vector<Vector3f> m_kTorusVerticesMS, m_kTorusVerticesWS;
    std::vector<int> m_kTorusIndices;
    Plane3f m_kPlane;

    NodePtr m_spkScene;
    TriMeshPtr m_spkTorus, m_spkMeshPlane;
    WireframeStatePtr m_spkWireframe;
    VertexColor3EffectPtr m_spkEffect;
    Culler m_kCuller;
    Attributes m_kAttr;
};

WM4_REGISTER_INITIALIZE(ClipMesh);

#endif
