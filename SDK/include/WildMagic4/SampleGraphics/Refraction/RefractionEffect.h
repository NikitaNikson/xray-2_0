// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef REFRACTIONEFFECT_H
#define REFRACTIONEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class RefractionEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    RefractionEffect (const char* acEnvironmentName,
        const char* acReflectionName);
    virtual ~RefractionEffect ();

    void SetFresnelConstant (int i, float fValue);
    float GetFresnelConstant (int i) const;
    void SetEtaRatio (float fEtaRatio);
    float GetEtaRatio () const;

protected:
    // streaming
    RefractionEffect ();

    // The first three values are the Fresnel constants.  The fourth value
    // is the eta ratio.
    float m_afVConstant[4];
};

WM4_REGISTER_STREAM(RefractionEffect);
typedef Pointer<RefractionEffect> RefractionEffectPtr;

#include "RefractionEffect.inl"

}

#endif
