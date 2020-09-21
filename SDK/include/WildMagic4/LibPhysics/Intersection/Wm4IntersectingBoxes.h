// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4INTERSECTINGBOXES_H
#define WM4INTERSECTINGBOXES_H

#include "Wm4PhysicsLIB.h"
#include "Wm4AxisAlignedBox3.h"
#include "Wm4EdgeKey.h"

namespace Wm4
{

template <class Real>
class WM4_PHYSICS_ITEM IntersectingBoxes
{
public:
    // construction and destruction
    IntersectingBoxes (std::vector<AxisAlignedBox3<Real> >& rkBoxes);
    ~IntersectingBoxes ();

    // This function is called by the constructor and does the sort-and-sweep
    // to initialize the update system.  However, if you add or remove items
    // from the array of boxes after the constructor call, you will need
    // to call this function once before you start the multiple calls of the
    // update function.
    void Initialize ();

    // After the system is initialized, you can move the boxes using this
    // function.  It is not enough to modify the input array of boxes
    // since the end point values stored internally by this class must also
    // change.  You can also retrieve the current rectangles information.
    void SetBox (int i, const AxisAlignedBox3<Real>& rkRect);
    void GetBox (int i, AxisAlignedBox3<Real>& rkRect) const;
    
    // When you are finished moving rectangles, call this function to
    // determine the overlapping boxes.  An incremental update is applied
    // to determine the new set of overlapping boxes.
    void Update ();

    // If (i,j) is in the overlap set, then box i and box j are
    // overlapping.  The indices are those for the the input array.  The
    // set elements (i,j) are stored so that i < j.
    const std::set<EdgeKey>& GetOverlap () const;

private:
    class WM4_PHYSICS_ITEM EndPoint
    {
    public:
        Real Value;
        int Type;  // '0' if interval min, '1' if interval max
        int Index;  // index of interval containing this end point

        // support for sorting of end points
        bool operator< (const EndPoint& rkEP) const
        {
            if (Value < rkEP.Value)
            {
                return true;
            }
            if (Value > rkEP.Value)
            {
                return false;
            }
            return Type < rkEP.Type;
        }
    };

    void InsertionSort (std::vector<EndPoint>& rkEndPoint,
        std::vector<int>& rkLookup);

    std::vector<AxisAlignedBox3<Real> >* m_pkBoxes;
    std::vector<EndPoint> m_kXEndPoint, m_kYEndPoint, m_kZEndPoint;
    std::set<EdgeKey> m_kOverlap;

    // The intervals are indexed 0 <= i < n.  The end point array has 2*n
    // entries.  The original 2*n interval values are ordered as b[0], e[0],
    // b[1], e[1], ..., b[n-1], e[n-1].  When the end point array is sorted,
    // the mapping between interval values and end points is lost.  In order
    // to modify interval values that are stored in the end point array, we
    // need to maintain the mapping.  This is done by the following lookup
    // table of 2*n entries.  The value m_kLookup[2*i] is the index of b[i]
    // in the end point array.  The value m_kLookup[2*i+1] is the index of
    // e[i] in the end point array.
    std::vector<int> m_kXLookup, m_kYLookup, m_kZLookup;
};

typedef IntersectingBoxes<float> IntersectingBoxesf;
typedef IntersectingBoxes<double> IntersectingBoxesd;

}

#endif
