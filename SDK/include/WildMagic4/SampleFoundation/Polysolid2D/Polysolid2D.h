// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef POLYSOLID2D_H
#define POLYSOLID2D_H

#include "Wm4WindowApplication2.h"
#include "Polysolid2.h"
using namespace Wm4;

class Polysolid2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    Polysolid2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    Polysolid2* ConstructInvertedEll ();
    Polysolid2* ConstructPentagon ();
    Polysolid2* ConstructSquare ();
    Polysolid2* ConstructSShape ();
    Polysolid2* ConstructPolyWithHoles ();

    void DoBoolean ();
    void DrawPolySolid (Polysolid2& rkP, Color kColor);

    Polysolid2 m_kIntersection, m_kUnion, m_kDiff01, m_kDiff10, m_kXor;
    Polysolid2* m_pkPoly0;
    Polysolid2* m_pkPoly1;
    Polysolid2* m_pkActive;
    int m_iChoice;
};

WM4_REGISTER_INITIALIZE(Polysolid2D);

#endif
