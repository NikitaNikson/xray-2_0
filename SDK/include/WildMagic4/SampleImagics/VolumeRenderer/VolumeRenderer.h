// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef VOLUMERENDERER_H
#define VOLUMERENDERER_H

#include "Wm4WindowApplication2.h"
#include "RayTrace.h"
using namespace Wm4;

class VolumeRenderer : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    VolumeRenderer ();

    virtual bool OnPrecreate ();
    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    int m_iBound;
    RayTrace* m_pkRT;
    float m_fX0, m_fY0, m_fX1, m_fY1, m_fHBound, m_fGamma;
    bool m_bButtonDown;
};

WM4_REGISTER_INITIALIZE(VolumeRenderer);

#endif
