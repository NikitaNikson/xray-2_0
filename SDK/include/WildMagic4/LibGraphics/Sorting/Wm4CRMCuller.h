// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CRMCULLER_H
#define WM4CRMCULLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Culler.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CRMCuller : public Culler
{
public:
    CRMCuller (int iMaxQuantity = 0, int iGrowBy = 0,
        const Camera* pkCamera = 0);
    virtual ~CRMCuller ();

    // Two portals leading into the room can be visible to the camera.  The
    // Culler would store visible objects twice.  CRMCuller maintains a list
    // of unique objects.
    virtual void Insert (Spatial* pkObject, Effect* pkGlobalEffect);

protected:
    THashSet<Spatial*> m_kUnique;
};

}

#endif
