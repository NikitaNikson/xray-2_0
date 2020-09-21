// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Polyline3.h"
#include "VertexCollapse.h"

//----------------------------------------------------------------------------
Polyline3::Polyline3 (int iVQuantity, Vector3f* akVertex, bool bClosed)
{
    assert(akVertex  && (bClosed ? iVQuantity >= 3 : iVQuantity >= 2));

    m_iVQuantity = iVQuantity;
    m_akVertex = akVertex;
    m_bClosed = bClosed;

    // compute the vertex collapses
    VertexCollapse(m_iVQuantity,m_akVertex,m_bClosed,m_aiMap,m_iEQuantity,
        m_aiEdge);

    // polyline initially at full level of detail
    m_iVMin = (m_bClosed ? 3 : 2);
    m_iVMax = m_iVQuantity;
}
//----------------------------------------------------------------------------
Polyline3::~Polyline3 ()
{
    WM4_DELETE[] m_akVertex;
    WM4_DELETE[] m_aiEdge;
    WM4_DELETE[] m_aiMap;
}
//----------------------------------------------------------------------------
void Polyline3::SetLevelOfDetail (int iVQuantity)
{
    if (iVQuantity < m_iVMin || iVQuantity > m_iVMax)
    {
        return;
    }

    // decrease level of detail
    while (m_iVQuantity > iVQuantity)
    {
        m_iVQuantity--;
        m_aiEdge[m_aiMap[m_iVQuantity]] = m_aiEdge[2*m_iEQuantity-1];
        m_iEQuantity--;
    }

    // increase level of detail
    while (m_iVQuantity < iVQuantity)
    {
        m_iEQuantity++;
        m_aiEdge[m_aiMap[m_iVQuantity]] = m_iVQuantity;
        m_iVQuantity++;
    }
}
//----------------------------------------------------------------------------
