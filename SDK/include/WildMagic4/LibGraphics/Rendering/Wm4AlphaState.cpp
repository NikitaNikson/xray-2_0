// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4AlphaState.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,AlphaState,GlobalState);
WM4_IMPLEMENT_STREAM(AlphaState);
WM4_IMPLEMENT_DEFAULT_NAME_ID(AlphaState,GlobalState);
WM4_IMPLEMENT_INITIALIZE(AlphaState);
WM4_IMPLEMENT_TERMINATE(AlphaState);

const char* AlphaState::ms_aacSrcBlend[SBF_QUANTITY] =
{
    "SBF_ZERO",
    "SBF_ONE",
    "SBF_DST_COLOR",
    "SBF_ONE_MINUS_DST_COLOR",
    "SBF_SRC_ALPHA",
    "SBF_ONE_MINUS_SRC_ALPHA",
    "SBF_DST_ALPHA",
    "SBF_ONE_MINUS_DST_ALPHA",
    "SBF_SRC_ALPHA_SATURATE",
    "SBF_CONSTANT_COLOR",
    "SBF_ONE_MINUS_CONSTANT_COLOR",
    "SBF_CONSTANT_ALPHA",
    "SBF_ONE_MINUS_CONSTANT_ALPHA"
};

const char* AlphaState::ms_aacDstBlend[DBF_QUANTITY] =
{
    "DBF_ZERO",
    "DBF_ONE",
    "DBF_SRC_COLOR",
    "DBF_ONE_MINUS_SRC_COLOR",
    "DBF_SRC_ALPHA",
    "DBF_ONE_MINUS_SRC_ALPHA",
    "DBF_DST_ALPHA",
    "DBF_ONE_MINUS_DST_ALPHA",
    "DBF_CONSTANT_COLOR",
    "DBF_ONE_MINUS_CONSTANT_COLOR",
    "DBF_CONSTANT_ALPHA",
    "DBF_ONE_MINUS_CONSTANT_ALPHA"
};

const char* AlphaState::ms_aacTestMode[TF_QUANTITY] =
{
    "TF_NEVER",
    "TF_LESS",
    "TF_EQUAL",
    "TF_LEQUAL",
    "TF_GREATER",
    "TF_NOTEQUAL",
    "TF_GEQUAL",
    "TF_ALWAYS"
};

//----------------------------------------------------------------------------
void AlphaState::Initialize ()
{
    Default[ALPHA] = WM4_NEW AlphaState;
}
//----------------------------------------------------------------------------
void AlphaState::Terminate ()
{
    Default[ALPHA] = 0;
}
//----------------------------------------------------------------------------
AlphaState::AlphaState ()
    :
    ConstantColor(0.0f,0.0f,0.0f,0.0f)
{
    BlendEnabled = false;
    SrcBlend = SBF_SRC_ALPHA;
    DstBlend = DBF_ONE_MINUS_SRC_ALPHA;
    TestEnabled = false;
    Test = TF_ALWAYS;
    Reference = 0.0f;
}
//----------------------------------------------------------------------------
AlphaState::~AlphaState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void AlphaState::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    GlobalState::Load(rkStream,pkLink);

    // native data
    int iTmp;
    rkStream.Read(BlendEnabled);
    rkStream.Read(iTmp);
    SrcBlend = (SrcBlendMode)iTmp;
    rkStream.Read(iTmp);
    DstBlend = (DstBlendMode)iTmp;
    rkStream.Read(TestEnabled);
    rkStream.Read(iTmp);
    Test = (TestMode)iTmp;
    rkStream.Read(Reference);

    WM4_END_DEBUG_STREAM_LOAD(AlphaState);
}
//----------------------------------------------------------------------------
void AlphaState::Link (Stream& rkStream, Stream::Link* pkLink)
{
    GlobalState::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool AlphaState::Register (Stream& rkStream) const
{
    return GlobalState::Register(rkStream);
}
//----------------------------------------------------------------------------
void AlphaState::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    GlobalState::Save(rkStream);

    // native data
    rkStream.Write(BlendEnabled);
    rkStream.Write((int)SrcBlend);
    rkStream.Write((int)DstBlend);
    rkStream.Write(TestEnabled);
    rkStream.Write((int)Test);
    rkStream.Write(Reference);

    WM4_END_DEBUG_STREAM_SAVE(AlphaState);
}
//----------------------------------------------------------------------------
int AlphaState::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return GlobalState::GetDiskUsed(rkVersion) +
        sizeof(char) + // BlendEnabled
        sizeof(int) + // SrcBlend
        sizeof(int) +  // DstBlend
        sizeof(char) + // TestEnabled
        sizeof(int) + // Test
        sizeof(Reference);
}
//----------------------------------------------------------------------------
StringTree* AlphaState::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("blend =",BlendEnabled));
    pkTree->Append(Format("src = ",ms_aacSrcBlend[SrcBlend]));
    pkTree->Append(Format("dst = ",ms_aacDstBlend[DstBlend]));
    pkTree->Append(Format("test =",TestEnabled));
    pkTree->Append(Format("test func = ",ms_aacTestMode[Test]));
    pkTree->Append(Format("test ref =",Reference));

    // children
    pkTree->Append(GlobalState::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
