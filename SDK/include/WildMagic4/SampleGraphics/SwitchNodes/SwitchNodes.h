// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SWITCHNODES_H
#define SWITCHNODES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class SwitchNodes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    SwitchNodes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();

    NodePtr m_spkScene;
    SwitchNodePtr m_spkSwitch;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(SwitchNodes);

#endif
