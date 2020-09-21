// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4TIMAGE3D_H
#define WM4TIMAGE3D_H

#include "Wm4ImagicsLIB.h"
#include "Wm4TImage.h"

namespace Wm4
{

template <class T>
class TImage3D : public TImage<T>
{
public:
    // Construction and destruction.  TImage3D accepts responsibility for
    // deleting the input data array.
    TImage3D (int iXBound, int iYBound, int iZBound, T* atData = 0);
    TImage3D (const TImage3D& rkImage);
    TImage3D (const char* acFilename);

    // data access
    T& operator() (int iX, int iY, int iZ) const;

    // conversion between 3D coordinates and 1D indexing
    int GetIndex (int iX, int iY, int iZ) const;
    void GetCoordinates (int iIndex, int& riX, int& riY, int& riZ) const;

    // assignment
    TImage3D& operator= (const TImage3D& rkImage);
    TImage3D& operator= (T tValue);

protected:
    using TImage<T>::SetData;
    using TImage<T>::m_atData;
};

#include "Wm4TImage3D.inl"

}

#endif
