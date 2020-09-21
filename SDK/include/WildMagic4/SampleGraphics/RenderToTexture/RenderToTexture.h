// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef RENDERTOTEXTURE_H
#define RENDERTOTEXTURE_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class RenderToTexture : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    RenderToTexture ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    Node* CreateModel ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    CameraPtr m_spkScreenCamera;

    TriMeshPtr m_spkScenePolygon;
    ImagePtr m_spkSceneImage;
    Texture* m_pkSceneTarget;
    FrameBuffer* m_pkPBuffer;
};

WM4_REGISTER_INITIALIZE(RenderToTexture);

#endif
