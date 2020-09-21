// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4DynamicTexture.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,DynamicTexture,Texture);
WM4_IMPLEMENT_STREAM(DynamicTexture);
WM4_IMPLEMENT_DEFAULT_NAME_ID(DynamicTexture,Texture);

//----------------------------------------------------------------------------
DynamicTexture::DynamicTexture ()
{
}
//----------------------------------------------------------------------------
DynamicTexture::DynamicTexture (const char* acTextureName, Image* pkImage)
    :
    Texture(acTextureName,pkImage)
{
}
//----------------------------------------------------------------------------
DynamicTexture::~DynamicTexture ()
{
}
//----------------------------------------------------------------------------
void DynamicTexture::SetImage (Image*)
{
    // You may not override m_spkImage that was set by the constructor.
}
//----------------------------------------------------------------------------
void DynamicTexture::SetFilterType (FilterType eFType)
{
    if (eFType == NEAREST_NEAREST || eFType == NEAREST_LINEAR)
    {
        eFType = NEAREST;
    }
    else if (eFType == LINEAR_NEAREST || eFType == LINEAR_LINEAR)
    {
        eFType = LINEAR;
    }

    Texture::SetFilterType(eFType);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void DynamicTexture::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    Texture::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(DynamicTexture);
}
//----------------------------------------------------------------------------
void DynamicTexture::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Texture::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool DynamicTexture::Register (Stream& rkStream) const
{
    return Texture::Register(rkStream);
}
//----------------------------------------------------------------------------
void DynamicTexture::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    Texture::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(DynamicTexture);
}
//----------------------------------------------------------------------------
int DynamicTexture::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Texture::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* DynamicTexture::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Texture::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
