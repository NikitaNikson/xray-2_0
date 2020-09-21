// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4GRADIENTANISOTROPIC3_H
#define WM4GRADIENTANISOTROPIC3_H

#include "Wm4ImagicsLIB.h"
#include "Wm4PdeFilter3.h"

namespace Wm4
{

class WM4_IMAGICS_ITEM GradientAnisotropic3 : public PdeFilter3
{
public:
    GradientAnisotropic3 (int iXBound, int iYBound, int iZBound,
        float fXSpacing, float fYSpacing, float fZSpacing,
        const float* afData, const bool* abMask, float fBorderValue,
        ScaleType eType, float fK);

    virtual ~GradientAnisotropic3 ();

protected:
    void ComputeParam ();
    virtual void OnPreUpdate ();
    virtual void OnUpdate (int iX, int iY, int iZ);

    float m_fK;           // k

    // These are updated on each iteration, since they depend on the current
    // average of the squared length of the gradients at the pixels.
    float m_fParam;       // 1/(k^2*average(gradMagSqr))
    float m_fMHalfParam;  // -0.5*m_fParam;
};

}

#endif
