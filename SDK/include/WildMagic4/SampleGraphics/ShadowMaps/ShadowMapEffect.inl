// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void ShadowMapEffect::SetDepthBias (float fDepthBias)
{
    m_afDepthBias[0] = fDepthBias;
}
//----------------------------------------------------------------------------
inline float ShadowMapEffect::GetDepthBias () const
{
    return m_afDepthBias[0];
}
//----------------------------------------------------------------------------
