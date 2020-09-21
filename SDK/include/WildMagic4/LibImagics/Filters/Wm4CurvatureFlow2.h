// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CURVATUREFLOW2_H
#define WM4CURVATUREFLOW2_H

#include "Wm4ImagicsLIB.h"
#include "Wm4PdeFilter2.h"

namespace Wm4
{

class WM4_IMAGICS_ITEM CurvatureFlow2 : public PdeFilter2
{
public:
    CurvatureFlow2 (int iXBound, int iYBound, float fXSpacing,
        float fYSpacing, const float* afData, const bool* abMask,
        float fBorderValue, ScaleType eType);

    virtual ~CurvatureFlow2 ();

protected:
    virtual void OnUpdate (int iX, int iY);
};

}

#endif
