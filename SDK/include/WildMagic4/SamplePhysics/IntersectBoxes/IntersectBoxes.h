// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef INTERSECTBOXES_H
#define INTERSECTBOXES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class IntersectBoxes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    IntersectBoxes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ModifyBoxes ();
    void ModifyMesh (int i);

    std::vector<AxisAlignedBox3f> m_kBoxes;
    IntersectingBoxesf* m_pkIB;
    bool m_bDoSimulation;
    float m_fLastIdle;

    NodePtr m_spkScene;
    MaterialStatePtr m_spkBlue, m_spkRed;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    static float ms_fSize;
};

WM4_REGISTER_INITIALIZE(IntersectBoxes);

#endif
