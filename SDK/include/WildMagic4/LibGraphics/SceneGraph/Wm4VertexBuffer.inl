// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline const Attributes& VertexBuffer::GetAttributes () const
{
    return m_kAttributes;
}
//----------------------------------------------------------------------------
inline int VertexBuffer::GetVertexSize () const
{
    return m_iVertexSize;
}
//----------------------------------------------------------------------------
inline int VertexBuffer::GetVertexQuantity () const
{
    return m_iVertexQuantity;
}
//----------------------------------------------------------------------------
inline int VertexBuffer::GetChannelQuantity () const
{
    return m_iChannelQuantity;
}
//----------------------------------------------------------------------------
inline float* VertexBuffer::GetData ()
{
    return m_afChannel;
}
//----------------------------------------------------------------------------
inline const float* VertexBuffer::GetData () const
{
    return m_afChannel;
}
//----------------------------------------------------------------------------
inline void VertexBuffer::SetVertexQuantity (int iVQuantity)
{
    m_iVertexQuantity = iVQuantity;
}
//----------------------------------------------------------------------------
