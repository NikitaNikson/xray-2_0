// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CONVEXHULL2D_H
#define CONVEXHULL2D_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class ConvexHull2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    ConvexHull2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual void ScreenOverlay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void GenerateHull0D ();
    void GenerateHull1D ();
    void GenerateHull2D ();
    void GenerateHullManyCollinear ();
    void RegenerateHull ();
    int UnitToScreen (float fValue);

    const float m_fEpsilon;
    Query::Type m_eQueryType;
    ConvexHullf* m_pkHull;
    int m_iVQuantity;
    Vector2f* m_akVertex;
};

WM4_REGISTER_INITIALIZE(ConvexHull2D);

#endif
