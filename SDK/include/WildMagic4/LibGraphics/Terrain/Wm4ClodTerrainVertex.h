// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CLODTERRAINVERTEX_H
#define WM4CLODTERRAINVERTEX_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ClodTerrainVertex
{
public:
    ClodTerrainVertex ();

    void SetDependent (int i, ClodTerrainVertex* pkDependent);
    ClodTerrainVertex* GetDependent (int i);
    bool GetEnabled () const;
    void Enable ();
    void Disable ();

protected:
    ClodTerrainVertex* m_akDependent[2];
    bool m_bEnabled;
};

#include "Wm4ClodTerrainVertex.inl"

}

#endif
