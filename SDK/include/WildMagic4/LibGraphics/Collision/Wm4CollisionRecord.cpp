// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4CollisionRecord.h"
#include "Wm4IntrTriangle3Triangle3.h"
using namespace Wm4;

//----------------------------------------------------------------------------
CollisionRecord::CollisionRecord (TriMesh* pkMesh, BoundingVolumeTree* pkTree,
    Vector3f* pkVelocity, Callback oCallback, void* pvCallbackData)
{
    assert(pkMesh && pkTree);

    m_pkMesh = pkMesh;
    m_pkTree = pkTree;
    m_pkVelocity = pkVelocity;
    m_oCallback = oCallback;
    m_pvCallbackData = pvCallbackData;
}
//----------------------------------------------------------------------------
CollisionRecord::~CollisionRecord ()
{
    WM4_DELETE m_pkTree;
}
//----------------------------------------------------------------------------
void CollisionRecord::TestIntersection (CollisionRecord& rkRecord)
{
    // convenience variables
    BoundingVolumeTree* pkTree0 = m_pkTree;
    BoundingVolumeTree* pkTree1 = rkRecord.m_pkTree;
    const TriMesh* pkMesh0 = m_pkTree->GetMesh();
    const TriMesh* pkMesh1 = rkRecord.m_pkTree->GetMesh();

    pkTree0->UpdateWorldBound();
    pkTree1->UpdateWorldBound();

    const BoundingVolume* pkWorldBV0 = pkTree0->GetWorldBound();
    const BoundingVolume* pkWorldBV1 = pkTree1->GetWorldBound();
    if (pkWorldBV0->TestIntersection(pkWorldBV1))
    {
        BoundingVolumeTree* pkRoot;

        if (pkTree0->IsInteriorNode())
        {
            pkRoot = m_pkTree;

            // compare Tree0.L to Tree1
            m_pkTree = pkRoot->GetLChild();
            TestIntersection(rkRecord);

            // compare Tree0.R to Tree1
            m_pkTree = pkRoot->GetRChild();
            TestIntersection(rkRecord);

            m_pkTree = pkRoot;
        }
        else if (pkTree1->IsInteriorNode())
        {
            pkRoot = rkRecord.m_pkTree;

            // compare Tree0 to Tree1.L
            rkRecord.m_pkTree = pkRoot->GetLChild();
            TestIntersection(rkRecord);

            // compare Tree0 to Tree1.R
            rkRecord.m_pkTree = pkRoot->GetRChild();
            TestIntersection(rkRecord);

            rkRecord.m_pkTree = pkRoot;
        }
        else
        {
            // at a leaf in each tree
            int iMax0 = pkTree0->GetTriangleQuantity();
            for (int i0 = 0; i0 < iMax0; i0++)
            {
                int iT0 = pkTree0->GetTriangle(i0);

                // get world space triangle
                Triangle3f kTri0;
                pkMesh0->GetWorldTriangle(iT0,kTri0);

                int iMax1 = pkTree1->GetTriangleQuantity();
                for (int i1 = 0; i1 < iMax1; i1++)
                {
                    int iT1 = pkTree1->GetTriangle(i1);

                    // get world space triangle
                    Triangle3f kTri1;
                    pkMesh1->GetWorldTriangle(iT1,kTri1);

                    IntrTriangle3Triangle3<float> kIntersector(kTri0,kTri1);
                    if (kIntersector.Test())
                    {
                        if (m_oCallback)
                        {
                            m_oCallback(*this,iT0,rkRecord,iT1,&kIntersector);
                        }

                        if (rkRecord.m_oCallback)
                        {
                            rkRecord.m_oCallback(rkRecord,iT1,*this,iT0,
                                &kIntersector);
                        }
                    }
                }
            }
        }
    }
}
//----------------------------------------------------------------------------
void CollisionRecord::FindIntersection (CollisionRecord& rkRecord)
{
    // convenience variables
    BoundingVolumeTree* pkTree0 = m_pkTree;
    BoundingVolumeTree* pkTree1 = rkRecord.m_pkTree;
    const TriMesh* pkMesh0 = m_pkTree->GetMesh();
    const TriMesh* pkMesh1 = rkRecord.m_pkTree->GetMesh();

    pkTree0->UpdateWorldBound();
    pkTree1->UpdateWorldBound();

    const BoundingVolume* pkWorldBV0 = pkTree0->GetWorldBound();
    const BoundingVolume* pkWorldBV1 = pkTree1->GetWorldBound();
    if (pkWorldBV0->TestIntersection(pkWorldBV1))
    {
        BoundingVolumeTree* pkRoot;

        if (pkTree0->IsInteriorNode())
        {
            pkRoot = m_pkTree;

            // compare Tree0.L to Tree1
            m_pkTree = pkRoot->GetLChild();
            FindIntersection(rkRecord);

            // compare Tree0.R to Tree1
            m_pkTree = pkRoot->GetRChild();
            FindIntersection(rkRecord);

            m_pkTree = pkRoot;
        }
        else if (pkTree1->IsInteriorNode())
        {
            pkRoot = rkRecord.m_pkTree;

            // compare Tree0 to Tree1.L
            rkRecord.m_pkTree = pkRoot->GetLChild();
            FindIntersection(rkRecord);

            // compare Tree0 to Tree1.R
            rkRecord.m_pkTree = pkRoot->GetRChild();
            FindIntersection(rkRecord);

            rkRecord.m_pkTree = pkRoot;
        }
        else
        {
            // at a leaf in each tree
            int iMax0 = pkTree0->GetTriangleQuantity();
            for (int i0 = 0; i0 < iMax0; i0++)
            {
                int iT0 = pkTree0->GetTriangle(i0);

                // get world space triangle
                Triangle3f kTri0;
                pkMesh0->GetWorldTriangle(iT0,kTri0);

                int iMax1 = pkTree1->GetTriangleQuantity();
                for (int i1 = 0; i1 < iMax1; i1++)
                {
                    int iT1 = pkTree1->GetTriangle(i1);

                    // get world space triangle
                    Triangle3f kTri1;
                    pkMesh1->GetWorldTriangle(iT1,kTri1);

                    IntrTriangle3Triangle3<float> kIntersector(kTri0,kTri1);
                    if (kIntersector.Find())
                    {
                        if (m_oCallback)
                        {
                            m_oCallback(*this,iT0,rkRecord,iT1,&kIntersector);
                        }

                        if (rkRecord.m_oCallback)
                        {
                            rkRecord.m_oCallback(rkRecord,iT1,*this,iT0,
                                &kIntersector);
                        }
                    }
                }
            }
        }
    }
}
//----------------------------------------------------------------------------
void CollisionRecord::TestIntersection (float fTMax,
    CollisionRecord& rkRecord)
{
    // convenience variables
    BoundingVolumeTree* pkTree0 = m_pkTree;
    BoundingVolumeTree* pkTree1 = rkRecord.m_pkTree;
    const TriMesh* pkMesh0 = m_pkTree->GetMesh();
    const TriMesh* pkMesh1 = rkRecord.m_pkTree->GetMesh();
    const Vector3f& rkVelocity0 = (m_pkVelocity ? *m_pkVelocity :
        Vector3f::ZERO);
    const Vector3f& rkVelocity1 = (rkRecord.m_pkVelocity ?
        *rkRecord.m_pkVelocity : Vector3f::ZERO);

    pkTree0->UpdateWorldBound();
    pkTree1->UpdateWorldBound();

    const BoundingVolume* pkWorldBV0 = pkTree0->GetWorldBound();
    const BoundingVolume* pkWorldBV1 = pkTree1->GetWorldBound();

    if (pkWorldBV0->TestIntersection(pkWorldBV1,fTMax,rkVelocity0,
        rkVelocity1))
    {
        BoundingVolumeTree* pkRoot;

        if (pkTree0->IsInteriorNode())
        {
            pkRoot = m_pkTree;

            // compare Tree0.L to Tree1
            m_pkTree = pkRoot->GetLChild();
            TestIntersection(fTMax,rkRecord);

            // compare Tree0.R to Tree1
            m_pkTree = pkRoot->GetRChild();
            TestIntersection(fTMax,rkRecord);

            m_pkTree = pkRoot;
        }
        else if (pkTree1->IsInteriorNode())
        {
            pkRoot = rkRecord.m_pkTree;

            // compare Tree0 to Tree1.L
            rkRecord.m_pkTree = pkRoot->GetLChild();
            TestIntersection(fTMax,rkRecord);

            // compare Tree0 to Tree1.R
            rkRecord.m_pkTree = pkRoot->GetRChild();
            TestIntersection(fTMax,rkRecord);

            rkRecord.m_pkTree = pkRoot;
        }
        else
        {
            // at a leaf in each tree
            int iMax0 = pkTree0->GetTriangleQuantity();
            for (int i0 = 0; i0 < iMax0; i0++)
            {
                int iT0 = pkTree0->GetTriangle(i0);

                // get world space triangle
                Triangle3f kTri0;
                pkMesh0->GetWorldTriangle(iT0,kTri0);

                int iMax1 = pkTree1->GetTriangleQuantity();
                for (int i1 = 0; i1 < iMax1; i1++)
                {
                    int iT1 = pkTree1->GetTriangle(i1);

                    // get world space triangle
                    Triangle3f kTri1;
                    pkMesh1->GetWorldTriangle(iT1,kTri1);

                    IntrTriangle3Triangle3<float> kIntersector(kTri0,kTri1);
                    if (kIntersector.Test(fTMax,rkVelocity0,rkVelocity1))
                    {
                        if (m_oCallback)
                        {
                            m_oCallback(*this,iT0,rkRecord,iT1,&kIntersector);
                        }

                        if (rkRecord.m_oCallback)
                        {
                            rkRecord.m_oCallback(rkRecord,iT1,*this,iT0,
                                &kIntersector);
                        }
                    }
                }
            }
        }
    }
}
//----------------------------------------------------------------------------
void CollisionRecord::FindIntersection (float fTMax,
    CollisionRecord& rkRecord)
{
    // convenience variables
    BoundingVolumeTree* pkTree0 = m_pkTree;
    BoundingVolumeTree* pkTree1 = rkRecord.m_pkTree;
    const TriMesh* pkMesh0 = m_pkTree->GetMesh();
    const TriMesh* pkMesh1 = rkRecord.m_pkTree->GetMesh();
    const Vector3f& rkVelocity0 = (m_pkVelocity ? *m_pkVelocity :
        Vector3f::ZERO);
    const Vector3f& rkVelocity1 = (rkRecord.m_pkVelocity ?
        *rkRecord.m_pkVelocity : Vector3f::ZERO);

    pkTree0->UpdateWorldBound();
    pkTree1->UpdateWorldBound();

    const BoundingVolume* pkWorldBV0 = pkTree0->GetWorldBound();
    const BoundingVolume* pkWorldBV1 = pkTree1->GetWorldBound();

    if (pkWorldBV0->TestIntersection(pkWorldBV1,fTMax,rkVelocity0,
        rkVelocity1))
    {
        BoundingVolumeTree* pkRoot;

        if (pkTree0->IsInteriorNode())
        {
            pkRoot = m_pkTree;

            // compare Tree0.L to Tree1
            m_pkTree = pkRoot->GetLChild();
            FindIntersection(fTMax,rkRecord);

            // compare Tree0.R to Tree1
            m_pkTree = pkRoot->GetRChild();
            FindIntersection(fTMax,rkRecord);

            m_pkTree = pkRoot;
        }
        else if ( pkTree1->IsInteriorNode() )
        {
            pkRoot = rkRecord.m_pkTree;

            // compare Tree0 to Tree1.L
            rkRecord.m_pkTree = pkRoot->GetLChild();
            FindIntersection(fTMax,rkRecord);

            // compare Tree0 to Tree1.R
            rkRecord.m_pkTree = pkRoot->GetRChild();
            FindIntersection(fTMax,rkRecord);

            rkRecord.m_pkTree = pkRoot;
        }
        else
        {
            // at a leaf in each tree
            int iMax0 = pkTree0->GetTriangleQuantity();
            for (int i0 = 0; i0 < iMax0; i0++)
            {
                int iT0 = pkTree0->GetTriangle(i0);

                // get world space triangle
                Triangle3f kTri0;
                pkMesh0->GetWorldTriangle(iT0,kTri0);

                int iMax1 = pkTree1->GetTriangleQuantity();
                for (int i1 = 0; i1 < iMax1; i1++)
                {
                    int iT1 = pkTree1->GetTriangle(i1);

                    // get world space triangle
                    Triangle3f kTri1;
                    pkMesh1->GetWorldTriangle(iT1,kTri1);

                    IntrTriangle3Triangle3<float> kIntersector(kTri0,kTri1);
                    if (kIntersector.Find(fTMax,rkVelocity0,rkVelocity1))
                    {
                        if (m_oCallback)
                        {
                            m_oCallback(*this,iT0,rkRecord,iT1,&kIntersector);
                        }

                        if (rkRecord.m_oCallback)
                        {
                            rkRecord.m_oCallback(rkRecord,iT1,*this,iT0,
                                &kIntersector);
                        }
                    }
                }
            }
        }
    }
}
//----------------------------------------------------------------------------
