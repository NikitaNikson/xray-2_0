// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4IMAGEVERSION_H
#define WM4IMAGEVERSION_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

// Images are stored in files with extension wmif.  The header is of the
// form "Wild Magic Image File 4.xx" where the major version is 4 and the
// the minor version is xx in [00,99].  The length of the string is 26, but
// the null terminator is written to disk, so total number of file bytes used
// by the version is 27.  The current version is "4.00"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ImageVersion
{
public:
    static const int MAJOR;     // 4
    static const int MINOR;     // 0
    static const char LABEL[];  // "Wild Magic Image File 4.00"
    static const int LENGTH;    // 27 = strlen(LABEL)+1
    static const ImageVersion CURRENT;

    ImageVersion (int iMajor = -1, int iMinor = -1);
    ImageVersion (const char* acString);

    int GetMajor () const;
    int GetMinor () const;

    // The version is valid if major is 4 and minor in [0,99].
    bool IsValid () const;

    // For comparisons of versions.  This is useful whenever a change to the
    // Image class causes a file format change.
    bool operator== (const ImageVersion& rkVersion) const;
    bool operator!= (const ImageVersion& rkVersion) const;
    bool operator<  (const ImageVersion& rkVersion) const;
    bool operator<= (const ImageVersion& rkVersion) const;
    bool operator>  (const ImageVersion& rkVersion) const;
    bool operator>= (const ImageVersion& rkVersion) const;

protected:
    int GetCombined () const;  // 100*major + minor

    int m_iMajor, m_iMinor;
};

}

#endif
