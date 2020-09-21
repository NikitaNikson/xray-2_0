// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void RefractionEffect::SetFresnelConstant (int i, float fValue)
{
    m_afVConstant[i] = fValue;
}
//----------------------------------------------------------------------------
inline float RefractionEffect::GetFresnelConstant (int i) const
{
    return m_afVConstant[i];
}
//----------------------------------------------------------------------------
inline void RefractionEffect::SetEtaRatio (float fEtaRatio)
{
    m_afVConstant[3] = fEtaRatio;
}
//----------------------------------------------------------------------------
inline float RefractionEffect::GetEtaRatio () const
{
    return m_afVConstant[3];
}
//----------------------------------------------------------------------------
