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
    void Initialize (double dTime, double dDeltaTime, double dTheta1,
        double dTheta2, double dTheta1Dot, double dTheta2Dot);

    // access the current state
    double GetTime () const;
    double GetDeltaTime () const;
    double GetTheta1 () const;
    double GetTheta1Dot () const;
    double GetTheta2 () const;
    double GetTheta2Dot () const;
    void GetPositions (double& rdX1, double& rdY1, double& rdX2,
        double& rdY2) const;

    // take a single step of the solver
    void Update ();

    // physical constants
    double Gravity;
    double Mass1, Mass2;
    double Length1, Length2;
    double JointX, JointY;

protected:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime;
    double m_adState[4], m_adAux[4];

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif
