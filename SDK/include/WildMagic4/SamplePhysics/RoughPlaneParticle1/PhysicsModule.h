// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "Wm4OdeSolver.h"

class PhysicsModule
{
public:
    // construction and destruction
    PhysicsModule ();
    ~PhysicsModule ();

    // initialize the differential equation solver
    void Initialize (double dTime, double dDeltaTime, double dX, double dW,
        double dXDot, double dWDot);

    // access the current state
    double GetTime () const;
    double GetDeltaTime () const;
    double GetX () const;
    double GetXDot () const;
    double GetW () const;
    double GetWDot () const;

    // take a single step of the solver
    void Update ();

    // physical constants // symbols used in the Game Physics book
    double Gravity;       // g
    double Mass;          // m
    double Friction;      // c
    double Angle;         // phi

protected:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime;
    double m_adState[4], m_adAux[2];

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif
