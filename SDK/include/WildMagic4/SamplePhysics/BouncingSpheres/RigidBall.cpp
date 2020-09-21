// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "RigidBall.h"
#include "Wm4StandardMesh.h"
#include "Wm4TextureEffect.h"

//----------------------------------------------------------------------------
RigidBall::RigidBall (float fRadius)
{
    m_fRadius = fRadius;
    Moved = false;

    Attributes kAttr;
    kAttr.SetPositionChannels(3);
    kAttr.SetTCoordChannels(0,2);
    m_spkMesh = StandardMesh(kAttr).Sphere(16,16,m_fRadius);

    m_spkMesh->AttachEffect(WM4_NEW TextureEffect("BallTexture"));
}
//----------------------------------------------------------------------------
float RigidBall::GetRadius () const
{ 
    return m_fRadius; 
}
//----------------------------------------------------------------------------
TriMeshPtr& RigidBall::Mesh ()
{
    return m_spkMesh;
}
//----------------------------------------------------------------------------
