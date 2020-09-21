// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "Wm4System.h"

class PhysicsModule
{
public:
    // construction and destruction
    PhysicsModule ();

    // initialize the differential equation solver
    void Initialize (double dTime, double dDeltaTime, double dX, double dY,
        double dTheta, double dXDer, double dYDer, double dThetaDer);

    // access the current state
    double GetTime () const;
    double GetDeltaTime () const;
    double GetX () const;
    double GetXDer () const;
    double GetY () const;
    double GetYDer () const;
    double GetTheta () const;
    double GetThetaDer () const;
    void Get (double& rdX1, double& rdY1, double& rdX2, double& rdY2) const;

    // take a single step of the solver
    void Update ();

    // physical constants   // symbols used in the Game Physics book
    double MuGravity;       // mu*g
    double Length;          // L1 = L2 = L/2

protected:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime;
    double m_dX, m_dY, m_dTheta, m_dXDer, m_dYDer, m_dThetaDer;
    double m_dX0, m_dY0, m_dTheta0, m_dXDer0, m_dYDer0, m_dThetaDer0;
    double m_dHalfLength, m_dLinVelCoeff, m_dAngVelCoeff;
};

#include "PhysicsModule.inl"

#endif
