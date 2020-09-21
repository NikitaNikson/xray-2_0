// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4PixelProgram.h"
#include "Wm4Catalog.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,PixelProgram,Program);
WM4_IMPLEMENT_STREAM(PixelProgram);
WM4_IMPLEMENT_DEFAULT_NAME_ID(PixelProgram,Program);

//----------------------------------------------------------------------------
PixelProgram::PixelProgram (const std::string& rkProgramName)
{
    std::string kFilename = std::string("p_") + rkProgramName +
        std::string(".") + RendererType + std::string(".wmsp");
    bool bLoaded = Program::Load(kFilename,this);
    assert(bLoaded);
    (void)bLoaded;  // Avoid warning in release builds.
    SetName(rkProgramName.c_str());

    // Verify that the pixel program does not require more resources than the
    // renderer can support.
    assert(m_kInputAttributes.GetMaxColors() <= Renderer::GetMaxColors());
    assert(m_kInputAttributes.GetMaxTCoords() <= Renderer::GetMaxTCoords());
    assert(
        (int)m_kSamplerInformation.size() <= Renderer::GetMaxPShaderImages());

    Catalog<PixelProgram>::GetActive()->Insert(this);
}
//----------------------------------------------------------------------------
PixelProgram::PixelProgram ()
{
}
//----------------------------------------------------------------------------
PixelProgram::~PixelProgram ()
{
    Catalog<PixelProgram>::RemoveAll(this);
}
//----------------------------------------------------------------------------
PixelProgram* PixelProgram::Load (const std::string& rkProgramName)
{
    return WM4_NEW PixelProgram(rkProgramName);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void PixelProgram::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Program::Load(rkStream,pkLink);

    std::string kFilename = std::string("p_") + GetName() +
        std::string(".") + RendererType + std::string(".wmsp");
    bool bLoaded = Program::Load(kFilename,this);
    assert(bLoaded);
    (void)bLoaded;  // Avoid warning in release builds.

    Catalog<PixelProgram>::GetActive()->Insert(this);

    WM4_END_DEBUG_STREAM_LOAD(PixelProgram);
}
//----------------------------------------------------------------------------
void PixelProgram::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Program::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool PixelProgram::Register (Stream& rkStream) const
{
    return Program::Register(rkStream);
}
//----------------------------------------------------------------------------
void PixelProgram::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Program::Save(rkStream);

    WM4_END_DEBUG_STREAM_SAVE(PixelProgram);
}
//----------------------------------------------------------------------------
int PixelProgram::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Program::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* PixelProgram::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Program::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
