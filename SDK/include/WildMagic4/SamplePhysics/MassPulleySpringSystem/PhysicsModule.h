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
    ~PhysicsModule ();

    // initialize the numerical solver
    void Initialize (double dTime, double dDeltaTime, double dY1, double dDY1,
        double dDY3);

    // take a single step of the solver
    void Update ();

    // gravitational constant
    double Gravity;

    // left mass in Figure 3.13
    double Mass1;

    // right mass in Figure 3.13
    double Mass2;

    // length of rigid wire connecting mass 1 to mass 2
    double WireLength;

    // pulley parameters
    double Mass3, Radius, Inertia;

    // spring parameters
    double SpringLength, SpringConstant;

    // accessors
    double GetInitialY1 () const;
    double GetCurrentY1 () const;
    double GetCurrentY2 () const;
    double GetCurrentY3 () const;
    double GetAngle () const;
    double GetCableFraction1 () const;
    double GetCableFraction2 () const;

private:
    // time information
    double m_dTime, m_dDeltaTime;

    // derived parameters
    double m_dAlpha, m_dBeta, m_dGamma, m_dDelta, m_dOmega, m_dGDivOmegaSqr;

    // initial conditions
    double m_dY1, m_dY2, m_dY3, m_dDY1, m_dDY2, m_dDY3;

    // solution parameters
    double m_dLPlusGDivOmegaSqr, m_dK1, m_dK2, m_dTCoeff, m_dTSqrCoeff;
    double m_dDeltaDivOmegaSqr, m_dY1Curr, m_dY2Curr, m_dY3Curr;
};

#include "PhysicsModule.inl"

#endif
