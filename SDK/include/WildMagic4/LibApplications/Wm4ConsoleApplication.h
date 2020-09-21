// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CONSOLEAPPLICATION_H
#define WM4CONSOLEAPPLICATION_H

#include "Wm4Application.h"

namespace Wm4
{

class ConsoleApplication : public Application
{
public:
    ConsoleApplication ();
    virtual ~ConsoleApplication ();

    // Entry point to be implemented by the application.  The return value
    // is an exit code, if desired.
    virtual int Main (int iQuantity, char** apcArgument) = 0;

protected:
    // The hookup to the 'main' entry point into the executable.
    static int Run (int iQuantity, char** apcArgument);
};

}

#endif
