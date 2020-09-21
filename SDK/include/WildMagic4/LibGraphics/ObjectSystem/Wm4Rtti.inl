// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline const char* Rtti::GetName () const
{
    return m_acName;
}
//----------------------------------------------------------------------------
inline int Rtti::GetDiskUsed () const
{
    // The name will be written to disk as a String object.
    int iLength = (int)strlen(m_acName);
    return sizeof(iLength) + iLength*sizeof(char);
}
//----------------------------------------------------------------------------
inline bool Rtti::IsExactly (const Rtti& rkType) const
{
    return &rkType == this;
}
//----------------------------------------------------------------------------
