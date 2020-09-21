// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int FastMarch2::GetXBound () const
{
    return m_iXBound;
}
//----------------------------------------------------------------------------
inline int FastMarch2::GetYBound () const
{
    return m_iYBound;
}
//----------------------------------------------------------------------------
inline float FastMarch2::GetXSpacing () const
{
    return m_fXSpacing;
}
//----------------------------------------------------------------------------
inline float FastMarch2::GetYSpacing () const
{
    return m_fYSpacing;
}
//----------------------------------------------------------------------------
inline int FastMarch2::Index (int iX, int iY) const
{
    assert(0 <= iX && iX < m_iXBound && 0 <= iY && iY < m_iYBound);
    return iX + m_iXBound*iY;
}
//----------------------------------------------------------------------------
