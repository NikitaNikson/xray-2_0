// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline const std::string& Program::GetProgramText () const
{
    return m_kProgramText;
}
//----------------------------------------------------------------------------
inline const Attributes& Program::GetInputAttributes () const
{
    return m_kInputAttributes;
}
//----------------------------------------------------------------------------
inline const Attributes& Program::GetOutputAttributes () const
{
    return m_kOutputAttributes;
}
//----------------------------------------------------------------------------
inline int Program::GetRendererConstantQuantity () const
{
    return (int)m_kRendererConstants.size();
}
//----------------------------------------------------------------------------
inline int Program::GetNumericalConstantQuantity () const
{
    return (int)m_kNumericalConstants.size();
}
//----------------------------------------------------------------------------
inline int Program::GetUserConstantQuantity () const
{
    return (int)m_kUserConstants.size();
}
//----------------------------------------------------------------------------
inline int Program::GetSamplerInformationQuantity () const
{
    return (int)m_kSamplerInformation.size();
}
//----------------------------------------------------------------------------
