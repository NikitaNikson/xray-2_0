// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Edge2.h"

//----------------------------------------------------------------------------
Edge2::Edge2 ()
{
    i0 = -1;
    i1 = -1;
}
//----------------------------------------------------------------------------
Edge2::Edge2 (int j0, int j1)
{
    i0 = j0;
    i1 = j1;
}
//----------------------------------------------------------------------------
bool Edge2::operator< (const Edge2& rkE) const
{
    if (i1 < rkE.i1)
    {
        return true;
    }

    if (i1 == rkE.i1)
    {
        return i0 < rkE.i0;
    }

    return false;
}
//----------------------------------------------------------------------------
