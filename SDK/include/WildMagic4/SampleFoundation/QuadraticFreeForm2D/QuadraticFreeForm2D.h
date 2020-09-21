// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef QUADRATICFREEFORM2D_H
#define QUADRATICFREEFORM2D_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class QuadraticFreeForm2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    QuadraticFreeForm2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

    // Allows user to drag control points.
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    float ScreenToControl (int iScreen) const;
    int ControlToScreen (float fControl) const;
    Vector2f Evaluate (const Vector2f& rkParam) const;
    void SelectVertex (int iX, int iY);

    // The image to map to the free-form region.
    Image* m_pkImage;

    // The control points that define the free-form region.
    int m_aaiCtrlX[3][3], m_aaiCtrlY[3][3];
    Vector2f m_aakCtrl[3][3];

    // Support for dragging the control points.
    bool m_bMouseDown;
    int m_iRow, m_iCol;
};

WM4_REGISTER_INITIALIZE(QuadraticFreeForm2D);

#endif
