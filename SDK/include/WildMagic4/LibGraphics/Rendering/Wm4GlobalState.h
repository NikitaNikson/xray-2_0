// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4GLOBALSTATE_H
#define WM4GLOBALSTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM GlobalState : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~GlobalState ();

    // supported global states
    enum StateType
    {
        ALPHA,
        CULL,
        MATERIAL,
        POLYGONOFFSET,
        STENCIL,
        WIREFRAME,
        ZBUFFER,
        MAX_STATE_TYPE
    };

    virtual StateType GetStateType () const = 0;

    // default states
    static Pointer<GlobalState> Default[MAX_STATE_TYPE];

protected:
    GlobalState ();
};

WM4_REGISTER_STREAM(GlobalState);
typedef Pointer<GlobalState> GlobalStatePtr;

}

#endif
