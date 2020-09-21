// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int CollapseRecordArray::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline CollapseRecord* CollapseRecordArray::GetData () const
{
    return m_akArray;
}
//----------------------------------------------------------------------------
inline CollapseRecordArray::operator const CollapseRecord* () const
{
    return m_akArray;
}
//----------------------------------------------------------------------------
inline CollapseRecordArray::operator CollapseRecord* ()
{
    return m_akArray;
}
//----------------------------------------------------------------------------
inline const CollapseRecord& CollapseRecordArray::operator[] (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akArray[i];
}
//----------------------------------------------------------------------------
inline CollapseRecord& CollapseRecordArray::operator[] (int i)
{
    assert(0 <= i && i < m_iQuantity);
    return m_akArray[i];
}
//----------------------------------------------------------------------------
