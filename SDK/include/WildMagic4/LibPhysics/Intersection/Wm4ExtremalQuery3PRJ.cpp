// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4PhysicsPCH.h"
#include "Wm4ExtremalQuery3PRJ.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3PRJ<Real>::ExtremalQuery3PRJ (
    const ConvexPolyhedron3<Real>& rkPolytope)
    :
    ExtremalQuery3<Real>(rkPolytope)
{
    m_kCentroid = m_pkPolytope->ComputeVertexAverage();
}
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3PRJ<Real>::~ExtremalQuery3PRJ ()
{
}
//----------------------------------------------------------------------------
template <class Real>
void ExtremalQuery3PRJ<Real>::GetExtremeVertices (
    const Vector3<Real>& rkDirection, int& riPositiveDirection,
    int& riNegativeDirection)
{
    Vector3<Real> kDiff = m_pkPolytope->GetVertex(0) - m_kCentroid;
    Real fMin = rkDirection.Dot(kDiff), fMax = fMin;
    riNegativeDirection = 0;
    riPositiveDirection = 0;

    for (int i = 1; i < m_pkPolytope->GetVQuantity(); i++)
    {
        kDiff = m_pkPolytope->GetVertex(i) - m_kCentroid;
        Real fDot = rkDirection.Dot(kDiff);
        if (fDot < fMin)
        {
            riNegativeDirection = i;
            fMin = fDot;
        }
        else if (fDot > fMax)
        {
            riPositiveDirection = i;
            fMax = fDot;
        }
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_PHYSICS_ITEM
class ExtremalQuery3PRJ<float>;

template WM4_PHYSICS_ITEM
class ExtremalQuery3PRJ<double>;
//----------------------------------------------------------------------------
}
