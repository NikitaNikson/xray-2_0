// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int PlanarShadowEffect::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline void PlanarShadowEffect::SetPlane (int i, TriMeshPtr spkPlane)
{
    assert(0 <= i && i < m_iQuantity);
    m_aspkPlane[i] = spkPlane;
    m_aspkPlane[i]->Culling = Spatial::CULL_ALWAYS;
}
//----------------------------------------------------------------------------
inline TriMeshPtr PlanarShadowEffect::GetPlane (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_aspkPlane[i];
}
//----------------------------------------------------------------------------
inline void PlanarShadowEffect::SetProjector (int i, LightPtr spkProjector)
{
    assert(0 <= i && i < m_iQuantity);
    m_aspkProjector[i] = spkProjector;
}
//----------------------------------------------------------------------------
inline LightPtr PlanarShadowEffect::GetProjector (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_aspkProjector[i];
}
//----------------------------------------------------------------------------
inline void PlanarShadowEffect::SetShadowColor (int i,
    const ColorRGBA& rkShadowColor)
{
    assert(0 <= i && i < m_iQuantity);
    m_akShadowColor[i] = rkShadowColor;
}
//----------------------------------------------------------------------------
inline const ColorRGBA& PlanarShadowEffect::GetShadowColor (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akShadowColor[i];
}
//----------------------------------------------------------------------------
