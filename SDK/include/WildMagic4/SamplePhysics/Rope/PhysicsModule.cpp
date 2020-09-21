// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "PhysicsModule.h"
using namespace Wm4;

//----------------------------------------------------------------------------
PhysicsModule::PhysicsModule (int iNumParticles, float fStep,
    const Vector3f& rkGravity, const Vector3f& rkWind,
    float fWindChangeAmplitude, float fViscosity)
    :
    MassSpringCurve3f(iNumParticles,fStep),
    m_kGravity(rkGravity),
    m_kWind(rkWind)
{
    m_fWindChangeAmplitude = fWindChangeAmplitude;
    m_fViscosity = fViscosity;
    m_bEnableWind = false;
    m_bEnableWindChange = false;
}
//----------------------------------------------------------------------------
bool& PhysicsModule::EnableWind ()
{
    return m_bEnableWind;
}
//----------------------------------------------------------------------------
bool& PhysicsModule::EnableWindChange ()
{
    return m_bEnableWindChange;
}
//----------------------------------------------------------------------------
Vector3f PhysicsModule::ExternalAcceleration (int i, float, const Vector3f*,
    const Vector3f* akVelocity)
{
    // acceleration due to gravity
    Vector3f kAcceleration = m_kGravity;

    // acceleration due to wind
    if (m_bEnableWind)
    {
        if (m_bEnableWindChange)
        {
            // generate random direction close to last one
            Vector3f kU, kV, kW = m_kWind;
            float fLength = kW.Normalize();
            Vector3f::GenerateComplementBasis(kU,kV,kW);
            float fUDelta = m_fWindChangeAmplitude*Mathf::SymmetricRandom();
            float fVDelta = m_fWindChangeAmplitude*Mathf::SymmetricRandom();
            kW += fUDelta*kU + fVDelta*kV;
            kW.Normalize();
            m_kWind = fLength*kW;
        }
        kAcceleration += m_kWind;
    }

    // Add in a friction term.  Otherwise the system tends to be "stiff"
    // (in the numerical stability sense) and leads to oscillatory behavior.
    kAcceleration -= m_fViscosity*akVelocity[i];

    return kAcceleration;
}
//----------------------------------------------------------------------------
