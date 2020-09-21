// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ImagicsPCH.h"
#include "Wm4GaussianBlur2.h"
using namespace Wm4;

//----------------------------------------------------------------------------
GaussianBlur2::GaussianBlur2 (int iXBound, int iYBound, float fXSpacing,
    float fYSpacing, const float* afData, const bool* abMask,
    float fBorderValue, ScaleType eType)
    :
    PdeFilter2(iXBound,iYBound,fXSpacing,fYSpacing,afData,abMask,fBorderValue,
        eType)
{
    m_fMaximumTimeStep = 0.5f/(m_fInvDxDx + m_fInvDyDy);
}
//----------------------------------------------------------------------------
GaussianBlur2::~GaussianBlur2 ()
{
}
//----------------------------------------------------------------------------
float GaussianBlur2::GetMaximumTimeStep () const
{
    return m_fMaximumTimeStep;
}
//----------------------------------------------------------------------------
void GaussianBlur2::OnUpdate (int iX, int iY)
{
    LookUp5(iX,iY);

    float fUxx = m_fInvDxDx*(m_fUpz - 2.0f*m_fUzz + m_fUmz);
    float fUyy = m_fInvDyDy*(m_fUzp - 2.0f*m_fUzz + m_fUzm);

    m_aafDst[iY][iX] = m_fUzz + m_fTimeStep*(fUxx + fUyy);
}
//----------------------------------------------------------------------------
