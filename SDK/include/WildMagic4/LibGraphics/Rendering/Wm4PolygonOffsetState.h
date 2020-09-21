// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4POLYGONOFFSETSTATE_H
#define WM4POLYGONOFFSETSTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4GlobalState.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM PolygonOffsetState : public GlobalState
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;
    WM4_DECLARE_INITIALIZE;
    WM4_DECLARE_TERMINATE;

public:
    virtual StateType GetStateType () const { return POLYGONOFFSET; }

    PolygonOffsetState ();
    virtual ~PolygonOffsetState ();

    // Set whether offset should be enabled for the various polygon drawing
    // modes (fill, line, point).
    bool FillEnabled;   // default: false
    bool LineEnabled;   // default: false
    bool PointEnabled;  // default: false

    // The offset is Scale*dZ + Bias*r where dZ is the change in depth
    // relative to the screen space area of the poly, and r is the smallest
    // resolvable depth difference.  Negative values move polygons closer to
    // the eye.
    float Scale;  // default: 0.0
    float Bias;   // default: 0.0
};

WM4_REGISTER_STREAM(PolygonOffsetState);
WM4_REGISTER_INITIALIZE(PolygonOffsetState);
WM4_REGISTER_TERMINATE(PolygonOffsetState);
typedef Pointer<PolygonOffsetState> PolygonOffsetStatePtr;

}

#endif
