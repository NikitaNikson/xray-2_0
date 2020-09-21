// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4MTIVertex.h"
using namespace Wm4;

//----------------------------------------------------------------------------
MTIVertex::MTIVertex (int iLabel)
{
    m_iLabel = iLabel;
}
//----------------------------------------------------------------------------
int MTIVertex::GetLabel () const
{
    return m_iLabel;
}
//----------------------------------------------------------------------------
bool MTIVertex::operator< (const MTIVertex& rkV) const
{
    return m_iLabel < rkV.m_iLabel;
}
//----------------------------------------------------------------------------
bool MTIVertex::operator== (const MTIVertex& rkV) const
{
    return m_iLabel == rkV.m_iLabel;
}
//----------------------------------------------------------------------------
bool MTIVertex::operator!= (const MTIVertex& rkV) const
{
    return m_iLabel != rkV.m_iLabel;
}
//----------------------------------------------------------------------------
