// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "SphereMapEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,SphereMapEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(SphereMapEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(SphereMapEffect,ShaderEffect);

//----------------------------------------------------------------------------
SphereMapEffect::SphereMapEffect (const std::string& rkEnvName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("SphereMap");
    m_kPShader[0] = WM4_NEW PixelShader("SphereMap");

    m_kPShader[0]->SetTexture(0,rkEnvName);
    m_kPShader[0]->GetTexture(0)->SetFilterType(Texture::LINEAR);
}
//----------------------------------------------------------------------------
SphereMapEffect::SphereMapEffect ()
{
}
//----------------------------------------------------------------------------
SphereMapEffect::~SphereMapEffect ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void SphereMapEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    ShaderEffect::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(SphereMapEffect);
}
//----------------------------------------------------------------------------
void SphereMapEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool SphereMapEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void SphereMapEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    ShaderEffect::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(SphereMapEffect);
}
//----------------------------------------------------------------------------
int SphereMapEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* SphereMapEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(ShaderEffect::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
