// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SHADOWMAPS_H
#define SHADOWMAPS_H

#include "Wm4WindowApplication3.h"
#include "ShadowMapEffect.h"
using namespace Wm4;

class ShadowMaps : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ShadowMaps ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateGround ();
    void CreateTorus ();
    void CreateGlobe ();
    void CreateFlashlight ();

    NodePtr m_spkScene, m_spkShadowMapNode, m_spkFlashlight;
    TriMeshPtr m_spkGround, m_spkTorus, m_spkGlobe, m_spkLightSphere;
    LightPtr m_spkLight;
    WireframeStatePtr m_spkWireframe;
    ShadowMapEffectPtr m_spkSMEffect;
    Culler m_kCuller;

    const char* m_acCaption;
    static const char* ms_aacCaptions[3];
};

WM4_REGISTER_INITIALIZE(ShadowMaps);

#endif
