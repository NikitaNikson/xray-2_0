// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef RIPPLINGOCEAN_H
#define RIPPLINGOCEAN_H

#include "Wm4WindowApplication3.h"
#include "RipplingOceanEffect.h"
using namespace Wm4;

class RipplingOcean : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    RipplingOcean ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateNormalMapFromHeightImage (const char* acImageName);

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    RipplingOceanEffectPtr m_spkEffect;
    ImagePtr m_spkNormalMap;
    Culler m_kCuller;

    // Time information.
    bool m_bStopped;
    float m_fStopTime;

    // Wave information.
    float m_fWaveSpeedAmplitude;
    float m_fWaveHeightAmplitude;
    float m_fBumpSpeedAmplitude;
    float m_afWaveSpeed[4];
    float m_afWaveHeight[4];
    float m_afBumpSpeed[4];
};

WM4_REGISTER_INITIALIZE(RipplingOcean);

#endif
