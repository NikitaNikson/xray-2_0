// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4MTITriangle.h"
using namespace Wm4;

//----------------------------------------------------------------------------
MTITriangle::MTITriangle (int iLabel0, int iLabel1, int iLabel2)
{
    if (iLabel0 < iLabel1)
    {
        if (iLabel0 < iLabel2)
        {
            // L0 is minimum
            m_aiLabel[0] = iLabel0;
            m_aiLabel[1] = iLabel1;
            m_aiLabel[2] = iLabel2;
        }
        else
        {
            // L2 is minimum
            m_aiLabel[0] = iLabel2;
            m_aiLabel[1] = iLabel0;
            m_aiLabel[2] = iLabel1;
        }
    }
    else
    {
        if (iLabel1 < iLabel2)
        {
            // L1 is minimum
            m_aiLabel[0] = iLabel1;
            m_aiLabel[1] = iLabel2;
            m_aiLabel[2] = iLabel0;
        }
        else
        {
            // L2 is minimum
            m_aiLabel[0] = iLabel2;
            m_aiLabel[1] = iLabel0;
            m_aiLabel[2] = iLabel1;
        }
    }
}
//----------------------------------------------------------------------------
inline int MTITriangle::GetLabel (int i) const
{
    assert(0 <= i && i < 3);
    return m_aiLabel[i];
}
//----------------------------------------------------------------------------
bool MTITriangle::operator< (const MTITriangle& rkT) const
{
    if (m_aiLabel[2] < rkT.m_aiLabel[2])
        return true;

    if (m_aiLabel[2] == rkT.m_aiLabel[2])
    {
        if (m_aiLabel[1] < rkT.m_aiLabel[1])
        {
            return true;
        }

        if (m_aiLabel[1] == rkT.m_aiLabel[1])
        {
            return m_aiLabel[0] < rkT.m_aiLabel[0];
        }
    }

    return false;
}
//----------------------------------------------------------------------------
bool MTITriangle::operator== (const MTITriangle& rkT) const
{
    return (m_aiLabel[0] == rkT.m_aiLabel[0]) &&
    ((m_aiLabel[1] == rkT.m_aiLabel[1] && m_aiLabel[2] == rkT.m_aiLabel[2])
    ||
    (m_aiLabel[1] == rkT.m_aiLabel[2] && m_aiLabel[2] == rkT.m_aiLabel[1]));
}
//----------------------------------------------------------------------------
bool MTITriangle::operator!= (const MTITriangle& rkT) const
{
    return !operator==(rkT);
}
//----------------------------------------------------------------------------
