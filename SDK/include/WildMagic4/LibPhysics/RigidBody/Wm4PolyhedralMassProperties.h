// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4POLYHEDRALMASSPROPERTIES_H
#define WM4POLYHEDRALMASSPROPERTIES_H

#include "Wm4PhysicsLIB.h"
#include "Wm4Matrix3.h"

namespace Wm4
{

// The input triangle mesh must represent a polyhedron.  The triangles are
// represented as triples of indices <V0,V1,V2> into the vertex array.
// The connectivity array has iTQuantity such triples.  The Boolean value
// bBodyCoords is 'true' if you want the inertia tensor to be relative to
// body coordinates, 'false' if you want it in world coordinates.
//
// NOTE:  The code assumes the rigid body has a constant density of 1.
// If your application assigns a constant density of 'd', then you must
// multiply the output rfMass by 'd' and the output rkInertia by 'd'.

template <class Real> WM4_PHYSICS_ITEM
void ComputeMassProperties (const Vector3<Real>* akVertex, int iTQuantity,
    const int* aiIndex, bool bBodyCoords, Real& rfMass,
    Vector3<Real>& rkCenter, Matrix3<Real>& rkInertia);

}

#endif
