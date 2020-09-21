// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "BooleanIntervalRectangle.h"
#include "RectangleSet.h"
using namespace Wm4;

WM4_CONSOLE_APPLICATION(BooleanIntervalRectangle);

//----------------------------------------------------------------------------
BooleanIntervalRectangle::BooleanIntervalRectangle ()
{
}
//----------------------------------------------------------------------------
BooleanIntervalRectangle::~BooleanIntervalRectangle ()
{
}
//----------------------------------------------------------------------------
int BooleanIntervalRectangle::Main (int, char**)
{
    IntervalSet<float> kS1, kS2;
    kS1.Insert(1.0f,3.0f);
    kS1.Insert(4.0f,9.0f);
    kS1.Insert(10.0f,12.0f);
    kS1.Insert(16.0f,17.0f);
    kS2.Insert(0.0f,2.0f);
    kS2.Insert(6.0f,7.0f);
    kS2.Insert(8.0f,11.0f);
    kS2.Insert(13.0f,14.0f);
    kS2.Insert(15.0f,18.0f);
    IntervalSet<float> kS1uS2, kS1iS2, kS1dS2, kS1xS2;
    IntervalSet<float>::Union(kS1,kS2,kS1uS2);
    IntervalSet<float>::Intersection(kS1,kS2,kS1iS2);
    IntervalSet<float>::Difference(kS1,kS2,kS1dS2);
    IntervalSet<float>::ExclusiveOr(kS1,kS2,kS1xS2);

    RectangleSet<float> kR1, kR2;
    kR1.Insert(0.0f,2.0f,0.0f,2.0f);
    kR2.Insert(1.0f,3.0f,1.0f,3.0f);
    RectangleSet<float> kR1uR2, kR1iR2, kR1dR2, kR1xR2;
    RectangleSet<float>::Union(kR1,kR2,kR1uR2);
    RectangleSet<float>::Intersection(kR1,kR2,kR1iR2);
    RectangleSet<float>::Difference(kR1,kR2,kR1dR2);
    RectangleSet<float>::ExclusiveOr(kR1,kR2,kR1xR2);
    return 0;
}
//----------------------------------------------------------------------------
