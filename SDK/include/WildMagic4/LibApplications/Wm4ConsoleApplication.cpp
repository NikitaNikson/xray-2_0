// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ApplicationPCH.h"
#include "Wm4ConsoleApplication.h"
using namespace Wm4;

//----------------------------------------------------------------------------
ConsoleApplication::ConsoleApplication ()
{
}
//----------------------------------------------------------------------------
ConsoleApplication::~ConsoleApplication ()
{
}
//----------------------------------------------------------------------------
int ConsoleApplication::Run (int iQuantity, char** apcArgument)
{
    ConsoleApplication* pkTheApp = (ConsoleApplication*)TheApplication;
    return pkTheApp->Main(iQuantity,apcArgument);
}
//----------------------------------------------------------------------------
