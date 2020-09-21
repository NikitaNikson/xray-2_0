// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4Rtti.h"
using namespace Wm4;

//----------------------------------------------------------------------------
Rtti::Rtti (const char* acName, const Rtti* pkBaseType)
{
    m_acName = acName;
    m_pkBaseType = pkBaseType;
}
//----------------------------------------------------------------------------
Rtti::~Rtti ()
{
}
//----------------------------------------------------------------------------
bool Rtti::IsDerived (const Rtti& rkType) const
{
    const Rtti* pkSearch = this;
    while (pkSearch)
    {
        if (pkSearch == &rkType)
        {
            return true;
        }
        pkSearch = pkSearch->m_pkBaseType;
    }
    return false;
}
//----------------------------------------------------------------------------
