// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void Texture::SetImage (Image* pkImage)
{
    m_spkImage = pkImage;
}
//----------------------------------------------------------------------------
inline Image* Texture::GetImage ()
{
    return m_spkImage;
}
//----------------------------------------------------------------------------
inline const Image* Texture::GetImage () const
{
    return m_spkImage;
}
//----------------------------------------------------------------------------
inline void Texture::SetFilterType (FilterType eFType)
{
    m_eFType = eFType;
}
//----------------------------------------------------------------------------
inline Texture::FilterType Texture::GetFilterType () const
{
    return m_eFType;
}
//----------------------------------------------------------------------------
inline void Texture::SetWrapType (int i, WrapType eWType)
{
    assert(0 <= i && i < 3);
    m_aeWType[i] = eWType;
}
//----------------------------------------------------------------------------
inline Texture::WrapType Texture::GetWrapType (int i) const
{
    assert(0 <= i && i < 3);
    return m_aeWType[i];
}
//----------------------------------------------------------------------------
inline void Texture::SetBorderColor (const ColorRGBA& rkBorderColor)
{
    m_kBorderColor = rkBorderColor;
}
//----------------------------------------------------------------------------
inline ColorRGBA Texture::GetBorderColor () const
{
    return m_kBorderColor;
}
//----------------------------------------------------------------------------
inline void Texture::SetAnisotropyValue (float fAnisotropy)
{
    m_fAnisotropy = fAnisotropy;
}
//----------------------------------------------------------------------------
inline float Texture::GetAnisotropyValue () const
{
    return m_fAnisotropy;
}
//----------------------------------------------------------------------------
inline bool Texture::IsOffscreenTexture () const
{
    return m_bOffscreenTexture;
}
//----------------------------------------------------------------------------
inline void Texture::SetOffscreenTexture (bool bOffscreenTexture)
{
    m_bOffscreenTexture = bOffscreenTexture;
}
//----------------------------------------------------------------------------
