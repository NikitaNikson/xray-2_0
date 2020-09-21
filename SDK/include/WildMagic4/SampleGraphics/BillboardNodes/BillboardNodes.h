// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BILLBOARDNODES_H
#define BILLBOARDNODES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

//#define DEMONSTRATE_VIEWPORT_BOUNDING_RECTANGLE
#define DEMONSTRATE_POST_PROJECTION_REFLECTION

class BillboardNodes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BillboardNodes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();

    NodePtr m_spkScene;
    BillboardNodePtr m_spkBillboard0, m_spkBillboard1;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

#ifdef DEMONSTRATE_POST_PROJECTION_REFLECTION
    CullStatePtr m_spkCullState;
#endif

#ifdef DEMONSTRATE_VIEWPORT_BOUNDING_RECTANGLE
    void CreateScreenObjects ();
    CameraPtr m_spkScreenCamera;
    TriMeshPtr m_spkScreenRectangle;
    TriMeshPtr m_spkTorus;
#endif
};

WM4_REGISTER_INITIALIZE(BillboardNodes);

#endif
