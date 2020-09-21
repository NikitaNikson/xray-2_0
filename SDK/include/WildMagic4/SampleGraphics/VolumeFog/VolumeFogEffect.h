// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VOLUMEFOGEFFECT_H
#define WM4VOLUMEFOGEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class VolumeFogEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    VolumeFogEffect (const std::string& rkBaseName);
    virtual ~VolumeFogEffect ();

protected:
    // streaming
    VolumeFogEffect ();
};

WM4_REGISTER_STREAM(VolumeFogEffect);
typedef Pointer<VolumeFogEffect> VolumeFogEffectPtr;

}

#endif
