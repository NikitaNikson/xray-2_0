// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SHADOWMAPS2_H
#define SHADOWMAPS2_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ShadowMaps2 : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ShadowMaps2 ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateGeometricObjects ();
    void CreateShaderConstants ();
    void CreateImagesTexturesFBOs ();
    void CreateShaders ();

    // shader constants
    Vector3f m_kLightWorldPosition;
    Matrix4f m_kLightVPMatrix;
    Matrix4f m_kLightVPBSMatrix;
    ColorRGBA m_kLightColor;
    float m_fDepthBias;
    int m_iShadowSize;
    float m_fTexelSize;
    enum { NUM_WEIGHTS = 11 };
    Vector3f m_akWeights[NUM_WEIGHTS];
    Vector2f m_akHOffsets[NUM_WEIGHTS];
    Vector2f m_akVOffsets[NUM_WEIGHTS];

    // scene objects
    NodePtr m_spkScene;
    TriMeshPtr m_spkPlane, m_spkSphere;
    WireframeStatePtr m_spkWireframe;
    ShaderEffectPtr m_spkPlaneEffect, m_spkSphereEffect;
    Culler m_kCuller;

    // shadow objects
    ImagePtr m_spkShadowImage;
    TexturePtr m_spkShadowTarget;
    FrameBuffer* m_pkShadowFBO;
    ShaderEffectPtr m_spkShadowEffect;

    // unlit objects
    ImagePtr m_spkUnlitImage;
    TexturePtr m_spkUnlitTarget;
    FrameBuffer* m_pkUnlitFBO;
    ShaderEffectPtr m_spkUnlitEffect;

    // Gaussian blur objects
    CameraPtr m_spkScreenCamera;
    TriMeshPtr m_spkScreenPolygon;
    ImagePtr m_spkHBlurImage;
    TexturePtr m_spkHBlurTarget;
    FrameBuffer* m_pkHBlurFBO;
    ShaderEffectPtr m_spkHBlurEffect;
    ShaderEffectPtr m_spkVBlurEffect;
};

WM4_REGISTER_INITIALIZE(ShadowMaps2);

#endif
