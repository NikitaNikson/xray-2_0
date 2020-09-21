// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef INTERSECTRECTANGLES_H
#define INTERSECTRECTANGLES_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class IntersectRectangles : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    IntersectRectangles ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ModifyRectangles ();
    void DrawRectangles ();

    std::vector<AxisAlignedBox2f> m_kRects;
    IntersectingRectanglesf* m_pkIR;
    bool m_bMouseDown;
    float m_fLastIdle;
};

WM4_REGISTER_INITIALIZE(IntersectRectangles);

#endif
