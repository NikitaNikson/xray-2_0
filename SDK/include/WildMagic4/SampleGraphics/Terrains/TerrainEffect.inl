// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void TerrainEffect::SetFogColor (const ColorRGB& rkFogColor)
{
    m_afFogColorDensity[0] = rkFogColor[0];
    m_afFogColorDensity[1] = rkFogColor[1];
    m_afFogColorDensity[2] = rkFogColor[2];
}
//----------------------------------------------------------------------------
inline ColorRGB TerrainEffect::GetFogColor () const
{
    return ColorRGB(m_afFogColorDensity[0],m_afFogColorDensity[1],
        m_afFogColorDensity[2]);
}
//----------------------------------------------------------------------------
inline void TerrainEffect::SetFogDensity (float fFogDensity)
{
    m_afFogColorDensity[3] = fFogDensity;
}
//----------------------------------------------------------------------------
inline float TerrainEffect::GetFogDensity () const
{
    return m_afFogColorDensity[3];
}
//----------------------------------------------------------------------------
