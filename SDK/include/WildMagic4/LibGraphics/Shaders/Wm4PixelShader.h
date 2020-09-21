// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PIXELSHADER_H
#define WM4PIXELSHADER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Shader.h"
#include "Wm4PixelProgram.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM PixelShader : public Shader
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    PixelShader (const std::string& rkShaderName);
    virtual ~PixelShader ();

    // Access to the shader's program.
    PixelProgram* GetProgram () const;

protected:
    // Streaming support.
    PixelShader ();
};

WM4_REGISTER_STREAM(PixelShader);
typedef Pointer<PixelShader> PixelShaderPtr;

}

#endif
