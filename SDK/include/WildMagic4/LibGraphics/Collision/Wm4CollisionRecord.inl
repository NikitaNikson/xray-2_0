// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline TriMesh* CollisionRecord::GetMesh ()
{
    return m_pkMesh;
}
//----------------------------------------------------------------------------
inline Vector3f* CollisionRecord::GetVelocity ()
{
    return m_pkVelocity;
}
//----------------------------------------------------------------------------
inline void* CollisionRecord::GetCallbackData ()
{
    return m_pvCallbackData;
}
//----------------------------------------------------------------------------
