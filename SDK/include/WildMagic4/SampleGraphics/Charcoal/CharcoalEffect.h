// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CHARCOALEFFECT_H
#define CHARCOALEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Light.h"

namespace Wm4
{

class CharcoalEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM_WITH_POSTLINK;

public:
    // The vertex shader expects two lights.  They should be attached
    // somewhere in the scene to affect the Geometry object to which this
    // effect is attached.  TO DO.  See the note in CharcoalEffects, function
    // CreateScene.
    CharcoalEffect (const char* acPaperName, float fAmbientIntensity,
        float fContrastExponent, float fSmudgeFactor, float fPaperFactor,
        Light* pkLight0, Light* pkLight1);
    virtual ~CharcoalEffect ();

    virtual void SetGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);
    virtual void RestoreGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);

    void SetAmbientIntensity (float fAmbientIntensity);
    float GetAmbientIntensity () const;
    void SetContrastExponent (float fContrastExponent);
    float GetContrastExponent () const;
    void SetSmudgeFactor (float fSmudgeFactor);
    float GetSmudgeFactor () const;
    void SetPaperFactor (float fPaperFactor);
    float GetPaperFactor () const;

protected:
    // streaming
    CharcoalEffect ();

    // Exchange information between the effect and the programs.
    void GenerateContrastImage ();
    void GenerateRandomImage ();

    // VShader constants.  The ambient intensity is stored at index 0.  The
    // contrast exponent is stored at index 1.  The other values are unused.
    float m_afAmbientContrast[4];

    // PShader constants.  The smudge factor is stored at index 0.  The paper
    // factor is stored at index 1.  The other values are unused.
    float m_afSmudgePaper[4];

    ImagePtr m_spkContrastImage, m_spkRandomImage;
    LightPtr m_spkLight0, m_spkLight1;
};

WM4_REGISTER_STREAM(CharcoalEffect);
typedef Pointer<CharcoalEffect> CharcoalEffectPtr;
#include "CharcoalEffect.inl"

}

#endif
