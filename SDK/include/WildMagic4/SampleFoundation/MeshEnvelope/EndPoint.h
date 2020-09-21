// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef ENDPOINT_H
#define ENDPOINT_H

#include "Rational.h"

class EndPoint
{
public:
    Rational Value;  // x-value for a segment endpoint
    int Type;        // '0' if interval min, '1' if interval max
    int Index;       // index of interval containing this endpoint

    // support for sorting
    bool operator< (const EndPoint& rkPoint) const
    {
        if (Value < rkPoint.Value)
        {
            return true;
        }
        if (Value > rkPoint.Value)
        {
            return false;
        }
        return Type < rkPoint.Type;
    }
};

#endif
