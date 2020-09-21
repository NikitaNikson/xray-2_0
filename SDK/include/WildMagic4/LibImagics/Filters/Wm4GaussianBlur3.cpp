// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ImagicsPCH.h"
#include "Wm4GaussianBlur3.h"
using namespace Wm4;

//----------------------------------------------------------------------------
GaussianBlur3::GaussianBlur3 (int iXBound, int iYBound, int iZBound,
    float fXSpacing, float fYSpacing, float fZSpacing, const float* afData,
    const bool* abMask, float fBorderValue, ScaleType eType)
    :
    PdeFilter3(iXBound,iYBound,iZBound,fXSpacing,fYSpacing,fZSpacing,afData,
        abMask,fBorderValue,eType)
{
    m_fMaximumTimeStep = 0.5f/(m_fInvDxDx + m_fInvDyDy + m_fInvDzDz);
}
//----------------------------------------------------------------------------
GaussianBlur3::~GaussianBlur3 ()
{
}
//----------------------------------------------------------------------------
float GaussianBlur3::GetMaximumTimeStep () const
{
    return m_fMaximumTimeStep;
}
//----------------------------------------------------------------------------
void GaussianBlur3::OnUpdate (int iX, int iY, int iZ)
{
    LookUp7(iX,iY,iZ);

    float fUxx = m_fInvDxDx*(m_fUpzz - 2.0f*m_fUzzz + m_fUmzz);
    float fUyy = m_fInvDyDy*(m_fUzpz - 2.0f*m_fUzzz + m_fUzmz);
    float fUzz = m_fInvDzDz*(m_fUzzp - 2.0f*m_fUzzz + m_fUzzm);

    m_aaafDst[iZ][iY][iX] = m_fUzzz + m_fTimeStep*(fUxx + fUyy + fUzz);
}
//----------------------------------------------------------------------------
