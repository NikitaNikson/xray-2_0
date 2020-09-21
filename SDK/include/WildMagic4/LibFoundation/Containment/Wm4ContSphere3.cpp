// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4FoundationPCH.h"
#include "Wm4ContSphere3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> ContSphereOfAABB (int iQuantity, const Vector3<Real>* akPoint)
{
    Vector3<Real> kMin, kMax;
    Vector3<Real>::ComputeExtremes(iQuantity,akPoint,kMin,kMax);

    Sphere3<Real> kSphere;
    kSphere.Center = ((Real)0.5)*(kMax + kMin);
    Vector3<Real> kHalfDiagonal = ((Real)0.5)*(kMax - kMin);
    kSphere.Radius = kHalfDiagonal.Length();
    return kSphere;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> ContSphereAverage (int iQuantity, const Vector3<Real>* akPoint)
{
    Sphere3<Real> kSphere;

    kSphere.Center = akPoint[0];
    int i;
    for (i = 1; i < iQuantity; i++)
    {
        kSphere.Center += akPoint[i];
    }
    kSphere.Center /= (Real)iQuantity;

    for (i = 0; i < iQuantity; i++)
    {
        Vector3<Real> kDiff = akPoint[i] - kSphere.Center;
        Real fRadiusSqr = kDiff.SquaredLength();
        if (fRadiusSqr > kSphere.Radius)
        {
            kSphere.Radius = fRadiusSqr;
        }
    }

    kSphere.Radius = Math<Real>::Sqrt(kSphere.Radius);
    return kSphere;
}
//----------------------------------------------------------------------------
template <class Real>
bool InSphere (const Vector3<Real>& rkPoint, const Sphere3<Real>& rkSphere)
{
    Vector3<Real> kDiff = rkPoint - rkSphere.Center;
    return kDiff.Length() <= rkSphere.Radius;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MergeSpheres (const Sphere3<Real>& rkSphere0,
    const Sphere3<Real>& rkSphere1)
{
    Vector3<Real> kCDiff = rkSphere1.Center - rkSphere0.Center;
    Real fLSqr = kCDiff.SquaredLength();
    Real fRDiff = rkSphere1.Radius - rkSphere0.Radius;
    Real fRDiffSqr = fRDiff*fRDiff;

    if (fRDiffSqr >= fLSqr)
    {
        return ( fRDiff >= (Real)0.0 ? rkSphere1 : rkSphere0 );
    }

    Real fLength = Math<Real>::Sqrt(fLSqr);
    Sphere3<Real> kSphere;

    if (fLength > Math<Real>::ZERO_TOLERANCE)
    {
        Real fCoeff = (fLength + fRDiff)/(((Real)2.0)*fLength);
        kSphere.Center = rkSphere0.Center + fCoeff*kCDiff;
    }
    else
    {
        kSphere.Center = rkSphere0.Center;
    }

    kSphere.Radius = ((Real)0.5)*(fLength + rkSphere0.Radius +
        rkSphere1.Radius);

    return kSphere;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// MinSphere3
//
// All internal minimal sphere calculations store the squared radius in the
// radius member of Sphere3<Real>.  Only at the end is a sqrt computed.
//----------------------------------------------------------------------------
template <class Real>
MinSphere3<Real>::MinSphere3 (int iQuantity, const Vector3<Real>* akPoint,
    Sphere3<Real>& rkMinimal, Real fEpsilon)
{
    m_fEpsilon = fEpsilon;
    m_aoUpdate[0] = 0;
    m_aoUpdate[1] = &MinSphere3<Real>::UpdateSupport1;
    m_aoUpdate[2] = &MinSphere3<Real>::UpdateSupport2;
    m_aoUpdate[3] = &MinSphere3<Real>::UpdateSupport3;
    m_aoUpdate[4] = &MinSphere3<Real>::UpdateSupport4;

    Support kSupp;
    Real fDistDiff;

    if (iQuantity >= 1)
    {
        // create identity permutation (0,1,...,iQuantity-1)
        Vector3<Real>** apkPerm = WM4_NEW Vector3<Real>*[iQuantity];
        int i;
        for (i = 0; i < iQuantity; i++)
        {
            apkPerm[i] = (Vector3<Real>*)&akPoint[i];
        }

        // generate random permutation
        for (i = iQuantity-1; i > 0; i--)
        {
            int j = rand() % (i+1);
            if (j != i)
            {
                Vector3<Real>* pSave = apkPerm[i];
                apkPerm[i] = apkPerm[j];
                apkPerm[j] = pSave;
            }
        }

        rkMinimal = ExactSphere1(*apkPerm[0]);
        kSupp.Quantity = 1;
        kSupp.Index[0] = 0;
        i = 1;
        while (i < iQuantity)
        {
            if (!kSupp.Contains(i,apkPerm,m_fEpsilon))
            {
                if (!Contains(*apkPerm[i],rkMinimal,fDistDiff))
                {
                    UpdateFunction oUpdate = m_aoUpdate[kSupp.Quantity];
                    Sphere3<Real> kSph =(this->*oUpdate)(i,apkPerm,kSupp);
                    if (kSph.Radius > rkMinimal.Radius)
                    {
                        rkMinimal = kSph;
                        i = 0;
                        continue;
                    }
                }
            }
            i++;
        }

        WM4_DELETE[] apkPerm;
    }
    else
    {
        assert(false);
    }

    rkMinimal.Radius = Math<Real>::Sqrt(rkMinimal.Radius);
}
//----------------------------------------------------------------------------
template <class Real>
bool MinSphere3<Real>::Contains (const Vector3<Real>& rkP,
    const Sphere3<Real>& rkS, Real& rfDistDiff)
{
    Vector3<Real> kDiff = rkP - rkS.Center;
    Real fTest = kDiff.SquaredLength();

    // NOTE:  In this algorithm, Sphere3 is storing the *squared radius*,
    // so the next line of code is not in error.
    rfDistDiff = fTest - rkS.Radius;

    return rfDistDiff <= (Real)0.0;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::ExactSphere1 (const Vector3<Real>& rkP)
{
    Sphere3<Real> kMinimal;
    kMinimal.Center = rkP;
    kMinimal.Radius = (Real)0.0;
    return kMinimal;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::ExactSphere2 (const Vector3<Real>& rkP0,
    const Vector3<Real>& rkP1)
{
    Sphere3<Real> kMinimal;
    kMinimal.Center = ((Real)0.5)*(rkP0+rkP1);
    Vector3<Real> kDiff = rkP1 - rkP0;
    kMinimal.Radius = ((Real)0.25)*kDiff.SquaredLength();
    return kMinimal;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::ExactSphere3 (const Vector3<Real>& rkP0,
    const Vector3<Real>& rkP1, const Vector3<Real>& rkP2)
{
    // Compute the circle (in 3D) containing p0, p1, and p2.  The Center in
    // barycentric coordinates is K = u0*p0+u1*p1+u2*p2 where u0+u1+u2=1.
    // The Center is equidistant from the three points, so |K-p0| = |K-p1| =
    // |K-p2| = R where R is the radius of the circle.
    //
    // From these conditions,
    //   K-p0 = u0*A + u1*B - A
    //   K-p1 = u0*A + u1*B - B
    //   K-p2 = u0*A + u1*B
    // where A = p0-p2 and B = p1-p2, which leads to
    //   r^2 = |u0*A+u1*B|^2 - 2*Dot(A,u0*A+u1*B) + |A|^2
    //   r^2 = |u0*A+u1*B|^2 - 2*Dot(B,u0*A+u1*B) + |B|^2
    //   r^2 = |u0*A+u1*B|^2
    // Subtracting the last equation from the first two and writing
    // the equations as a linear system,
    //
    // +-                 -++   -+       +-        -+
    // | Dot(A,A) Dot(A,B) || u0 | = 0.5 | Dot(A,A) |
    // | Dot(B,A) Dot(B,B) || u1 |       | Dot(B,B) |
    // +-                 -++   -+       +-        -+
    //
    // The following code solves this system for u0 and u1, then
    // evaluates the third equation in r^2 to obtain r.

    Vector3<Real> kA = rkP0 - rkP2;
    Vector3<Real> kB = rkP1 - rkP2;
    Real fAdA = kA.Dot(kA);
    Real fAdB = kA.Dot(kB);
    Real fBdB = kB.Dot(kB);
    Real fDet = fAdA*fBdB-fAdB*fAdB;

    Sphere3<Real> kMinimal;

    if (Math<Real>::FAbs(fDet) > m_fEpsilon)
    {
        Real fHalfInvDet = ((Real)0.5)/fDet;
        Real fU0 = fHalfInvDet*fBdB*(fAdA-fAdB);
        Real fU1 = fHalfInvDet*fAdA*(fBdB-fAdB);
        Real fU2 = (Real)1.0-fU0-fU1;
        kMinimal.Center = fU0*rkP0 + fU1*rkP1 + fU2*rkP2;
        Vector3<Real> kTmp = fU0*kA + fU1*kB;
        kMinimal.Radius = kTmp.SquaredLength();
    }
    else
    {
        kMinimal.Center = Vector3<Real>::ZERO;
        kMinimal.Radius = Math<Real>::MAX_REAL;
    }

    return kMinimal;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::ExactSphere4 (const Vector3<Real>& rkP0,
    const Vector3<Real>& rkP1, const Vector3<Real>& rkP2,
    const Vector3<Real>& rkP3)
{
    // Compute the sphere containing p0, p1, p2, and p3.  The Center in
    // barycentric coordinates is K = u0*p0+u1*p1+u2*p2+u3*p3 where
    // u0+u1+u2+u3=1.  The Center is equidistant from the three points, so
    // |K-p0| = |K-p1| = |K-p2| = |K-p3| = R where R is the radius of the
    // sphere.
    //
    // From these conditions,
    //   K-p0 = u0*A + u1*B + u2*C - A
    //   K-p1 = u0*A + u1*B + u2*C - B
    //   K-p2 = u0*A + u1*B + u2*C - C
    //   K-p3 = u0*A + u1*B + u2*C
    // where A = p0-p3, B = p1-p3, and C = p2-p3 which leads to
    //   r^2 = |u0*A+u1*B+u2*C|^2 - 2*Dot(A,u0*A+u1*B+u2*C) + |A|^2
    //   r^2 = |u0*A+u1*B+u2*C|^2 - 2*Dot(B,u0*A+u1*B+u2*C) + |B|^2
    //   r^2 = |u0*A+u1*B+u2*C|^2 - 2*Dot(C,u0*A+u1*B+u2*C) + |C|^2
    //   r^2 = |u0*A+u1*B+u2*C|^2
    // Subtracting the last equation from the first three and writing
    // the equations as a linear system,
    //
    // +-                          -++   -+       +-        -+
    // | Dot(A,A) Dot(A,B) Dot(A,C) || u0 | = 0.5 | Dot(A,A) |
    // | Dot(B,A) Dot(B,B) Dot(B,C) || u1 |       | Dot(B,B) |
    // | Dot(C,A) Dot(C,B) Dot(C,C) || u2 |       | Dot(C,C) |
    // +-                          -++   -+       +-        -+
    //
    // The following code solves this system for u0, u1, and u2, then
    // evaluates the fourth equation in r^2 to obtain r.

    Vector3<Real> kE10 = rkP0 - rkP3;
    Vector3<Real> kE20 = rkP1 - rkP3;
    Vector3<Real> kE30 = rkP2 - rkP3;

    Real aafA[3][3];
    aafA[0][0] = kE10.Dot(kE10);
    aafA[0][1] = kE10.Dot(kE20);
    aafA[0][2] = kE10.Dot(kE30);
    aafA[1][0] = aafA[0][1];
    aafA[1][1] = kE20.Dot(kE20);
    aafA[1][2] = kE20.Dot(kE30);
    aafA[2][0] = aafA[0][2];
    aafA[2][1] = aafA[1][2];
    aafA[2][2] = kE30.Dot(kE30);

    Real afB[3];
    afB[0] = ((Real)0.5)*aafA[0][0];
    afB[1] = ((Real)0.5)*aafA[1][1];
    afB[2] = ((Real)0.5)*aafA[2][2];

    Real aafAInv[3][3];
    aafAInv[0][0] = aafA[1][1]*aafA[2][2]-aafA[1][2]*aafA[2][1];
    aafAInv[0][1] = aafA[0][2]*aafA[2][1]-aafA[0][1]*aafA[2][2];
    aafAInv[0][2] = aafA[0][1]*aafA[1][2]-aafA[0][2]*aafA[1][1];
    aafAInv[1][0] = aafA[1][2]*aafA[2][0]-aafA[1][0]*aafA[2][2];
    aafAInv[1][1] = aafA[0][0]*aafA[2][2]-aafA[0][2]*aafA[2][0];
    aafAInv[1][2] = aafA[0][2]*aafA[1][0]-aafA[0][0]*aafA[1][2];
    aafAInv[2][0] = aafA[1][0]*aafA[2][1]-aafA[1][1]*aafA[2][0];
    aafAInv[2][1] = aafA[0][1]*aafA[2][0]-aafA[0][0]*aafA[2][1];
    aafAInv[2][2] = aafA[0][0]*aafA[1][1]-aafA[0][1]*aafA[1][0];
    Real fDet = aafA[0][0]*aafAInv[0][0] + aafA[0][1]*aafAInv[1][0] +
        aafA[0][2]*aafAInv[2][0];

    Sphere3<Real> kMinimal;

    if (Math<Real>::FAbs(fDet) > m_fEpsilon)
    {
        Real fInvDet = ((Real)1.0)/fDet;
        int iRow, iCol;
        for (iRow = 0; iRow < 3; iRow++)
        {
            for (iCol = 0; iCol < 3; iCol++)
            {
                aafAInv[iRow][iCol] *= fInvDet;
            }
        }
        
        Real afU[4];
        for (iRow = 0; iRow < 3; iRow++)
        {
            afU[iRow] = 0.0f;
            for (iCol = 0; iCol < 3; iCol++)
            {
                afU[iRow] += aafAInv[iRow][iCol]*afB[iCol];
            }
        }
        afU[3] = (Real)1.0 - afU[0] - afU[1] - afU[2];
        
        kMinimal.Center = afU[0]*rkP0 + afU[1]*rkP1 + afU[2]*rkP2 +
            afU[3]*rkP3;
        Vector3<Real> kTmp = afU[0]*kE10 + afU[1]*kE20 + afU[2]*kE30;
        kMinimal.Radius = kTmp.SquaredLength();
    }
    else
    {
        kMinimal.Center = Vector3<Real>::ZERO;
        kMinimal.Radius = Math<Real>::MAX_REAL;
    }

    return kMinimal;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::UpdateSupport1 (int i,
    Vector3<Real>** apkPerm, Support& rkSupp)
{
    const Vector3<Real>& rkP0 = *apkPerm[rkSupp.Index[0]];
    const Vector3<Real>& rkP1 = *apkPerm[i];

    Sphere3<Real> kMinimal = ExactSphere2(rkP0,rkP1);
    rkSupp.Quantity = 2;
    rkSupp.Index[1] = i;

    return kMinimal;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::UpdateSupport2 (int i,
    Vector3<Real>** apkPerm, Support& rkSupp)
{
    const Vector3<Real>& rkP0 = *apkPerm[rkSupp.Index[0]];
    const Vector3<Real>& rkP1 = *apkPerm[rkSupp.Index[1]];
    const Vector3<Real>& rkP2 = *apkPerm[i];

    Sphere3<Real> akS[3];
    Real fMinRSqr = Math<Real>::MAX_REAL;
    Real fDistDiff;
    int iIndex = -1;

    akS[0] = ExactSphere2(rkP0,rkP2);
    if (Contains(rkP1,akS[0],fDistDiff))
    {
        fMinRSqr = akS[0].Radius;
        iIndex = 0;
    }

    akS[1] = ExactSphere2(rkP1,rkP2);
    if (akS[1].Radius < fMinRSqr)
    {
        if (Contains(rkP0,akS[1],fDistDiff))
        {
            fMinRSqr = akS[1].Radius;
            iIndex = 1;
        }
    }

    Sphere3<Real> kMinimal;

    if (iIndex != -1)
    {
        kMinimal = akS[iIndex];
        rkSupp.Index[1-iIndex] = i;
    }
    else
    {
        kMinimal = ExactSphere3(rkP0,rkP1,rkP2);
        assert(kMinimal.Radius <= fMinRSqr);
        rkSupp.Quantity = 3;
        rkSupp.Index[2] = i;
    }

    return kMinimal;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::UpdateSupport3 (int i,
    Vector3<Real>** apkPerm, Support& rkSupp)
{
    const Vector3<Real>& rkP0 = *apkPerm[rkSupp.Index[0]];
    const Vector3<Real>& rkP1 = *apkPerm[rkSupp.Index[1]];
    const Vector3<Real>& rkP2 = *apkPerm[rkSupp.Index[2]];
    const Vector3<Real>& rkP3 = *apkPerm[i];

    Sphere3<Real> akS[6];
    Real fMinRSqr = Math<Real>::MAX_REAL;
    Real fDistDiff;
    int iIndex = -1;

    akS[0] = ExactSphere2(rkP0,rkP3);
    if (Contains(rkP1,akS[0],fDistDiff) && Contains(rkP2,akS[0],fDistDiff))
    {
        fMinRSqr = akS[0].Radius;
        iIndex = 0;
    }

    akS[1] = ExactSphere2(rkP1,rkP3);
    if (akS[1].Radius < fMinRSqr
    && Contains(rkP0,akS[1],fDistDiff) && Contains(rkP2,akS[1],fDistDiff))
    {
        fMinRSqr = akS[1].Radius;
        iIndex = 1;
    }

    akS[2] = ExactSphere2(rkP2,rkP3);
    if (akS[2].Radius < fMinRSqr
    && Contains(rkP0,akS[2],fDistDiff) && Contains(rkP1,akS[2],fDistDiff))
    {
        fMinRSqr = akS[2].Radius;
        iIndex = 2;
    }

    akS[3] = ExactSphere3(rkP0,rkP1,rkP3);
    if (akS[3].Radius < fMinRSqr && Contains(rkP2,akS[3],fDistDiff))
    {
        fMinRSqr = akS[3].Radius;
        iIndex = 3;
    }

    akS[4] = ExactSphere3(rkP0,rkP2,rkP3);
    if (akS[4].Radius < fMinRSqr && Contains(rkP1,akS[4],fDistDiff))
    {
        fMinRSqr = akS[4].Radius;
        iIndex = 4;
    }

    akS[5] = ExactSphere3(rkP1,rkP2,rkP3);
    if (akS[5].Radius < fMinRSqr && Contains(rkP0,akS[5],fDistDiff))
    {
        fMinRSqr = akS[5].Radius;
        iIndex = 5;
    }

    Sphere3<Real> kMinimal;

    switch (iIndex)
    {
    case 0:
        kMinimal = akS[0];
        rkSupp.Quantity = 2;
        rkSupp.Index[1] = i;
        break;
    case 1:
        kMinimal = akS[1];
        rkSupp.Quantity = 2;
        rkSupp.Index[0] = i;
        break;
    case 2:
        kMinimal = akS[2];
        rkSupp.Quantity = 2;
        rkSupp.Index[0] = rkSupp.Index[2];
        rkSupp.Index[1] = i;
        break;
    case 3:
        kMinimal = akS[3];
        rkSupp.Index[2] = i;
        break;
    case 4:
        kMinimal = akS[4];
        rkSupp.Index[1] = i;
        break;
    case 5:
        kMinimal = akS[5];
        rkSupp.Index[0] = i;
        break;
    default:
        kMinimal = ExactSphere4(rkP0,rkP1,rkP2,rkP3);
        assert(kMinimal.Radius <= fMinRSqr);
        rkSupp.Quantity = 4;
        rkSupp.Index[3] = i;
        break;
    }

    return kMinimal;
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real> MinSphere3<Real>::UpdateSupport4 (int i,
    Vector3<Real>** apkPerm, Support& rkSupp)
{
    const Vector3<Real>* apkPt[4] =
    {
        apkPerm[rkSupp.Index[0]],
        apkPerm[rkSupp.Index[1]],
        apkPerm[rkSupp.Index[2]],
        apkPerm[rkSupp.Index[3]]
    };

    const Vector3<Real>& rkP4 = *apkPerm[i];

    // permutations of type 1
    int aiT1[4][4] =
    {
        {0, /*4*/ 1,2,3},
        {1, /*4*/ 0,2,3},
        {2, /*4*/ 0,1,3},
        {3, /*4*/ 0,1,2}
    };

    // permutations of type 2
    int aiT2[6][4] =
    {
        {0,1, /*4*/ 2,3},
        {0,2, /*4*/ 1,3},
        {0,3, /*4*/ 1,2},
        {1,2, /*4*/ 0,3},
        {1,3, /*4*/ 0,2},
        {2,3, /*4*/ 0,1}
    };

    // permutations of type 3
    int aiT3[4][4] =
    {
        {0,1,2, /*4*/ 3},
        {0,1,3, /*4*/ 2},
        {0,2,3, /*4*/ 1},
        {1,2,3, /*4*/ 0}
    };

    Sphere3<Real> akS[14];
    Real fMinRSqr = Math<Real>::MAX_REAL;
    int iIndex = -1;
    Real fDistDiff, fMinDistDiff = Math<Real>::MAX_REAL;
    int iMinIndex = -1;
    int k = 0;  // sphere index

    // permutations of type 1
    int j;
    for (j = 0; j < 4; j++, k++)
    {
        akS[k] = ExactSphere2(*apkPt[aiT1[j][0]],rkP4);
        if (akS[k].Radius < fMinRSqr)
        {
            if (Contains(*apkPt[aiT1[j][1]],akS[k],fDistDiff)
            &&  Contains(*apkPt[aiT1[j][2]],akS[k],fDistDiff)
            &&  Contains(*apkPt[aiT1[j][3]],akS[k],fDistDiff) )
            {
                fMinRSqr = akS[k].Radius;
                iIndex = k;
            }
            else if (fDistDiff < fMinDistDiff)
            {
                fMinDistDiff = fDistDiff;
                iMinIndex = k;
            }
        }
    }

    // permutations of type 2
    for (j = 0; j < 6; j++, k++)
    {
        akS[k] = ExactSphere3(*apkPt[aiT2[j][0]],*apkPt[aiT2[j][1]],rkP4);
        if (akS[k].Radius < fMinRSqr)
        {
            if (Contains(*apkPt[aiT2[j][2]],akS[k],fDistDiff)
            &&  Contains(*apkPt[aiT2[j][3]],akS[k],fDistDiff))
            {
                fMinRSqr = akS[k].Radius;
                iIndex = k;
            }
            else if (fDistDiff < fMinDistDiff)
            {
                fMinDistDiff = fDistDiff;
                iMinIndex = k;
            }
        }
    }

    // permutations of type 3
    for (j = 0; j < 4; j++, k++)
    {
        akS[k] = ExactSphere4(*apkPt[aiT3[j][0]],*apkPt[aiT3[j][1]],
            *apkPt[aiT3[j][2]],rkP4);
        if (akS[k].Radius < fMinRSqr)
        {
            if (Contains(*apkPt[aiT3[j][3]],akS[k],fDistDiff))
            {
                fMinRSqr = akS[k].Radius;
                iIndex = k;
            }
            else if (fDistDiff < fMinDistDiff)
            {
                fMinDistDiff = fDistDiff;
                iMinIndex = k;
            }
        }
    }

    // Theoretically, iIndex >= 0 should happen, but floating point round-off
    // error can lead to this.  When this happens, the sphere is chosen that
    // has the minimum absolute errors between points (barely) outside the
    // sphere and the sphere.
    if (iIndex == -1)
    {
        iIndex = iMinIndex;
    }

    Sphere3<Real> kMinimal = akS[iIndex];

    switch (iIndex)
    {
    case 0:
        rkSupp.Quantity = 2;
        rkSupp.Index[1] = i;
        break;
    case 1:
        rkSupp.Quantity = 2;
        rkSupp.Index[0] = i;
        break;
    case 2:
        rkSupp.Quantity = 2;
        rkSupp.Index[0] = rkSupp.Index[2];
        rkSupp.Index[1] = i;
        break;
    case 3:
        rkSupp.Quantity = 2;
        rkSupp.Index[0] = rkSupp.Index[3];
        rkSupp.Index[1] = i;
        break;
    case 4:
        rkSupp.Quantity = 3;
        rkSupp.Index[2] = i;
        break;
    case 5:
        rkSupp.Quantity = 3;
        rkSupp.Index[1] = i;
        break;
    case 6:
        rkSupp.Quantity = 3;
        rkSupp.Index[1] = rkSupp.Index[3];
        rkSupp.Index[2] = i;
        break;
    case 7:
        rkSupp.Quantity = 3;
        rkSupp.Index[0] = i;
        break;
    case 8:
        rkSupp.Quantity = 3;
        rkSupp.Index[0] = rkSupp.Index[3];
        rkSupp.Index[2] = i;
        break;
    case 9:
        rkSupp.Quantity = 3;
        rkSupp.Index[0] = rkSupp.Index[3];
        rkSupp.Index[1] = i;
        break;
    case 10:
        rkSupp.Index[3] = i;
        break;
    case 11:
        rkSupp.Index[2] = i;
        break;
    case 12:
        rkSupp.Index[1] = i;
        break;
    case 13:
        rkSupp.Index[0] = i;
        break;
    }

    return kMinimal;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
Sphere3<float> ContSphereOfAABB<float> (int, const Vector3<float>*);

template WM4_FOUNDATION_ITEM
Sphere3<float> ContSphereAverage<float> (int, const Vector3<float>*);

template WM4_FOUNDATION_ITEM
bool InSphere<float> (const Vector3<float>&, const Sphere3<float>&);

template WM4_FOUNDATION_ITEM
Sphere3<float> MergeSpheres<float> (const Sphere3<float>&,
    const Sphere3<float>&);

template WM4_FOUNDATION_ITEM
class MinSphere3<float>;

template WM4_FOUNDATION_ITEM
Sphere3<double> ContSphereOfAABB<double> (int, const Vector3<double>*);

template WM4_FOUNDATION_ITEM
Sphere3<double> ContSphereAverage<double> (int, const Vector3<double>*);

template WM4_FOUNDATION_ITEM
bool InSphere<double> (const Vector3<double>&, const Sphere3<double>&);

template WM4_FOUNDATION_ITEM
Sphere3<double> MergeSpheres<double> (const Sphere3<double>&,
    const Sphere3<double>&);

template WM4_FOUNDATION_ITEM
class MinSphere3<double>;
//----------------------------------------------------------------------------
}
