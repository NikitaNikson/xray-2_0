// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MTVERTEX_H
#define WM4MTVERTEX_H

#include "Wm4System.h"
#include "Wm4UnorderedSet.h"

namespace Wm4
{

class MTVertex
{
public:
    MTVertex (int iLabel = -1, int iEGrow = 0, int iTGrow = 0);
    MTVertex (const MTVertex& rkV);
    virtual ~MTVertex ();

    MTVertex& operator= (const MTVertex& rkV);

    // Vertex labels are read-only since they are used for maps in the MTMesh
    // class for inverse look-up.
    int GetLabel () const;

    int GetEdgeQuantity () const;
    int GetEdge (int i) const;
    bool InsertEdge (int iE);
    bool RemoveEdge (int iE);
    bool ReplaceEdge (int iEOld, int iENew);

    int GetTriangleQuantity () const;
    int GetTriangle (int i) const;
    bool InsertTriangle (int iT);
    bool RemoveTriangle (int iT);
    bool ReplaceTriangle(int iTOld, int iTNew);

    bool operator== (const MTVertex& rkV) const;

protected:
    int m_iLabel;
    UnorderedSet<int> m_kESet, m_kTSet;
};

#include "Wm4MTVertex.inl"

}

#endif
