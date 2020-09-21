// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int PdeFilter::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline float PdeFilter::GetBorderValue () const
{
    return m_fBorderValue;
}
//----------------------------------------------------------------------------
inline PdeFilter::ScaleType PdeFilter::GetScaleType () const
{
    return m_eScaleType;
}
//----------------------------------------------------------------------------
inline void PdeFilter::SetTimeStep (float fTimeStep)
{
    m_fTimeStep = fTimeStep;
}
//----------------------------------------------------------------------------
inline float PdeFilter::GetTimeStep () const
{
    return m_fTimeStep;
}
//----------------------------------------------------------------------------
