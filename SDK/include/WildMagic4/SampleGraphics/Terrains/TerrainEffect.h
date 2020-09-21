// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef TERRAINEFFECT_H
#define TERRAINEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class TerrainEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM_WITH_POSTLINK;

public:
    // The fog factor is computed to be f = exp(-(d*z)^2), where d is the
    // fog density and z is the z-component of the view-space vertex position.
    TerrainEffect (const char* acBaseName, const char* acDetailName,
        const ColorRGB& rkFogColor, float fFogDensity);
    virtual ~TerrainEffect ();

    void SetFogColor (const ColorRGB& rkFogColor);
    ColorRGB GetFogColor () const;

    void SetFogDensity (float fFogDensity);
    float GetFogDensity () const;

protected:
    // streaming
    TerrainEffect ();

    // The fog color is stored in the first three components (R = 0, G = 1,
    // and B = 2).  The fog density is stored in the last component.
    float m_afFogColorDensity[4];
};

WM4_REGISTER_STREAM(TerrainEffect);
typedef Pointer<TerrainEffect> TerrainEffectPtr;

#include "TerrainEffect.inl"

}

#endif
