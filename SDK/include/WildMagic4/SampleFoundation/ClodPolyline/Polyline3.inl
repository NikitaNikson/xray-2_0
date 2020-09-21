// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int Polyline3::GetVertexQuantity () const
{
    return m_iVQuantity;
}
//----------------------------------------------------------------------------
inline const Vector3f* Polyline3::GetVertices () const
{
    return m_akVertex;
}
//----------------------------------------------------------------------------
inline bool Polyline3::GetClosed () const
{
    return m_bClosed;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetEdgeQuantity () const
{
    return m_iEQuantity;
}
//----------------------------------------------------------------------------
inline const int* Polyline3::GetEdges () const
{
    return m_aiEdge;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetMinLevelOfDetail () const
{
    return m_iVMin;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetMaxLevelOfDetail () const
{
    return m_iVMax;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetLevelOfDetail () const
{
    return m_iVQuantity;
}
//----------------------------------------------------------------------------
