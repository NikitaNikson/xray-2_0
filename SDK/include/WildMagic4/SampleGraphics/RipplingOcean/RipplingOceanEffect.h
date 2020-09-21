// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef RIPPLINGOCEANEFFECT_H
#define RIPPLINGOCEANEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class RipplingOceanEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    RipplingOceanEffect (const char* acBumpName, const char* acWaterName,
        const char* acEnvName);
    virtual ~RipplingOceanEffect ();

    void SetLightDir (const Vector3f& rkValue);
    Vector3f GetLightDir () const;

    void SetWaveDirX (float afValue[4]);
    void GetWaveDirX (float afValue[4]) const;
    void SetWaveDirY (float afValue[4]);
    void GetWaveDirY (float afValue[4]) const;
    void SetWaveSpeed (float afValue[4]);
    void GetWaveSpeed (float afValue[4]) const;
    void SetWaveOffset (float afValue[4]);
    void GetWaveOffset (float afValue[4]) const;
    void SetWaveHeight (float afValue[4]);
    void GetWaveHeight (float afValue[4]) const;
    void SetBumpSpeed (float afValue[4]);
    void GetBumpSpeed (float afValue[4]) const;

    void SetAverageDuDxDvDy (float fValue);
    float GetAverageDuDxDvDy () const;
    void SetAmbient (float fValue);
    float GetAmbient () const;
    void SetTextureRepeat (float fValue);
    float GetTextureRepeat () const;
    void SetTime (float fValue);
    float GetTime () const;

protected:
    // streaming
    RipplingOceanEffect ();

    // The light direction is a 3-tuple.  The last component is unused.
    float m_afLightDir[4];

    // The rippling ocean is made up of 4 waves.
    float m_afWaveDirX[4];
    float m_afWaveDirY[4];
    float m_afWaveSpeed[4];
    float m_afWaveOffset[4];
    float m_afWaveHeight[4];
    float m_afBumpSpeed[4];

    // Index 0 is averageDuDxDvDy, index 1 is ambient, index 2 is
    // texture repeat, and index 3 is time.
    float m_afConstants[4];
};

WM4_REGISTER_STREAM(RipplingOceanEffect);
typedef Pointer<RipplingOceanEffect> RipplingOceanEffectPtr;
#include "RipplingOceanEffect.inl"

}

#endif
