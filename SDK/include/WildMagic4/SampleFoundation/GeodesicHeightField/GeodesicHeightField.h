// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef GEODESICHEIGHTFIELD_H
#define GEODESICHEIGHTFIELD_H

#include "Wm4WindowApplication3.h"
#include "Wm4BSplineGeodesic.h"
using namespace Wm4;

class GeodesicHeightField : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    GeodesicHeightField ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    void DrawLine (int iX0, int iY0, int iX1, int iY1,
        int iWidth, unsigned char* aucData);
    void ComputeDistanceCurvature ();
    static void RefineCallback ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkMesh;
    ImagePtr m_spkImage;
    TextureEffectPtr m_spkEffect;
    Culler m_kCuller;

    Picker m_kPicker;

    BSplineRectangled* m_pkSurface;
    BSplineGeodesicd* m_pkGeodesic;

    int m_iSelected;
    int m_aiXIntr[2], m_aiYIntr[2];
    GVectord m_akPoint[2];
    int m_iPQuantity;
    GVectord* m_akPath;

    double m_dDistance, m_dCurvature;
};

WM4_REGISTER_INITIALIZE(GeodesicHeightField);

#endif
