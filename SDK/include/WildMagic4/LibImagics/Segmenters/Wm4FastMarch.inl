// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void FastMarch::SetTime (int i, float fTime)
{
    assert(0 <= i && i < m_iQuantity);
    m_afTime[i] = fTime;
}
//----------------------------------------------------------------------------
inline float FastMarch::GetTime (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_afTime[i];
}
//----------------------------------------------------------------------------
inline int FastMarch::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline bool FastMarch::IsValid (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return 0.0f <= m_afTime[i] && m_afTime[i] < Mathf::MAX_REAL;
}
//----------------------------------------------------------------------------
inline bool FastMarch::IsTrial (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_apkTrial[i] != 0;
}
//----------------------------------------------------------------------------
inline bool FastMarch::IsFar (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_afTime[i] == Mathf::MAX_REAL;
}
//----------------------------------------------------------------------------
inline bool FastMarch::IsZeroSpeed (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_afTime[i] == -Mathf::MAX_REAL;
}
//----------------------------------------------------------------------------
inline bool FastMarch::IsInterior (int i) const
{
    return IsValid(i) && !IsTrial(i);
}
//----------------------------------------------------------------------------
