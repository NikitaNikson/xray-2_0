// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef POLYGON2_H
#define POLYGON2_H

#include "Types2.h"

class BspTree2;

class Polygon2
{
public:
    Polygon2 ();
    Polygon2 (const Polygon2& rkP);
    ~Polygon2 ();

    Polygon2& operator= (const Polygon2& rkP);

    int InsertVertex (const Vector2d& rkV);
    int InsertEdge (const Edge2& rkE);
    void Finalize ();

    int GetVertexQuantity () const;
    bool GetVertex (int i, Vector2d& rkV) const;
    int GetEdgeQuantity () const;
    bool GetEdge (int i, Edge2& rkE) const;

    // negation
    Polygon2 operator~ () const;

    // intersection
    Polygon2 operator& (const Polygon2& rkP) const;

    // union
    Polygon2 operator| (const Polygon2& rkP) const;

    // difference
    Polygon2 operator- (const Polygon2& rkP) const;

    // exclusive or
    Polygon2 operator^ (const Polygon2& rkP) const;

    // point location (-1 inside, 0 on polygon, 1 outside)
    int PointLocation (const Vector2d& rkV) const;

    void Print (const char* acFilename) const;

protected:
    void SplitEdge (int iV0, int iV1, int iVMid);
    void GetInsideEdgesFrom (const Polygon2& rkP, Polygon2& rkInside) const;

    // vertices
    VMap m_kVMap;
    VArray m_kVArray;

    // edges
    EMap m_kEMap;
    EArray m_kEArray;

    friend class BspTree2;
    BspTree2* m_pkTree;

};

#endif
