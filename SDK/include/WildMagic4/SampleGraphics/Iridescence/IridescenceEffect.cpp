// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "IridescenceEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,IridescenceEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(IridescenceEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(IridescenceEffect,ShaderEffect);

//----------------------------------------------------------------------------
IridescenceEffect::IridescenceEffect (const char* acBaseName,
    const char* acGradName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Iridescence");
    m_kPShader[0] = WM4_NEW PixelShader("Iridescence");

    m_kPShader[0]->SetTexture(0,acBaseName);
    m_kPShader[0]->SetTexture(1,acGradName);

    Texture* pkBase = m_kPShader[0]->GetTexture(0);
    pkBase->SetFilterType(Texture::LINEAR);
    pkBase->SetWrapType(0,Texture::REPEAT);
    pkBase->SetWrapType(1,Texture::REPEAT);

    Texture* pkGrad = m_kPShader[0]->GetTexture(1);
    pkGrad->SetFilterType(Texture::LINEAR);

    VertexProgram* pkVProgram = m_kVShader[0]->GetProgram();
    pkVProgram->GetUserConstant("InterpolateFactor")->SetDataSource(
        m_afInterpolate);
}
//----------------------------------------------------------------------------
IridescenceEffect::IridescenceEffect ()
{
}
//----------------------------------------------------------------------------
IridescenceEffect::~IridescenceEffect ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void IridescenceEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_afInterpolate[0]);

    WM4_END_DEBUG_STREAM_LOAD(IridescenceEffect);
}
//----------------------------------------------------------------------------
void IridescenceEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool IridescenceEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void IridescenceEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    rkStream.Write(m_afInterpolate[0]);

    WM4_END_DEBUG_STREAM_SAVE(IridescenceEffect);
}
//----------------------------------------------------------------------------
int IridescenceEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        sizeof(m_afInterpolate[0]);
}
//----------------------------------------------------------------------------
StringTree* IridescenceEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("interpolation factor =",m_afInterpolate[0]));

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
