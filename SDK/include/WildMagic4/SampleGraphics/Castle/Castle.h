// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CASTLE_H
#define CASTLE_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class Castle : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Castle ();
    virtual ~Castle ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    // arrange for camera to be fixed distance above the nearest object
    void AdjustVerticalDistance ();
    virtual void MoveForward ();
    virtual void MoveBackward ();
    float m_fVerticalDistance;

    void SetAllWireframe (Spatial* pkSpatial);
    void ToggleAllWireframe (Spatial* pkSpatial);

    NodePtr m_spkScene;
    NodePtr m_spkModel;
    Culler m_kCuller;

    // name of picked object
    enum { PICKED_SIZE = 1024 };
    char m_acPicked[PICKED_SIZE];

    // pick ray parameters
    bool AllowMotion (float fSign);
    int m_iNumRays;
    float m_fHalfAngle;
    float* m_afCos;
    float* m_afSin;
    float* m_afTolerance;
    Picker m_kPicker;
};

WM4_REGISTER_INITIALIZE(Castle);

#endif
