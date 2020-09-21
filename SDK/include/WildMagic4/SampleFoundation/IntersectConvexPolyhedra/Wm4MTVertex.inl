// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int MTVertex::GetLabel () const
{
    return m_iLabel;
}
//----------------------------------------------------------------------------
inline int MTVertex::GetEdgeQuantity () const
{
    return m_kESet.GetQuantity();
}
//----------------------------------------------------------------------------
inline int MTVertex::GetEdge (int i) const
{
    return m_kESet.Get(i);
}
//----------------------------------------------------------------------------
inline int MTVertex::GetTriangleQuantity () const
{
    return m_kTSet.GetQuantity();
}
//----------------------------------------------------------------------------
inline int MTVertex::GetTriangle (int i) const
{
    return m_kTSet.Get(i);
}
//----------------------------------------------------------------------------
