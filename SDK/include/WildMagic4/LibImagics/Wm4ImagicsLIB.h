// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4IMAGICSLIB_H
#define WM4IMAGICSLIB_H

// For the DLL library.
#ifdef WM4_IMAGICS_DLL_EXPORT
#define WM4_IMAGICS_ITEM __declspec(dllexport)

// For a client of the DLL library.
#else
#ifdef WM4_IMAGICS_DLL_IMPORT
#define WM4_IMAGICS_ITEM __declspec(dllimport)

// For the static library.
#else
#define WM4_IMAGICS_ITEM

#endif
#endif
#endif
