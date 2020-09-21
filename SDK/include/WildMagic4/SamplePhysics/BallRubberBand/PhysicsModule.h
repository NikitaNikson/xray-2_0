// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "Wm4Vector2.h"

class PhysicsModule
{
public:
    // construction and destruction
    PhysicsModule ();
    ~PhysicsModule ();

    // initialize the system
    void Initialize (double dTime, double dDeltaTime,
        const Wm4::Vector2d& rkInitPos, const Wm4::Vector2d& rkInitVel);

    // take a single step of the simulation
    void Update ();

    // access the current state
    double GetTime () const;
    double GetDeltaTime () const;
    const Wm4::Vector2d& GetPosition () const;
    const Wm4::Vector2d& GetVelocity () const;
    double GetFrequency () const;

    // physical constants
    double SpringConstant;  // c
    double Mass;  // m

private:
    void Evaluate ();

    // state variables
    double m_dTime, m_dDeltaTime;
    Wm4::Vector2d m_kPosition, m_kVelocity;

    // auxiliary variables
    Wm4::Vector2d m_kInitPos;  // initial position
    double m_dFrequency;  // sqrt(c/m)
    Wm4::Vector2d m_kVelDivFreq;  // initial_velocity/frequency
};

#include "PhysicsModule.inl"

#endif
