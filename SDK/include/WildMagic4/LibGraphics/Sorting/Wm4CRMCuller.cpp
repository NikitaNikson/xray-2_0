// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4CRMCuller.h"
using namespace Wm4;

//----------------------------------------------------------------------------
CRMCuller::CRMCuller (int iMaxQuantity, int iGrowBy, const Camera* pkCamera)
    :
    Culler(iMaxQuantity,iGrowBy,pkCamera),
    m_kUnique(iMaxQuantity > 0 ? iMaxQuantity : 1024)
{
}
//----------------------------------------------------------------------------
CRMCuller::~CRMCuller ()
{
}
//----------------------------------------------------------------------------
void CRMCuller::Insert (Spatial* pkObject, Effect* pkGlobalEffect)
{
    if (pkObject)
    {
        if (&pkObject != m_kUnique.Insert(pkObject))
        {
            // The object was not in the list of unique objects.
            Culler::Insert(pkObject,pkGlobalEffect);
        }
    }
    else
    {
        // This is an end-sentinel for a global effect.  There can be
        // multiple copies of these.
        Culler::Insert(0,0);
    }
}
//----------------------------------------------------------------------------
