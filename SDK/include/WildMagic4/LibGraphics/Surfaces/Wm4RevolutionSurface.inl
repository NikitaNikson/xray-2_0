// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int RevolutionSurface::GetCurveSamples () const
{
    return m_iCurveSamples;
}
//----------------------------------------------------------------------------
inline int RevolutionSurface::GetRadialSamples () const
{
    return m_iRadialSamples;
}
//----------------------------------------------------------------------------
inline void RevolutionSurface::SetCurve (Curve2f* pkCurve)
{
    m_pkCurve = pkCurve;
}
//----------------------------------------------------------------------------
inline const Curve2f* RevolutionSurface::GetCurve () const
{
    return m_pkCurve;
}
//----------------------------------------------------------------------------
inline RevolutionSurface::TopologyType RevolutionSurface::GetTopology () const
{
    return m_eTopology;
}
//----------------------------------------------------------------------------
inline bool& RevolutionSurface::SampleByArcLength ()
{
    return m_bSampleByArcLength;
}
//----------------------------------------------------------------------------
inline bool RevolutionSurface::GetSampleByArcLength () const
{
    return m_bSampleByArcLength;
}
//----------------------------------------------------------------------------
