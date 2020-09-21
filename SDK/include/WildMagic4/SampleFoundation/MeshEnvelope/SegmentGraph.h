// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SEGMENTGRAPH
#define SEGMENTGRAPH

#include "Rational.h"

class SegmentGraph
{
public:
    SegmentGraph ();
    ~SegmentGraph ();

    class Vertex
    {
    public:
        Vertex ();
        ~Vertex ();

        void InsertAdjacent (Vertex* pkAdjacent);
        void RemoveAdjacent (Vertex* pkAdjacent);

        enum { VG_CHUNK = 16 };
        RPoint2 Position;
        int VQuantity;
        Vertex** V;
    };

    class Edge
    {
    public:
        Edge ();
        Edge (Vertex* pkV0, Vertex* pkV1);

        void SetVertices (Vertex* pkV0, Vertex* pkV1);
        Vertex* GetVertex (int i) const;
        bool operator== (const Edge& rkEdge) const;
        bool operator< (const Edge& rkEdge) const;

    private:
        Vertex* m_apkV[2];
    };

    typedef std::map<RPoint2,Vertex*> VMap;
    typedef std::set<Edge> ESet;

    VMap& GetVertices ();
    ESet& GetEdges ();

    void InsertEdge (const RPoint2& rkPoint0, const RPoint2& rkPoint1);
    bool RemoveEdge (const RPoint2& rkPoint0, const RPoint2& rkPoint1);
    void ExtractEnvelope (std::vector<RPoint2>& rkEnvelope);

private:
    Vertex* GetVertex (const RPoint2& rkPoint);
    Vertex* InsertVertex (const RPoint2& rkPoint);

    VMap m_kVMap;
    ESet m_kESet;
};

#endif
