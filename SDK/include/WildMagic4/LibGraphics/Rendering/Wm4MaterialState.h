// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MATERIALSTATE_H
#define WM4MATERIALSTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4GlobalState.h"
#include "Wm4ColorRGB.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM MaterialState : public GlobalState
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;
    WM4_DECLARE_INITIALIZE;
    WM4_DECLARE_TERMINATE;

public:
    virtual StateType GetStateType () const { return MATERIAL; }

    MaterialState ();
    virtual ~MaterialState ();

    ColorRGB Emissive;  // default: ColorRGB(0,0,0)
    ColorRGB Ambient;   // default: ColorRGB(0.2,0.2,0.2)
    ColorRGB Diffuse;   // default: ColorRGB(0.8,0.8,0.8)
    ColorRGB Specular;  // default: ColorRGB(0,0,0)
    float Alpha;        // default: 1
    float Shininess;    // default: 1
};

WM4_REGISTER_STREAM(MaterialState);
WM4_REGISTER_INITIALIZE(MaterialState);
WM4_REGISTER_TERMINATE(MaterialState);
typedef Pointer<MaterialState> MaterialStatePtr;

}

#endif
