// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline float* PointController::PointLinearSpeed ()
{
    return m_afPointLinearSpeed;
}
//----------------------------------------------------------------------------
inline float* PointController::PointAngularSpeed ()
{
    return m_afPointAngularSpeed;
}
//----------------------------------------------------------------------------
inline Vector3f* PointController::PointLinearAxis ()
{
    return m_akPointLinearAxis;
}
//----------------------------------------------------------------------------
inline Vector3f* PointController::PointAngularAxis ()
{
    return m_akPointAngularAxis;
}
//----------------------------------------------------------------------------
