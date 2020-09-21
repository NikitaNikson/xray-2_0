// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4TRISTRIP_H
#define WM4TRISTRIP_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Triangles.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM TriStrip : public Triangles
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    TriStrip (VertexBuffer* pkVBuffer,
        bool bUpdateModelNormals = true,
        int iTangentSpaceType = GU_TANGENT_SPACE_NONE);

    TriStrip (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer,
        bool bUpdateModelNormals = true,
        int iTangentSpaceType = GU_TANGENT_SPACE_NONE);

    virtual ~TriStrip ();

    // Interpretation of the index buffer data.
    virtual int GetTriangleQuantity () const;
    virtual bool GetTriangle (int i, int& riV0, int& riV1, int& riV2) const;

protected:
    TriStrip ();
};

WM4_REGISTER_STREAM(TriStrip);
typedef Pointer<TriStrip> TriStripPtr;
#include "Wm4TriStrip.inl"

}

#endif
