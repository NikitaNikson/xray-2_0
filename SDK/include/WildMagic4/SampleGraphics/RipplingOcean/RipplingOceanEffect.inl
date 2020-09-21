// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetLightDir (const Vector3f& rkLightDir)
{
    m_afLightDir[0] = rkLightDir[0];
    m_afLightDir[1] = rkLightDir[1];
    m_afLightDir[2] = rkLightDir[2];
}
//----------------------------------------------------------------------------
inline Vector3f RipplingOceanEffect::GetLightDir () const
{
    return Vector3f(m_afLightDir[0],m_afLightDir[1],m_afLightDir[2]);
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetWaveDirX (float afValue[4])
{
    m_afWaveDirX[0] = afValue[0];
    m_afWaveDirX[1] = afValue[1];
    m_afWaveDirX[2] = afValue[2];
    m_afWaveDirX[3] = afValue[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::GetWaveDirX (float afValue[4]) const
{
    afValue[0] = m_afWaveDirX[0];
    afValue[1] = m_afWaveDirX[1];
    afValue[2] = m_afWaveDirX[2];
    afValue[3] = m_afWaveDirX[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetWaveDirY (float afValue[4])
{
    m_afWaveDirY[0] = afValue[0];
    m_afWaveDirY[1] = afValue[1];
    m_afWaveDirY[2] = afValue[2];
    m_afWaveDirY[3] = afValue[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::GetWaveDirY (float afValue[4]) const
{
    afValue[0] = m_afWaveDirY[0];
    afValue[1] = m_afWaveDirY[1];
    afValue[2] = m_afWaveDirY[2];
    afValue[3] = m_afWaveDirY[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetWaveSpeed (float afValue[4])
{
    m_afWaveSpeed[0] = afValue[0];
    m_afWaveSpeed[1] = afValue[1];
    m_afWaveSpeed[2] = afValue[2];
    m_afWaveSpeed[3] = afValue[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::GetWaveSpeed (float afValue[4]) const
{
    afValue[0] = m_afWaveSpeed[0];
    afValue[1] = m_afWaveSpeed[1];
    afValue[2] = m_afWaveSpeed[2];
    afValue[3] = m_afWaveSpeed[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetWaveOffset (float afValue[4])
{
    m_afWaveOffset[0] = afValue[0];
    m_afWaveOffset[1] = afValue[1];
    m_afWaveOffset[2] = afValue[2];
    m_afWaveOffset[3] = afValue[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::GetWaveOffset (float afValue[4]) const
{
    afValue[0] = m_afWaveOffset[0];
    afValue[1] = m_afWaveOffset[1];
    afValue[2] = m_afWaveOffset[2];
    afValue[3] = m_afWaveOffset[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetWaveHeight (float afValue[4])
{
    m_afWaveHeight[0] = afValue[0];
    m_afWaveHeight[1] = afValue[1];
    m_afWaveHeight[2] = afValue[2];
    m_afWaveHeight[3] = afValue[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::GetWaveHeight (float afValue[4]) const
{
    afValue[0] = m_afWaveHeight[0];
    afValue[1] = m_afWaveHeight[1];
    afValue[2] = m_afWaveHeight[2];
    afValue[3] = m_afWaveHeight[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetBumpSpeed (float afValue[4])
{
    m_afBumpSpeed[0] = afValue[0];
    m_afBumpSpeed[1] = afValue[1];
    m_afBumpSpeed[2] = afValue[2];
    m_afBumpSpeed[3] = afValue[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::GetBumpSpeed (float afValue[4]) const
{
    afValue[0] = m_afBumpSpeed[0];
    afValue[1] = m_afBumpSpeed[1];
    afValue[2] = m_afBumpSpeed[2];
    afValue[3] = m_afBumpSpeed[3];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetAverageDuDxDvDy (float fValue)
{
    m_afConstants[0] = fValue;
}
//----------------------------------------------------------------------------
inline float RipplingOceanEffect::GetAverageDuDxDvDy () const
{
    return m_afConstants[0];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetAmbient (float fValue)
{
    m_afConstants[1] = fValue;
}
//----------------------------------------------------------------------------
inline float RipplingOceanEffect::GetAmbient () const
{
    return m_afConstants[1];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetTextureRepeat (float fValue)
{
    m_afConstants[2] = fValue;
}
//----------------------------------------------------------------------------
inline float RipplingOceanEffect::GetTextureRepeat () const
{
    return m_afConstants[2];
}
//----------------------------------------------------------------------------
inline void RipplingOceanEffect::SetTime (float fValue)
{
    m_afConstants[3] = fValue;
}
//----------------------------------------------------------------------------
inline float RipplingOceanEffect::GetTime () const
{
    return m_afConstants[3];
}
//----------------------------------------------------------------------------
