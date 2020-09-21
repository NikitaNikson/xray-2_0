// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BLENDEDTERRAINEFFECT_H
#define BLENDEDTERRAINEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class BlendedTerrainEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM_WITH_POSTLINK;

public:
    BlendedTerrainEffect (const char* acGrassName, const char* acStoneName,
        const char* acBlendName, const char* acCloudName);
    virtual ~BlendedTerrainEffect ();

    // for the vertex program
    void SetFlowDirection (const Vector2f& rkFlowDirection);
    Vector2f GetFlowDirection () const;

    // for the pixel program
    void SetPowerFactor (float fPowerFactor);
    float GetPowerFactor () const;

protected:
    // streaming
    BlendedTerrainEffect ();

    // The flow direction is stored in locations 0 and 1.  The others are
    // unused.
    float m_afFlowDirection[4];

    // The power factor is stored in location 0.  The others are unused.
    float m_afPowerFactor[4];
};

WM4_REGISTER_STREAM(BlendedTerrainEffect);
typedef Pointer<BlendedTerrainEffect> BlendedTerrainEffectPtr;

#include "BlendedTerrainEffect.inl"

}

#endif
