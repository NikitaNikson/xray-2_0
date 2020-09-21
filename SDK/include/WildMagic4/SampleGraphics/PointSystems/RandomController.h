// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef RANDOMCONTROLLER_H
#define RANDOMCONTROLLER_H

#include "Wm4PointController.h"

namespace Wm4
{

class RandomController : public PointController
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    RandomController ();
protected:
    virtual void UpdatePointMotion (float fCtrlTime);
};

WM4_REGISTER_STREAM(RandomController);

}

#endif
