// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef HELIXTUBESURFACE_H
#define HELIXTUBESURFACE_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class HelixTubeSurface : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    HelixTubeSurface ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnSpecialKeyDown (int iKey, int iX, int iY);

protected:
    MultipleCurve3f* CreateCurve ();
    static float Radial (float fT);
    virtual bool MoveCamera ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
    MultipleCurve3f* m_pkCurve;
    float m_fMinCurveTime, m_fMaxCurveTime, m_fCurvePeriod;
    float m_fCurveTime, m_fDeltaTime;
};

WM4_REGISTER_INITIALIZE(HelixTubeSurface);

#endif
