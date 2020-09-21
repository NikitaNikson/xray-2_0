// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline Vector3f& RayTracer::Location ()
{
    return m_kLocation;
}
//----------------------------------------------------------------------------
inline Vector3f& RayTracer::Direction ()
{
    return m_kDirection;
}
//----------------------------------------------------------------------------
inline Vector3f& RayTracer::Up ()
{
    return m_kUp;
}
//----------------------------------------------------------------------------
inline Vector3f& RayTracer::Right ()
{
    return m_kRight;
}
//----------------------------------------------------------------------------
inline float& RayTracer::Near ()
{
    return m_fNear;
}
//----------------------------------------------------------------------------
inline float& RayTracer::Far ()
{
    return m_fFar;
}
//----------------------------------------------------------------------------
inline float& RayTracer::HalfWidth ()
{
    return m_fHalfWidth;
}
//----------------------------------------------------------------------------
inline float& RayTracer::HalfHeight ()
{
    return m_fHalfHeight;
}
//----------------------------------------------------------------------------
inline int RayTracer::GetWidth () const
{
    return m_iWidth;
}
//----------------------------------------------------------------------------
inline int RayTracer::GetHeight () const
{
    return m_iHeight;
}
//----------------------------------------------------------------------------
inline const float* RayTracer::GetImage () const
{
    return m_afImage;
}
//----------------------------------------------------------------------------
