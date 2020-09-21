// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef MORPHCONTROLLERS_H
#define MORPHCONTROLLERS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class MorphControllers : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    MorphControllers ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    void LoadTargets ();
    void CreateFace ();
    void CreateController ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkFace;
    Culler m_kCuller;

    // shared data
    IndexBufferPtr m_spkIBuffer;
    MaterialStatePtr m_spkMaterial;
    LightPtr m_spkLight;

    enum
    {
        TARGET_QUANTITY = 5,
        KEY_QUANTITY = 6
    };
    TriMeshPtr m_aspkTarget[TARGET_QUANTITY];

    // animation time
    double m_dBaseTime, m_dCurrTime;

    // picking
    enum { PICK_MESSAGE_SIZE = 128 };
    int m_iXPick, m_iYPick;
    char m_acPickMessage[PICK_MESSAGE_SIZE];
    bool m_bPickPending;
    Picker m_kPicker;
};

WM4_REGISTER_INITIALIZE(MorphControllers);

#endif
