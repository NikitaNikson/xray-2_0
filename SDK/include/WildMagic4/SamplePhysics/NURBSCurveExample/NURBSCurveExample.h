// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef NURBSCURVEEXAMPLE_H
#define NURBSCURVEEXAMPLE_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class NURBSCurveExample : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    NURBSCurveExample ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void DoSimulation1 ();
    void DoSimulation2 ();
    void InitialConfiguration ();
    void NextConfiguration ();

    NURBSCurve2f* m_pkSpline;
    NURBSCurve2f* m_pkCircle;
    Vector2f* m_akCtrlPoint;
    Vector2f* m_akTarget;
    float m_fH, m_fD;
    float m_fSimTime, m_fSimDelta;

    bool m_bDrawControlPoints;
};

WM4_REGISTER_INITIALIZE(NURBSCurveExample);

#endif
