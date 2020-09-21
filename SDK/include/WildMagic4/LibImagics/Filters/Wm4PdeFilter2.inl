// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int PdeFilter2::GetXBound () const
{
    return m_iXBound;
}
//----------------------------------------------------------------------------
inline int PdeFilter2::GetYBound () const
{
    return m_iYBound;
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetXSpacing () const
{
    return m_fXSpacing;
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetYSpacing () const
{
    return m_fYSpacing;
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetU (int iX, int iY) const
{
    return m_aafSrc[iY+1][iX+1];
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetUx (int iX, int iY) const
{
    int iYp1 = iY + 1;
    return m_fHalfInvDx*(m_aafSrc[iYp1][iX+2] - m_aafSrc[iYp1][iX]);
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetUy (int iX, int iY) const
{
    int iXp1 = iX + 1;
    return m_fHalfInvDy*(m_aafSrc[iY+2][iXp1] - m_aafSrc[iY][iXp1]);
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetUxx (int iX, int iY) const
{
    int iYp1 = iY + 1;
    return m_fInvDxDx*(m_aafSrc[iYp1][iX+2] - 2.0f*m_aafSrc[iYp1][iX+1] +
        m_aafSrc[iYp1][iX]);
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetUxy (int iX, int iY) const
{
    int iXp2 = iX + 2, iYp2 = iY + 2;
    return m_fFourthInvDxDy*(m_aafSrc[iY][iX] - m_aafSrc[iY][iXp2] +
        m_aafSrc[iYp2][iXp2] - m_aafSrc[iYp2][iX]);
}
//----------------------------------------------------------------------------
inline float PdeFilter2::GetUyy (int iX, int iY) const
{
    int iXp1 = iX + 1;
    return m_fInvDyDy*(m_aafSrc[iY+2][iXp1] - 2.0f*m_aafSrc[iY+1][iXp1] +
        m_aafSrc[iY][iXp1]);
}
//----------------------------------------------------------------------------
inline bool PdeFilter2::GetMask (int iX, int iY) const
{
    return (m_aabMask ? m_aabMask[iY+1][iX+1] : true);
}
//----------------------------------------------------------------------------
