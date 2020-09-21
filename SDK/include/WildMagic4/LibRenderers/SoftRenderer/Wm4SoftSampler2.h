// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTSAMPLER2_H
#define WM4SOFTSAMPLER2_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftSampler.h"

namespace Wm4
{

class WM4_RENDERER_ITEM SoftSampler2 : public SoftSampler
{
    WM4_DECLARE_INITIALIZE;

public:
    SoftSampler2 (const Texture* pkTexture);
    virtual ~SoftSampler2 ();

    virtual void Recreate (const ColorRGBA* akCImage);

    virtual void ComputeMipmapParameters (const int aiX[3], const int aiY[3],
        const float* aafVertex[3], const Attributes& rkAttr, int iUnit);
    virtual void DisallowMipmapping ();
    virtual void CurrentPixel (int iX, int iY);

    virtual ColorRGBA operator() (const float* afCoord);

private:
    int Index (int iX, int iY) const;
    void CreateMipmaps ();
    void RecreateMipmaps ();

    ColorRGBA GetNearestColor (float fXIm, float fYIm) const;
    ColorRGBA GetLinearColor (float fXIm, float fYIm) const;

    int* m_aiXBound;
    int* m_aiYBound;
    int* m_aiLog2XBound;
    int m_iXBound0, m_iXBound1;
    int m_iYBound0, m_iYBound1;
    int m_iLog2XBound0, m_iLog2XBound1;
    int m_iCurrXBound, m_iCurrYBound;
    int m_iCurrLog2XBound;

    // Mipmapping parameters.  The texture coordinates and derivatives at
    // the pixel (x,y) are
    //   u = (a0*x + b0*y + c0)/(d*x + e*y + f)
    //   du/dx = (+(a0*e-b0*d)*y + (a0*f-c0*d))/(d*x + e*y + f)^2
    //   du/dy = (-(a0*e-b0*d)*x + (b0*f-c0*e))/(d*x + e*y + f)^2
    //   v = (a1*x + b1*y + c1)/(d*x + e*y + f)
    //   dv/dx = (+(a1*e-b1*d)*y + (a1*f-c1*d))/(d*x + e*y + f)^2
    //   dv/dy = (-(a1*e-b1*d)*x + (b1*f-c1*e))/(d*x + e*y + f)^2
    float m_afA[2], m_afB[2], m_afC[2];
    float m_afAEmBD[2], m_afAFmCD[2], m_afBFmCE[2];

    // Factory creation of samplers.
    static SoftSampler* Create2 (const Texture* pkTexture);
};

WM4_REGISTER_INITIALIZE(SoftSampler2);

#include "Wm4SoftSampler2.inl"

}

#endif
