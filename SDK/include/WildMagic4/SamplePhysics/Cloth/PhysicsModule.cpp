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
PhysicsModule::PhysicsModule (int iRows, int iCols, float fStep,
    const Vector3f& rkGravity, const Vector3f& rkWind, float fViscosity,
    float fAmplitude)
    :
    MassSpringSurface3f(iRows,iCols,fStep),
    m_kGravity(rkGravity),
    m_kWind(rkWind)
{
    m_fViscosity = fViscosity;
    m_kDirection = m_kGravity.UnitCross(m_kWind);
    m_fAmplitude = fAmplitude;

    m_afPhase = WM4_NEW float[m_iNumParticles];
    for (int iRow = 0; iRow < m_iRows; iRow++)
    {
        for (int iCol = 0; iCol < m_iCols; iCol++)
        {
            m_afPhase[GetIndex(iRow,iCol)] = Mathf::UnitRandom()*Mathf::PI;
        }
    }
}
//----------------------------------------------------------------------------
PhysicsModule::~PhysicsModule ()
{
    WM4_DELETE[] m_afPhase;
}
//----------------------------------------------------------------------------
Vector3f PhysicsModule::ExternalAcceleration (int i, float fTime,
    const Vector3f*, const Vector3f* akVelocity)
{
    // acceleration due to gravity, wind, and viscosity
    Vector3f kAcceleration = m_kGravity + m_kWind -
        m_fViscosity*akVelocity[i];

    // sinusoidal perturbation
    float fAmplitude = m_fAmplitude*Mathf::Sin(2.0f*fTime+m_afPhase[i]);
    kAcceleration += fAmplitude*m_kDirection;

    return kAcceleration;
}
//----------------------------------------------------------------------------
