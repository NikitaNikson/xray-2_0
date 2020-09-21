// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4MTIEdge.h"
using namespace Wm4;

//----------------------------------------------------------------------------
MTIEdge::MTIEdge (int iLabel0, int iLabel1)
{
    if (iLabel0 < iLabel1)
    {
        // L0 is minimum
        m_aiLabel[0] = iLabel0;
        m_aiLabel[1] = iLabel1;
    }
    else
    {
        // L1 is minimum
        m_aiLabel[0] = iLabel1;
        m_aiLabel[1] = iLabel0;
    }
}
//----------------------------------------------------------------------------
int MTIEdge::GetLabel (int i) const
{
    assert(0 <= i && i < 2);
    return m_aiLabel[i];
}
//----------------------------------------------------------------------------
bool MTIEdge::operator< (const MTIEdge& rkE) const
{
    if (m_aiLabel[1] < rkE.m_aiLabel[1])
    {
        return true;
    }

    if (m_aiLabel[1] == rkE.m_aiLabel[1])
    {
        return m_aiLabel[0] < rkE.m_aiLabel[0];
    }

    return false;
}
//----------------------------------------------------------------------------
bool MTIEdge::operator== (const MTIEdge& rkE) const
{
    return m_aiLabel[0] == rkE.m_aiLabel[0]
        && m_aiLabel[1] == rkE.m_aiLabel[1];
}
//----------------------------------------------------------------------------
bool MTIEdge::operator!= (const MTIEdge& rkE) const
{
    return !operator==(rkE);
}
//----------------------------------------------------------------------------
