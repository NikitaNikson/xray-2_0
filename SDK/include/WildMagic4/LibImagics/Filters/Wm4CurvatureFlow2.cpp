// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ImagicsPCH.h"
#include "Wm4CurvatureFlow2.h"
using namespace Wm4;

//----------------------------------------------------------------------------
CurvatureFlow2::CurvatureFlow2 (int iXBound, int iYBound, float fXSpacing,
    float fYSpacing, const float* afData, const bool* abMask,
    float fBorderValue, ScaleType eType)
    :
    PdeFilter2(iXBound,iYBound,fXSpacing,fYSpacing,afData,abMask,fBorderValue,
        eType)
{
}
//----------------------------------------------------------------------------
CurvatureFlow2::~CurvatureFlow2 ()
{
}
//----------------------------------------------------------------------------
void CurvatureFlow2::OnUpdate (int iX, int iY)
{
    LookUp9(iX,iY);

    float fUx = m_fHalfInvDx*(m_fUpz - m_fUmz);
    float fUy = m_fHalfInvDy*(m_fUzp - m_fUzm);
    float fUxx = m_fInvDxDx*(m_fUpz - 2.0f*m_fUzz + m_fUmz);
    float fUxy = m_fFourthInvDxDy*(m_fUmm + m_fUpp - m_fUmp - m_fUpm);
    float fUyy = m_fInvDyDy*(m_fUzp - 2.0f*m_fUzz + m_fUzm);

    float fSqrUx = fUx*fUx;
    float fSqrUy = fUy*fUy;
    float fSqrLength = fSqrUx + fSqrUy + 1e-08f;  // prevent zero division
    m_aafDst[iY][iX] = m_fUzz + m_fTimeStep*(fUxx*fSqrUy +
        fUyy*fSqrUx - 0.5f*fUxy*fUx*fUy)/fSqrLength;
}
//----------------------------------------------------------------------------
