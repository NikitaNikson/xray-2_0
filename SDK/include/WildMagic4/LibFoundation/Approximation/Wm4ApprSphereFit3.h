// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4APPRSPHEREFIT3_H
#define WM4APPRSPHEREFIT3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Sphere3.h"

namespace Wm4
{

// Least-squares fit of a sphere to a set of points.  Successful fit is
// indicated by return value of 'true'.  If return value is false, number of
// iterations was exceeded.  Try increasing the maximum number of iterations.
//
// If bInitialCenterIsAverage is set to 'true', the initial guess for the
// sphere center is the average of the data points.  If the data points are
// clustered along a solid angle, SphereFit3 is very slow to converge.  If
// bInitialCenterIsAverage is set to 'false', the initial guess for the
// sphere center is computed using a least-squares estimate of the
// coefficients for a quadratic equation that represents a sphere.  This
// approach tends to converge rapidly.

template <class Real> WM4_FOUNDATION_ITEM
bool SphereFit3 (int iQuantity, const Vector3<Real>* akPoint,
    int iMaxIterations, Sphere3<Real>& rkSphere,
    bool bInitialCenterIsAverage);

}

#endif
