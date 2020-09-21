// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline float SurfacePatch::GetUMin () const
{
    return m_fUMin;
}
//----------------------------------------------------------------------------
inline float SurfacePatch::GetUMax () const
{
    return m_fUMax;
}
//----------------------------------------------------------------------------
inline float SurfacePatch::GetVMin () const
{
    return m_fVMin;
}
//----------------------------------------------------------------------------
inline float SurfacePatch::GetVMax () const
{
    return m_fVMax;
}
//----------------------------------------------------------------------------
inline bool SurfacePatch::IsRectangular () const
{
    return m_bRectangular;
}
//----------------------------------------------------------------------------
