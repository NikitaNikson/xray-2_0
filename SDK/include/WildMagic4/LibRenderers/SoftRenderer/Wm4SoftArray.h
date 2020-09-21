// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTARRAY_H
#define WM4SOFTARRAY_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4System.h"

namespace Wm4
{

template <typename Type>
class SoftArray
{
public:
    SoftArray (int iMaxQuantity);
    SoftArray (const SoftArray& rkObject);
    ~SoftArray ();

    SoftArray& operator= (const SoftArray& rkObject);

    int GetQuantity () const;
    int GetMaxQuantity () const;
    Type* GetData ();
    const Type* GetData () const;

    void EnsureCapacity (int iRequestedMaxQuantity);
    void Clear ();
    void Append (Type tValue);
    Type Get (int i) const;

private:
    int m_iQuantity, m_iMaxQuantity;
    Type* m_atData;
};

#include "Wm4SoftArray.inl"

}

#endif
