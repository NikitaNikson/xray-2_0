// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef DRAWIMPLICITSURFACE_H
#define DRAWIMPLICITSURFACE_H

#include "Wm4WindowApplication2.h"
#include "RayTracer.h"
using namespace Wm4;

class DrawImplicitSurface : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    DrawImplicitSurface ();

    virtual bool OnInitialize ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnSpecialKeyDown (int iKey, int iX, int iY);

protected:
    RayTracer m_kRT;
    int m_iMaxSample;
    bool m_bBlur;
};

WM4_REGISTER_INITIALIZE(DrawImplicitSurface);

#endif
