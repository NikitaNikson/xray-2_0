// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4FASTMARCH3_H
#define WM4FASTMARCH3_H

#include "Wm4ImagicsLIB.h"
#include "Wm4FastMarch.h"

namespace Wm4
{

class WM4_IMAGICS_ITEM FastMarch3 : public FastMarch
{
public:
    // Construction and destruction.
    FastMarch3 (int iXBound, int iYBound, int iZBound, float fXSpacing,
        float fYSpacing, float fZSpacing, const float* afSpeed,
        const std::vector<int>& rkSeeds);

    FastMarch3 (int iXBound, int iYBound, int iZBound, float fXSpacing,
        float fYSpacing, float fZSpacing, const float fSpeed,
        const std::vector<int>& rkSeeds);

    ~FastMarch3 ();

    // Member access.
    int GetXBound () const;
    int GetYBound () const;
    int GetZBound () const;
    float GetXSpacing () const;
    float GetYSpacing () const;
    float GetZSpacing () const;
    int Index (int iX, int iY, int iZ) const;

    // Voxel classification.
    virtual void GetBoundary (std::vector<int>& rkBoundary) const;
    virtual bool IsBoundary (int i) const;

    // Run one step of the fast marching algorithm.
    virtual void Iterate ();

protected:
    // Called by the constructors.
    void Initialize (int iXBound, int iYBound, int iZBound, float fXSpacing,
        float fYSpacing, float fZSpacing);

    // Called by Iterate().
    void ComputeTime (int i);

    int m_iXBound, m_iYBound, m_iZBound, m_iXYBound;
    int m_iXBm1, m_iYBm1, m_iZBm1;
    float m_fXSpacing, m_fYSpacing, m_fZSpacing;
    float m_fInvXSpacing, m_fInvYSpacing, m_fInvZSpacing;

    static const float ms_fOneThird;
};

#include "Wm4FastMarch3.inl"

}

#endif
