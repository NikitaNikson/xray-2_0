// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4UNORDEREDSET_H
#define WM4UNORDEREDSET_H

// An unordered set of objects stored in contiguous memory.  The type T must
// have the following member functions:
//   T::T();
//   T::~T();
//   T& operator= (const T&);
//   bool operator== (const T&) const;

#include "Wm4System.h"

namespace Wm4
{

template <class T>
class UnorderedSet
{
public:
    UnorderedSet (int iMaxQuantity = 0, int iGrow = 0);
    UnorderedSet (const UnorderedSet& rkSet);
    ~UnorderedSet ();

    void Reset (int iMaxQuantity = 0, int iGrow = 0);
    void Clear ();
    UnorderedSet& operator= (const UnorderedSet& rkSet);

    int GetMaxQuantity () const;
    int GetGrow () const;

    int GetQuantity () const;
    const T& Get (int i) const;
    T& operator[] (int i);

    bool Exists (const T& rtElement) const;
    bool Insert (const T& rtElement);
    int Append (const T& rtElement);
    bool Remove (const T& rtElement, int* piOld = 0, int* piNew = 0);
    bool RemoveAt (int i, int* piOld = 0, int* piNew = 0);
    void Compactify ();

    enum { DEFAULT_GROW = 8 };

protected:
    int m_iQuantity, m_iMaxQuantity, m_iGrow;
    T* m_atElement;
};

#include "Wm4UnorderedSet.inl"

}

#endif
