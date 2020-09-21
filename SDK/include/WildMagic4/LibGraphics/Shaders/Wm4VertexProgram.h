// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VERTEXPROGRAM_H
#define WM4VERTEXPROGRAM_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Program.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VertexProgram : public Program
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    VertexProgram (const std::string& rkProgramName);
    virtual ~VertexProgram ();

    // To support Catalog<VertexProgram>.
    static VertexProgram* Load (const std::string& rkProgramName);

protected:
    // Streaming support.
    VertexProgram ();
};

WM4_REGISTER_STREAM(VertexProgram);
typedef Pointer<VertexProgram> VertexProgramPtr;

}

#endif
