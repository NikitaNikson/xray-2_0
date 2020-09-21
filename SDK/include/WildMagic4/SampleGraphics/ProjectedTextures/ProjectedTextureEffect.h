// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PROJECTEDTEXTUREEFFECT_H
#define PROJECTEDTEXTUREEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Camera.h"
#include "Wm4Light.h"

namespace Wm4
{

class ProjectedTextureEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    ProjectedTextureEffect (Camera* pkProjector, const char* acProjectorImage,
        Light* pkLight);
    virtual ~ProjectedTextureEffect ();

    virtual void SetGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);
    virtual void RestoreGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);

protected:
    // streaming
    ProjectedTextureEffect ();

    CameraPtr m_spkProjector;
    LightPtr m_spkLight;
};

WM4_REGISTER_STREAM(ProjectedTextureEffect);
typedef Pointer<ProjectedTextureEffect> ProjectedTextureEffectPtr;

}

#endif
