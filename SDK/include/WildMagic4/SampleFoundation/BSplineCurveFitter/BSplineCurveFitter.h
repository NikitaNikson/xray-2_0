// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BSPLINECURVEFITTER_H
#define BSPLINECURVEFITTER_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class BSplineCurveFitter : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BSplineCurveFitter ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateBSplinePolyline ();

    NodePtr m_spkScene;
    VertexColor3EffectPtr m_spkEffect;
    Culler m_kCuller;

    int m_iSampleQuantity;
    Vector3f* m_akSample;
    int m_iDegree;
    int m_iCtrlQuantity;
    BSplineCurveFitf* m_pkBSpline;

    enum { MESSAGE_SIZE = 128 };
    char m_acMessage[MESSAGE_SIZE];
};

WM4_REGISTER_INITIALIZE(BSplineCurveFitter);

#endif
