// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CLODMESHES_H
#define CLODMESHES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

// The sample creates a clodified mesh with a texture.  To see the original
// mesh with the texture, comment out the #define of USE_CLOD_MESH.
#define USE_CLOD_MESH

class ClodMeshes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ClodMeshes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

#ifdef USE_CLOD_MESH
    void DrawTriangleQuantity (int iX, int iY, const ColorRGBA& rkColor);
    virtual void MoveForward ();
    virtual void MoveBackward ();
    void UpdateClods ();
    ClodMeshPtr m_aspkClod[2], m_spkActive;
#endif
};

WM4_REGISTER_INITIALIZE(ClodMeshes);

#endif
