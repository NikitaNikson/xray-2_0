// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ImagicsPCH.h"
#include "Wm4FastMarch.h"
using namespace Wm4;

//----------------------------------------------------------------------------
FastMarch::FastMarch (int iQuantity, const float* afSpeed,
    const std::vector<int>& rkSeeds)
    :
    m_kHeap(iQuantity,1)
{
    Initialize(iQuantity,rkSeeds);
    InitializeSpeed(afSpeed);
}
//----------------------------------------------------------------------------
FastMarch::FastMarch (int iQuantity, const float fSpeed,
    const std::vector<int>& rkSeeds)
    :
    m_kHeap(iQuantity,1)
{
    Initialize(iQuantity,rkSeeds);
    InitializeSpeed(fSpeed);
}
//----------------------------------------------------------------------------
FastMarch::~FastMarch ()
{
    WM4_DELETE[] m_apkTrial;
    WM4_DELETE[] m_afInvSpeed;
    WM4_DELETE[] m_afTime;
}
//----------------------------------------------------------------------------
void FastMarch::Initialize (int iQuantity, const std::vector<int>& rkSeeds)
{
    m_iQuantity = iQuantity;

    // The seed points have a crossing time of 0.  As the iterations occur,
    // some of the non-seed points are visited by the moving front.  The
    // valid crossing times are 0 <= t < MAX_REAL.  A value of MAX_REAL
    // indicates the pixel has not yet been reached by the moving front.  If
    // the speed value at a pixel is 0, the pixel is marked with a time of
    // -MAX_REAL.  Such pixels can never be visited; the minus sign
    // distinguishes these from pixels not yet reached during iteration.
    m_afTime = WM4_NEW float[m_iQuantity];
    int i;
    for (i = 0; i < m_iQuantity; i++)
    {
        m_afTime[i] = Mathf::MAX_REAL;
    }

    for (i = 0; i < (int)rkSeeds.size(); i++)
    {
        m_afTime[rkSeeds[i]] = 0.0f;
    }

    // Trial pixels are identified by having min-heap record associated with
    // them.  Known or Far pixels have no associated record.
    m_apkTrial = WM4_NEW const TMinHeapRecord<int,float>*[m_iQuantity];
    size_t uiSize = m_iQuantity*sizeof(const TMinHeapRecord<int,float>*);
    memset(m_apkTrial,0,uiSize);
}
//----------------------------------------------------------------------------
void FastMarch::InitializeSpeed (const float* afSpeed)
{
    // Invert the speeds since the reciprocals are all that are needed in the
    // numerical method.  Mark all zero-speed interior pixels.
    m_afInvSpeed = WM4_NEW float[m_iQuantity];
    for (int i = 0; i < m_iQuantity; i++)
    {
        assert(afSpeed[i] >= 0.0f);
        if (afSpeed[i] > 0.0f)
        {
            m_afInvSpeed[i] = 1.0f/afSpeed[i];
        }
        else
        {
            m_afInvSpeed[i] = Mathf::MAX_REAL;
            m_afTime[i] = -Mathf::MAX_REAL;
        }
    }
}
//----------------------------------------------------------------------------
void FastMarch::InitializeSpeed (const float fSpeed)
{
    float fInvSpeed = 1.0f/fSpeed;
    m_afInvSpeed = WM4_NEW float[m_iQuantity];
    for (int i = 0; i < m_iQuantity; i++)
    {
        m_afInvSpeed[i] = fInvSpeed;
    }
}
//----------------------------------------------------------------------------
void FastMarch::GetTimeExtremes (float& rfMin, float& rfMax) const
{
    rfMin = Mathf::MAX_REAL;
    rfMax = -Mathf::MAX_REAL;
    int i;
    for (i = 0; i < m_iQuantity; i++)
    {
        if (IsValid(i))
        {
            rfMin = m_afTime[i];
            rfMax = rfMin;
            break;
        }
    }
    assert(i < m_iQuantity);

    for (/**/; i < m_iQuantity; i++)
    {
        if (IsValid(i))
        {
            if (m_afTime[i] < rfMin)
            {
                rfMin = m_afTime[i];
            }
            else if (m_afTime[i] > rfMax)
            {
                rfMax = m_afTime[i];
            }
        }
    }
}
//----------------------------------------------------------------------------
void FastMarch::GetInterior (std::vector<int>& rkInterior) const
{
    for (int i = 0; i < m_iQuantity; i++)
    {
        if (IsValid(i) && !IsTrial(i))
        {
            rkInterior.push_back(i);
        }
    }
}
//----------------------------------------------------------------------------
