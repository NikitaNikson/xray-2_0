// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SIMPLESEGMENT_H
#define SIMPLESEGMENT_H

#include "Wm4CurveSegment.h"

namespace Wm4
{

class SimpleSegment : public CurveSegment
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SimpleSegment ();
    virtual ~SimpleSegment ();

    float Amplitude, Frequency, Height;

    // position and derivatives up to third order
    virtual Vector3f P (float fU) const;
    virtual Vector3f PU (float fU) const;
    virtual Vector3f PUU (float fU) const;
    virtual Vector3f PUUU (float fU) const;
};

WM4_REGISTER_STREAM(SimpleSegment);
typedef Pointer<SimpleSegment> SimpleSegmentPtr;

}

#endif
