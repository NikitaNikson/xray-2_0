// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTSAMPLER1_H
#define WM4SOFTSAMPLER1_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftSampler.h"

namespace Wm4
{

class WM4_RENDERER_ITEM SoftSampler1 : public SoftSampler
{
    WM4_DECLARE_INITIALIZE;

public:
    SoftSampler1 (const Texture* pkTexture);
    virtual ~SoftSampler1 ();

    virtual void Recreate (const ColorRGBA* akCImage);

    virtual void ComputeMipmapParameters (const int aiX[3], const int aiY[3],
        const float* aafVertex[3], const Attributes& rkAttr, int iUnit);
    virtual void DisallowMipmapping ();
    virtual void CurrentPixel (int iX, int iY);

    virtual ColorRGBA operator() (const float* afCoord);

private:
    void CreateMipmaps ();
    void RecreateMipmaps ();

    ColorRGBA GetNearestColor (float fXIm) const;
    ColorRGBA GetLinearColor (float fXIm) const;

    int* m_aiXBound;
    int m_iXBound0, m_iXBound1;
    int m_iCurrXBound;

    // Mipmapping parameters.  The texture coordinate and derivatives at
    // the pixel (x,y) are
    //   u = (a*x + b*y + c)/(d*x + e*y + f)
    //   du/dx = (+(a*e-b*d)*y + (a*f-c*d))/(d*x + e*y + f)^2
    //   du/dy = (-(a*e-b*d)*x + (b*f-c*e))/(d*x + e*y + f)^2
    float m_fA, m_fB, m_fC;
    float m_fAEmBD, m_fAFmCD, m_fBFmCE;

    // Factory creation of samplers.
    static SoftSampler* Create1 (const Texture* pkTexture);
};

WM4_REGISTER_INITIALIZE(SoftSampler1);

}

#endif
