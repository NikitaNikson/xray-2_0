// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4TextureEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,TextureEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(TextureEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(TextureEffect,ShaderEffect);

//----------------------------------------------------------------------------
TextureEffect::TextureEffect (const std::string& rkBaseName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Texture");
    m_kPShader[0] = WM4_NEW PixelShader("Texture");
    m_kPShader[0]->SetTexture(0,rkBaseName);
}
//----------------------------------------------------------------------------
TextureEffect::TextureEffect ()
{
}
//----------------------------------------------------------------------------
TextureEffect::~TextureEffect ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void TextureEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    ShaderEffect::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(TextureEffect);
}
//----------------------------------------------------------------------------
void TextureEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool TextureEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void TextureEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    ShaderEffect::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(TextureEffect);
}
//----------------------------------------------------------------------------
int TextureEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* TextureEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(ShaderEffect::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
