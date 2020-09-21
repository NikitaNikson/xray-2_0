// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int Stream::GetOrderedQuantity () const
{
    return (int)m_kOrdered.size();
}
//----------------------------------------------------------------------------
inline Object* Stream::GetOrderedObject (int i) const
{
    assert(0 <= i && i < (int)m_kOrdered.size());
    if (i < 0 || i >= (int)m_kOrdered.size())
    {
        return 0;
    }

    return m_kOrdered[i];
}
//----------------------------------------------------------------------------
inline int Stream::GetBufferSize () const
{
    return m_iBufferSize;
}
//----------------------------------------------------------------------------
inline int Stream::GetBufferNext () const
{
    return m_iBufferNext;
}
//----------------------------------------------------------------------------
inline StreamVersion Stream::GetVersion () const
{
    return m_kVersion;
}
//----------------------------------------------------------------------------
