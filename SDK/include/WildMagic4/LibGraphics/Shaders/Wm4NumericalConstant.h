// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4NUMERICALCONSTANT_H
#define WM4NUMERICALCONSTANT_H

#include "Wm4GraphicsLIB.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM NumericalConstant
{
public:
    // Construction and destruction.  The register must be nonnegative.  A
    // numerical constant corresponds to four floating-point numbers.
    NumericalConstant (int iRegister, float afData[4]);
    ~NumericalConstant ();

    // Member access.  The renderer will use these to pass the information to
    // the graphics API (specifically, to DirectX).
    int GetRegister () const;
    float* GetData () const;

private:
    int m_iRegister;
    float m_afData[4];
};

#include "Wm4NumericalConstant.inl"

}

#endif
