// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4POLYNOMIAL1_H
#define WM4POLYNOMIAL1_H

#include "Wm4FoundationLIB.h"
#include "Wm4Math.h"

namespace Wm4
{

template <class Real>
class Polynomial1
{
public:
    // construction and destruction
    Polynomial1 (int iDegree = -1);
    Polynomial1 (const Polynomial1& rkPoly);
    ~Polynomial1 ();

    // member access
    void SetDegree (int iDegree);
    int GetDegree () const;
    operator const Real* () const;
    operator Real* ();
    Real operator[] (int i) const;
    Real& operator[] (int i);

    // assignment
    Polynomial1& operator= (const Polynomial1& rkPoly);

    // evaluation
    Real operator() (Real fT) const;

    // arithmetic operations
    Polynomial1 operator+ (const Polynomial1& rkPoly) const;
    Polynomial1 operator- (const Polynomial1& rkPoly) const;
    Polynomial1 operator* (const Polynomial1& rkPoly) const;
    Polynomial1 operator+ (Real fScalar) const;  // input is degree 0 poly
    Polynomial1 operator- (Real fScalar) const;  // input is degree 0 poly
    Polynomial1 operator* (Real fScalar) const;
    Polynomial1 operator/ (Real fScalar) const;
    Polynomial1 operator- () const;

    // arithmetic updates
    Polynomial1& operator += (const Polynomial1& rkPoly);
    Polynomial1& operator -= (const Polynomial1& rkPoly);
    Polynomial1& operator *= (const Polynomial1& rkPoly);
    Polynomial1& operator += (Real fScalar);  // input is degree 0 poly
    Polynomial1& operator -= (Real fScalar);  // input is degree 0 poly
    Polynomial1& operator *= (Real fScalar);
    Polynomial1& operator /= (Real fScalar);

    // derivation
    Polynomial1 GetDerivative () const;

    // inversion ( invpoly[i] = poly[degree-i] for 0 <= i <= degree )
    Polynomial1 GetInversion () const;

    // Reduce degree by eliminating all (nearly) zero leading coefficients
    // and by making the leading coefficient one.  The input parameter is
    // the threshold for specifying that a coefficient is effectively zero.
    void Compress (Real fEpsilon);

    // If 'this' is P(t) and the divisor is D(t) with degree(P) >= degree(D),
    // then P(t) = Q(t)*D(t)+R(t) where Q(t) is the quotient with
    // degree(Q) = degree(P) - degree(D) and R(t) is the remainder with
    // degree(R) < degree(D).  If this routine is called with
    // degree(P) < degree(D), then Q = 0 and R = P are returned.  The value
    // of epsilon is used as a threshold on the coefficients of the remainder
    // polynomial.  If smaller, the coefficient is assumed to be zero.
    void Divide (const Polynomial1& rkDiv, Polynomial1& rkQuot,
        Polynomial1& rkRem, Real fEpsilon) const;

protected:
    int m_iDegree;
    Real* m_afCoeff;
};

template <class Real>
Polynomial1<Real> operator* (Real fScalar, const Polynomial1<Real>& rkPoly);

#include "Wm4Polynomial1.inl"

typedef Polynomial1<float> Polynomial1f;
typedef Polynomial1<double> Polynomial1d;

}

#endif
