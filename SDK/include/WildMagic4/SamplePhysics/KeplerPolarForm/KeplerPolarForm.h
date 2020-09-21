// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef KEPLERPOLARFORM_H
#define KEPLERPOLARFORM_H

#include "Wm4WindowApplication2.h"
#include "PhysicsModule.h"
using namespace Wm4;

class KeplerPolarForm : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    KeplerPolarForm ();

    virtual bool OnInitialize ();
    virtual void OnDisplay ();

protected:
    PhysicsModule m_kModule;
    std::vector<Vector2d> m_kPosition;
};

WM4_REGISTER_INITIALIZE(KeplerPolarForm);

#endif
