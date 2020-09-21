// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef POINTINPOLYHEDRON_H
#define POINTINPOLYHEDRON_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class PointInPolyhedron : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    PointInPolyhedron ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateQuery (TriMesh* pkMesh);
    void DeleteQuery ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    PolypointPtr m_spkPoints;
    Culler m_kCuller;

    PointInPolyhedron3f* m_pkQuery;
    PointInPolyhedron3f::TriangleFace* m_akTFace;
    PointInPolyhedron3f::ConvexFace* m_akCFace;
    PointInPolyhedron3f::SimpleFace* m_akSFace;
    int m_iRayQuantity;
    Vector3f* m_akRayDirection;
};

WM4_REGISTER_INITIALIZE(PointInPolyhedron);

#endif
