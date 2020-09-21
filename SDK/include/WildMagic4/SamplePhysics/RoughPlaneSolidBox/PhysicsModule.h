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
        double dTheta, double dXDer, double dWDer, double dThetaDer);

    // access the current state
    double GetTime () const;
    double GetDeltaTime () const;
    double GetX () const;
    double GetXDer () const;
    double GetW () const;
    double GetWDer () const;
    double GetTheta () const;
    double GetThetaDer () const;

    // get rectangle corners in counterclockwise order
    void GetRectangle (
        double& rdX00, double& rdY00,
        double& rdX10, double& rdY10,
        double& rdX11, double& rdY11,
        double& rdX01, double& rdY01) const;

    // take a single step of the solver
    void Update ();

    // physical constants // symbols used in the Game Physics book
    double Mu;            // mu
    double Gravity;       // g
    double Angle;         // phi
    double SinAngle;      // sin(phi)
    double CosAngle;      // cos(phi)
    double XLocExt;       // a
    double YLocExt;       // b
    double ZLocExt;       // h

protected:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime;
    double m_dX, m_dW, m_dXDer, m_dWDer;
    double m_adState[6], m_adAux[2];

    // angular speed can be solved in closed form
    double m_dTheta0, m_dThetaDer0, m_dAngVelCoeff;

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif
