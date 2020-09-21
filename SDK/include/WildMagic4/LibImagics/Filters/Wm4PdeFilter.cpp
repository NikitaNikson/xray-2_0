// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ImagicsPCH.h"
#include "Wm4PdeFilter.h"
using namespace Wm4;

//----------------------------------------------------------------------------
PdeFilter::PdeFilter (int iQuantity, const float* afData, float fBorderValue,
    ScaleType eScaleType)
{
    assert(afData);

    m_iQuantity = iQuantity;
    m_fBorderValue = fBorderValue;
    m_eScaleType = eScaleType;
    m_fTimeStep = 0.0f;

    float fMax = afData[0];
    m_fMin = fMax;
    for (int i = 1; i < m_iQuantity; i++)
    {
        float fValue = afData[i];
        if (fValue < m_fMin)
        {
            m_fMin = fValue;
        }
        else if (fValue > fMax)
        {
            fMax = fValue;
        }
    }

    if (m_fMin != fMax)
    {
        switch (m_eScaleType)
        {
        case ST_NONE:
            m_fOffset = 0.0f;
            m_fScale = 1.0f;
            break;
        case ST_UNIT:
            m_fOffset = 0.0f;
            m_fScale = 1.0f/(fMax - m_fMin);
            break;
        case ST_SYMMETRIC:
            m_fOffset = -1.0f;
            m_fScale = 2.0f/(fMax - m_fMin);
            break;
        case ST_PRESERVE_ZERO:
            m_fOffset = 0.0f;
            m_fScale = (fMax >= -m_fMin ? 1.0f/fMax : -1.0f/m_fMin);
            m_fMin = 0.0f;
            break;
        }
    }
    else
    {
        m_fOffset = 0.0f;
        m_fScale = 1.0f;
    }
}
//----------------------------------------------------------------------------
PdeFilter::~PdeFilter ()
{
}
//----------------------------------------------------------------------------
void PdeFilter::Update ()
{
    OnPreUpdate();
    OnUpdate();
    OnPostUpdate();
}
//----------------------------------------------------------------------------
