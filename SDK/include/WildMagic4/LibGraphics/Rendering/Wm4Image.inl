// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline Image::FormatMode Image::GetFormat () const
{
    return m_eFormat;
}
//----------------------------------------------------------------------------
inline const std::string& Image::GetFormatName () const
{
    return ms_akFormatName[m_eFormat];
}
//----------------------------------------------------------------------------
inline std::string Image::GetFormatName (int eFormat)
{
    return ms_akFormatName[eFormat];
}
//----------------------------------------------------------------------------
inline bool Image::IsDepthImage () const
{
    return m_eFormat == IT_DEPTH16
        || m_eFormat == IT_DEPTH24
        || m_eFormat == IT_DEPTH32;
}
//----------------------------------------------------------------------------
inline bool Image::IsCubeImage () const
{
    return m_eFormat == IT_CUBE_RGB888 || m_eFormat == IT_CUBE_RGBA8888;
}
//----------------------------------------------------------------------------
inline int Image::GetBytesPerPixel () const
{
    return ms_aiBytesPerPixel[m_eFormat];
}
//----------------------------------------------------------------------------
inline int Image::GetBytesPerPixel (int eFormat)
{
    return ms_aiBytesPerPixel[eFormat];
}
//----------------------------------------------------------------------------
inline int Image::GetDimension () const
{
    return m_iDimension;
}
//----------------------------------------------------------------------------
inline int Image::GetBound (int i) const
{
    assert(0 <= i && i < 3);
    return m_aiBound[i];
}
//----------------------------------------------------------------------------
inline int Image::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline unsigned char* Image::GetData () const
{
    return m_aucData;
}
//----------------------------------------------------------------------------
inline unsigned char* Image::operator() (int i)
{
    return m_aucData + i*ms_aiBytesPerPixel[m_eFormat];
}
//----------------------------------------------------------------------------
