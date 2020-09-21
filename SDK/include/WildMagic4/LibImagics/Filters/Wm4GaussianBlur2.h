// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4GAUSSIANBLUR2_H
#define WM4GAUSSIANBLUR2_H

#include "Wm4ImagicsLIB.h"
#include "Wm4PdeFilter2.h"

namespace Wm4
{

class WM4_IMAGICS_ITEM GaussianBlur2 : public PdeFilter2
{
public:
    GaussianBlur2 (int iXBound, int iYBound, float fXSpacing, float fYSpacing,
        const float* afData, const bool* abMask, float fBorderValue,
        ScaleType eType);

    virtual ~GaussianBlur2 ();

    float GetMaximumTimeStep () const;

protected:
    virtual void OnUpdate (int iX, int iY);

    float m_fMaximumTimeStep;
};

}

#endif
