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
    void Initialize (double dTime, double dDeltaTime, double dQ,
        double dQDot);

    // take a single step of the solver
    void Update ();

    // access the current state
    double GetTime () const;
    double GetDeltaTime () const;
    double GetQ () const;
    double GetQDot () const;

    // physical constants
    double Gravity;
    double Mass;

private:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime, m_dQ, m_dQDer;
    double m_adState[2], m_adAux[1];

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif
