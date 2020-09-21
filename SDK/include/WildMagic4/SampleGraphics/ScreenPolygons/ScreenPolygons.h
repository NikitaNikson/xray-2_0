// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SCREENPOLYGONS_H
#define SCREENPOLYGONS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ScreenPolygons : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ScreenPolygons ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();

    NodePtr m_spkScene;
    CameraPtr m_spkScreenCamera;
    TriMeshPtr m_spkForePoly, m_spkMidPoly, m_spkBackPoly;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    float m_fLinearZ, m_fDepthZ;
    double m_dAnimTime, m_dAnimTimeDelta;
};

WM4_REGISTER_INITIALIZE(ScreenPolygons);

#endif
