// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4TRIANGLES_H
#define WM4TRIANGLES_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Geometry.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Triangles : public Geometry
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~Triangles ();

    // These functions depend on the interpretation of the index buffer of
    // the triangle primitive.  The triangle <V0,V1,V2> is counterclockwise
    // order.
    virtual int GetTriangleQuantity () const = 0;
    virtual bool GetTriangle (int i, int& riV0, int& riV1, int& riV2)
        const = 0;

    bool GetModelTriangle (int i, Triangle3f& rkMTri) const;
    bool GetWorldTriangle (int i, Triangle3f& rkWTri) const;

    // Compute per-vertex normals.  If the vertex buffer does not have normal
    // attibutes, it is recreated to include the storage for normals.
    void GenerateNormals ();

    // Compute per-vertex tangents and bitangents.  This requires normal
    // vectors to exist, so if the vertex buffer does not have normal
    // attributes, it is recreated to include the storage for normals.  The
    // same goes for tangent and bitangent attributes; the vertex buffer is
    // recreated to hold exactly the information needed to satisfy the request
    // for a tangent space.
    //
    // Pass in Geometry::GU_TANGENT_SPACE_USE_GEOMETRY if you want the tangent
    // space to be computed using only the mesh geometry.  The algorithm uses
    // a least-squares approach to computing the tangent space.  If you want
    // the tangent space to be computed using a texture coordinate unit, pass
    // in the unit number, 0 <= unit < maxUnits, where maxUnits depends on
    // your graphics card/driver.  If the vertex buffer does not have texture
    // coordinates for this unit, the function returns 'false'; otherwise, the
    // function computes the tangent space and returns 'true'.
    bool GenerateTangents (int iTextureCoordinateUnit);

protected:
    Triangles ();
    Triangles (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer);

    // geometric updates
    virtual void UpdateModelNormals ();
    virtual void UpdateModelTangentSpace (int iTangentSpaceType);

private:
    void UpdateTangentSpaceUseGeometry ();
    void UpdateTangentSpaceUseTCoord (int iTextureCoordinateUnit);

    // This function is used by GenerateTangents to compute a tangent vector
    // at rkPos0.  The triangle is has positions rkPos0, rkPos1, and rkPos2,
    // listed in counterclockwise order.  The corresponding texture
    // coordinates are rkTCoord0, rkTCoord1, and rkTCoord2, and are those
    // associate with iTextureCoordinateUnit.
    static Vector3f ComputeTangent (
        const Vector3f& rkPos0, const Vector2f& rkTCoord0,
        const Vector3f& rkPos1, const Vector2f& rkTCoord1,
        const Vector3f& rkPos2, const Vector2f& rkTCoord2);
};

WM4_REGISTER_STREAM(Triangles);
typedef Pointer<Triangles> TrianglesPtr;

}

#endif
