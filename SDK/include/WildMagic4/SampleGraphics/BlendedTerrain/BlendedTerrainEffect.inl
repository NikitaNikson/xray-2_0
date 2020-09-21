// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void BlendedTerrainEffect::SetFlowDirection (
    const Vector2f& rkFlowDirection)
{
    m_afFlowDirection[0] = rkFlowDirection[0];
    m_afFlowDirection[1] = rkFlowDirection[1];
}
//----------------------------------------------------------------------------
inline Vector2f BlendedTerrainEffect::GetFlowDirection () const
{
    return Vector2f(m_afFlowDirection[0],m_afFlowDirection[1]);
}
//----------------------------------------------------------------------------
inline void BlendedTerrainEffect::SetPowerFactor (float fPowerFactor)
{
    m_afPowerFactor[0] = fPowerFactor;
}
//----------------------------------------------------------------------------
inline float BlendedTerrainEffect::GetPowerFactor () const
{
    return m_afPowerFactor[0];
}
//----------------------------------------------------------------------------
