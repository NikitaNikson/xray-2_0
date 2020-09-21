// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int IndexBuffer::GetIndexQuantity () const
{
    return m_iIQuantity;
}
//----------------------------------------------------------------------------
inline int* IndexBuffer::GetData ()
{
    return m_aiIndex;
}
//----------------------------------------------------------------------------
inline const int* IndexBuffer::GetData () const
{
    return m_aiIndex;
}
//----------------------------------------------------------------------------
inline int IndexBuffer::operator[] (int i) const
{
    assert(0 <= i && i < m_iIQuantity);
    return m_aiIndex[i];
}
//----------------------------------------------------------------------------
inline int& IndexBuffer::operator[] (int i)
{
    assert(0 <= i && i < m_iIQuantity);
    return m_aiIndex[i];
}
//----------------------------------------------------------------------------
inline void IndexBuffer::SetIndexQuantity (int iIQuantity)
{
    m_iIQuantity = iIQuantity;
}
//----------------------------------------------------------------------------
inline void IndexBuffer::SetOffset (int iOffset)
{
    assert(iOffset >= 0);
    m_iOffset = iOffset;
}
//----------------------------------------------------------------------------
inline int IndexBuffer::GetOffset () const
{
    return m_iOffset;
}
//----------------------------------------------------------------------------
