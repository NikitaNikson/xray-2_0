// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef REFLECTIONSANDSHADOWS_H
#define REFLECTIONSANDSHADOWS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ReflectionsAndShadows : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ReflectionsAndShadows ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void LoadBiped ();
    void CreatePlanes ();
    void CreatePlanarReflection ();
    void CreatePlanarShadow ();

    NodePtr m_spkScene;
    NodePtr m_spkBiped;
    TriMeshPtr m_spkPlane0, m_spkPlane1;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    double m_dAnimTime, m_dAnimTimeDelta;
};

WM4_REGISTER_INITIALIZE(ReflectionsAndShadows);

#endif
