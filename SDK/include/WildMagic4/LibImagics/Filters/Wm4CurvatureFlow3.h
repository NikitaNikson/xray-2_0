// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CURVATUREFLOW3_H
#define WM4CURVATUREFLOW3_H

#include "Wm4ImagicsLIB.h"
#include "Wm4PdeFilter3.h"

namespace Wm4
{

class WM4_IMAGICS_ITEM CurvatureFlow3 : public PdeFilter3
{
public:
    CurvatureFlow3 (int iXBound, int iYBound, int iZBound, float fXSpacing,
        float fYSpacing, float fZSpacing, const float* afData,
        const bool* abMask, float fBorderValue, ScaleType eType);

    virtual ~CurvatureFlow3 ();

protected:
    virtual void OnUpdate (int iX, int iY, int iZ);
};

}

#endif
