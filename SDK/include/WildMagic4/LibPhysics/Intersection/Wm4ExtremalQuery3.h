// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4EXTREMALQUERY3_H
#define WM4EXTREMALQUERY3_H

#include "Wm4PhysicsLIB.h"
#include "Wm4ConvexPolyhedron3.h"

namespace Wm4
{

template <class Real>
class WM4_PHYSICS_ITEM ExtremalQuery3
{
public:
    // Abstract base class.
    virtual ~ExtremalQuery3 ();

    // Compute the extreme vertices in the specified direction and return the
    // indices of the vertices in the polyhedron vertex array.
    virtual void GetExtremeVertices (const Vector3<Real>& rkDirection,
        int& riPositiveDirection, int& riNegativeDirection) = 0;

    const ConvexPolyhedron3<Real>& GetPolytope () const;
    const Vector3<Real>* GetFaceNormals () const;

protected:
    ExtremalQuery3 (const ConvexPolyhedron3<Real>& rkPolytope);

    const ConvexPolyhedron3<Real>* m_pkPolytope;
    Vector3<Real>* m_akFaceNormal;
};

typedef ExtremalQuery3<float> ExtremalQuery3f;
typedef ExtremalQuery3<double> ExtremalQuery3d;

}

#endif
