// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4StreamVersion.h"
using namespace Wm4;

const int StreamVersion::MAJOR = 4;
const int StreamVersion::MINOR = 7;
const char StreamVersion::LABEL[] = "Wild Magic Object File 4.07";
const int StreamVersion::LENGTH = 28;
const StreamVersion StreamVersion::CURRENT(MAJOR,MINOR);

//----------------------------------------------------------------------------
StreamVersion::StreamVersion (int iMajor, int iMinor)
{
    m_iMajor = iMajor;
    m_iMinor = iMinor;
}
//----------------------------------------------------------------------------
StreamVersion::StreamVersion (const char* acString)
{
    m_iMajor = -1;
    m_iMinor = -1;

    if (acString
    &&  strlen(acString) >= LENGTH-1
    &&  acString[LENGTH-1] == 0
    &&  strncmp(acString,LABEL,LENGTH-5) == 0)  // 5 = strlen(" 4.xx")
    {
        // The version string is "x.yy".
        const char* acVersion = acString + LENGTH - 5;
        m_iMajor = (int)(acVersion[0]-'0');
        m_iMinor = 10*(int)(acVersion[2]-'0') + (int)(acVersion[3]-'0');
    }
}
//----------------------------------------------------------------------------
bool StreamVersion::IsValid () const
{
    return m_iMajor == StreamVersion::MAJOR
        && 0 <= m_iMinor && m_iMinor < 100;
}
//----------------------------------------------------------------------------
int StreamVersion::GetMajor () const
{
    return m_iMajor;
}
//----------------------------------------------------------------------------
int StreamVersion::GetMinor () const
{
    return m_iMinor;
}
//----------------------------------------------------------------------------
int StreamVersion::GetCombined () const
{
    return 100*m_iMajor + m_iMinor;
}
//----------------------------------------------------------------------------
bool StreamVersion::operator== (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() == rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator!= (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() != rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator< (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() < rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator<= (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() <= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator> (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() > rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator>= (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() >= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
