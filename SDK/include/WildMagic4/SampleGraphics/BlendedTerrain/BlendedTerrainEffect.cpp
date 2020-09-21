// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "BlendedTerrainEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,BlendedTerrainEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(BlendedTerrainEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(BlendedTerrainEffect,ShaderEffect);

//----------------------------------------------------------------------------
BlendedTerrainEffect::BlendedTerrainEffect (const char* acGrassName,
    const char* acStoneName, const char* acBlendName, const char* acCloudName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("BlendedTerrain");
    m_kPShader[0] = WM4_NEW PixelShader("BlendedTerrain");

    m_kPShader[0]->SetTexture(0,acGrassName);
    m_kPShader[0]->SetTexture(1,acStoneName);
    m_kPShader[0]->SetTexture(2,acBlendName);
    m_kPShader[0]->SetTexture(3,acCloudName);

    Texture* pkGrass = m_kPShader[0]->GetTexture(0);
    pkGrass->SetFilterType(Texture::LINEAR_LINEAR);
    pkGrass->SetWrapType(0,Texture::REPEAT);
    pkGrass->SetWrapType(1,Texture::REPEAT);

    Texture* pkStone = m_kPShader[0]->GetTexture(1);
    pkStone->SetFilterType(Texture::LINEAR_LINEAR);
    pkStone->SetWrapType(0,Texture::REPEAT);
    pkStone->SetWrapType(1,Texture::REPEAT);

    Texture* pkBlend = m_kPShader[0]->GetTexture(2);
    pkBlend->SetFilterType(Texture::LINEAR);
    pkBlend->SetWrapType(0,Texture::CLAMP_EDGE);

    Texture* pkCloud = m_kPShader[0]->GetTexture(3);
    pkCloud->SetFilterType(Texture::LINEAR_LINEAR);
    pkCloud->SetWrapType(0,Texture::REPEAT);
    pkCloud->SetWrapType(1,Texture::REPEAT);

    m_afFlowDirection[0] = 0.0f;
    m_afFlowDirection[1] = 0.0f;
    m_afPowerFactor[0] = 0.5f;

    ConnectVShaderConstant(0,"FlowDirection",m_afFlowDirection);
    ConnectPShaderConstant(0,"PowerFactor",m_afPowerFactor);
}
//----------------------------------------------------------------------------
BlendedTerrainEffect::BlendedTerrainEffect ()
{
}
//----------------------------------------------------------------------------
BlendedTerrainEffect::~BlendedTerrainEffect ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void BlendedTerrainEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_afFlowDirection[0]);
    rkStream.Read(m_afFlowDirection[1]);
    rkStream.Read(m_afPowerFactor[0]);

    WM4_END_DEBUG_STREAM_LOAD(BlendedTerrainEffect);
}
//----------------------------------------------------------------------------
void BlendedTerrainEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool BlendedTerrainEffect::PostLink ()
{
    // WARNING.  If you use create a classless effect (comment out the
    // #define of USE_BTEFFECT in BlendedTerrain.h), you cannot obtain the
    // postlink semantics because ShaderEffect knows nothing about
    // BlendedTerrainEffect.  In this situation, you must connect the shader
    // constants in the application code after loading the effect.
    ConnectVShaderConstant(0,"FlowDirection",m_afFlowDirection);
    ConnectPShaderConstant(0,"PowerFactor",m_afPowerFactor);
    return GetVConstant(0,0) && GetPConstant(0,0);
}
//----------------------------------------------------------------------------
bool BlendedTerrainEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void BlendedTerrainEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    rkStream.Write(m_afFlowDirection[0]);
    rkStream.Write(m_afFlowDirection[1]);
    rkStream.Write(m_afPowerFactor[0]);

    WM4_END_DEBUG_STREAM_SAVE(BlendedTerrainEffect);
}
//----------------------------------------------------------------------------
int BlendedTerrainEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        sizeof(m_afFlowDirection[0]) +
        sizeof(m_afFlowDirection[1]) +
        sizeof(m_afPowerFactor[0]);
}
//----------------------------------------------------------------------------
StringTree* BlendedTerrainEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    Vector2f kFlowDirection(m_afFlowDirection[0],m_afFlowDirection[1]);
    pkTree->Append(Format("flow direction =",kFlowDirection));
    pkTree->Append(Format("power factor =",m_afPowerFactor[0]));

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
