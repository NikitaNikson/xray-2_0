// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int SoftFrameBuffer::GetWidth () const
{
    return m_iWidth;
}
//----------------------------------------------------------------------------
inline int SoftFrameBuffer::GetHeight () const
{
    return m_iHeight;
}
//----------------------------------------------------------------------------
inline int SoftFrameBuffer::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline void SoftFrameBuffer::SetColorBufferUI (unsigned int* auiColorBuffer)
{
    m_auiColorBuffer = auiColorBuffer;
    m_bColorBufferOwner = false;
}
//----------------------------------------------------------------------------
inline unsigned int* SoftFrameBuffer::GetColorBufferUI () const
{
    return m_auiColorBuffer;
}
//----------------------------------------------------------------------------
inline ColorRGBA* SoftFrameBuffer::GetColorBufferRGBA () const
{
    return m_akColorBuffer;
}
//----------------------------------------------------------------------------
inline unsigned int SoftFrameBuffer::GetMaxDepthValue () const
{
    return m_uiMaxDepthValue;
}
//----------------------------------------------------------------------------
inline unsigned int* SoftFrameBuffer::GetDepthBufferUI () const
{
    return m_auiDepthBuffer;
}
//----------------------------------------------------------------------------
inline float* SoftFrameBuffer::GetDepthBufferF () const
{
    return m_afDepthBuffer;
}
//----------------------------------------------------------------------------
inline unsigned int SoftFrameBuffer::GetMaxStencilValue () const
{
    return m_uiMaxStencilValue;
}
//----------------------------------------------------------------------------
inline unsigned int* SoftFrameBuffer::GetStencilBuffer () const
{
    return m_auiStencilBuffer;
}
//----------------------------------------------------------------------------
