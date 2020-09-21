// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SEGMENTEDGE_H
#define SEGMENTEDGE_H

#include "RPoint2.h"

class Polysolid2;

class SegmentEdge
{
public:
    SegmentEdge ();
    ~SegmentEdge ();

    bool HasEdges () const;
    void AddEdge (const RPoint2& rkPosition0, const RPoint2& rkPosition1);

    // for union, intersection
    void MergeAppend (SegmentEdge& rkTEdge);
    void MergeUnique (SegmentEdge& rkTEdge);
    void MergeEqual  (SegmentEdge& rkTEdge);

    // for difference, exclusive or
    void MergeAppendReverse (SegmentEdge& rkTEdge);
    void MergeUniqueReverse (SegmentEdge& rkTEdge);

    void ConvertToPolySolid (Polysolid2& rkPoly);

protected:
    class TaggedEdge
    {
    public:
        RPoint2 Position[2];
        TaggedEdge* Next;
    };

    TaggedEdge* m_pkFirst;
};

#endif
