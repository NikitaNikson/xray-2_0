// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline double PhysicsModule::GetTime () const
{
    return m_dTime;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetDeltaTime () const
{
    return m_dDeltaTime;
}
//----------------------------------------------------------------------------
inline const Wm4::Vector2d& PhysicsModule::GetPosition () const
{
    return m_kPosition;
}
//----------------------------------------------------------------------------
inline const Wm4::Vector2d& PhysicsModule::GetVelocity () const
{
    return m_kVelocity;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetFrequency () const
{
    return m_dFrequency;
}
//----------------------------------------------------------------------------
