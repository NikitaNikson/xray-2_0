// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int SoftSamplerProj::Index (int iX, int iY) const
{
    return iX + (iY << m_iCurrLog2XBound);
}
//----------------------------------------------------------------------------
