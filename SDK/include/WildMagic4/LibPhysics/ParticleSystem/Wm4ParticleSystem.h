// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PARTICLESYSTEM_H
#define WM4PARTICLESYSTEM_H

#include "Wm4PhysicsLIB.h"
#include "Wm4Vector2.h"
#include "Wm4Vector3.h"

namespace Wm4
{

template <class Real, class TVector>
class WM4_PHYSICS_ITEM ParticleSystem
{
public:
    // Construction and destruction.  If a particle is to be immovable, set
    // its mass to Math<Real>::MAX_REAL.
    ParticleSystem (int iNumParticles, Real fStep);
    virtual ~ParticleSystem ();

    int GetNumParticles () const;
    void SetMass (int i, Real fMass);
    Real GetMass (int i) const;
    TVector* Positions () const;
    TVector& Position (int i);
    TVector* Velocities () const;
    TVector& Velocity (int i);
    void SetStep (Real fStep);
    Real GetStep () const;

    // Callback for acceleration (ODE solver uses x" = F/m) applied to
    // particle i.  The positions and velocities are not necessarily
    // m_akPosition and m_akVelocity since the ODE solver evaluates the
    // impulse function at intermediate positions.
    virtual TVector Acceleration (int i, Real fTime,
        const TVector* akPosition,  const TVector* akVelocity) = 0;

    // Update the particle positions based on current time and particle state.
    // The Acceleration(...) function is called in this update for each
    // particle.  This function is virtual so that derived classes can
    // perform pre-update and/or post-update semantics.
    virtual void Update (Real fTime);

protected:
    int m_iNumParticles;
    Real* m_afMass;
    Real* m_afInvMass;
    TVector* m_akPosition;
    TVector* m_akVelocity;
    Real m_fStep, m_fHalfStep, m_fSixthStep;

    // temporary storage for solver
    typedef TVector* TVectorPtr;
    TVectorPtr m_akPTmp, m_akDPTmp1, m_akDPTmp2, m_akDPTmp3, m_akDPTmp4;
    TVectorPtr m_akVTmp, m_akDVTmp1, m_akDVTmp2, m_akDVTmp3, m_akDVTmp4;
};

typedef ParticleSystem<float,Vector2f> ParticleSystem2f;
typedef ParticleSystem<double,Vector2d> ParticleSystem2d;
typedef ParticleSystem<float,Vector3f> ParticleSystem3f;
typedef ParticleSystem<double,Vector3d> ParticleSystem3d;

}

#endif
