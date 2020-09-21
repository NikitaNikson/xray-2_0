// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4FoundationPCH.h"
#include "Wm4IntrSegment3Cylinder3.h"
#include "Wm4IntrLine3Cylinder3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrSegment3Cylinder3<Real>::IntrSegment3Cylinder3 (
    const Segment3<Real>& rkSegment, const Cylinder3<Real>& rkCylinder)
    :
    m_pkSegment(&rkSegment),
    m_pkCylinder(&rkCylinder)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Segment3<Real>& IntrSegment3Cylinder3<Real>::GetSegment () const
{
    return *m_pkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
const Cylinder3<Real>& IntrSegment3Cylinder3<Real>::GetCylinder () const
{
    return *m_pkCylinder;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrSegment3Cylinder3<Real>::Find ()
{
    Real afT[2];
    int iQuantity = IntrLine3Cylinder3<Real>::Find(m_pkSegment->Origin,
        m_pkSegment->Direction,*m_pkCylinder,afT);

    m_iQuantity = 0;
    for (int i = 0; i < iQuantity; i++)
    {
        if (Math<Real>::FAbs(afT[i]) <= m_pkSegment->Extent)
        {
            m_akPoint[m_iQuantity++] = m_pkSegment->Origin +
                afT[i]*m_pkSegment->Direction;
        }
    }

    if (m_iQuantity == 2)
    {
        m_iIntersectionType = IT_SEGMENT;
    }
    else if (m_iQuantity == 1)
    {
        m_iIntersectionType = IT_POINT;
    }
    else
    {
        m_iIntersectionType = IT_EMPTY;
    }

    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
int IntrSegment3Cylinder3<Real>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>& IntrSegment3Cylinder3<Real>::GetPoint (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akPoint[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrSegment3Cylinder3<float>;

template WM4_FOUNDATION_ITEM
class IntrSegment3Cylinder3<double>;
//----------------------------------------------------------------------------
}
