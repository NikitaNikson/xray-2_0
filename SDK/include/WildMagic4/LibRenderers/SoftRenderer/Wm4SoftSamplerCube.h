// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTSAMPLERCUBE_H
#define WM4SOFTSAMPLERCUBE_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftSampler2.h"

namespace Wm4
{

class WM4_RENDERER_ITEM SoftSamplerCube : public SoftSampler
{
    WM4_DECLARE_INITIALIZE;

public:
    SoftSamplerCube (const Texture* pkTexture);
    virtual ~SoftSamplerCube ();

    virtual void Recreate (const ColorRGBA* akCImage);

    virtual void ComputeMipmapParameters (const int aiX[3], const int aiY[3],
        const float* aafVertex[3], const Attributes& rkAttr, int iUnit);
    virtual void DisallowMipmapping ();
    virtual void CurrentPixel (int iX, int iY);

    virtual ColorRGBA operator() (const float* afCoord);

private:
    // +x, -x, +y, -y, +z, -z
    Texture* m_apkTexture[6];
    SoftSampler2* m_apkSampler[6];

    // Factory creation of samplers.
    static SoftSampler* CreateCube (const Texture* pkTexture);
};

WM4_REGISTER_INITIALIZE(SoftSamplerCube);

}

#endif
