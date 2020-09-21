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
#include "Wm4Matrix3.h"

class PhysicsModule
{
public:
    // construction and destruction
    PhysicsModule ();
    ~PhysicsModule ();

    // initialize the differential equation solver
    void Initialize (double dTime, double dDeltaTime, double dTheta,
        double dPhi, double dThetaDot, double dPhiDot);

    double GetTime () const;
    double GetDeltaTime () const;
    double GetTheta () const;
    double GetThetaDot () const;
    double GetPhi () const;
    double GetPhiDot () const;

    // the orientation of the pendulum
    Wm4::Matrix3f GetOrientation () const;

    // take a single step of the solver
    void Update ();

    // pendulum parameters
    double AngularSpeed;  // w
    double Latitude;  // lat
    double GDivL;  // g/L

private:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime, m_adState[4], m_adAux[3];

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif
