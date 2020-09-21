// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4BINARY3D_H
#define WM4BINARY3D_H

#include "Wm4ImagicsLIB.h"
#include "Wm4Images.h"

namespace Wm4
{

class Binary3D : public ImageInt3D
{
public:
    // Construction and destruction.  Binary3D accepts responsibility for
    // deleting the input data array.
    WM4_IMAGICS_ITEM Binary3D (int iXBound, int iYBound, int iZBound,
        Eint* atData = 0);
    WM4_IMAGICS_ITEM Binary3D (const Binary3D& rkImage);
    WM4_IMAGICS_ITEM Binary3D (const char* acFilename);

    // Compute the connected components of a binary image.  The components in
    // the returned image are labeled with positive integer values.  If the
    // image is identically zero, then the components image is identically
    // zero and the returned quantity is zero.
    WM4_IMAGICS_ITEM void GetComponents (int& riQuantity,
        ImageInt3D& rkComponents) const;

protected:
    // helper for component labeling
    void AddToAssociative (int i0, int i1, int* aiAssoc) const;
};

}

#endif
