// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef RIGIDTETRA_H
#define RIGIDTETRA_H

#include "Wm4RigidBody.h"
#include "Wm4TriMesh.h"
using namespace Wm4;

class RigidTetra : public RigidBodyf
{
public:
    RigidTetra (float fSize, float fMass, const Vector3f& rkPos,
        const Vector3f& rkLinMom, const Vector3f& rkAngMom);

    TriMeshPtr Mesh () const;
    float GetRadius () const;
    void GetVertices (Vector3f* akVertex) const;

    bool Moved;

private:
    TriMeshPtr m_spkMesh;
    float m_fRadius;
};

#endif
