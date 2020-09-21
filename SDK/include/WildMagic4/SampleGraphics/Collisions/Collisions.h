// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class Collisions : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Collisions ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();

    NodePtr m_spkScene;
    TriMeshPtr m_spkCyln0, m_spkCyln1;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    // collision system
    CollisionGroup* m_pkGroup;
    bool Transform (unsigned char ucKey);
    void ResetColors ();
    static void Response (CollisionRecord& rkRecord0, int iT0,
        CollisionRecord& rkRecord1, int iT1,
        Intersector<float,Vector3f>* pkIntersector);

    ImagePtr m_spkCylinderImage;
    static Vector2f ms_kBlueUV, ms_kRedUV, ms_kCyanUV, ms_kYellowUV;
};

WM4_REGISTER_INITIALIZE(Collisions);

#endif
