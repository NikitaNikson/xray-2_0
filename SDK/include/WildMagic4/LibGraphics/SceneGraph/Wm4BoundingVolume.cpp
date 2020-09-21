// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4BoundingVolume.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,BoundingVolume,Object);
WM4_IMPLEMENT_ABSTRACT_STREAM(BoundingVolume);
WM4_IMPLEMENT_DEFAULT_NAME_ID(BoundingVolume,Object);

//----------------------------------------------------------------------------
BoundingVolume::BoundingVolume ()
{
}
//----------------------------------------------------------------------------
BoundingVolume::~BoundingVolume ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void BoundingVolume::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    Object::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(BoundingVolume);
}
//----------------------------------------------------------------------------
void BoundingVolume::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool BoundingVolume::Register (Stream& rkStream) const
{
    return Object::Register(rkStream);
}
//----------------------------------------------------------------------------
void BoundingVolume::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    Object::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(BoundingVolume);
}
//----------------------------------------------------------------------------
int BoundingVolume::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Object::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* BoundingVolume::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Object::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
