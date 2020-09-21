// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTSHADERLIBRARYMCR_H
#define WM4SOFTSHADERLIBRARYMCR_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4Main.h"

#ifdef WM4_HAS_SOFT_SHADER

//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_VPROGRAM(name) \
static bool ms_bVInitializeRegistered_##name = false; \
static void v_##name##Initialize () \
{ \
    SoftRenderer::RegisterVProgram(#name,&v_##name); \
} \
\
bool v_##name##Register () \
{ \
    if (!ms_bVInitializeRegistered_##name) \
    { \
        Main::AddInitializer(&v_##name##Initialize); \
        ms_bVInitializeRegistered_##name = true; \
    } \
    return ms_bVInitializeRegistered_##name; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_VPROGRAM(name) \
extern bool v_##name##Register (); \
static bool gs_bVInitializeRegistered_##name = v_##name##Register ()
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_PPROGRAM(name) \
static bool ms_bPInitializeRegistered_##name = false; \
static void p_##name##Initialize () \
{ \
    SoftRenderer::RegisterPProgram(#name,&p_##name); \
} \
\
bool p_##name##Register () \
{ \
    if (!ms_bPInitializeRegistered_##name) \
    { \
        Main::AddInitializer(&p_##name##Initialize); \
        ms_bPInitializeRegistered_##name = true; \
    } \
    return ms_bPInitializeRegistered_##name; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_PPROGRAM(name) \
extern bool p_##name##Register (); \
static bool gs_bPInitializeRegistered_##name = p_##name##Register ()
//----------------------------------------------------------------------------

#else

//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_VPROGRAM(name) \
static bool ms_bVInitializeRegistered_##name = false; \
static void v_##name##Initialize () \
{ \
    SoftRenderer::RegisterVProgram(#name,&v_##name); \
} \
\
WM4_RENDERER_ITEM bool v_##name##Register () \
{ \
    if (!ms_bVInitializeRegistered_##name) \
    { \
        Main::AddInitializer(&v_##name##Initialize); \
        ms_bVInitializeRegistered_##name = true; \
    } \
    return ms_bVInitializeRegistered_##name; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_VPROGRAM(name) \
extern WM4_RENDERER_ITEM bool v_##name##Register (); \
static bool gs_bVInitializeRegistered_##name = v_##name##Register ()
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_PPROGRAM(name) \
static bool ms_bPInitializeRegistered_##name = false; \
static void p_##name##Initialize () \
{ \
    SoftRenderer::RegisterPProgram(#name,&p_##name); \
} \
\
WM4_RENDERER_ITEM bool p_##name##Register () \
{ \
    if (!ms_bPInitializeRegistered_##name) \
    { \
        Main::AddInitializer(&p_##name##Initialize); \
        ms_bPInitializeRegistered_##name = true; \
    } \
    return ms_bPInitializeRegistered_##name; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_PPROGRAM(name) \
extern WM4_RENDERER_ITEM bool p_##name##Register (); \
static bool gs_bPInitializeRegistered_##name = p_##name##Register ()
//----------------------------------------------------------------------------

#endif

#endif
