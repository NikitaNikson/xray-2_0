// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4UserConstant.h"
using namespace Wm4;

//----------------------------------------------------------------------------
UserConstant::UserConstant (const std::string& rkName, int iBaseRegister,
    int iRegisterQuantity)
    :
    m_kName(rkName)
{
    assert(iBaseRegister >= 0);
    assert(iRegisterQuantity > 0);

    m_iBaseRegister = iBaseRegister;
    m_iRegisterQuantity = iRegisterQuantity;

    // To be set later in the effect creation.
    m_afData = 0;
}
//----------------------------------------------------------------------------
UserConstant::~UserConstant ()
{
    // The memory pointed to by m_afData is not owned by UserConstant, so
    // no deletion occurs here.
}
//----------------------------------------------------------------------------
void UserConstant::SetDataSource (float* afData)
{
    assert(afData);

    m_afData = afData;
}
//----------------------------------------------------------------------------
