// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4Texture.h"
#include "Wm4Catalog.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Texture,Object);
WM4_IMPLEMENT_STREAM(Texture);
WM4_IMPLEMENT_DEFAULT_NAME_ID(Texture,Object);

const char* Texture::ms_aacFilterType[MAX_FILTER_TYPES] =
{
    "NEAREST",
    "LINEAR",
    "NEAREST_NEAREST",
    "NEAREST_LINEAR",
    "LINEAR_NEAREST",
    "LINEAR_LINEAR"
};

const char* Texture::ms_aacWrapType[MAX_WRAP_TYPES] =
{
    "CLAMP",
    "REPEAT",
    "MIRRORED_REPEAT",
    "CLAMP_BORDER",
    "CLAMP_EDGE"
};

//----------------------------------------------------------------------------
Texture::Texture (const char* acTextureName, Image* pkImage)
    :
    m_spkImage(pkImage),
    m_kBorderColor(ColorRGBA::BLACK)
{
    if (acTextureName)
    {
        SetName(acTextureName);
    }
    else if (pkImage)
    {
        SetName(pkImage->GetName());
    }
    else
    {
        SetName("");
    }

    m_eFType = LINEAR;
    m_aeWType[0] = CLAMP_EDGE;
    m_aeWType[1] = CLAMP_EDGE;
    m_aeWType[2] = CLAMP_EDGE;
    m_fAnisotropy = 1.0f;
    m_bOffscreenTexture = false;

    Catalog<Texture>::GetActive()->Insert(this);
}
//----------------------------------------------------------------------------
Texture::Texture ()
    :
    m_spkImage(0),
    m_kBorderColor(ColorRGBA::BLACK)
{
    SetName("");
    m_eFType = LINEAR;
    m_aeWType[0] = CLAMP_EDGE;
    m_aeWType[1] = CLAMP_EDGE;
    m_aeWType[2] = CLAMP_EDGE;
    m_fAnisotropy = 1.0f;
    m_bOffscreenTexture = false;
}
//----------------------------------------------------------------------------
Texture::~Texture ()
{
    // Inform all renderers using this texture that it is being destroyed.
    // This allows the renderer to free up any associated resources.
    Release();

    Catalog<Texture>::RemoveAll(this);
}
//----------------------------------------------------------------------------
Texture* Texture::Load (const std::string &rkTextureName)
{
    Image* pkImage = Catalog<Image>::GetActive()->Find(rkTextureName);
    if (pkImage)
    {
        return WM4_NEW Texture(rkTextureName.c_str(), pkImage);
    }
    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void Texture::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);

    int iTmp;
    rkStream.Read(iTmp);
    m_eFType = (FilterType)iTmp;
    for (int i = 0; i < 3; i++)
    {
        rkStream.Read(iTmp);
        m_aeWType[i] = (WrapType)iTmp;
    }
    rkStream.Read(m_kBorderColor);

    if (rkStream.GetVersion() < StreamVersion(4,5))
    {
        rkStream.Read(iTmp);  // m_eCompare
    }

    if (rkStream.GetVersion() >= StreamVersion(4,6))
    {
        rkStream.Read(m_fAnisotropy);
    }
    else
    {
        m_fAnisotropy = 1.0f;
    }

    rkStream.Read(m_bOffscreenTexture);

    // The data member m_spkImage is set during program runtime.

    WM4_END_DEBUG_STREAM_LOAD(Texture);
}
//----------------------------------------------------------------------------
void Texture::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool Texture::Register (Stream& rkStream) const
{
    return Object::Register(rkStream);
}
//----------------------------------------------------------------------------
void Texture::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);

    rkStream.Write((int)m_eFType);
    for (int i = 0; i < 3; i++)
    {
        rkStream.Write((int)m_aeWType[i]);
    }
    rkStream.Write(m_kBorderColor);
    rkStream.Write(m_fAnisotropy);
    rkStream.Write(m_bOffscreenTexture);

    // The data member m_spkImage is set during program runtime.

    WM4_END_DEBUG_STREAM_SAVE(Texture);
}
//----------------------------------------------------------------------------
int Texture::GetDiskUsed (const StreamVersion& rkVersion) const
{
    int iSize = Object::GetDiskUsed(rkVersion) +
        sizeof(int) + // m_eFType
        3*sizeof(int) + // m_aeWType[]
        sizeof(m_kBorderColor) +
        sizeof(m_fAnisotropy) +
        sizeof(char);  // m_bOffscreenTexture

    if (rkVersion < StreamVersion(4,5))
    {
        iSize += sizeof(int);  // m_eCompare removed in streamversion 4.5
    }
    if (rkVersion < StreamVersion(4,6))
    {
        iSize -= sizeof(float);  // m_fAnisotropy added to streamversion 4.6
    }

    return iSize;
}
//----------------------------------------------------------------------------
StringTree* Texture::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("filter = ",ms_aacFilterType[m_eFType]));

    const size_t uiTitleSize = 16;
    char acTitle[uiTitleSize];
    for (int i = 0; i < 3; i++)
    {
        System::Sprintf(acTitle,uiTitleSize,"wrap[%d] =",i);
        pkTree->Append(Format(acTitle,ms_aacWrapType[m_aeWType[i]]));
    }

    pkTree->Append(Format("border color =",m_kBorderColor));
    pkTree->Append(Format("anisotropy =",m_fAnisotropy));
    pkTree->Append(Format("offscreen =",m_bOffscreenTexture));

    // children
    pkTree->Append(Object::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
