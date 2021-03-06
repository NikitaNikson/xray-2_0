// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4FoundationPCH.h"
#include "Wm4IntrSegment3Plane3.h"
#include "Wm4IntrLine3Plane3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrSegment3Plane3<Real>::IntrSegment3Plane3 (const Segment3<Real>& rkSegment,
    const Plane3<Real>& rkPlane)
    :
    m_pkSegment(&rkSegment),
    m_pkPlane(&rkPlane)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Segment3<Real>& IntrSegment3Plane3<Real>::GetSegment () const
{
    return *m_pkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
const Plane3<Real>& IntrSegment3Plane3<Real>::GetPlane () const
{
    return *m_pkPlane;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrSegment3Plane3<Real>::Test ()
{
    Vector3<Real> kP0 = m_pkSegment->GetNegEnd();
    Real fSDistance0 = m_pkPlane->DistanceTo(kP0);
    if (Math<Real>::FAbs(fSDistance0) <= Math<Real>::ZERO_TOLERANCE)
    {
        fSDistance0 = (Real)0.0;
    }

    Vector3<Real> kP1 = m_pkSegment->GetPosEnd();
    Real fSDistance1 = m_pkPlane->DistanceTo(kP1);
    if (Math<Real>::FAbs(fSDistance1) <= Math<Real>::ZERO_TOLERANCE)
    {
        fSDistance1 = (Real)0.0;
    }

    Real fProd = fSDistance0*fSDistance1;
    if (fProd < (Real)0.0)
    {
        // The segment passes through the plane.
        m_iIntersectionType = IT_POINT;
        return true;
    }

    if (fProd > (Real)0.0)
    {
        // The segment is on one side of the plane.
        m_iIntersectionType = IT_EMPTY;
        return false;
    }

    if (fSDistance0 != (Real)0.0 || fSDistance1 != (Real)0.0)
    {
        // A segment end point touches the plane.
        m_iIntersectionType = IT_POINT;
        return true;
    }

    // The segment is coincident with the plane.
    m_iIntersectionType = IT_SEGMENT;
    return true;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrSegment3Plane3<Real>::Find ()
{
    Line3<Real> kLine(m_pkSegment->Origin,m_pkSegment->Direction);
    IntrLine3Plane3<Real> kIntr(kLine,*m_pkPlane);
    if (kIntr.Find())
    {
        // The line intersects the plane, but possibly at a point that is
        // not on the segment.
        m_iIntersectionType = kIntr.GetIntersectionType();
        m_fSegmentT = kIntr.GetLineT();
        return Math<Real>::FAbs(m_fSegmentT) <= m_pkSegment->Extent;
    }

    m_iIntersectionType = IT_EMPTY;
    return false;
}
//----------------------------------------------------------------------------
template <class Real>
Real IntrSegment3Plane3<Real>::GetSegmentT () const
{
    return m_fSegmentT;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrSegment3Plane3<float>;

template WM4_FOUNDATION_ITEM
class IntrSegment3Plane3<double>;
//----------------------------------------------------------------------------
}
