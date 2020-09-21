// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4APPLICATIONMCR_H
#define WM4APPLICATIONMCR_H

//----------------------------------------------------------------------------
#define WM4_CONSOLE_APPLICATION(classname) \
WM4_IMPLEMENT_INITIALIZE(classname); \
\
void classname::Initialize () \
{ \
    Application::Run = &ConsoleApplication::Run; \
    TheApplication = WM4_NEW classname; \
}
//----------------------------------------------------------------------------
#define WM4_WINDOW_APPLICATION(classname) \
WM4_IMPLEMENT_INITIALIZE(classname); \
\
void classname::Initialize () \
{ \
    Application::Run = &WindowApplication::Run; \
    TheApplication = WM4_NEW classname; \
}
//----------------------------------------------------------------------------

#endif
