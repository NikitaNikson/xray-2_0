// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline BSplineVolumef*& BoxSurface::Volume ()
{
    return m_pkVolume;
}
//----------------------------------------------------------------------------
inline const BSplineVolumef* BoxSurface::GetVolume () const
{
    return m_pkVolume;
}
//----------------------------------------------------------------------------
inline int BoxSurface::GetUSamples () const
{
    return m_iUSamples;
}
//----------------------------------------------------------------------------
inline int BoxSurface::GetVSamples () const
{
    return m_iVSamples;
}
//----------------------------------------------------------------------------
inline int BoxSurface::GetWSamples () const
{
    return m_iWSamples;
}
//----------------------------------------------------------------------------
