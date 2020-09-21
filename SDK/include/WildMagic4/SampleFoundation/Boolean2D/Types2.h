// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef TYPES2_H
#define TYPES2_H

#include "Edge2.h"
#include "Wm4Vector2.h"
using namespace Wm4;

#include <map>
#include <vector>
using namespace std;

// vertices
typedef map<Vector2d,int> VMap;
typedef map<Vector2d,int>::iterator VIterator;
typedef map<Vector2d,int>::const_iterator VCIterator;
typedef vector<Vector2d> VArray;

// edges
typedef map<Edge2,int> EMap;
typedef map<Edge2,int>::iterator EIterator;
typedef map<Edge2,int>::const_iterator ECIterator;
typedef vector<Edge2> EArray;

#endif
