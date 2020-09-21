// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VERTEXSHADER_H
#define WM4VERTEXSHADER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Shader.h"
#include "Wm4VertexProgram.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VertexShader : public Shader
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    VertexShader (const std::string& rkShaderName);
    virtual ~VertexShader ();

    // Access to the shader's program.
    VertexProgram* GetProgram () const;

protected:
    // Streaming support.
    VertexShader ();
};

WM4_REGISTER_STREAM(VertexShader);
typedef Pointer<VertexShader> VertexShaderPtr;

}

#endif
