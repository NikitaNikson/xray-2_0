// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4USERCONSTANT_H
#define WM4USERCONSTANT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM UserConstant
{
public:
    // Construction and destruction.  The base register must be nonnegative.
    // The register quantity must be positive.  Each register represents four
    // floating-point values.
    UserConstant (const std::string& rkName, int iBaseRegister,
        int iRegisterQuantity);
    ~UserConstant ();

    // Member access.  The renderer will use these to pass the information to
    // the graphics API.
    const std::string& GetName () const;
    int GetBaseRegister () const;
    int GetRegisterQuantity () const;
    float* GetData () const;

    // The Shader base class provides storage for the user constants and
    // will set the float pointer to this storage when the shader program is
    // loaded.  However, Shader-derived classes may provide their own
    // storage and set the float pointer accordingly.  Such derived classes
    // are responsible for deallocating the storage if it was dynamically
    // allocated.
    void SetDataSource (float* afData);

private:
    std::string m_kName;
    int m_iBaseRegister;
    int m_iRegisterQuantity;
    float* m_afData;
};

#include "Wm4UserConstant.inl"

}

#endif
