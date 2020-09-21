// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VERTEXCOLOR3EFFECT_H
#define WM4VERTEXCOLOR3EFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ShaderEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VertexColor3Effect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    VertexColor3Effect ();
    virtual ~VertexColor3Effect ();
};

WM4_REGISTER_STREAM(VertexColor3Effect);
typedef Pointer<VertexColor3Effect> VertexColor3EffectPtr;

}

#endif
