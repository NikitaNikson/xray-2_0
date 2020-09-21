// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef FREEFORMDEFORMATION_H
#define FREEFORMDEFORMATION_H

#include "Wm4WindowApplication3.h"
#include "Wm4BSplineVolume.h"
using namespace Wm4;

class FreeFormDeformation : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    FreeFormDeformation ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void Setup ();
    void CreateBSplineVolume ();
    void CreatePolylines ();
    void CreateControlBoxes ();

    void UpdateMesh ();
    void UpdatePolylines ();
    void UpdateControlBoxes ();

    void DoRandomControlPoints ();
    void OnMouseDown (int iX, int iY);
    void OnMouseMove (int iX, int iY);

    // the scene graph
    NodePtr m_spkScene, m_spkTrnNode;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkMesh;
    Culler m_kCuller;

    // control volume for deformation
    int m_iQuantity, m_iDegree;
    BSplineVolumef* m_pkVolume;
    float m_fXMin, m_fYMin, m_fZMin, m_fDX, m_fDY, m_fDZ;
    Vector3f* m_akParameter;  // (u,v,w) for mesh vertices

    // Q control points per dimension, 3*Q^2*(Q-1) polylines to connect them
    NodePtr m_spkPolylineRoot;

    // toggle between automated random motion and user-adjusted controls
    bool m_bDoRandom;

    // random motion parameters
    float m_fAmplitude, m_fRadius, m_fLastUpdateTime;

    // user-adjusted controls
    NodePtr m_spkControlRoot;
    TriMeshPtr m_spkSelected;
    MaterialStatePtr m_spkControlActive, m_spkControlInactive;
    LightPtr m_spkControlLight;
    Vector3f m_kOldWorldPos;
    bool m_bMouseDown;

    // picking
    Picker m_kPicker;
};

WM4_REGISTER_INITIALIZE(FreeFormDeformation);

#endif
