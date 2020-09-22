// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline RendererConstant::Type RendererConstant::GetType () const
{
    return m_eType;
}
//----------------------------------------------------------------------------
inline int RendererConstant::GetBaseRegister () const
{
    return m_iBaseRegister;
}
//----------------------------------------------------------------------------
inline int RendererConstant::GetRegisterQuantity () const
{
    return m_iRegisterQuantity;
}
//----------------------------------------------------------------------------
inline float* RendererConstant::GetData () const
{
    return (float*)&m_afData[0];
}
//----------------------------------------------------------------------------