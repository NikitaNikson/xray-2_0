// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef NONITERATIVEEIGENSOLVER_H
#define NONITERATIVEEIGENSOLVER_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class NoniterativeEigensolver : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

private:
    void SolveAndMeasure (const Matrix3f& rkA, float& rfIError,
        float& rfNError, float& rfIDet, float& rfNDet);

    // Data for iterative method.
    float m_afIEValue[3];
    Vector3f m_akIEVector[3];

    // Data for noniterative method.
    float m_afNEValue[3];
    Vector3f m_akNEVector[3];
};

WM4_REGISTER_INITIALIZE(NoniterativeEigensolver);

#endif
