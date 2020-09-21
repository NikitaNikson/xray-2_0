// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef GEODESICPATHS_H
#define GEODESICPATHS_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class GeodesicPaths : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    GeodesicPaths ();
    virtual ~GeodesicPaths ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual void ScreenOverlay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ComputeTruePath ();
    void ComputeApprPath (bool bSubdivide);
    void ComputeApprLength ();
    void ParamToXY (const GVectorf& rkParam, int& riX, int& riY);
    void XYToParam (int iX, int iY, GVectorf& rkParam);
    static void RefineCallback ();

    EllipsoidGeodesicf m_kEG;
    GVectorf m_kParam0, m_kParam1;
    float m_fXMin, m_fXMax, m_fXDelta;
    float m_fYMin, m_fYMax, m_fYDelta;

    int m_iTrueQuantity;
    GVectorf* m_akTruePoint;
    float m_fTrueDistance;

    int m_iApprQuantity;
    int m_iCurrApprQuantity;
    GVectorf* m_akApprPoint;
    float m_fApprDistance;
    float m_fApprCurvature;
};

WM4_REGISTER_INITIALIZE(GeodesicPaths);

#endif
