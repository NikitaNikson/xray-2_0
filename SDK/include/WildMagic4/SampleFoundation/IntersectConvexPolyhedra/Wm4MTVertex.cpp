// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4MTVertex.h"
using namespace Wm4;

//----------------------------------------------------------------------------
MTVertex::MTVertex (int iLabel, int iEGrow, int iTGrow)
    :
    m_kESet(iEGrow,iEGrow),
    m_kTSet(iTGrow,iTGrow)
{
    m_iLabel = iLabel;
}
//----------------------------------------------------------------------------
MTVertex::MTVertex (const MTVertex& rkV)
    :
    m_kESet(rkV.m_kESet),
    m_kTSet(rkV.m_kTSet)
{
    m_iLabel = rkV.m_iLabel;
}
//----------------------------------------------------------------------------
MTVertex::~MTVertex ()
{
}
//----------------------------------------------------------------------------
MTVertex& MTVertex::operator= (const MTVertex& rkV)
{
    m_kESet = rkV.m_kESet;
    m_kTSet = rkV.m_kTSet;
    m_iLabel = rkV.m_iLabel;
    return *this;
}
//----------------------------------------------------------------------------
bool MTVertex::InsertEdge (int iE)
{
    return m_kESet.Insert(iE);
}
//----------------------------------------------------------------------------
bool MTVertex::RemoveEdge (int iE)
{
    return m_kESet.Remove(iE);
}
//----------------------------------------------------------------------------
bool MTVertex::ReplaceEdge (int iEOld, int iENew)
{
    for (int i = 0; i < m_kESet.GetQuantity(); i++)
    {
        if (m_kESet[i] == iEOld)
        {
            m_kESet[i] = iENew;
            return true;
        }
    }

    return false;
}
//----------------------------------------------------------------------------
bool MTVertex::InsertTriangle (int iT)
{
    return m_kTSet.Insert(iT);
}
//----------------------------------------------------------------------------
bool MTVertex::RemoveTriangle (int iT)
{
    return m_kTSet.Remove(iT);
}
//----------------------------------------------------------------------------
bool MTVertex::ReplaceTriangle (int iTOld, int iTNew)
{
    for (int i = 0; i < m_kTSet.GetQuantity(); i++)
    {
        if (m_kTSet[i] == iTOld)
        {
            m_kTSet[i] = iTNew;
            return true;
        }
    }

    return false;
}
//----------------------------------------------------------------------------
bool MTVertex::operator== (const MTVertex& rkV) const
{
    return m_iLabel == rkV.m_iLabel;
}
//----------------------------------------------------------------------------
