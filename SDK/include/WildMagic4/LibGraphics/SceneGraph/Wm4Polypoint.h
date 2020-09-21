// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4POLYPOINT_H
#define WM4POLYPOINT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Geometry.h"
#include "Wm4IntArray.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Polypoint : public Geometry
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // construction and destruction
    Polypoint (VertexBuffer* pkVBuffer);
    virtual ~Polypoint ();

    // member access
    void SetActiveQuantity (int iActiveQuantity);
    int GetActiveQuantity () const;

protected:
    Polypoint ();

    // Allow application to specify fewer than the maximum number of vertices
    // to draw.
    int m_iActiveQuantity;
};

WM4_REGISTER_STREAM(Polypoint);
typedef Pointer<Polypoint> PolypointPtr;
#include "Wm4Polypoint.inl"

}

#endif
