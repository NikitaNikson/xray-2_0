// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CHARCOAL_H
#define CHARCOAL_H

#include "Wm4WindowApplication3.h"
#include "CharcoalEffect.h"
using namespace Wm4;

class Charcoal : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Charcoal ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void AttachShader (Spatial* pkObject);
    void UpdateConstants ();

    NodePtr m_spkScene;
    CharcoalEffectPtr m_spkEffect;
    bool m_bSmudge, m_bDisplayPaper, m_bDisplayLighting;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(Charcoal);

#endif
