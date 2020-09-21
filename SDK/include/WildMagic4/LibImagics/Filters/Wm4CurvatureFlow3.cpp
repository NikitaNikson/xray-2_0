// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ImagicsPCH.h"
#include "Wm4CurvatureFlow3.h"
using namespace Wm4;

//----------------------------------------------------------------------------
CurvatureFlow3::CurvatureFlow3 (int iXBound, int iYBound, int iZBound,
    float fXSpacing, float fYSpacing, float fZSpacing, const float* afData,
    const bool* abMask, float fBorderValue, ScaleType eType)
    :
    PdeFilter3(iXBound,iYBound,iZBound,fXSpacing,fYSpacing,fZSpacing,afData,
        abMask,fBorderValue,eType)
{
}
//----------------------------------------------------------------------------
CurvatureFlow3::~CurvatureFlow3 ()
{
}
//----------------------------------------------------------------------------
void CurvatureFlow3::OnUpdate (int iX, int iY, int iZ)
{
    LookUp27(iX,iY,iZ);

    float fUx = m_fHalfInvDx*(m_fUpzz - m_fUmzz);
    float fUy = m_fHalfInvDy*(m_fUzpz - m_fUzmz);
    float fUz = m_fHalfInvDz*(m_fUzzp - m_fUzzm);
    float fUxx = m_fInvDxDx*(m_fUpzz - 2.0f*m_fUzzz + m_fUmzz);
    float fUxy = m_fFourthInvDxDy*(m_fUmmz + m_fUppz - m_fUpmz - m_fUmpz);
    float fUxz = m_fFourthInvDxDz*(m_fUmzm + m_fUpzp - m_fUpzm - m_fUmzp);
    float fUyy = m_fInvDyDy*(m_fUzpz - 2.0f*m_fUzzz + m_fUzmz);
    float fUyz = m_fFourthInvDyDz*(m_fUzmm+ m_fUzpp - m_fUzpm  - m_fUzmp);
    float fUzz = m_fInvDzDz*(m_fUzzp - 2.0f*m_fUzzz + m_fUzzm);

    float fGradMagSqr = fUx*fUx + fUy*fUy + fUz*fUz;
    float fNumer0 = fUy*(fUxx*fUy - fUxy*fUx) + fUx*(fUyy*fUx - fUxy*fUy);
    float fNumer1 = fUz*(fUxx*fUz - fUxz*fUx) + fUx*(fUzz*fUx - fUxz*fUz);
    float fNumer2 = fUz*(fUyy*fUz - fUyz*fUy) + fUy*(fUzz*fUy - fUyz*fUz);
    float fDenom = fGradMagSqr + 1e-08f;  // prevent zero division
    float fCurvatureLength = (fNumer0 + fNumer1 + fNumer2)/fDenom;

    m_aaafDst[iZ][iY][iX] = m_fUzzz + m_fTimeStep*fCurvatureLength;
}
//----------------------------------------------------------------------------
