// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SKINCONTROLLER_H
#define WM4SKINCONTROLLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Controller.h"
#include "Wm4Vector3.h"

namespace Wm4
{

class Node;

class WM4_GRAPHICS_ITEM SkinController : public Controller
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  SkinController accepts responsibility
    // for deleting the input arrays.  The weight and offset arrays must have
    // been allocated using the template function Allocate found in
    // Wm4System.h.
    SkinController (int iVertexQuantity, int iBoneQuantity, Node** apkBones,
        float** aafWeight, Vector3f** aakOffset);
    virtual ~SkinController ();

    // member access
    int GetVertexQuantity () const;
    int GetBoneQuantity () const;
    Node* GetBone (int iBone) const;
    float& Weight (int iVertex, int iBone);
    Vector3f& Offset (int iVertex, int iBone);

    // animation update
    virtual bool Update (double dAppTime);

protected:
    SkinController ();

    int m_iVertexQuantity;    // vq
    int m_iBoneQuantity;      // bq
    Node** m_apkBones;        // bones[bq]
    float** m_aafWeight;      // weight[vq][bq]
    Vector3f** m_aakOffset;   // offset[vq][bq]
};

WM4_REGISTER_STREAM(SkinController);
typedef Pointer<SkinController> SkinControllerPtr;
#include "Wm4SkinController.inl"

}

#endif
