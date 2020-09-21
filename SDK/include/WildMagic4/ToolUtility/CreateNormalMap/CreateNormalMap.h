// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef CREATENORMALMAP_H
#define CREATENORMALMAP_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class CreateNormalMap : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void Usage ();

    int GetImage (const char* acBMPName, int& riWidth, int& riHeight,
        unsigned char*& raucData);

    void SaveImage (const char* acBMPName, int iWidth, int iHeight,
        unsigned char* aucData);

    unsigned char* GenerateNormals (int iXMax, int iYMax,
        float* afHeight, float fXScale, float fYScale);
};

WM4_REGISTER_INITIALIZE(CreateNormalMap);

#endif
