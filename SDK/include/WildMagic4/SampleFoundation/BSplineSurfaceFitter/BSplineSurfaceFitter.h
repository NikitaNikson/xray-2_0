// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BSPLINESURFACEFITTER_H
#define BSPLINESURFACEFITTER_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class BSplineSurfaceFitter : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BSplineSurfaceFitter ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void UpdateFog ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkHeightField;
    TriMeshPtr m_spkFittedField;
    ImagePtr m_spkHeightImage;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(BSplineSurfaceFitter);

#endif
