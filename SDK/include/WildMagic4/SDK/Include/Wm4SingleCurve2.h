// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SINGLECURVE2_H
#define WM4SINGLECURVE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Curve2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM SingleCurve2 : public Curve2<Real>
{
public:
    // abstract base class
    SingleCurve2 (Real fTMin, Real fTMax);

    // length-from-time and time-from-length
    virtual Real GetLength (Real fT0, Real fT1) const;
    virtual Real GetTime (Real fLength, int iIterations = 32,
        Real fTolerance = (Real)1e-06) const;

protected:
    using Curve2<Real>::m_fTMin;
    using Curve2<Real>::m_fTMax;
    using Curve2<Real>::GetTotalLength;

    static Real GetSpeedWithData (Real fTime, void* pvData);
};

typedef SingleCurve2<float> SingleCurve2f;
typedef SingleCurve2<double> SingleCurve2d;

}

#endif
