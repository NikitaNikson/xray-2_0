// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "Wm4MassSpringArbitrary.h"

class PhysicsModule : public Wm4::MassSpringArbitrary3f
{
public:
    // construction and destruction
    PhysicsModule (int iNumParticles, int iNumSteps, float fStep,
        float fViscosity);

    virtual ~PhysicsModule ();

    // external acceleration is due to viscous forces
    virtual Wm4::Vector3f ExternalAcceleration (int i, float fTime,
        const Wm4::Vector3f* akPosition, const Wm4::Vector3f* akVelocity);

protected:
    float m_fViscosity;
};

#endif
