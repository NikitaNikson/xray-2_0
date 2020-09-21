// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int VisibleSet::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline VisibleObject* VisibleSet::GetVisible ()
{
    return m_akVisible;
}
//----------------------------------------------------------------------------
inline VisibleObject& VisibleSet::GetVisible (int i)
{
    assert(0 <= i && i < m_iQuantity);
    return m_akVisible[i];
}
//----------------------------------------------------------------------------
inline void VisibleSet::Clear ()
{
    m_iQuantity = 0;
}
//----------------------------------------------------------------------------
