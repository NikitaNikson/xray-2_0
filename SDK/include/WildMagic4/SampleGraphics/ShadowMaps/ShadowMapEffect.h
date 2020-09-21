// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SHADOWMAPEFFECT_H
#define SHADOWMAPEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Camera.h"
#include "Wm4Texture.h"

namespace Wm4
{

class ShadowMapEffect : public Effect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    ShadowMapEffect (Camera* pkProjector,
        const std::string& rkProjectionImage, int iDepthWidth,
        int iDepthHeight, float fDepthBias);

    virtual ~ShadowMapEffect ();

    virtual void Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
        int iMin, int iMax, VisibleObject* akVisible);

    void SetDepthBias (float fDepthBias);
    float GetDepthBias () const;

protected:
    ShadowMapEffect ();

    CameraPtr m_spkProjector;
    ShaderEffectPtr m_spkDepthEffect;
    FrameBuffer* m_pkDepthBuffer;
    ImagePtr m_spkDepthImage;
    ShaderEffectPtr m_spkShadowEffect;
    Texture* m_pkDepthTexture;  // For testing (copy depth to system memory).

    // The depth bias is stored at index 0.  The other array values are
    // unused.
    float m_afDepthBias[4];
};

WM4_REGISTER_STREAM(ShadowMapEffect);
typedef Pointer<ShadowMapEffect> ShadowMapEffectPtr;
#include "ShadowMapEffect.inl"

}

#endif
