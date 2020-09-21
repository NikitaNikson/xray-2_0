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
    Length = 0.0;
    Inertia1 = 0.0;
    Inertia3 = 0.0;
    m_dTime = 0.0;
    m_dDeltaTime = 0.0;
    memset(m_adState,0,3*sizeof(double));
    memset(m_adAux,0,5*sizeof(double));
    m_pkSolver = 0;
}
//----------------------------------------------------------------------------
PhysicsModule::~PhysicsModule ()
{
    WM4_DELETE m_pkSolver;
}
//----------------------------------------------------------------------------
void PhysicsModule::Initialize (double dTime, double dDeltaTime,
    double dTheta, double dPhi, double dPsi, double dAngVel1,
    double dAngVel2, double dAngVel3)
{
    m_dTime = dTime;
    m_dDeltaTime = dDeltaTime;

    double dCosPhi = Mathd::Cos(dPhi), dSinPhi = Mathd::Sin(dPhi);
    double dCosPsi = Mathd::Cos(dPsi), dSinPsi = Mathd::Sin(dPsi);

    // state variables
    m_adState[0] = dTheta;
    m_adState[1] = dPhi;
    m_adState[2] = dPsi;

    // auxiliary variables
    m_adAux[0] = Mass*Gravity*Length/Inertia1;  // alpha
    m_adAux[1] = dAngVel1*dAngVel1 + dAngVel2*dAngVel2 +
        2.0*dCosPhi*m_adAux[0];  // beta
    m_adAux[2] = dAngVel3*Inertia3/Inertia1;  // epsilon
    m_adAux[3] = dSinPhi*(dAngVel1*dSinPsi+dAngVel2*dCosPsi) +
        dCosPhi*m_adAux[2];  // delta
    m_adAux[4] = dAngVel3;

    // RK4 differential equation solver.  Since m_pkSolver is a base class
    // pointer, you can instead create a solver of whatever class you prefer.
    WM4_DELETE m_pkSolver;
    m_pkSolver = WM4_NEW OdeRungeKutta4d(3,m_dDeltaTime,OdeFunction,m_adAux);
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
Matrix3f PhysicsModule::GetBodyAxes () const
{
    float fCosTheta = (float)Mathd::Cos(m_adState[0]);
    float fSinTheta = (float)Mathd::Sin(m_adState[0]);
    float fCosPhi = (float)Mathd::Cos(m_adState[1]);
    float fSinPhi = (float)Mathd::Sin(m_adState[1]);
    float fCosPsi = (float)Mathd::Cos(m_adState[2]);
    float fSinPsi = (float)Mathd::Sin(m_adState[2]);

    Vector3f kN(fCosTheta,fSinTheta,0.0f);
    Vector3f kAxis3(fSinTheta*fSinPhi,-fCosTheta*fSinPhi,fCosPhi);
    Vector3f kAxis3xN = kAxis3.Cross(kN);
    Vector3f kAxis1 = fCosPsi*kN + fSinPsi*kAxis3xN;
    Vector3f kAxis2 = fCosPsi*kAxis3xN - fSinPsi*kN;

    return Matrix3f(kAxis1,kAxis2,kAxis3,true);
}
//----------------------------------------------------------------------------
void PhysicsModule::OdeFunction (double, const double* adState,
    void* pvData, double* adFValue)
{
    double* adAux = (double*)pvData;

    double dCos = Mathd::Cos(adState[1]);
    double dInvSin = 1.0/Mathd::Sin(adState[1]);
    double dNumer = adAux[3] - adAux[2]*dCos;
    double dFraction = dNumer*dInvSin;
    double dArg = adAux[1] - 2.0*adAux[0]*dCos - dFraction*dFraction;
    double dThetaDotFunction = dFraction*dInvSin;
    double dPhiDotFunction = Mathd::Sqrt(Mathd::FAbs(dArg));
    double dPsiDotFunction = adAux[4] - dCos*dThetaDotFunction;

    // dot(theta) function
    adFValue[0] = dThetaDotFunction;

    // dot(phi) function
    adFValue[1] = dPhiDotFunction;

    // dot(psi) function
    adFValue[2] = dPsiDotFunction;
}
//----------------------------------------------------------------------------
