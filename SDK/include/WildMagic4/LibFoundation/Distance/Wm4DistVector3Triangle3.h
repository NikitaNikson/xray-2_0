// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4DISTVECTOR3TRIANGLE3_H
#define WM4DISTVECTOR3TRIANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistVector3Triangle3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistVector3Triangle3 (const Vector3<Real>& rkVector,
        const Triangle3<Real>& rkTriangle);

    // object access
    const Vector3<Real>& GetVector () const;
    const Triangle3<Real>& GetTriangle () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Information about the closest triangle point.
    Real GetTriangleBary (int i) const;

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    const Vector3<Real>* m_pkVector;
    const Triangle3<Real>* m_pkTriangle;

    // Information about the closest triangle point.
    Real m_afTriangleBary[3];  // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
};

typedef DistVector3Triangle3<float> DistVector3Triangle3f;
typedef DistVector3Triangle3<double> DistVector3Triangle3d;

}

#endif
