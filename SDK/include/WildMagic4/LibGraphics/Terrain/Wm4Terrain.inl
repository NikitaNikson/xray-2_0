// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int Terrain::GetRowQuantity () const
{
    return m_iRows;
}
//----------------------------------------------------------------------------
inline int Terrain::GetColQuantity () const
{
    return m_iCols;
}
//----------------------------------------------------------------------------
inline int Terrain::GetSize () const
{
    return m_iSize;
}
//----------------------------------------------------------------------------
inline float Terrain::GetMinElevation () const
{
    return m_fMinElevation;
}
//----------------------------------------------------------------------------
inline float Terrain::GetMaxElevation () const
{
    return m_fMaxElevation;
}
//----------------------------------------------------------------------------
inline float Terrain::GetSpacing () const
{
    return m_fSpacing;
}
//----------------------------------------------------------------------------
inline float& Terrain::UVBias ()
{
    return m_fUVBias;
}
//----------------------------------------------------------------------------
inline ColorRGBA& Terrain::BorderColor ()
{
    return m_kBorderColor;
}
//----------------------------------------------------------------------------
