// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef EXTRACTLEVELCURVES_H
#define EXTRACTLEVELCURVES_H

#include "Wm4ConsoleApplication.h"
#include "Wm4Imagics.h"
using namespace Wm4;

class ExtractLevelCurves : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    enum { MAGNIFY = 8, SIZE = 32, XPOS = 100, YPOS = 100 };

    bool Extract ();
    float LinearInterpolate (const ImageInt2D& rkImage, float fX, float fY)
        const;
    float BilinearInterpolate (const ImageInt2D& rkImage, float fX, float fY)
        const;

    static void DrawPixel (int iX, int iY);
    static ImageRGB82D* ms_pkColor;
    static unsigned int ms_uiColor;
    static float ms_fMultiply;
};

WM4_REGISTER_INITIALIZE(ExtractLevelCurves);

#endif
