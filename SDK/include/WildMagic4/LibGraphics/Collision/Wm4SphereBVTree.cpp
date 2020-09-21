// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4SphereBVTree.h"
#include "Wm4ApprLineFit3.h"
#include "Wm4ContSphere3.h"
using namespace Wm4;

WM4_IMPLEMENT_INITIALIZE(SphereBVTree);

//----------------------------------------------------------------------------
void SphereBVTree::Initialize ()
{
    ms_aoCreateModelBound[BoundingVolume::BV_SPHERE] =
        &SphereBVTree::CreateModelBound;

    ms_aoCreateWorldBound[BoundingVolume::BV_SPHERE] =
        &SphereBVTree::CreateWorldBound;
}
//----------------------------------------------------------------------------
SphereBVTree::SphereBVTree (const TriMesh* pkMesh, int iMaxTrisPerLeaf,
    bool bStoreInteriorTris)
    :
    BoundingVolumeTree(BoundingVolume::BV_SPHERE,pkMesh,iMaxTrisPerLeaf,
        bStoreInteriorTris)
{
}
//----------------------------------------------------------------------------
BoundingVolume* SphereBVTree::CreateModelBound (const TriMesh* pkMesh, int i0,
    int i1, int* aiISplit, Line3f& rkLine)
{
    // Tag vertices that are used in the submesh.
    int iVQuantity = pkMesh->VBuffer->GetVertexQuantity();
    const int* aiIndex = pkMesh->IBuffer->GetData();
    bool* abValid = WM4_NEW bool[iVQuantity];
    memset(abValid,0,iVQuantity*sizeof(bool));
    int i;
    for (i = i0; i <= i1; i++)
    {
        int j = 3*aiISplit[i];
        abValid[aiIndex[j++]] = true;
        abValid[aiIndex[j++]] = true;
        abValid[aiIndex[j++]] = true;
    }

    // Create a contiguous set of vertices in the submesh.
    std::vector<Vector3f> kMeshVertices;
    for (i = 0; i < iVQuantity; i++)
    {
        if (abValid[i])
        {
            kMeshVertices.push_back(pkMesh->VBuffer->Position3(i));
        }
    }
    WM4_DELETE[] abValid;

    SphereBV* pkModelBound = WM4_NEW SphereBV;
    pkModelBound->Sphere() = ContSphereAverage<float>(
        (int)kMeshVertices.size(),&kMeshVertices.front());

    rkLine = OrthogonalLineFit3<float>((int)kMeshVertices.size(),
        &kMeshVertices.front());
    return pkModelBound;
}
//----------------------------------------------------------------------------
BoundingVolume* SphereBVTree::CreateWorldBound ()
{
    return WM4_NEW SphereBV;
}
//----------------------------------------------------------------------------
