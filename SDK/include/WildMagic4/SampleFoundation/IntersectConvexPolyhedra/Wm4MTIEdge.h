// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MTIEDGE_H
#define WM4MTIEDGE_H

#include "Wm4System.h"

namespace Wm4
{

class MTIEdge
{
public:
    MTIEdge (int iLabel0, int iLabel1);
    bool operator< (const MTIEdge& rkE) const;
    bool operator== (const MTIEdge& rkE) const;
    bool operator!= (const MTIEdge& rkE) const;

    int GetLabel (int i) const;

protected:
    int m_aiLabel[2];
};

}

#endif
