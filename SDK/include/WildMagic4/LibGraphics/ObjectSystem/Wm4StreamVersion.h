// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4STREAMVERSION_H
#define WM4STREAMVERSION_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

// Scene graphs are stored in files with extension wmof.  The header is of the
// form "Wild Magic Object File 4.xx" where the major version is 4 and the
// the minor version is xx in [00,99].  The length of the string is 27, but
// the null terminator is written to disk, so total number of file bytes used
// by the version is 28.  The current version is "4.07"

namespace Wm4
{

class WM4_GRAPHICS_ITEM StreamVersion
{
public:
    static const int MAJOR;     // 4
    static const int MINOR;     // 5
    static const char LABEL[];  // "Wild Magic Object File 4.07"
    static const int LENGTH;    // 28 = strlen(LABEL)+1
    static const StreamVersion CURRENT;

    StreamVersion (int iMajor = MAJOR, int iMinor = MINOR);
    StreamVersion (const char* acString);

    int GetMajor () const;
    int GetMinor () const;

    // The version is valid if major is 4 and minor in [0,99].
    bool IsValid () const;

    // For comparisons of versions.  This is useful in the Stream support in
    // an Object-derived class whenever a change to that class causes a file
    // format change.
    bool operator== (const StreamVersion& rkVersion) const;
    bool operator!= (const StreamVersion& rkVersion) const;
    bool operator<  (const StreamVersion& rkVersion) const;
    bool operator<= (const StreamVersion& rkVersion) const;
    bool operator>  (const StreamVersion& rkVersion) const;
    bool operator>= (const StreamVersion& rkVersion) const;

protected:
    int GetCombined () const;  // 100*major + minor

    int m_iMajor, m_iMinor;
};

}

#endif
