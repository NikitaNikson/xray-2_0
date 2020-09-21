// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int BoxBV::GetBVType () const
{
    return BoundingVolume::BV_BOX;
}
//----------------------------------------------------------------------------
inline void BoxBV::SetCenter (const Vector3f& rkCenter)
{
    m_kBox.Center = rkCenter;
}
//----------------------------------------------------------------------------
inline Vector3f BoxBV::GetCenter () const
{
    return m_kBox.Center;
}
//----------------------------------------------------------------------------
inline Box3f& BoxBV::Box ()
{
    return m_kBox;
}
//----------------------------------------------------------------------------
inline const Box3f& BoxBV::GetBox () const
{
    return m_kBox;
}
//----------------------------------------------------------------------------
