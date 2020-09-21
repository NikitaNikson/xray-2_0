// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CULLSTATE_H
#define WM4CULLSTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4GlobalState.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CullState : public GlobalState
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;
    WM4_DECLARE_INITIALIZE;
    WM4_DECLARE_TERMINATE;

public:
    virtual StateType GetStateType () const { return CULL; }

    CullState ();
    virtual ~CullState ();

    enum FrontMode
    {
        FT_CCW,  // front faces are counterclockwise ordered
        FT_CW,   // front faces are clockwise ordered
        FT_QUANTITY
    };

    enum CullMode
    {
        CT_FRONT,  // cull front-facing triangles
        CT_BACK,   // cull back-facing triangles
        CT_QUANTITY
    };

    bool Enabled;         // default: true
    FrontMode FrontFace;  // default: FT_CCW
    CullMode CullFace;    // default: CT_BACK

private:
    static const char* ms_aacFrontMode[FT_QUANTITY];
    static const char* ms_aacCullMode[CT_QUANTITY];
};

WM4_REGISTER_STREAM(CullState);
WM4_REGISTER_INITIALIZE(CullState);
WM4_REGISTER_TERMINATE(CullState);
typedef Pointer<CullState> CullStatePtr;

}

#endif
