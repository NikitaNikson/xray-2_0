// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PLANARSHADOWEFFECT_H
#define WM4PLANARSHADOWEFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Effect.h"
#include "Wm4Light.h"
#include "Wm4TriMesh.h"
#include "Wm4Matrix4.h"
#include "Wm4MaterialEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM PlanarShadowEffect : public Effect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    PlanarShadowEffect (int iQuantity);
    virtual ~PlanarShadowEffect ();

    virtual void Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
        int iMin, int iMax, VisibleObject* akVisible);

    // member access
    int GetQuantity () const;
    void SetPlane (int i, TriMeshPtr spkPlane);
    TriMeshPtr GetPlane (int i) const;
    void SetProjector (int i, LightPtr spkProjector);
    LightPtr GetProjector (int i) const;
    void SetShadowColor (int i, const ColorRGBA& rkShadowColor);
    const ColorRGBA& GetShadowColor (int i) const;

protected:
    PlanarShadowEffect ();

    bool GetProjectionMatrix (int i,
        const BoundingVolume* pkGlobalObjectWorldBound,
        Matrix4f& rkProjection);

    int m_iQuantity;
    TriMeshPtr* m_aspkPlane;
    LightPtr* m_aspkProjector;
    ColorRGBA* m_akShadowColor;

    // Temporary render state for drawing.
    AlphaStatePtr m_spkAState;
    MaterialStatePtr m_spkMState;
    StencilStatePtr m_spkSState;
    ZBufferStatePtr m_spkZState;
    MaterialEffectPtr m_spkMEffect;
};

WM4_REGISTER_STREAM(PlanarShadowEffect);
typedef Pointer<PlanarShadowEffect> PlanarShadowEffectPtr;
#include "Wm4PlanarShadowEffect.inl"

}

#endif
