// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PARTICLECONTROLLER_H
#define WM4PARTICLECONTROLLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Controller.h"
#include "Wm4Particles.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ParticleController : public Controller
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    virtual ~ParticleController ();

    // The system motion, in local coordinates.  The velocity vectors should
    // be unit length.
    float SystemLinearSpeed;
    float SystemAngularSpeed;
    Vector3f SystemLinearAxis;
    Vector3f SystemAngularAxis;

    // Point motion, in the model space of the system.  The velocity vectors
    // should be unit length.  In applications where the points represent a
    // rigid body, you might choose the origin of the system to be the center
    // of mass of the points and the coordinate axes to correspond to the
    // principal directions of the inertia tensor.
    float* PointLinearSpeed ();
    Vector3f* PointLinearAxis ();

    // size change parameters
    float SystemSizeChange;
    float* PointSizeChange ();

    // animation update
    virtual bool Update (double dAppTime);

protected:
    // streaming support
    ParticleController ();

    // for deferred allocation of the point motion arrays
    void Reallocate (int iVertexQuantity);
    virtual void SetObject (Object* pkObject);

    // update the motion parameters
    virtual void UpdateSystemMotion (float fCtrlTime);
    virtual void UpdatePointMotion (float fCtrlTime);

    // point motion (in model space of system)
    int m_iLQuantity;
    float* m_afPointLinearSpeed;
    Vector3f* m_akPointLinearAxis;

    // size change parameters
    float* m_afPointSizeChange;
};

WM4_REGISTER_STREAM(ParticleController);
typedef Pointer<ParticleController> ParticleControllerPtr;
#include "Wm4ParticleController.inl"

}

#endif
