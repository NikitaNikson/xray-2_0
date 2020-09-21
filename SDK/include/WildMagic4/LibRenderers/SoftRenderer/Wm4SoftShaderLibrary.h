// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTSHADERLIBRARY_H
#define WM4SOFTSHADERLIBRARY_H

#include "Wm4SoftShaderLibraryMCR.h"

// vertex programs
WM4_REGISTER_VPROGRAM(Default);
WM4_REGISTER_VPROGRAM(L1a);
WM4_REGISTER_VPROGRAM(L1d);
WM4_REGISTER_VPROGRAM(L1p);
WM4_REGISTER_VPROGRAM(L1s);
WM4_REGISTER_VPROGRAM(Material);
WM4_REGISTER_VPROGRAM(MaterialTexture);
WM4_REGISTER_VPROGRAM(Texture);
WM4_REGISTER_VPROGRAM(T0d2T1d2PassThrough);
WM4_REGISTER_VPROGRAM(VertexColor3);
WM4_REGISTER_VPROGRAM(VertexColor4);

// pixel programs
WM4_REGISTER_PPROGRAM(Default);
WM4_REGISTER_PPROGRAM(MaterialTexture);
WM4_REGISTER_PPROGRAM(PassThrough3);
WM4_REGISTER_PPROGRAM(PassThrough4);
WM4_REGISTER_PPROGRAM(Texture);
WM4_REGISTER_PPROGRAM(T0s1d0T1s1d1);
WM4_REGISTER_PPROGRAM(T0s1d0T1s2d0);
WM4_REGISTER_PPROGRAM(T0s1d0T1s3d1);

#endif
