// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4ImageVersion.h"
using namespace Wm4;

const int ImageVersion::MAJOR = 4;
const int ImageVersion::MINOR = 0;
const char ImageVersion::LABEL[] = "Wild Magic Image File 4.00";
const int ImageVersion::LENGTH = 27;
const ImageVersion ImageVersion::CURRENT(MAJOR,MINOR);

//----------------------------------------------------------------------------
ImageVersion::ImageVersion (int iMajor, int iMinor)
{
    m_iMajor = iMajor;
    m_iMinor = iMinor;
}
//----------------------------------------------------------------------------
ImageVersion::ImageVersion (const char* acString)
{
    m_iMajor = -1;
    m_iMinor = -1;

    if (acString
    &&  strlen(acString) >= LENGTH-1
    &&  acString[LENGTH-1] == 0
    &&  strncmp(acString,LABEL,LENGTH-5) == 0)  // 5 = strlen(" x.yy")
    {
        // The version string is "x.yy".
        const char* acVersion = acString + LENGTH - 5;
        m_iMajor = (int)(acVersion[0]-'0');
        m_iMinor = 10*(int)(acVersion[2]-'0') + (int)(acVersion[3]-'0');
    }
}
//----------------------------------------------------------------------------
bool ImageVersion::IsValid () const
{
    return m_iMajor == MAJOR && 0 <= m_iMinor && m_iMinor < 100;
}
//----------------------------------------------------------------------------
int ImageVersion::GetMajor () const
{
    return m_iMajor;
}
//----------------------------------------------------------------------------
int ImageVersion::GetMinor () const
{
    return m_iMinor;
}
//----------------------------------------------------------------------------
int ImageVersion::GetCombined () const
{
    return 100*m_iMajor + m_iMinor;
}
//----------------------------------------------------------------------------
bool ImageVersion::operator== (const ImageVersion& rkVersion) const
{
    return GetCombined() == rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator!= (const ImageVersion& rkVersion) const
{
    return GetCombined() != rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator< (const ImageVersion& rkVersion) const
{
    return GetCombined() < rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator<= (const ImageVersion& rkVersion) const
{
    return GetCombined() <= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator> (const ImageVersion& rkVersion) const
{
    return GetCombined() > rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool ImageVersion::operator>= (const ImageVersion& rkVersion) const
{
    return GetCombined() >= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
