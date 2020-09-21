// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PLANARREFLECTIONEFFECT_H
#define WM4PLANARREFLECTIONEFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Effect.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM PlanarReflectionEffect : public Effect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    PlanarReflectionEffect (int iQuantity);
    virtual ~PlanarReflectionEffect ();

    virtual void Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
        int iMin, int iMax, VisibleObject* akVisible);

    // member access
    int GetQuantity () const;
    void SetPlane (int i, TriMeshPtr spkPlane);
    TriMeshPtr GetPlane (int i) const;
    void SetReflectance (int i, float fReflectance);
    float GetReflectance (int i) const;

protected:
    PlanarReflectionEffect ();

    void GetReflectionMatrixAndPlane (int i, Matrix4f& rkReflection,
        Plane3f& rkPlane);

    int m_iQuantity;
    TriMeshPtr* m_aspkPlane;
    float* m_afReflectance;

    // Temporary render state for drawing.
    AlphaStatePtr m_spkAState;
    StencilStatePtr m_spkSState;
    ZBufferStatePtr m_spkZState;
};

WM4_REGISTER_STREAM(PlanarReflectionEffect);
typedef Pointer<PlanarReflectionEffect> PlanarReflectionEffectPtr;
#include "Wm4PlanarReflectionEffect.inl"

}

#endif
