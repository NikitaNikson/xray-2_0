// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "BeadSlide.h"
#include "PhysicsModule.h"
using namespace Wm4;

WM4_CONSOLE_APPLICATION(BeadSlide);

//----------------------------------------------------------------------------
BeadSlide::BeadSlide ()
{
}
//----------------------------------------------------------------------------
void BeadSlide::Simulation ()
{
    // set up the physics module
    PhysicsModule kModule;
    kModule.Gravity = 1.0;
    kModule.Mass = 0.1;

    double dTime = 0.0;
    double dDeltaTime = 0.001;
    double dQ = 1.0;
    double dQDot = 0.0;
    kModule.Initialize(dTime,dDeltaTime,dQ,dQDot);

    // run the simulation
    std::ofstream kOStr(System::GetPath("","simulation.txt"));
    kOStr << "time  q  qder  position" << std::endl;
    const int iMax = 2500;
    for (int i = 0; i < iMax; i++)
    {
        double dX = dQ, dY = dQ*dQ, dZ = dQ*dY;

        const size_t uiSize = 512;
        char acMsg[uiSize];
        System::Sprintf(acMsg,uiSize,
            "%5.3lf %+16.8lf %+16.8lf %+8.4lf %+8.4lf %+8.4lf",
            dTime,dQ,dQDot,dX,dY,dZ);
        kOStr << acMsg << std::endl;

        kModule.Update();

        dTime = kModule.GetTime();
        dQ = kModule.GetQ();
        dQDot = kModule.GetQDot();
    }
    kOStr.close();
}
//----------------------------------------------------------------------------
int BeadSlide::Main (int, char**)
{
    Simulation();
    return 0;
}
//----------------------------------------------------------------------------
