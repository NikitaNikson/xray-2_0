// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int PlanarReflectionEffect::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline void PlanarReflectionEffect::SetPlane (int i, TriMeshPtr spkPlane)
{
    assert(0 <= i && i < m_iQuantity);
    m_aspkPlane[i] = spkPlane;
    m_aspkPlane[i]->Culling = Spatial::CULL_ALWAYS;
}
//----------------------------------------------------------------------------
inline TriMeshPtr PlanarReflectionEffect::GetPlane (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_aspkPlane[i];
}
//----------------------------------------------------------------------------
inline void PlanarReflectionEffect::SetReflectance (int i, float fReflectance)
{
    assert(0 <= i && i < m_iQuantity);
    m_afReflectance[i] = fReflectance;
}
//----------------------------------------------------------------------------
inline float PlanarReflectionEffect::GetReflectance (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_afReflectance[i];
}
//----------------------------------------------------------------------------
