// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline Curve3f*& TubeSurface::Medial ()
{
    return m_pkMedial;
}
//----------------------------------------------------------------------------
inline const Curve3f* TubeSurface::GetMedial () const
{
    return m_pkMedial;
}
//----------------------------------------------------------------------------
inline TubeSurface::RadialFunction& TubeSurface::Radial ()
{
    return m_oRadial;
}
//----------------------------------------------------------------------------
inline TubeSurface::RadialFunction TubeSurface::GetRadial () const
{
    return m_oRadial;
}
//----------------------------------------------------------------------------
inline Vector3f& TubeSurface::UpVector ()
{
    return m_kUpVector;
}
//----------------------------------------------------------------------------
inline const Vector3f& TubeSurface::GetUpVector () const
{
    return m_kUpVector;
}
//----------------------------------------------------------------------------
inline int TubeSurface::GetSliceSamples () const
{
    return m_iSliceSamples;
}
//----------------------------------------------------------------------------
inline int TubeSurface::Index (int iS, int iM)
{
    return iS + (m_iSliceSamples+1)*iM;
}
//----------------------------------------------------------------------------
