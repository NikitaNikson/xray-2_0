// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4PhysicsPCH.h"
#include "Wm4ExtremalQuery3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3<Real>::ExtremalQuery3 (
    const ConvexPolyhedron3<Real>& rkPolytope)
    :
    m_pkPolytope(&rkPolytope)
{
    // Create the triangle normals.
    const Vector3<Real>* akVertex = m_pkPolytope->GetVertices();
    int iTQuantity = m_pkPolytope->GetTQuantity();
    const int* piIndex = m_pkPolytope->GetIndices();
    m_akFaceNormal = WM4_NEW Vector3<Real>[iTQuantity];
    for (int i = 0; i < iTQuantity; i++)
    {
        const Vector3<Real>& rkV0 = akVertex[*piIndex++];
        const Vector3<Real>& rkV1 = akVertex[*piIndex++];
        const Vector3<Real>& rkV2 = akVertex[*piIndex++];
        Vector3<Real> kEdge1 = rkV1 - rkV0;
        Vector3<Real> kEdge2 = rkV2 - rkV0;
        m_akFaceNormal[i] = kEdge1.UnitCross(kEdge2);
    }
}
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3<Real>::~ExtremalQuery3 ()
{
    WM4_DELETE[] m_akFaceNormal;
}
//----------------------------------------------------------------------------
template <class Real>
const ConvexPolyhedron3<Real>& ExtremalQuery3<Real>::GetPolytope () const
{
    return *m_pkPolytope;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>* ExtremalQuery3<Real>::GetFaceNormals () const
{
    return m_akFaceNormal;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_PHYSICS_ITEM
class ExtremalQuery3<float>;

template WM4_PHYSICS_ITEM
class ExtremalQuery3<double>;
//----------------------------------------------------------------------------
}
