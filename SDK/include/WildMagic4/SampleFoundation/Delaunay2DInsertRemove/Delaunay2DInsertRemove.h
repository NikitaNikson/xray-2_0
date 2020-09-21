// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef DELAUNAY2DINSERTREMOVE_H
#define DELAUNAY2DINSERTREMOVE_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class Delaunay2DInsertRemove : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    Delaunay2DInsertRemove ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void GetMesh ();

    IncrementalDelaunay2f* m_pkDelaunay;
    int m_iVQuantity;
    Vector2f* m_akVertex;
    int m_iTQuantity;
    int* m_aiTVertex;
    int* m_aiTAdjacent;
};

WM4_REGISTER_INITIALIZE(Delaunay2DInsertRemove);

#endif
