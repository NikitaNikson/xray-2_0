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
inline double PhysicsModule::GetX () const
{
    return m_adState[0];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetXDot () const
{
    return m_adState[1];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetY () const
{
    return m_adState[2];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetYDot () const
{
    return m_adState[3];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetTheta () const
{
    return m_adState[4];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetThetaDot () const
{
    return m_adState[5];
}
//----------------------------------------------------------------------------
