// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef VERTEXTEXTURES_H
#define VERTEXTEXTURES_H

// WARNING.  This sample application requires that your graphics card supports
// vertex textures.  For OpenGL, use the following Cg commands to compile the
// shader programs:
//    cgc -profile vp40 -entry v_HeightEffect -o v_HeightEffect.ogl.wmsp HeightEffect.cg
//    cgc -profile fp40 -entry p_HeightEffect -o p_HeightEffect.ogl.wmsp HeightEffect.cg

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class VertexTextures : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    VertexTextures ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    TriMesh* CreateRectangle (int iXSamples, int iYSamples, float fXExtent,
        float fYExtent);

    NodePtr m_spkScene;
    ImagePtr m_spkHeight, m_spkHeight32;
    Culler m_kCuller;
    WireframeStatePtr m_spkWireframe;
};

WM4_REGISTER_INITIALIZE(VertexTextures);

#endif
