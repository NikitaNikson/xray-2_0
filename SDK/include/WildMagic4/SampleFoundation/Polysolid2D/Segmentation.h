// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include "RPoint2.h"
#include <list>

class Polysolid2;
class SegmentEdge;

enum { OTAG, ITAG, MTAG, PTAG };

class Segmentation
{
public:
    Segmentation (const RPoint2& rkNormal, const Rational& rkConstant);
    ~Segmentation ();

    bool HasPoints () const;
    void AddPoint (const RPoint2& rkPosition, int eTag);
    void SegmentBy (const Polysolid2& rkPoly);
    void IntersectWith (const RPoint2& rkPosition0,
        const RPoint2& rkPosition1);
    void ConvertToEdges (SegmentEdge akTEdge[4]);

protected:
    class TaggedPoint
    {
    public:
        TaggedPoint (const Rational& rkOrder, const RPoint2& rkPosition,
            int eTag)
            :
            Order(rkOrder),
            Position(rkPosition),
            Tag(eTag)
        {
        }

        Rational Order;
        RPoint2 Position;
        int Tag;
    };

    RPoint2 m_kNormal;
    Rational m_kConstant;
    std::list<TaggedPoint> m_kList;

    static int ms_aiKlein4[4][4];
};

#endif
