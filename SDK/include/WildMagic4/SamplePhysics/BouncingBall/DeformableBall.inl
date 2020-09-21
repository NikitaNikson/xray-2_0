// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline float DeformableBall::GetDuration () const
{
    return m_fDuration;
}
//----------------------------------------------------------------------------
inline float DeformableBall::GetPeriod () const
{
    return m_fPeriod;
}
//----------------------------------------------------------------------------
inline float DeformableBall::GetMinActive () const
{
    return m_fMinActive;
}
//----------------------------------------------------------------------------
inline float DeformableBall::GetMaxActive () const
{
    return m_fMaxActive;
}
//----------------------------------------------------------------------------
inline bool& DeformableBall::DoAffine ()
{
    return m_bDoAffine;
}
//----------------------------------------------------------------------------
inline TriMeshPtr& DeformableBall::Mesh ()
{
    return m_spkMesh;
}
//----------------------------------------------------------------------------
inline float DeformableBall::GetAmplitude (float fTime)
{
    return m_fDeformMult*(fTime-m_fMinActive)*(m_fMaxActive-fTime);
}
//----------------------------------------------------------------------------
