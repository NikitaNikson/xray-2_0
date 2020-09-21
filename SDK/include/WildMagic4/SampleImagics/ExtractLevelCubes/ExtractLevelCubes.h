// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef EXTRACTLEVELCUBES_H
#define EXTRACTLEVELCUBES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ExtractLevelCubes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ExtractLevelCubes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    bool CreateModel ();

    NodePtr m_spkScene, m_spkTrnNode;
    TriMeshPtr m_spkModel;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(ExtractLevelCubes);

#endif
