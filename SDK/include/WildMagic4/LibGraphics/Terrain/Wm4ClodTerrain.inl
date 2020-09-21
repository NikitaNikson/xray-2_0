// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int ClodTerrain::GetRowQuantity () const
{
    return m_iRows;
}
//----------------------------------------------------------------------------
inline int ClodTerrain::GetColQuantity () const
{
    return m_iCols;
}
//----------------------------------------------------------------------------
inline int ClodTerrain::GetSize () const
{
    return m_iSize;
}
//----------------------------------------------------------------------------
inline float ClodTerrain::GetMinElevation () const
{
    return m_fMinElevation;
}
//----------------------------------------------------------------------------
inline float ClodTerrain::GetMaxElevation () const
{
    return m_fMaxElevation;
}
//----------------------------------------------------------------------------
inline float ClodTerrain::GetSpacing () const
{
    return m_fSpacing;
}
//----------------------------------------------------------------------------
inline float ClodTerrain::GetPixelTolerance () const
{
    return m_fPixelTolerance;
}
//----------------------------------------------------------------------------
inline void ClodTerrain::SetRenderer (Renderer* pkRenderer)
{
    m_pkRenderer = pkRenderer;
}
//----------------------------------------------------------------------------
inline bool& ClodTerrain::CloseAssumption ()
{
    return m_bCloseAssumption;
}
//----------------------------------------------------------------------------
inline float& ClodTerrain::UVBias ()
{
    return m_fUVBias;
}
//----------------------------------------------------------------------------
inline ColorRGBA& ClodTerrain::BorderColor ()
{
    return m_kBorderColor;
}
//----------------------------------------------------------------------------
