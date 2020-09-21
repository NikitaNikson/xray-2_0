// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BSPNODES_H
#define BSPNODES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class BspNodes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BspNodes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    BspNode* CreateNode (const Vector2f& rkV0, const Vector2f& rkV1,
        const ColorRGB& rkColor);

    NodePtr m_spkScene;
    BspNodePtr m_spkBsp;
    WireframeStatePtr m_spkWireframe;

    // for rectangles used to visualize the binary separating planes
    CullStatePtr m_spkRCull;
    WireframeStatePtr m_spkRWireframe;

    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(BspNodes);

#endif
