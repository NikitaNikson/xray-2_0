// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4PICKER_H
#define WM4PICKER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4PickRecord.h"
#include "Wm4Vector3.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Picker
{
public:
    Picker ();

    // The linear component is parameterized by P + t*D, where P is a point on
    // the component (P is the origin), D is a unit-length direction, and t is
    // a scalar in the interval [tmin,tmax] with tmin < tmax.  The P and D
    // values must be in world coordinates.  The choices for tmin and tmax are
    //   line:     tmin = -Mathf::MAX_REAL, tmax = Mathf::MAX_REAL
    //   ray:      tmin = 0, tmax = Mathf::MAX_REAL
    //   segment:  tmin = 0, tmax > 0;
    //
    // A call to this function will automatically clear the Records array.
    // If you need any information from this array obtained by a previous
    // call to Execute, you must save it first.
    void Execute (Spatial* pkScene, const Vector3f& rkOrigin,
        const Vector3f& rkDirection, float fTMin, float fTMax);

    // The following three functions return the index of the record satisfying
    // the constraints.  They should be called only if Records.size() > 0.
    // The index i satisfies 0 <= i < Records.size().

    // Locate the record whose T value is smallest in absolute value.
    const PickRecord& GetClosestToZero () const;

    // Locate the record with nonnegative T value closest to zero.
    const PickRecord& GetClosestNonnegative () const;

    // Locate the record with nonpositive T value closest to zero.
    const PickRecord& GetClosestNonpositive () const;

    std::vector<PickRecord> Records;

private:
    // The picking occurs recursively by traversing the input scene.
    void ExecuteRecursive (Spatial* pkObject);

    Vector3f m_kOrigin, m_kDirection;
    float m_fTMin, m_fTMax;

    // The value returned if the Get* functions are called when Records has
    // no elements.
    static const PickRecord ms_kInvalid;
};

}

#endif
