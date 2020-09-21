// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef SIMPLEPENDULUM_H
#define SIMPLEPENDULUM_H

#include "Wm4ConsoleApplication.h"
#include "Wm4Imagics.h"
using namespace Wm4;

class SimplePendulum : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    enum { SIZE = 512 };

    static float* ExplicitEuler (float fX0, float fY0, float fH);
    static float* ImplicitEuler (float fX0, float fY0, float fH);
    static float* RungeKutta (float fX0, float fY0, float fH);
    static float* LeapFrog (float fX0, float fY0, float fH);
    void SolveMethod (float* (*oMethod)(float,float,float),
        const char* acOutIm, const char* acOutTxt);

    void Stiff1 ();
    float F0 (float fT, float fX, float fY);
    float F1 (float fT, float fX, float fY);
    void Stiff2True ();
    void Stiff2Approximate ();

    static void DrawPixel (int iX, int iY);
    static ImageRGB82D* ms_pkImage;
    static unsigned int ms_uiColor;
    static float ms_fK;
};

WM4_REGISTER_INITIALIZE(SimplePendulum);

#endif
