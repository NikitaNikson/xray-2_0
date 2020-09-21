// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BEADSLIDE_H
#define BEADSLIDE_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class BeadSlide : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    BeadSlide ();

    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void Simulation ();
};

WM4_REGISTER_INITIALIZE(BeadSlide);

#endif
