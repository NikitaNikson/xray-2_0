// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CURVESEGMENT_H
#define WM4CURVESEGMENT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4Vector3.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CurveSegment : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~CurveSegment ();

    // The parametric domain is umin <= u <= umax.
    float GetUMin () const;
    float GetUMax () const;

    // position and derivatives up to third order
    virtual Vector3f P (float fU) const = 0;
    virtual Vector3f PU (float fU) const = 0;
    virtual Vector3f PUU (float fU) const = 0;
    virtual Vector3f PUUU (float fU) const = 0;

    // differential geometric quantities
    Vector3f Tangent (float fU) const;
    Vector3f Normal (float fU) const;
    Vector3f Binormal (float fU) const;
    void GetFrame (float fU, Vector3f& rkPosition, Vector3f& rkTangent,
        Vector3f& rkNormal, Vector3f& rkBinormal) const;
    float Curvature (float fU) const;
    float Torsion (float fU) const;

protected:
    CurveSegment (float fUMin, float fUMax);
    CurveSegment ();

    float m_fUMin, m_fUMax;
};

WM4_REGISTER_STREAM(CurveSegment);
typedef Pointer<CurveSegment> CurveSegmentPtr;
#include "Wm4CurveSegment.inl"

}

#endif
