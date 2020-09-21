// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4PixelShader.h"
#include "Wm4Catalog.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,PixelShader,Shader);
WM4_IMPLEMENT_STREAM(PixelShader);
WM4_IMPLEMENT_DEFAULT_NAME_ID(PixelShader,Shader);

//----------------------------------------------------------------------------
PixelShader::PixelShader (const std::string& rkShaderName)
    :
    Shader(rkShaderName)
{
    m_spkProgram = Catalog<PixelProgram>::GetActive()->Find(rkShaderName);
    if (!m_spkProgram )
    {
        // Use the default pixel program when the requested program
        // cannot be found.
        m_spkProgram = Catalog<PixelProgram>::GetActive()->Find("Default");

        // In release builds, if the default pixel program cannot be found,
        // you probably have placed the shader programs in a place that
        // is not stored in the System directory lists.
        assert(m_spkProgram);
    }

    if (m_spkProgram)
    {
        OnLoadProgram();
    }
}
//----------------------------------------------------------------------------
PixelShader::PixelShader ()
{
}
//----------------------------------------------------------------------------
PixelShader::~PixelShader ()
{
}
//----------------------------------------------------------------------------
PixelProgram* PixelShader::GetProgram () const
{
    return StaticCast<PixelProgram>(m_spkProgram);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void PixelShader::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    Shader::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(PixelShader);
}
//----------------------------------------------------------------------------
void PixelShader::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Shader::Link(rkStream,pkLink);

    if (rkStream.GetVersion() < StreamVersion(4,6))
    {
        // The PixelProgram object was not written to disk.  The program
        // load used to occur at render time, but must now be loaded
        // immediately.
        assert(!m_spkProgram);
        m_spkProgram = WM4_NEW PixelProgram(m_kShaderName);
    }
}
//----------------------------------------------------------------------------
bool PixelShader::Register (Stream& rkStream) const
{
    return Shader::Register(rkStream);
}
//----------------------------------------------------------------------------
void PixelShader::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    Shader::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(PixelShader);
}
//----------------------------------------------------------------------------
int PixelShader::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Shader::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* PixelShader::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Shader::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
