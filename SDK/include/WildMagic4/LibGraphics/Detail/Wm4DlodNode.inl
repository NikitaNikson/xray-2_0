// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline Vector3f& DlodNode::ModelCenter ()
{
    return m_kModelLodCenter;
}
//----------------------------------------------------------------------------
inline const Vector3f& DlodNode::GetModelCenter () const
{
    return m_kModelLodCenter;
}
//----------------------------------------------------------------------------
inline const Vector3f& DlodNode::GetWorldCenter () const
{
    return m_kWorldLodCenter;
}
//----------------------------------------------------------------------------
inline float DlodNode::GetModelMinDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kModelMinDist[i];
}
//----------------------------------------------------------------------------
inline float DlodNode::GetModelMaxDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kModelMaxDist[i];
}
//----------------------------------------------------------------------------
inline float DlodNode::GetWorldMinDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kWorldMinDist[i];
}
//----------------------------------------------------------------------------
inline float DlodNode::GetWorldMaxDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kWorldMaxDist[i];
}
//----------------------------------------------------------------------------
