// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "PhysicsModule.h"
#include "Wm4Math.h"
#include "Wm4OdeRungeKutta4.h"
using namespace Wm4;

//----------------------------------------------------------------------------
PhysicsModule::PhysicsModule ()
{
    Gravity = 0.0;
    Mass = 0.0;
    Friction = 0.0;
    Angle = 0.0;
    m_dTime = 0.0;
    m_dDeltaTime = 0.0;
    memset(m_adState,0,4*sizeof(double));
    memset(m_adAux,0,2*sizeof(double));
    m_pkSolver = 0;
}
//----------------------------------------------------------------------------
PhysicsModule::~PhysicsModule ()
{
    WM4_DELETE m_pkSolver;
}
//----------------------------------------------------------------------------
void PhysicsModule::Initialize (double dTime, double dDeltaTime, double dX,
    double dXDer, double dW, double dWDer)
{
    m_dTime = dTime;
    m_dDeltaTime = dDeltaTime;

    // state variables
    m_adState[0] = dX;
    m_adState[1] = dXDer;
    m_adState[2] = dW;
    m_adState[3] = dWDer;

    // auxiliary variable
    m_adAux[0] = Friction/Mass;
    m_adAux[1] = Gravity*Mathd::Sin(Angle);

    // RK4 differential equation solver.  Since m_pkSolver is a base class
    // pointer, you can instead create a solver of whatever class you prefer.
    WM4_DELETE m_pkSolver;
    m_pkSolver = WM4_NEW OdeRungeKutta4d(4,m_dDeltaTime,OdeFunction,m_adAux);
}
//----------------------------------------------------------------------------
void PhysicsModule::Update ()
{
    assert(m_pkSolver);
    if (!m_pkSolver)
    {
        return;
    }

    // take a single step in the ODE solver
    m_pkSolver->Update(m_dTime,m_adState,m_dTime,m_adState);
}
//----------------------------------------------------------------------------
void PhysicsModule::OdeFunction (double, const double* adState,
    void* pvData, double* adFValue)
{
    double* adAux = (double*)pvData;

    double dVLen = Mathd::Sqrt(adState[1]*adState[1]+adState[3]*adState[3]);
    double dXDotFunction, dWDotFunction;
    if (dVLen > Mathd::ZERO_TOLERANCE)
    {
        double dTemp = -adAux[0]/dVLen;
        dXDotFunction = dTemp*adState[1];
        dWDotFunction = dTemp*adState[3] - adAux[1];
    }
    else
    {
        // velocity is effectively zero, so frictional force is zero
        dXDotFunction = 0.0;
        dWDotFunction = -adAux[1];
    }

    // x function
    adFValue[0] = adState[1];

    // dot(x) function
    adFValue[1] = dXDotFunction;

    // w function
    adFValue[2] = adState[3];

    // dot(w) function
    adFValue[3] = dWDotFunction;
}
//----------------------------------------------------------------------------
