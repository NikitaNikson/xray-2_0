// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SIMPLEBUMPMAPEFFECT_H
#define SIMPLEBUMPMAPEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Light.h"
#include "Wm4Triangles.h"

namespace Wm4
{

class SimpleBumpMapEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SimpleBumpMapEffect (const char* acBaseName, const char* acNormalName,
        const Vector3f& rkLightDirection);
    virtual ~SimpleBumpMapEffect ();

    void SetLightDirection (const Vector3f& rkLightDirection);
    const Vector3f& GetLightDirection () const;
    void ComputeLightVectors (Triangles* pkMesh);

protected:
    SimpleBumpMapEffect ();

    // Compute a tangent at the vertex P0.  The triangle is counterclockwise
    // ordered, <P0,P1,P2>.
    bool ComputeTangent (
        const Vector3f& rkPos0, const Vector2f& rkTCoord0,
        const Vector3f& rkPos1, const Vector2f& rkTCoord1,
        const Vector3f& rkPos2, const Vector2f& rkTCoord2,
        Vector3f& rkTangent);

    Vector3f m_kLightDirection;
};

WM4_REGISTER_STREAM(SimpleBumpMapEffect);
typedef Pointer<SimpleBumpMapEffect> SimpleBumpMapEffectPtr;

}

#endif
