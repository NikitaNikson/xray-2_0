// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int TerrainPage::GetSize () const
{
    return m_iSize;
}
//----------------------------------------------------------------------------
inline const unsigned short* TerrainPage::GetHeights () const
{
    return m_ausHeight;
}
//----------------------------------------------------------------------------
inline const Vector2f& TerrainPage::GetOrigin () const
{
    return m_kOrigin;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetMinElevation () const
{
    return m_fMinElevation;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetMaxElevation () const
{
    return m_fMaxElevation;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetSpacing () const
{
    return m_fSpacing;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetX (int iX) const
{
    return m_kOrigin.X() + m_fSpacing*float(iX);
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetY (int iY) const
{
    return m_kOrigin.Y() + m_fSpacing*float(iY);
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetHeight (int iIndex) const
{
    return m_fMinElevation + m_fMultiplier*float(m_ausHeight[iIndex]);
}
//----------------------------------------------------------------------------
inline float& TerrainPage::UVBias ()
{
    return m_fUVBias;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetTextureCoordinate (int iIndex) const
{
    return m_fTextureSpacing*float(iIndex);
}
//----------------------------------------------------------------------------
