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
PhysicsModule::PhysicsModule (int iSlices, int iRows, int iCols, float fStep,
    float fViscosity)
    :
    MassSpringVolume3f(iSlices,iRows,iCols,fStep)
{
    m_fViscosity = fViscosity;
}
//----------------------------------------------------------------------------
PhysicsModule::~PhysicsModule ()
{
}
//----------------------------------------------------------------------------
float& PhysicsModule::Viscosity ()
{
    return m_fViscosity;
}
//----------------------------------------------------------------------------
Vector3f PhysicsModule::ExternalAcceleration (int i, float, const Vector3f*,
    const Vector3f* akVelocity)
{
    Vector3f kAcceleration = -m_fViscosity*akVelocity[i];
    return kAcceleration;
}
//----------------------------------------------------------------------------
