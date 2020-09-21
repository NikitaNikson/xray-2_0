// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BSPLINECURVEEXAMPLES_H
#define BSPLINECURVEEXAMPLES_H

#include "Wm4WindowApplication2.h"
#include "Wm4BSplineCurve2.h"
using namespace Wm4;

class BSplineCurveExamples : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    BSplineCurveExamples ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    BSplineCurve2f* m_pkSpline;
    int m_iNumCtrlPoints, m_iDegree;
    Vector2f* m_akCtrlPoint;
    float* m_afKnot;
    float m_afLocCtrlMin[6], m_afLocCtrlMax[6];
    int m_iCurveType;
    bool m_bModified;
};

WM4_REGISTER_INITIALIZE(BSplineCurveExamples);

#endif
