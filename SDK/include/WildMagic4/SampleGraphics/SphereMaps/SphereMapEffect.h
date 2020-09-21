// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SPHEREMAPEFFECT_H
#define SPHEREMAPEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class SphereMapEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SphereMapEffect (const std::string& rkEnvName);
    virtual ~SphereMapEffect ();

protected:
    SphereMapEffect ();
};

WM4_REGISTER_STREAM(SphereMapEffect);
typedef Pointer<SphereMapEffect> SphereMapEffectPtr;

}

#endif
