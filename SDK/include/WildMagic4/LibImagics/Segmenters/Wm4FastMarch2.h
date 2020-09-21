// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4FASTMARCH2_H
#define WM4FASTMARCH2_H

#include "Wm4ImagicsLIB.h"
#include "Wm4FastMarch.h"

namespace Wm4
{

class WM4_IMAGICS_ITEM FastMarch2 : public FastMarch
{
public:
    // Construction and destruction.
    FastMarch2 (int iXBound, int iYBound, float fXSpacing, float fYSpacing,
        const float* afSpeed, const std::vector<int>& rkSeeds);

    FastMarch2 (int iXBound, int iYBound, float fXSpacing, float fYSpacing,
        const float fSpeed, const std::vector<int>& rkSeeds);

    ~FastMarch2 ();

    // Member access.
    int GetXBound () const;
    int GetYBound () const;
    float GetXSpacing () const;
    float GetYSpacing () const;
    int Index (int iX, int iY) const;

    // Pixel classification.
    virtual void GetBoundary (std::vector<int>& rkBoundary) const;
    virtual bool IsBoundary (int i) const;

    // Run one step of the fast marching algorithm.
    virtual void Iterate ();

protected:
    // Called by the constructors.
    void Initialize (int iXBound, int iYBound, float fXSpacing,
        float fYSpacing);

    // Called by Iterate().
    void ComputeTime (int i);

    int m_iXBound, m_iYBound, m_iXBm1, m_iYBm1;
    float m_fXSpacing, m_fYSpacing, m_fInvXSpacing, m_fInvYSpacing;
};

#include "Wm4FastMarch2.inl"

}

#endif
