// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline const std::string& Shader::GetShaderName () const
{
    return m_kShaderName;
}
//----------------------------------------------------------------------------
inline int Shader::GetTextureQuantity () const
{
    return (int)m_kTextures.size();
}
//----------------------------------------------------------------------------
