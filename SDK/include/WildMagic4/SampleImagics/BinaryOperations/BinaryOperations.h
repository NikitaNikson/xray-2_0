// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef BINARYOPERATIONS_H
#define BINARYOPERATIONS_H

#include "Wm4ConsoleApplication.h"
#include "Wm4Imagics.h"
using namespace Wm4;

class BinaryOperations : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void GetBoundaries (const Binary2D& rkImage);
    void GetComponents (const Binary2D& rkImage);
    void GetL1Distance (const Binary2D& rkImage);
    void GetL2Distance (const Binary2D& rkImage);
    void GetSkeleton (const Binary2D& rkImage);
};

WM4_REGISTER_INITIALIZE(BinaryOperations);

#endif
