// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
template <class Real>
Capsule3<Real>::Capsule3 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Capsule3<Real>::Capsule3 (const Segment3<Real>& rkSegment, Real fRadius)
    :
    Segment(rkSegment)
{
    Radius = fRadius;
}
//----------------------------------------------------------------------------
