// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MTTRIANGLE_H
#define WM4MTTRIANGLE_H

#include "Wm4System.h"

namespace Wm4
{

class MTTriangle
{
public:
    MTTriangle (int iLabel = -1);
    MTTriangle (const MTTriangle& rkT);
    virtual ~MTTriangle ();

    MTTriangle& operator= (const MTTriangle& rkT);

    int GetLabel () const;
    int& Label ();

    int GetVertex (int i) const;
    int& Vertex (int i);
    bool ReplaceVertex (int iVOld, int iVNew);

    int GetEdge (int i) const;
    int& Edge (int i);
    bool ReplaceEdge (int iEOld, int iENew);

    int GetAdjacent (int i) const;
    int& Adjacent (int i);
    bool ReplaceAdjacent (int iAOld, int iANew);

    bool operator== (const MTTriangle& rkT) const;

protected:
    int m_iLabel;
    int m_aiVertex[3];
    int m_aiEdge[3];
    int m_aiAdjacent[3];
};

#include "Wm4MTTriangle.inl"

}

#endif
