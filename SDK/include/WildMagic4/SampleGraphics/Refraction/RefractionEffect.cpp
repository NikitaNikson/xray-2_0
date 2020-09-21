// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "RefractionEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,RefractionEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(RefractionEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(RefractionEffect,ShaderEffect);

//----------------------------------------------------------------------------
RefractionEffect::RefractionEffect (const char* acEnvironmentName,
    const char* acReflectionName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Refraction");
    m_kPShader[0] = WM4_NEW PixelShader("Refraction");

    m_kPShader[0]->SetTexture(0,acEnvironmentName);
    m_kPShader[0]->SetTexture(1,acReflectionName);

    Texture* pkEnvironment = m_kPShader[0]->GetTexture(0);
    pkEnvironment->SetFilterType(Texture::LINEAR);

    Texture* pkReflection = m_kPShader[0]->GetTexture(1);
    pkReflection->SetFilterType(Texture::LINEAR);

    VertexProgram* pkVProgram = m_kVShader[0]->GetProgram();
    pkVProgram->GetUserConstant("FresnelConstants")->SetDataSource(
        m_afVConstant);
}
//----------------------------------------------------------------------------
RefractionEffect::RefractionEffect ()
{
}
//----------------------------------------------------------------------------
RefractionEffect::~RefractionEffect ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void RefractionEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(4,m_afVConstant);

    WM4_END_DEBUG_STREAM_LOAD(RefractionEffect);
}
//----------------------------------------------------------------------------
void RefractionEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool RefractionEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void RefractionEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    rkStream.Write(4,m_afVConstant);

    WM4_END_DEBUG_STREAM_SAVE(RefractionEffect);
}
//----------------------------------------------------------------------------
int RefractionEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        4*sizeof(m_afVConstant[0]);
}
//----------------------------------------------------------------------------
StringTree* RefractionEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("Fresnel constant 0 =",m_afVConstant[0]));
    pkTree->Append(Format("Fresnel constant 1 =",m_afVConstant[1]));
    pkTree->Append(Format("Fresnel constant 2 =",m_afVConstant[2]));
    pkTree->Append(Format("Fresnel constant 3 =",m_afVConstant[3]));

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
