// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef INTERSECTCONVEXPOLYHEDRA_H
#define INTERSECTCONVEXPOLYHEDRA_H

#include "Wm4WindowApplication3.h"
#include "Wm4ConvexPolyhedron.h"
using namespace Wm4;

class IntersectConvexPolyhedra : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    IntersectConvexPolyhedra ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void ComputeIntersection ();

    NodePtr m_spkScene;
    TriMeshPtr m_spkMeshPoly0, m_spkMeshPoly1, m_spkMeshIntersection;
    VertexColor3EffectPtr m_spkEffect;
    Culler m_kCuller;
    Attributes m_kAttr;

    ConvexPolyhedronf m_kWorldPoly0, m_kWorldPoly1, m_kIntersection;
};

WM4_REGISTER_INITIALIZE(IntersectConvexPolyhedra);

#endif
