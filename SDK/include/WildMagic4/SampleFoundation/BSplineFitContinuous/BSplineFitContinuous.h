// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BSPLINEFITCONTINUOUS_H
#define BSPLINEFITCONTINUOUS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class BSplineFitContinuous : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BSplineFitContinuous ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();

protected:
    Polyline* OriginalPolyline (int iCtrlQuantity, Vector3d* akCtrl);
    Polyline* ReducedPolyline (int iCtrlQuantity, Vector3d* akCtrl,
        double dFraction);

    NodePtr m_spkScene, m_spkTrnNode;
    Culler m_kCuller;
    int m_iDegree;
};

WM4_REGISTER_INITIALIZE(BSplineFitContinuous);

#endif
