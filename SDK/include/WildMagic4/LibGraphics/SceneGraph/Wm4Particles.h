// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PARTICLES_H
#define WM4PARTICLES_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TriMesh.h"
#include "Wm4FloatArray.h"

namespace Wm4
{

class Camera;
class Culler;

class WM4_GRAPHICS_ITEM Particles : public TriMesh
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // construction and destruction
    Particles (const Attributes& rkAttr, Vector3fArray* pkLocations,
        FloatArray* pkSizes);
    virtual ~Particles ();

    // data members
    Vector3fArrayPtr Locations;
    FloatArrayPtr Sizes;
    float SizeAdjust;

    void SetActiveQuantity (int iActiveQuantity);
    int GetActiveQuantity () const;

protected:
    Particles ();

    // The particles are billboards that always face the camera.
    void GenerateParticles (const Camera* pkCamera);

    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    // Allow application to specify fewer than the maximum number of vertices
    // to draw.
    int m_iActiveQuantity;
};

WM4_REGISTER_STREAM(Particles);
typedef Pointer<Particles> ParticlesPtr;
#include "Wm4Particles.inl"

}

#endif
