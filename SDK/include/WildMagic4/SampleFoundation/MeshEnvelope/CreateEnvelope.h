// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CREATEENVELOPE_H
#define CREATEENVELOPE_H

#include "Wm4Vector2.h"

void CreateEnvelope (int iVertexQuantity, const Wm4::Vector2f* akVertex,
    int iIndexQuantity, const int* aiIndex, int& riEnvelopeQuantity,
    Wm4::Vector2f*& rakEnvelopeVertex);

#endif
