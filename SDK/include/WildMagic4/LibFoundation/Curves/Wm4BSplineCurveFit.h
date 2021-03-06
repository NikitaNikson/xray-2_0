// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4BSPLINECURVEFIT_H
#define WM4BSPLINECURVEFIT_H

#include "Wm4FoundationLIB.h"
#include "Wm4BSplineFitBasis.h"
#include "Wm4BandedMatrix.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM BSplineCurveFit
{
public:
    // Construction and destruction.  The preconditions for calling the
    // constructor are
    //   1 <= iDegree && iDegree < iControlQuantity <= iSampleQuantity
    // The samples point are contiguous blocks of iDimension real value
    // stored in afSampleData.
    BSplineCurveFit (int iDimension, int iSampleQuantity,
        const Real* afSampleData, int iDegree, int iControlQuantity);
    ~BSplineCurveFit ();

    // Access to input sample information.
    int GetDimension () const;
    int GetSampleQuantity () const;
    const Real* GetSampleData () const;

    // Access to output control point and curve information.
    int GetDegree () const;
    int GetControlQuantity () const;
    const Real* GetControlData () const;
    const BSplineFitBasis<Real>& GetBasis () const;

    // Evaluation of the B-spline curve.  It is defined for 0 <= t <= 1.  If
    // a t-value is outside [0,1], an open spline clamps it to [0,1].  The
    // caller must ensure that afPosition[] has (at least) 'dimension'
    // elements.
    void GetPosition (Real fT, Real* afPosition) const;

private:
    // Input sample information.
    int m_iDimension;
    int m_iSampleQuantity;
    const Real* m_afSampleData;

    // The fitted B-spline curve, open and with uniform knots.
    int m_iDegree;
    int m_iControlQuantity;
    Real* m_afControlData;
    BSplineFitBasis<Real> m_kBasis;
};

typedef BSplineCurveFit<float> BSplineCurveFitf;
typedef BSplineCurveFit<double> BSplineCurveFitd;

}

#endif
