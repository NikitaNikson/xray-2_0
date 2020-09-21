// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4COLLISIONRECORD_H
#define WM4COLLISIONRECORD_H

#include "Wm4GraphicsLIB.h"
#include "Wm4BoundingVolumeTree.h"
#include "Wm4Intersector.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CollisionRecord
{
public:
    typedef void (*Callback) (CollisionRecord& rkRecord0, int iT0,
        CollisionRecord& rkRecord1, int iT1,
        Intersector<float,Vector3f>* pkIntersector);

    // Construction and destruction.  CollisionRecord assumes responsibility
    // for deleting pkTree, so it should be dynamically allocated.
    CollisionRecord (TriMesh* pkMesh, BoundingVolumeTree* pkTree,
        Vector3f* pkVelocity, Callback oCallback, void* pvCallbackData);

    ~CollisionRecord ();

    // member access
    TriMesh* GetMesh ();
    Vector3f* GetVelocity ();
    void* GetCallbackData ();

    // intersection queries
    void TestIntersection (CollisionRecord& rkRecord);
    void FindIntersection (CollisionRecord& rkRecord);
    void TestIntersection (float fTMax, CollisionRecord& rkRecord);
    void FindIntersection (float fTMax ,CollisionRecord& rkRecord);

protected:
    TriMesh* m_pkMesh;
    BoundingVolumeTree* m_pkTree;
    Vector3f* m_pkVelocity;
    Callback m_oCallback;
    void* m_pvCallbackData;
};

#include "Wm4CollisionRecord.inl"

}

#endif
