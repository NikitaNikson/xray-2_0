// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CAMERAANDLIGHTNODES_H
#define CAMERAANDLIGHTNODES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class CameraAndLightNodes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    CameraAndLightNodes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual void MoveForward ();
    virtual void MoveBackward ();
    virtual void TurnLeft ();
    virtual void TurnRight ();
    virtual void MoveUp ();
    virtual void MoveDown ();
    virtual void LookUp ();
    virtual void LookDown ();

protected:
    void CreateScene ();
    TriMesh* CreateGround ();
    TriMesh* CreateLightTarget (Light* pkLight);
    Node* CreateLightFixture (LightPtr& rspkAdjustableLight);
    void CreateScreenPolygon ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframeState;
    CameraNodePtr m_spkCNode;
    CameraPtr m_spkScreenCamera;
    TriMeshPtr m_spkSky;
    LightPtr m_spkAdjustableLight0, m_spkAdjustableLight1;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(CameraAndLightNodes);

#endif
