// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4BOXBVTREE_H
#define WM4BOXBVTREE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4BoundingVolumeTree.h"
#include "Wm4BoxBV.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM BoxBVTree : public BoundingVolumeTree
{
    WM4_DECLARE_INITIALIZE;

public:
    BoxBVTree (const TriMesh* pkMesh, int iMaxTrisPerLeaf = 1,
        bool bStoreInteriorTris = false);

protected:
    static BoundingVolume* CreateModelBound (const TriMesh* pkMesh, int i0,
        int i1, int* aiISplit, Line3f& rkLine);

    static BoundingVolume* CreateWorldBound ();
};

WM4_REGISTER_INITIALIZE(BoxBVTree);

}

#endif
