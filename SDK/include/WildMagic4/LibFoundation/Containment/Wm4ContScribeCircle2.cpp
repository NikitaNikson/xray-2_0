// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4FoundationPCH.h"
#include "Wm4ContScribeCircle2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
bool Circumscribe (const Vector2<Real>& rkV0, const Vector2<Real>& rkV1,
    const Vector2<Real>& rkV2, Circle2<Real>& rkCircle)
{
    Vector2<Real> kE10 = rkV1 - rkV0;
    Vector2<Real> kE20 = rkV2 - rkV0;

    Real aafA[2][2] =
    {
        {kE10.X(), kE10.Y()},
        {kE20.X(), kE20.Y()}
    };

    Real afB[2] =
    {
        ((Real)0.5)*kE10.SquaredLength(),
        ((Real)0.5)*kE20.SquaredLength()
    };

    Vector2<Real> kSol;
    if (LinearSystem<Real>().Solve2(aafA,afB,(Real*)&kSol))
    {
        rkCircle.Center = rkV0 + kSol;
        rkCircle.Radius = kSol.Length();
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
template <class Real>
bool Inscribe (const Vector2<Real>& rkV0, const Vector2<Real>& rkV1,
    const Vector2<Real>& rkV2, Circle2<Real>& rkCircle)
{
    Vector2<Real> kD10 = rkV1 - rkV0;
    Vector2<Real> kD20 = rkV2 - rkV0;
    Vector2<Real> kD21 = rkV2 - rkV1;
    Real fL10 = kD10.Length();
    Real fL20 = kD20.Length();
    Real fL21 = kD21.Length();
    Real fPerimeter = fL10 + fL20 + fL21;
    if (fPerimeter > Math<Real>::ZERO_TOLERANCE)
    {
        Real fInv = ((Real)1.0)/fPerimeter;
        fL10 *= fInv;
        fL20 *= fInv;
        fL21 *= fInv;
        rkCircle.Center = fL21*rkV0 + fL20*rkV1 + fL10*rkV2;
        rkCircle.Radius = fInv*Math<Real>::FAbs(kD10.DotPerp(kD20));
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
bool Circumscribe<float> (const Vector2<float>&, const Vector2<float>&,
    const Vector2<float>&, Circle2<float>&);

template WM4_FOUNDATION_ITEM
bool Inscribe<float> (const Vector2<float>&, const Vector2<float>&,
    const Vector2<float>&, Circle2<float>&);

template WM4_FOUNDATION_ITEM
bool Circumscribe<double> (const Vector2<double>&, const Vector2<double>&,
    const Vector2<double>&, Circle2<double>&);

template WM4_FOUNDATION_ITEM
bool Inscribe<double> (const Vector2<double>&, const Vector2<double>&,
    const Vector2<double>&, Circle2<double>&);
//----------------------------------------------------------------------------
}
