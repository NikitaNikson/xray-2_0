// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int FastMarch3::GetXBound () const
{
    return m_iXBound;
}
//----------------------------------------------------------------------------
inline int FastMarch3::GetYBound () const
{
    return m_iYBound;
}
//----------------------------------------------------------------------------
inline int FastMarch3::GetZBound () const
{
    return m_iZBound;
}
//----------------------------------------------------------------------------
inline float FastMarch3::GetXSpacing () const
{
    return m_fXSpacing;
}
//----------------------------------------------------------------------------
inline float FastMarch3::GetYSpacing () const
{
    return m_fYSpacing;
}
//----------------------------------------------------------------------------
inline float FastMarch3::GetZSpacing () const
{
    return m_fZSpacing;
}
//----------------------------------------------------------------------------
inline int FastMarch3::Index (int iX, int iY, int iZ) const
{
    assert(0 <= iX && iX < m_iXBound
        && 0 <= iY && iY < m_iYBound
        && 0 <= iZ && iZ < m_iZBound);

    return iX + m_iXBound*(iY + m_iYBound*iZ);
}
//----------------------------------------------------------------------------
