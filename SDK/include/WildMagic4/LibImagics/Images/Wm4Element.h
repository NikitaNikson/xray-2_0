// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4ELEMENT_H
#define WM4ELEMENT_H

#include "Wm4ImagicsLIB.h"
#include "Wm4System.h"

// wrappers for native types
const int WM4_ELEMENT_QUANTITY = 12;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned short rgb5;
typedef unsigned int rgb8;

#define Wm4DeclareElement(T) \
class WM4_IMAGICS_ITEM E##T \
{ \
public: \
    E##T (T tValue = 0) { m_tValue = tValue; } \
    \
    E##T& operator= (E##T kElement) \
    { \
        m_tValue = kElement.m_tValue; \
        return *this; \
    } \
    \
    operator T () { return m_tValue; } \
    \
    static int GetRTTI () { return ms_iRTTI; } \
    \
protected: \
    T m_tValue; \
    static const int ms_iRTTI; \
}

#define Wm4ImplementElement(T,iRTTI) \
const int E##T::ms_iRTTI = iRTTI

namespace Wm4
{

Wm4DeclareElement(char);
Wm4DeclareElement(uchar);
Wm4DeclareElement(short);
Wm4DeclareElement(ushort);
Wm4DeclareElement(int);
Wm4DeclareElement(uint);
Wm4DeclareElement(long);
Wm4DeclareElement(ulong);
Wm4DeclareElement(float);
Wm4DeclareElement(double);
Wm4DeclareElement(rgb5);
Wm4DeclareElement(rgb8);

#include "Wm4Element.inl"

}

#endif
