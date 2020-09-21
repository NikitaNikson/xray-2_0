// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline Vector3f Camera::GetLocation () const
{
    return m_kLocation;
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetDVector () const
{
    return m_kDVector;
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetUVector () const
{
    return m_kUVector;
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetRVector () const
{
    return m_kRVector;
}
//----------------------------------------------------------------------------
inline const float* Camera::GetFrustum () const
{
    return m_afFrustum;
}
//----------------------------------------------------------------------------
inline float Camera::GetDMin () const
{
    return m_afFrustum[VF_DMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetDMax () const
{
    return m_afFrustum[VF_DMAX];
}
//----------------------------------------------------------------------------
inline float Camera::GetUMin () const
{
    return m_afFrustum[VF_UMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetUMax () const
{
    return m_afFrustum[VF_UMAX];
}
//----------------------------------------------------------------------------
inline float Camera::GetRMin () const
{
    return m_afFrustum[VF_RMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetRMax () const
{
    return m_afFrustum[VF_RMAX];
}
//----------------------------------------------------------------------------
