// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef POLYGONDISTANCE_H
#define POLYGONDISTANCE_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class PolygonDistance : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    PolygonDistance ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void InitialConfiguration ();
    void NextConfiguration ();
    void PolarRepresentation (int iNum, const Vector2f* akVertices,
        Vector2f& rkCentroid, Vector2f* akPolar);
    void CartesianRepresentation (int iNum, Vector2f* akVertices,
        const Vector2f& rkCentroid, const Vector2f* akPolar);
    void PolyRotate (int iNum, int iSign, Vector2f* akPolar);
    void DoEdgeNorm (int iNum, const Vector2f* akVertices,
        const Vector2f& rkClosest, Vector2f* akEnd);
    void DrawLineSegment (int iThick, Color kColor, const Vector2f& rkEnd1,
        const Vector2f& rkEnd2);
    void DrawPerps (const Vector2f* akEP);
    void DrawPoints (int iThick, Color kColor, const Vector2f& rkPoint);

    enum { PD_NUM_POLYS = 3 };

    class Polygon
    {
    public:
        int m_iNumVertices;
        int m_iSign;
        Vector2f* m_akVertices;
        Vector2f m_akCentroid;
        Vector2f* m_akPolar;
        TTuple<2,int>* m_akFaces;
    };

    Polygon* m_kPolygon;
    bool m_bDoPerps;
};

WM4_REGISTER_INITIALIZE(PolygonDistance);

#endif
