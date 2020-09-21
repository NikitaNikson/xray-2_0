// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SMARTPOINTER_H
#define WM4SMARTPOINTER_H

#include "Wm4GraphicsLIB.h"

namespace Wm4
{

template <class T>
class Pointer
{
public:
    // construction and destruction
    Pointer (T* pkObject = 0);
    Pointer (const Pointer& rkPointer);
    ~Pointer ();

    // implicit conversions
    operator T* () const;
    T& operator* () const;
    T* operator-> () const;

    // assignment
    Pointer& operator= (T* pkObject);
    Pointer& operator= (const Pointer& rkReference);

    // comparisons
    bool operator== (T* pkObject) const;
    bool operator!= (T* pkObject) const;
    bool operator== (const Pointer& rkReference) const;
    bool operator!= (const Pointer& rkReference) const;

protected:
    // the shared object
    T* m_pkObject;
};

#include "Wm4SmartPointer.inl"

}

#endif
