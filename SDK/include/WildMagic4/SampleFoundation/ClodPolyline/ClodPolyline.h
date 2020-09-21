// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CLODPOLYLINE_H
#define CLODPOLYLINE_H

#include "Wm4WindowApplication2.h"
#include "Polyline3.h"
using namespace Wm4;

class ClodPolyline : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    ClodPolyline ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    Polyline3* m_pkPolyline;
    int m_iLOD;
};

WM4_REGISTER_INITIALIZE(ClodPolyline);

#endif
