// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CUBEMAPS_H
#define CUBEMAPS_H

#include "Wm4WindowApplication3.h"
#include "CubeMapEffect.h"
using namespace Wm4;

class CubeMaps : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    CubeMaps ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void MorphSphere ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    CullStatePtr m_spkCull;
    TriMeshPtr m_spkSphere;
    CubeMapEffectPtr m_spkCubeMap;
    Culler m_kCuller;

    // For random morphing of the sphere.
    float m_fRadius;
    float* m_afAmplitude;
    float* m_afFrequency;
};

WM4_REGISTER_INITIALIZE(CubeMaps);

#endif
