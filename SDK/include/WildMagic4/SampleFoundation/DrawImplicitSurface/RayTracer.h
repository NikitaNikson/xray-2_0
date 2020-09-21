// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Wm4Vector3.h"
using namespace Wm4;

class RayTracer
{
public:
    typedef float (*Function)(const Vector3f&);
    typedef Vector3f (*Gradient)(const Vector3f&);

    // Ray trace level surface F(x,y,z) = 0.  The surface normals are
    // computed from DF(x,y,z), the gradient of F.
    RayTracer (Function oF, Gradient oDF, int iWidth, int iHeight);
    ~RayTracer ();

    // camera and view frustum
    Vector3f& Location ();
    Vector3f& Direction ();
    Vector3f& Up ();
    Vector3f& Right ();
    float& Near ();
    float& Far ();
    float& HalfWidth ();
    float& HalfHeight ();

    // rendered image
    int GetWidth () const;
    int GetHeight () const;
    const float* GetImage () const;

    // Ray trace the view frustum region.  The tracing uses a single
    // directional light.  TO DO:  Allow more lights and different light
    // types.  The number of samples per ray for computing intersection of
    // rays with the surface is specified in iMaxSample.
    void DrawSurface (int iMaxSample, const Vector3f& rkLightDir, bool bBlur);

private:
    // find intersection of ray with surface
    void FindSurface (float fS0, float fF0, const Vector3f& rkP0, float fS1,
        float fF1, const Vector3f& rkP1, const Vector3f& kRayDir,
        Vector3f& rkPos, Vector3f& rkNormal);

    // blur the image for a cheap antialiasing
    void BlurImage ();

    // camera and view frustum
    Vector3f m_kLocation, m_kDirection, m_kUp, m_kRight;
    float m_fNear, m_fFar, m_fHalfWidth, m_fHalfHeight;

    // level surface F(x,y,z) = 0, surface normal DF(x,y,z)
    Function m_oF;
    Gradient m_oDF;

    // rendered image
    int m_iWidth, m_iHeight;
    float* m_afImage;
    float* m_afBlur;
};

#include "RayTracer.inl"

#endif
