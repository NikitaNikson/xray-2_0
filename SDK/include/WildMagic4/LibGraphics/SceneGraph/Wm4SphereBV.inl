// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int SphereBV::GetBVType () const
{
    return BoundingVolume::BV_SPHERE;
}
//----------------------------------------------------------------------------
inline void SphereBV::SetCenter (const Vector3f& rkCenter)
{
    m_kSphere.Center = rkCenter;
}
//----------------------------------------------------------------------------
inline void SphereBV::SetRadius (float fRadius)
{
    m_kSphere.Radius = fRadius;
}
//----------------------------------------------------------------------------
inline Vector3f SphereBV::GetCenter () const
{
    return m_kSphere.Center;
}
//----------------------------------------------------------------------------
inline float SphereBV::GetRadius () const
{
    return m_kSphere.Radius;
}
//----------------------------------------------------------------------------
inline Sphere3f& SphereBV::Sphere ()
{
    return m_kSphere;
}
//----------------------------------------------------------------------------
inline const Sphere3f& SphereBV::GetSphere () const
{
    return m_kSphere;
}
//----------------------------------------------------------------------------
