// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef DYNAMICTEXTURES_H
#define DYNAMICTEXTURES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class DynamicTextures : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    DynamicTextures ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    Vector2f Evaluate (const Vector2f& rkParam) const;
    void UpdateTexture ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    DynamicTexturePtr m_spkDTexture;
    TextureEffectPtr m_spkEffect;
    Culler m_kCuller;

    int m_iQuantity;
    int* m_aiPermutation;
    int* m_aiInversePermutation;
    int m_iCurrent, m_iDelta;
    bool m_bReverse;
    bool m_bIsDirect3D;
};

WM4_REGISTER_INITIALIZE(DynamicTextures);

#endif
