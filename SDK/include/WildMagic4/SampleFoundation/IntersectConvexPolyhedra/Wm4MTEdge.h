// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MTEDGE_H
#define WM4MTEDGE_H

#include "Wm4System.h"

namespace Wm4
{

class MTEdge
{
public:
    MTEdge (int iLabel = -1);
    MTEdge (const MTEdge& rkE);
    virtual ~MTEdge ();

    MTEdge& operator= (const MTEdge& rkE);

    int GetLabel () const;
    int& Label ();

    int GetVertex (int i) const;
    int& Vertex (int i);
    bool ReplaceVertex (int iVOld, int iVNew);

    int GetTriangle (int i) const;
    int& Triangle (int i);
    bool ReplaceTriangle (int iTOld, int iTNew);

    bool operator== (const MTEdge& rkE) const;

protected:
    int m_iLabel;
    int m_aiVertex[2];
    int m_aiTriangle[2];
};

#include "Wm4MTEdge.inl"

}

#endif
