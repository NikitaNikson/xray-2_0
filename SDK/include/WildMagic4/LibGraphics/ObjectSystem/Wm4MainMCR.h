// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MAINMCR_H
#define WM4MAINMCR_H

//----------------------------------------------------------------------------
#define WM4_DECLARE_INITIALIZE \
public: \
    static bool RegisterInitialize (); \
    static void Initialize (); \
private: \
    static bool ms_bInitializeRegistered
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_INITIALIZE(classname) \
bool classname::ms_bInitializeRegistered = false; \
bool classname::RegisterInitialize () \
{ \
    if (!ms_bInitializeRegistered) \
    { \
        Main::AddInitializer(classname::Initialize); \
        ms_bInitializeRegistered = true; \
    } \
    return ms_bInitializeRegistered; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_INITIALIZE(classname) \
static bool gs_bInitializeRegistered_##classname = \
    classname::RegisterInitialize ()
//----------------------------------------------------------------------------
#define WM4_DECLARE_TERMINATE \
public: \
    static bool RegisterTerminate (); \
    static void Terminate (); \
private: \
    static bool ms_bTerminateRegistered
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_TERMINATE(classname) \
bool classname::ms_bTerminateRegistered = false; \
bool classname::RegisterTerminate () \
{ \
    if (!ms_bTerminateRegistered) \
    { \
        Main::AddTerminator(classname::Terminate); \
        ms_bTerminateRegistered = true; \
    } \
    return ms_bTerminateRegistered; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_TERMINATE(classname) \
static bool gs_bTerminateRegistered_##classname = \
    classname::RegisterTerminate ()
//----------------------------------------------------------------------------

#endif
