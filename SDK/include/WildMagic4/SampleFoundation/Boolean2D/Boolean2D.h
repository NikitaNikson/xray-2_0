// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BOOLEAN2D_H
#define BOOLEAN2D_H

#include "Wm4WindowApplication2.h"
#include "Polygon2.h"

class Boolean2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    Boolean2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    Polygon2* ConstructInvertedEll ();
    Polygon2* ConstructPentagon ();
    Polygon2* ConstructSquare ();
    Polygon2* ConstructSShape ();
    Polygon2* ConstructPolyWithHoles ();

    void DoBoolean ();
    void DrawPolySolid (Polygon2& rkP, Color kColor);

    Polygon2 m_kIntersection, m_kUnion, m_kDiff01, m_kDiff10, m_kXor;
    Polygon2* m_pkPoly0;
    Polygon2* m_pkPoly1;
    Polygon2* m_pkActive;
    int m_iChoice;
};

WM4_REGISTER_INITIALIZE(Boolean2D);

#endif
