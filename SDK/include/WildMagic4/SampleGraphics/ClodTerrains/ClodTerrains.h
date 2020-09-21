// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CLODTERRAINS_H
#define CLODTERRAINS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ClodTerrains : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ClodTerrains ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateSkyDome ();
    void CreateTerrain ();

    // turret-based camera motion
    virtual void MoveForward ();
    virtual void MoveBackward ();
    virtual void MoveUp ();
    virtual void MoveDown ();
    virtual void TurnLeft ();
    virtual void TurnRight ();
    virtual void LookUp ();
    virtual void LookDown ();

    NodePtr m_spkScene;
    ClodTerrainPtr m_spkTerrain;
    TriMeshPtr m_spkSkyDome;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    float m_fUVBias;
    ColorRGBA m_kFogColor;
    float m_fHeightAboveTerrain;

    // override the simplification by setting to 'false'
    bool m_bAllowSimplification;
};

WM4_REGISTER_INITIALIZE(ClodTerrains);

#endif
