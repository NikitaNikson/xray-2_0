// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4System.h"
#include "Wm4NumericalConstant.h"
using namespace Wm4;

//----------------------------------------------------------------------------
NumericalConstant::NumericalConstant (int iRegister, float afData[4])
{
    assert(iRegister >= 0);

    m_iRegister = iRegister;
    for (int i = 0; i < 4; i++)
    {
        m_afData[i] = afData[i];
    }
}
//----------------------------------------------------------------------------
NumericalConstant::~NumericalConstant ()
{
}
//----------------------------------------------------------------------------
