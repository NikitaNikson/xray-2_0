// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline const TriMesh* BoundingVolumeTree::GetMesh () const
{
    return m_pkMesh;
}
//----------------------------------------------------------------------------
inline const BoundingVolume* BoundingVolumeTree::GetWorldBound () const
{
    return m_spkWorldBound;
}
//----------------------------------------------------------------------------
inline int BoundingVolumeTree::GetTriangleQuantity () const
{
    return m_iTriangleQuantity;
}
//----------------------------------------------------------------------------
inline int BoundingVolumeTree::GetTriangle (int i) const
{
    return m_aiTriangle[i];
}
//----------------------------------------------------------------------------
inline const int* BoundingVolumeTree::GetTriangles () const
{
    return m_aiTriangle;
}
//----------------------------------------------------------------------------
inline BoundingVolumeTree* BoundingVolumeTree::GetLChild ()
{
    return m_pkLChild;
}
//----------------------------------------------------------------------------
inline BoundingVolumeTree* BoundingVolumeTree::GetRChild ()
{
    return m_pkRChild;
}
//----------------------------------------------------------------------------
inline bool BoundingVolumeTree::IsInteriorNode () const
{
    return m_pkLChild || m_pkRChild;
}
//----------------------------------------------------------------------------
inline bool BoundingVolumeTree::IsLeafNode () const
{
    return !m_pkLChild && !m_pkRChild;
}
//----------------------------------------------------------------------------
