// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "Wm4MassSpringSurface.h"

class PhysicsModule : public Wm4::MassSpringSurface3f
{
public:
    // Construction and destruction.
    //
    // Gravity is controlled by the input rkGravity.
    //
    // Mass-spring systems tend to exhibit "stiffness" (in the sense of
    // numerical stability).  To remedy this problem, a small amount of
    // viscous friction is added to the external force.  This term is
    // of the form -fViscosity*velocity where fViscosity > 0.
    //
    // The initial wind force is specified by the caller.  The wind remains
    // in effect throughout the simulation.  To simulate oscillatory behavior
    // locally, random forces are applied at each mass in the direction
    // perpendicular to the plane of the wind and gravity vectors.  The
    // amplitudes are sinusoidal.  The phases are randomly generated.

    PhysicsModule (int iRows, int iCols, float fStep,
        const Wm4::Vector3f& rkGravity, const Wm4::Vector3f& rkWind,
        float fViscosity, float fAmplitude);

    virtual ~PhysicsModule ();

    // Acceleration is due to forces of gravitation, wind, and viscous
    // friction.  The wind forces are randomly generated.
    virtual Wm4::Vector3f ExternalAcceleration (int i, float fTime,
        const Wm4::Vector3f* akPosition, const Wm4::Vector3f* akVelocity);

protected:
    Wm4::Vector3f m_kGravity, m_kWind;
    float m_fViscosity;

    // sinusoidal forces
    float m_fAmplitude;
    float* m_afPhase;
    Wm4::Vector3f m_kDirection;
};

#endif
