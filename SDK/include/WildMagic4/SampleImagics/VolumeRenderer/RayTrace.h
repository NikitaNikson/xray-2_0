// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef RAYTRACE_H
#define RAYTRACE_H

#include "Wm4Images.h"
using namespace Wm4;

class RayTrace
{
public:
    RayTrace (ImageUChar3D* pkImage, float fGamma);
    ~RayTrace ();

    bool MoveTrackBall (float fX0, float fY0, float fX1, float fY1);
    void Trace (int iSpacing);
    void DrawWireFrame ();
    void Correction (float fGamma);
    Ergb8 GetRendered (int iX, int iY);
    Ergb8 GetRendered (int i);
    float& Frame (int iY, int iX);

private:
    // storage for scaled volume data
    ImageFloat3D* m_pkDensity;

    // accumulator and render images
    int m_iBound, m_iBoundM1;
    int m_iHBound;
    ImageFloat2D* m_pkAccum;
    ImageRGB82D* m_pkRender;

    // center point of image
    float m_fXCenter, m_fYCenter, m_fZCenter;

    // for gamma correction of rendered image values
    float m_fGamma;

    // frame field for eyepoint:  u = column 0, v = column 1, w = column 2
    float m_aafFrame[3][3];

    bool Clipped (float fP, float fQ, float& rfU1, float& rfU2);
    bool Clip3D (float& rfX1, float& rfY1, float& rfZ1, float& rfX2,
        float& rfY2, float& rfZ2);
    void Line3D (int iJ0, int iJ1, int iX0, int iY0, int iZ0, int iX1,
        int iY1, int iZ1);
    void Line2D (bool bVisible, int iX0, int iY0, int iX1, int iY1);
};

#include "RayTrace.inl"

#endif
