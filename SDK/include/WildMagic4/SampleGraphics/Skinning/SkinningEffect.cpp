// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "SkinningEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,SkinningEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(SkinningEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(SkinningEffect,ShaderEffect);

//----------------------------------------------------------------------------
SkinningEffect::SkinningEffect ()
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Skinning");
    m_kPShader[0] = WM4_NEW PixelShader("PassThrough3");

    VertexProgram* pkVProgram = m_kVShader[0]->GetProgram();
    char acName[] = "SkinningMatrix*";
    for (int i = 0; i < 4; i++)
    {
        m_akMatrix[i] = Matrix4f::IDENTITY;
        acName[14] = '0' + i;
        ConnectVShaderConstant(0,acName,(float*)m_akMatrix[i]);
    }
}
//----------------------------------------------------------------------------
SkinningEffect::~SkinningEffect ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void SkinningEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    for (int i = 0; i < 4; i++)
    {
        rkStream.Read(m_akMatrix[i]);
    }

    WM4_END_DEBUG_STREAM_LOAD(SkinningEffect);
}
//----------------------------------------------------------------------------
void SkinningEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool SkinningEffect::PostLink ()
{
    char acName[] = "SkinningMatrix*";
    for (int i = 0; i < 4; i++)
    {
        m_akMatrix[i] = Matrix4f::IDENTITY;
        acName[14] = '0' + i;
        ConnectVShaderConstant(0,acName,(float*)m_akMatrix[i]);
    }
    return true;
}
//----------------------------------------------------------------------------
bool SkinningEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void SkinningEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    for (int i = 0; i < 4; i++)
    {
        rkStream.Write(m_akMatrix[i]);
    }

    WM4_END_DEBUG_STREAM_SAVE(SkinningEffect);
}
//----------------------------------------------------------------------------
int SkinningEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        4*sizeof(m_akMatrix[0]);
}
//----------------------------------------------------------------------------
StringTree* SkinningEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));

    const size_t uiTitleSize = 16;
    char acTitle[uiTitleSize];
    for (int i = 0; i < 4; i++)
    {
        System::Sprintf(acTitle,uiTitleSize,"matrix[%d] =",i);
        pkTree->Append(Format(acTitle,m_akMatrix[i]));
    }

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
