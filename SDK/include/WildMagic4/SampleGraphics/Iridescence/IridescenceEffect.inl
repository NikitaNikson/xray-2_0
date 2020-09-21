// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void IridescenceEffect::SetInterpolateFactor (float fInterpolateFactor)
{
    m_afInterpolate[0] = fInterpolateFactor;
}
//----------------------------------------------------------------------------
inline float IridescenceEffect::GetInterpolateFactor () const
{
    return m_afInterpolate[0];
}
//----------------------------------------------------------------------------
