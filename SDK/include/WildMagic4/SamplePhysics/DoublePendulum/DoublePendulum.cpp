// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "DoublePendulum.h"
using namespace std;

WM4_WINDOW_APPLICATION(DoublePendulum);

const int g_iSize = 256;

//#define SINGLE_STEP

//----------------------------------------------------------------------------
DoublePendulum::DoublePendulum ()
    :
    WindowApplication2("DoublePendulum",0,0,g_iSize,g_iSize,
        ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool DoublePendulum::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

    // set up the physics module
    m_kModule.Gravity = 10.0;
    m_kModule.Mass1 = 10.0;
    m_kModule.Mass2 = 20.0;
    m_kModule.Length1 = 100.0;
    m_kModule.Length2 = 100.0;
    m_kModule.JointX = (double)(g_iSize/2);
    m_kModule.JointY = (double)(g_iSize-8);

    // initialize the differential equations
    double dTime = 0.0;
    double dDeltaTime = 1.0/6.0;
    double dTheta1 = 0.125*Mathd::PI;
    double dTheta1Dot = 0.0;
    double dTheta2 = 0.25*Mathd::PI;
    double dTheta2Dot = 0.0;
    m_kModule.Initialize(dTime,dDeltaTime,dTheta1,dTheta2,dTheta1Dot,
        dTheta2Dot);

    // use right-handed coordinates
    DoFlip(true);

    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void DoublePendulum::OnIdle ()
{
#ifndef SINGLE_STEP
    m_kModule.Update();
    OnDisplay();
#endif
}
//----------------------------------------------------------------------------
void DoublePendulum::OnDisplay ()
{
    ClearScreen();

    Color kBlack(0,0,0), kGray(128,128,128), kBlue(0,0,255);

    double dX1, dY1, dX2, dY2;
    m_kModule.GetPositions(dX1,dY1,dX2,dY2);
    int iX1 = (int)(dX1+0.5);
    int iY1 = (int)(dY1+0.5);
    int iX2 = (int)(dX2+0.5);
    int iY2 = (int)(dY2+0.5);

    // draw axes
    DrawLine(g_iSize/2,0,g_iSize/2,g_iSize-1,kGray);
    DrawLine(0,0,g_iSize-1,0,kGray);

    // pendulum joint
    int iJX = (int)(m_kModule.JointX+0.5);
    int iJY = (int)(m_kModule.JointY+0.5);

    // draw pendulum rods
    DrawLine(iJX,iJY,iX1,iY1,kBlue);
    DrawLine(iX1,iY1,iX2,iY2,kBlue);

    // draw pendulum joint
    DrawCircle(iJX,iJY,2,kBlack,true);

    // draw pendulum masses
    DrawCircle(iX1,iY1,2,kBlack,true);
    DrawCircle(iX2,iY2,2,kBlack,true);

    WindowApplication2::OnDisplay();
}
//----------------------------------------------------------------------------
bool DoublePendulum::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication2::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

#ifdef SINGLE_STEP
    switch (ucKey)
    {
    case 'g':
    case 'G':
        m_kModule.Update();
        OnDisplay();
        return true;
    }
#endif

    return false;
}
//----------------------------------------------------------------------------
