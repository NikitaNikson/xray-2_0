// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Segmentation.h"
#include "Polysolid2.h"
#include "SegmentEdge.h"

int Segmentation::ms_aiKlein4[4][4] =
{
    { 0, 1, 2, 3 },
    { 1, 0, 3, 2 },
    { 2, 3, 0, 1 },
    { 3, 2, 1, 0 }
};

//----------------------------------------------------------------------------
Segmentation::Segmentation (const RPoint2& rkNormal,
    const Rational& rkConstant)
    :
    m_kNormal(rkNormal),
    m_kConstant(rkConstant)
{
}
//----------------------------------------------------------------------------
Segmentation::~Segmentation ()
{
}
//----------------------------------------------------------------------------
bool Segmentation::HasPoints () const
{
    return m_kList.size() > 0;
}
//----------------------------------------------------------------------------
void Segmentation::AddPoint (const RPoint2& rkPosition, int eTag)
{
    Rational kOrder = m_kNormal.DotPerp(rkPosition);

    std::list<TaggedPoint>::iterator pkPoint;
    for (pkPoint = m_kList.begin(); pkPoint != m_kList.end(); pkPoint++)
    {
        if (kOrder == pkPoint->Order)
        {
            // point already in segmentation, adjust its tag
            pkPoint->Tag = ms_aiKlein4[eTag][pkPoint->Tag];
            return;
        }

        if (kOrder < pkPoint->Order)
        {
            break;
        }
    }

    // point not in segmentation, add it
    if (m_kList.size() == 0 || pkPoint == m_kList.begin())
    {
        m_kList.push_front(TaggedPoint(kOrder,rkPosition,eTag));
    }
    else if (pkPoint == m_kList.end())
    {
        m_kList.push_back(TaggedPoint(kOrder,rkPosition,eTag));
    }
    else
    {
        m_kList.insert(pkPoint,TaggedPoint(kOrder,rkPosition,eTag));
    }
}
//----------------------------------------------------------------------------
void Segmentation::SegmentBy (const Polysolid2& rkPoly)
{
    const Polysolid2::ESet& rkESet = rkPoly.GetEdges();
    Polysolid2::ESet::const_iterator pkIter;
    for (pkIter = rkESet.begin(); pkIter != rkESet.end(); pkIter++)
    {
        const Polysolid2::Vertex* pkV0 = pkIter->GetVertex(0);
        const Polysolid2::Vertex* pkV1 = pkIter->GetVertex(1);
        const RPoint2& rkPosition0 = pkV0->Position;
        const RPoint2& rkPosition1 = pkV1->Position;
        Rational kDot0 = m_kNormal.Dot(rkPosition0);
        Rational kDot1 = m_kNormal.Dot(rkPosition1);

        Rational kT;
        RPoint2 kIntr;

        if (kDot0 > m_kConstant)
        {
            if (kDot1 > m_kConstant)
            {
                // edge does not intersect line
            }
            else if (kDot1 < m_kConstant)
            {
                // edge crosses line
                kT = (m_kConstant - kDot0)/(kDot1 - kDot0);
                kIntr = rkPosition0 + (rkPosition1 - rkPosition0)*kT;
                AddPoint(kIntr,ITAG);
            }
            else  // dot1 == line.constant
            {
                // end point of edge is on line
                AddPoint(rkPosition1,PTAG);
            }
        }
        else if (kDot0 < m_kConstant)
        {
            if (kDot1 > m_kConstant)
            {
                // edge crosses line
                kT = (m_kConstant - kDot0)/(kDot1 - kDot0);
                kIntr = rkPosition0 + (rkPosition1 - rkPosition0)*kT;
                AddPoint(kIntr,ITAG);
            }
            else if (kDot1 < m_kConstant)
            {
                // edge does not intersect line
            }
            else  // dot1 == line.constant
            {
                // end point of edge is on line
                AddPoint(rkPosition1,MTAG);
            }
        }
        else  // dot0 == line.constant
        {
            if (kDot1 > m_kConstant)
            {
                // end point of edge is on line
                AddPoint(rkPosition0,PTAG);
            }
            else if (kDot1 < m_kConstant)
            {
                // end point of edge is on line
                AddPoint(rkPosition0,MTAG);
            }
            else  // dot1 == line.constant
            {
                // edge is on the line
            }
        }
    }
}
//----------------------------------------------------------------------------
void Segmentation::IntersectWith (const RPoint2& rkPosition0,
    const RPoint2& rkPosition1)
{
    Rational kOrder0 = m_kNormal.DotPerp(rkPosition0);
    int eTag = OTAG;
    while (true)
    {
        if (m_kList.size() == 0)
        {
            return;
        }

        TaggedPoint& rkFirst = m_kList.front();
        if (kOrder0 < rkFirst.Order)
        {
            m_kList.push_front(TaggedPoint(kOrder0,rkPosition0,eTag));
            break;
        }

        eTag = ms_aiKlein4[eTag][rkFirst.Tag];
        m_kList.pop_front();
    }

    Rational kOrder1 = m_kNormal.DotPerp(rkPosition1);
    eTag = OTAG;
    while (true)
    {
        if (m_kList.size() == 0)
        {
            return;
        }

        TaggedPoint& rkLast = m_kList.back();
        if (kOrder1 > rkLast.Order)
        {
            m_kList.push_back(TaggedPoint(kOrder1,rkPosition1,eTag));
            break;
        }

        eTag = ms_aiKlein4[eTag][rkLast.Tag];
        m_kList.pop_back();
    }
}
//----------------------------------------------------------------------------
void Segmentation::ConvertToEdges (SegmentEdge akTEdge[4])
{
    std::list<TaggedPoint>::iterator pkCurr = m_kList.begin();
    std::list<TaggedPoint>::iterator pkNext = m_kList.begin();
    pkNext++;

    for (int eTag = OTAG; pkNext != m_kList.end(); pkCurr++, pkNext++)
    {
        eTag = ms_aiKlein4[eTag][pkCurr->Tag];
        akTEdge[eTag].AddEdge(pkCurr->Position,pkNext->Position);
    }
}
//----------------------------------------------------------------------------
