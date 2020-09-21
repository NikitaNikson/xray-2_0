// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void CharcoalEffect::SetAmbientIntensity (float fAmbientIntensity)
{
    m_afAmbientContrast[0] = fAmbientIntensity;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetAmbientIntensity () const
{
    return m_afAmbientContrast[0];
}
//----------------------------------------------------------------------------
inline void CharcoalEffect::SetContrastExponent (float fContrastExponent)
{
    m_afAmbientContrast[1] = fContrastExponent;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetContrastExponent () const
{
    return m_afAmbientContrast[1];
}
//----------------------------------------------------------------------------
inline void CharcoalEffect::SetSmudgeFactor (float fSmudgeFactor)
{
    m_afSmudgePaper[0] = fSmudgeFactor;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetSmudgeFactor () const
{
    return m_afSmudgePaper[0];
}
//----------------------------------------------------------------------------
inline void CharcoalEffect::SetPaperFactor (float fPaperFactor)
{
    m_afSmudgePaper[1] = fPaperFactor;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetPaperFactor () const
{
    return m_afSmudgePaper[1];
}
//----------------------------------------------------------------------------
