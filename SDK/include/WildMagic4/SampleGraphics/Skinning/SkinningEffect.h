// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SKINNINGEFFECT_H
#define SKINNINGEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class SkinningEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM_WITH_POSTLINK;

public:
    SkinningEffect ();
    virtual ~SkinningEffect ();

    void SetMatrix (int i, const Matrix4f& rkMatrix);
    const Matrix4f& GetMatrix (int i) const;

protected:
    Matrix4f m_akMatrix[4];
};

WM4_REGISTER_STREAM(SkinningEffect);
typedef Pointer<SkinningEffect> SkinningEffectPtr;

#include "SkinningEffect.inl"

}

#endif
