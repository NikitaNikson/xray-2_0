// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SKINNEDBIPED_H
#define SKINNEDBIPED_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class SkinnedBiped : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    SkinnedBiped ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    Node* GetNode (const char* acName);
    TriMesh* GetMesh (const char* acName, Node* pkBiped);

    // Node objects and keyframe controllers
    Node* CreateBiped ();
    void CreatePelvis (Node* pkBiped);
    void CreateSpine (Node* pkPelvis);
    void CreateSpine1 (Node* pkSpine);
    void CreateSpine2 (Node* pkSpine1);
    void CreateSpine3 (Node* pkSpine2);
    void CreateNeck (Node* pkSpine3);
    void CreateHead (Node* pkNeck);
    void CreateLClavicle (Node* pkNeck);
    void CreateRClavicle (Node* pkNeck);
    void CreateLUpperArm (Node* pkLClavicle);
    void CreateRUpperArm (Node* pkRClavicle);
    void CreateLForeArm (Node* pkLUpperArm);
    void CreateRForeArm (Node* pkRUpperArm);
    void CreateLHand (Node* pkLForeArm);
    void CreateRHand (Node* pkRForeArm);
    void CreateLThigh (Node* pkPelvis);
    void CreateRThigh (Node* pkPelvis);
    void CreateLCalf (Node* pkLThigh);
    void CreateRCalf (Node* pkRThigh);
    void CreateLFoot (Node* pkLCalf);
    void CreateRFoot (Node* pkRCalf);
    void CreateLToe (Node* pkLFoot);
    void CreateRToe (Node* pkRFoot);

    // TriMesh objects and skin controllers
    void CreateShirt (Node* pkPelvis);
    void CreatePants (Node* pkPelvis);
    void CreateFace (Node* pkSpine3);
    void CreateHair (Node* pkHead);
    void CreateLArm (Node* pkLUpperArm);
    void CreateRArm (Node* pkRUpperArm);
    void CreateLLeg (Node* pkLThigh);
    void CreateLAnkle (Node* pkLThigh);
    void CreateRLeg (Node* pkRThigh);
    void CreateRAnkle (Node* pkRThigh);
    void CreateLShoe (Node* pkLCalf);
    void CreateRShoe (Node* pkRCalf);

    // root of scene
    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    double m_dAnimTime, m_dAnimTimeDelta;
};

WM4_REGISTER_INITIALIZE(SkinnedBiped);

#endif
