// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BUMPMAPS_H
#define BUMPMAPS_H

#include "Wm4WindowApplication3.h"
#include "SimpleBumpMapEffect.h"
using namespace Wm4;

class BumpMaps : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BumpMaps ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    TriMesh* CreateTorus ();
    TriMesh* CreateSquare ();
    void UpdateBumpMap ();

    NodePtr m_spkScene;
    Culler m_kCuller;
    bool m_bUseTorus;
    bool m_bUseBumpMap;
};

WM4_REGISTER_INITIALIZE(BumpMaps);

#endif
