// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4EXTREMALQUERY3PRJ_H
#define WM4EXTREMALQUERY3PRJ_H

#include "Wm4PhysicsLIB.h"
#include "Wm4ExtremalQuery3.h"

namespace Wm4
{

template <class Real>
class WM4_PHYSICS_ITEM ExtremalQuery3PRJ : public ExtremalQuery3<Real>
{
public:
    ExtremalQuery3PRJ (const ConvexPolyhedron3<Real>& rkPolytope);
    virtual ~ExtremalQuery3PRJ ();

    // Compute the extreme vertices in the specified direction and return the
    // indices of the vertices in the polyhedron vertex array.
    virtual void GetExtremeVertices (const Vector3<Real>& rkDirection,
        int& riPositiveDirection, int& riNegativeDirection);

private:
    using ExtremalQuery3<Real>::m_pkPolytope;

    Vector3<Real> m_kCentroid;
};

typedef ExtremalQuery3PRJ<float> ExtremalQuery3PRJf;
typedef ExtremalQuery3PRJ<double> ExtremalQuery3PRJd;

}

#endif
