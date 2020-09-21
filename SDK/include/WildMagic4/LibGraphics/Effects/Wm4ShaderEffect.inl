// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int ShaderEffect::GetPassQuantity () const
{
    return m_iPassQuantity;
}
//----------------------------------------------------------------------------
inline AlphaState* ShaderEffect::GetBlending (int iPass)
{
    // A derived class might want to use alpha state for selecting shader
    // programs for doing a single-pass renderering.  The class can resize
    // the alpha state array to contain more items than the number of passes.
    // Thus, the assertion here does not compare iPass to m_iPassQuantity.
    assert(0 <= iPass && iPass < (int)m_kAlphaState.size());
    return m_kAlphaState[iPass];
}
//----------------------------------------------------------------------------
inline VertexShader* ShaderEffect::GetVShader (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass];
}
//----------------------------------------------------------------------------
inline VertexProgram* ShaderEffect::GetVProgram (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetProgram();
}
//----------------------------------------------------------------------------
inline const std::string& ShaderEffect::GetVShaderName (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetShaderName();
}
//----------------------------------------------------------------------------
inline int ShaderEffect::GetVConstantQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkVProgram = m_kVShader[iPass]->GetProgram();
    return pkVProgram ? pkVProgram->GetUserConstantQuantity() : 0;
}
//----------------------------------------------------------------------------
inline UserConstant* ShaderEffect::GetVConstant (int iPass,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkVProgram = m_kVShader[iPass]->GetProgram();
    return pkVProgram ? pkVProgram->GetUserConstant(rkName) : 0;
}
//----------------------------------------------------------------------------
inline UserConstant* ShaderEffect::GetVConstant (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkVProgram = m_kVShader[iPass]->GetProgram();
    if (pkVProgram)
    {
        assert(0 <= i && i < pkVProgram->GetUserConstantQuantity());
        return pkVProgram->GetUserConstant(i);
    }
    return 0;
}
//----------------------------------------------------------------------------
inline int ShaderEffect::GetVTextureQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetTextureQuantity();
}
//----------------------------------------------------------------------------
inline Texture* ShaderEffect::GetVTexture (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetTexture(i);
}
//----------------------------------------------------------------------------
inline Texture* ShaderEffect::GetVTexture (int iPass,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetTexture(rkName);
}
//----------------------------------------------------------------------------
inline bool ShaderEffect::SetVTexture (int iPass, int i, Texture* pkTexture)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->SetTexture(i,pkTexture);
}
//----------------------------------------------------------------------------
inline bool ShaderEffect::SetVTexture (int iPass, int i,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->SetTexture(i,rkName);
}
//----------------------------------------------------------------------------
inline PixelShader* ShaderEffect::GetPShader (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass];
}
//----------------------------------------------------------------------------
inline PixelProgram* ShaderEffect::GetPProgram (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetProgram();
}
//----------------------------------------------------------------------------
inline const std::string& ShaderEffect::GetPShaderName (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetShaderName();
}
//----------------------------------------------------------------------------
inline int ShaderEffect::GetPConstantQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    return pkPProgram ? pkPProgram->GetUserConstantQuantity() : 0;
}
//----------------------------------------------------------------------------
inline UserConstant* ShaderEffect::GetPConstant (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    if (pkPProgram)
    {
        assert(0 <= i && i < pkPProgram->GetUserConstantQuantity());
        return pkPProgram->GetUserConstant(i);
    }
    return 0;
}
//----------------------------------------------------------------------------
inline UserConstant* ShaderEffect::GetPConstant (int iPass,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    return pkPProgram ? pkPProgram->GetUserConstant(rkName) : 0;
}
//----------------------------------------------------------------------------
inline int ShaderEffect::GetPTextureQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    return pkPProgram ? pkPProgram->GetSamplerInformationQuantity() : 0;
}
//----------------------------------------------------------------------------
inline Texture* ShaderEffect::GetPTexture (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetTexture(i);
}
//----------------------------------------------------------------------------
inline Texture* ShaderEffect::GetPTexture (int iPass,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetTexture(rkName);
}
//----------------------------------------------------------------------------
inline bool ShaderEffect::SetPTexture (int iPass, int i, Texture* pkTexture)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->SetTexture(i,pkTexture);
}
//----------------------------------------------------------------------------
inline bool ShaderEffect::SetPTexture (int iPass, int i,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->SetTexture(i,rkName);
}
//----------------------------------------------------------------------------
