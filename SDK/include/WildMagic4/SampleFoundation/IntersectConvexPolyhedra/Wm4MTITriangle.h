// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MTITRIANGLE_H
#define WM4MTITRIANGLE_H

#include "Wm4System.h"

namespace Wm4
{

class MTITriangle
{
public:
    MTITriangle (int iLabel0, int iLabel1, int iLabel2);
    bool operator< (const MTITriangle& rkT) const;
    bool operator== (const MTITriangle& rkT) const;
    bool operator!= (const MTITriangle& rkT) const;

    int GetLabel (int i) const;

protected:
    int m_aiLabel[3];
};

}

#endif
