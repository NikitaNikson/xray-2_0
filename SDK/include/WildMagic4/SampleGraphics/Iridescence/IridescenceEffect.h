// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef IRIDESCENCEEFFECT_H
#define IRIDESCENCEEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class IridescenceEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    IridescenceEffect (const char* acBaseName, const char* acGradName);
    virtual ~IridescenceEffect ();

    void SetInterpolateFactor (float fInterpolateFactor);
    float GetInterpolateFactor () const;

protected:
    // streaming
    IridescenceEffect ();

    // The interpolation factor is stored at index 0.  The other values are
    // unused.
    float m_afInterpolate[4];
};

WM4_REGISTER_STREAM(IridescenceEffect);
typedef Pointer<IridescenceEffect> IridescenceEffectPtr;

#include "IridescenceEffect.inl"

}

#endif
