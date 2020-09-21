// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WRIGGLINGSNAKE_H
#define WRIGGLINGSNAKE_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class WrigglingSnake : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    WrigglingSnake ();
    virtual ~WrigglingSnake ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateSnake ();
    void CreateSnakeBody ();
    void CreateSnakeHead ();
    void UpdateSnake ();
    void UpdateSnakeBody ();
    void UpdateSnakeHead ();
    void ModifyCurve ();
    static float Radial (float fT);

    NodePtr m_spkScene, m_spkTrnNode, m_spkSnakeRoot;
    TubeSurfacePtr m_spkSnakeBody;
    TriMeshPtr m_spkSnakeHead;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    int m_iNumCtrl, m_iDegree;
    BSplineCurve3f* m_pkCenter;
    float* m_afAmplitude;
    float* m_afPhase;
    int m_iShellQuantity;
    static float ms_fRadius;
};

WM4_REGISTER_INITIALIZE(WrigglingSnake);

#endif
