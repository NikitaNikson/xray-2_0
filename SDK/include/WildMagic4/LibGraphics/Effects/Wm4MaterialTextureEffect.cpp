// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4MaterialTextureEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,MaterialTextureEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(MaterialTextureEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(MaterialTextureEffect,ShaderEffect);

//----------------------------------------------------------------------------
MaterialTextureEffect::MaterialTextureEffect (const std::string& rkBaseName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("MaterialTexture");
    m_kPShader[0] = WM4_NEW PixelShader("MaterialTexture");
    m_kPShader[0]->SetTexture(0,rkBaseName);
}
//----------------------------------------------------------------------------
MaterialTextureEffect::MaterialTextureEffect ()
{
}
//----------------------------------------------------------------------------
MaterialTextureEffect::~MaterialTextureEffect ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void MaterialTextureEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    ShaderEffect::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(MaterialTextureEffect);
}
//----------------------------------------------------------------------------
void MaterialTextureEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool MaterialTextureEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void MaterialTextureEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    ShaderEffect::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(MaterialTextureEffect);
}
//----------------------------------------------------------------------------
int MaterialTextureEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* MaterialTextureEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(ShaderEffect::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
