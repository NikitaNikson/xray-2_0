// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef VOLUMETEXTURES_H
#define VOLUMETEXTURES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class VolumeTextures : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    VolumeTextures ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateVolumeTexture ();
    void CreateGridMesh ();
    TriMesh* Rectangle (int iSamples0, int iSamples1, float fW);

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkMesh;
    ImagePtr m_spkVolume;
    ShaderEffectPtr m_spkVolumeTexture;
    float m_afCommonAlpha[4];  // channel 0 has the alpha value
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(VolumeTextures);

#endif
