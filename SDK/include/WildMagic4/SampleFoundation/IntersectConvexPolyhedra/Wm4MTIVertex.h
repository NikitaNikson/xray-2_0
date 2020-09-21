// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MTIVERTEX_H
#define WM4MTIVERTEX_H

#include "Wm4System.h"

namespace Wm4
{

class MTIVertex
{
public:
    MTIVertex (int iLabel);

    bool operator< (const MTIVertex& rkV) const;
    bool operator== (const MTIVertex& rkV) const;
    bool operator!= (const MTIVertex& rkV) const;

    int GetLabel () const;

protected:
    int m_iLabel;
};

}

#endif
