// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Polysolid2.h"
#include "SegmentEdge.h"
#include "Segmentation.h"

//----------------------------------------------------------------------------
Polysolid2::Polysolid2 ()
{
}
//----------------------------------------------------------------------------
Polysolid2::Polysolid2 (const Polysolid2& rkPoly)
{
    *this = rkPoly;
}
//----------------------------------------------------------------------------
Polysolid2::~Polysolid2 ()
{
    VMap::iterator pkIter;
    for (pkIter = m_kVMap.begin(); pkIter != m_kVMap.end(); pkIter++)
    {
        Vertex* pkVertex = pkIter->second;
        WM4_DELETE pkVertex;
    }
}
//----------------------------------------------------------------------------
Polysolid2& Polysolid2::operator= (const Polysolid2& rkPoly)
{
    m_kVMap.clear();
    m_kESet.clear();

    ESet::const_iterator pkIter = rkPoly.m_kESet.begin();
    for (/**/; pkIter != rkPoly.m_kESet.end(); pkIter++)
    {
        const Vertex* pkV0 = pkIter->GetVertex(0);
        const Vertex* pkV1 = pkIter->GetVertex(1);
        InsertEdge(pkV0->Position,pkV1->Position);
    }

    return *this;
}
//----------------------------------------------------------------------------
const Polysolid2::VMap& Polysolid2::GetVertices () const
{
    return m_kVMap;
}
//----------------------------------------------------------------------------
const Polysolid2::ESet& Polysolid2::GetEdges () const
{
    return m_kESet;
}
//----------------------------------------------------------------------------
void Polysolid2::InsertEdge (const RPoint2& rkPoint0, const RPoint2& rkPoint1)
{
    // Insert vertices into the vertex set.  If the points already exist,
    // the function call is just a look up.  Otherwise, new vertices are
    // allocated.
    Vertex* pkVertex0 = InsertVertex(rkPoint0);
    Vertex* pkVertex1 = InsertVertex(rkPoint1);

    Edge kEdge(pkVertex0,pkVertex1);
    std::set<Edge>::iterator pkIter = m_kESet.find(kEdge);
    if (pkIter == m_kESet.end())
    {
        // The edge does not exist, insert it into the set.
        m_kESet.insert(kEdge);

        // Update the vertex-adjacency information.
        pkVertex0->InsertAdjacent(pkVertex1);
        pkVertex1->InsertAdjacent(pkVertex0);
    }
}
//----------------------------------------------------------------------------
Polysolid2 Polysolid2::operator& (const Polysolid2& rkPoly) const
{
    // intersection, P AND Q

    // segment the polysolids
    SegmentEdge akTEdgeL[4], akTEdgeR[4];
    SegmentAll(rkPoly,akTEdgeR);
    rkPoly.SegmentAll(*this,akTEdgeL);

    // all ITAG edges are in the intersection
    akTEdgeL[ITAG].MergeAppend(akTEdgeR[ITAG]);

    // all PTAG edges are in the intersection, avoid duplicates
    akTEdgeL[PTAG].MergeUnique(akTEdgeR[PTAG]);

    // final merge
    akTEdgeL[ITAG].MergeAppend(akTEdgeL[PTAG]);

    // convert segment edges to a polysolid
    Polysolid2 kResult;
    akTEdgeL[ITAG].ConvertToPolySolid(kResult);

    return kResult;
}
//----------------------------------------------------------------------------
Polysolid2 Polysolid2::operator| (const Polysolid2& rkPoly) const
{
    // union, P OR Q

    // segment the polysolids
    SegmentEdge akTEdgeL[4], akTEdgeR[4];
    SegmentAll(rkPoly,akTEdgeR);
    rkPoly.SegmentAll(*this,akTEdgeL);

    // all OTAG edges are in the union
    akTEdgeL[OTAG].MergeAppend(akTEdgeR[OTAG]);

    // all MTAG-MTAG edges are in the union
    akTEdgeL[MTAG].MergeEqual(akTEdgeR[MTAG]);

    // all PTAG-PTAG edges are in the union
    akTEdgeL[PTAG].MergeEqual(akTEdgeR[PTAG]);

    // final merge
    akTEdgeL[OTAG].MergeAppend(akTEdgeL[MTAG]);
    akTEdgeL[OTAG].MergeAppend(akTEdgeL[PTAG]);

    // convert segment edges to a polysolid
    Polysolid2 kResult;
    akTEdgeL[OTAG].ConvertToPolySolid(kResult);

    return kResult;
}
//----------------------------------------------------------------------------
Polysolid2 Polysolid2::operator- (const Polysolid2& rkPoly) const
{
    // difference, P-Q = P AND -Q

    // segment the polysolids
    SegmentEdge akTEdgeL[4], akTEdgeR[4];
    SegmentAll(rkPoly,akTEdgeR);
    rkPoly.SegmentAll(*this,akTEdgeL);

    // all OTAG edges of P and ITAG edges of Q are in the difference
    akTEdgeL[OTAG].MergeAppendReverse(akTEdgeR[ITAG]);

    // all PTAG edges are in the difference, avoid duplicates
    akTEdgeL[MTAG].MergeUniqueReverse(akTEdgeR[PTAG]);

    // final merge
    akTEdgeL[OTAG].MergeAppend(akTEdgeL[MTAG]);

    // convert segment edges to a polysolid
    Polysolid2 kResult;
    akTEdgeL[OTAG].ConvertToPolySolid(kResult);

    return kResult;
}
//----------------------------------------------------------------------------
Polysolid2 Polysolid2::operator^ (const Polysolid2& rkPoly) const
{
    // exclusive or, P XOR Q = (P-Q) OR (Q-P)
    return (*this - rkPoly) | (rkPoly - *this);
}
//----------------------------------------------------------------------------
Polysolid2::Vertex* Polysolid2::GetVertex (const RPoint2& rkPoint)
{
    VMap::iterator pkIter = m_kVMap.find(rkPoint);
    if (pkIter != m_kVMap.end())
    {
        return pkIter->second;
    }

    return 0;
}
//----------------------------------------------------------------------------
Polysolid2::Vertex* Polysolid2::InsertVertex (const RPoint2& rkPoint)
{
    VMap::iterator pkIter = m_kVMap.find(rkPoint);
    if (pkIter != m_kVMap.end())
    {
        return pkIter->second;
    }

    // Insert the vertex into the vertex set.  The adjacency array has already
    // been initialized to empty.
    Vertex* pkVertex = WM4_NEW Vertex;
    pkVertex->Position = rkPoint;
    m_kVMap[rkPoint] = pkVertex;
    return pkVertex;
}
//----------------------------------------------------------------------------
void Polysolid2::SegmentAll (const Polysolid2& rkPoly,
    SegmentEdge akTEdge[4]) const
{
    ESet::const_iterator pkIter = rkPoly.m_kESet.begin();
    for (/**/; pkIter != rkPoly.m_kESet.end(); pkIter++)
    {
        const Vertex* pkV0 = pkIter->GetVertex(0);
        const Vertex* pkV1 = pkIter->GetVertex(1);

        // construct line containing edge
        const RPoint2& rkPosition0 = pkV0->Position;
        const RPoint2& rkPosition1 = pkV1->Position;
        RPoint2 kDiff = rkPosition1 - rkPosition0;
        RPoint2 kNormal = kDiff.Perp();
        Rational kConstant = kNormal.Dot(rkPosition0);

        // segment line against 'this' polygon
        Segmentation kSeg(kNormal,kConstant);
        kSeg.SegmentBy(*this);

        if (kSeg.HasPoints())
        {
            // compute intersection of edge and segmentation
            assert(rkPosition0 != rkPosition1);
            kSeg.IntersectWith(rkPosition0,rkPosition1);

            if (kSeg.HasPoints())
            {
                // compute tagged edge lists
                kSeg.ConvertToEdges(akTEdge);
            }
        }

        if (!kSeg.HasPoints())
        {
            // line of edge did not intersect 'this', so must be outside
            akTEdge[OTAG].AddEdge(rkPosition0,rkPosition1);
        }
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Polysolid2::Vertex
//----------------------------------------------------------------------------
Polysolid2::Vertex::Vertex ()
{
}
//----------------------------------------------------------------------------
Polysolid2::Vertex::~Vertex ()
{
}
//----------------------------------------------------------------------------
void Polysolid2::Vertex::InsertAdjacent (Vertex* pkAdjacent)
{
    Adjacent.push_back(pkAdjacent);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Polysolid2::Edge
//----------------------------------------------------------------------------
Polysolid2::Edge::Edge ()
{
    m_apkV[0] = 0;
    m_apkV[1] = 0;
}
//----------------------------------------------------------------------------
Polysolid2::Edge::Edge (Vertex* pkV0, Vertex* pkV1)
{
    SetVertices(pkV0,pkV1);
}
//----------------------------------------------------------------------------
void Polysolid2::Edge::SetVertices (Vertex* pkV0, Vertex* pkV1)
{
    if (pkV0 < pkV1)
    {
        // v0 is minimum
        m_apkV[0] = pkV0;
        m_apkV[1] = pkV1;
    }
    else
    {
        // v1 is minimum
        m_apkV[0] = pkV1;
        m_apkV[1] = pkV0;
    }
}
//----------------------------------------------------------------------------
Polysolid2::Vertex* Polysolid2::Edge::GetVertex (int i) const
{
    return m_apkV[i];
}
//----------------------------------------------------------------------------
bool Polysolid2::Edge::operator< (const Edge& rkEdge) const
{
    if (m_apkV[1] < rkEdge.m_apkV[1])
    {
        return true;
    }

    if (m_apkV[1] > rkEdge.m_apkV[1])
    {
        return false;
    }

    return m_apkV[0] < rkEdge.m_apkV[0];
}
//----------------------------------------------------------------------------
