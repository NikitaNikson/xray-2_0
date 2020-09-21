// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SAMPLERINFORMATION_H
#define WM4SAMPLERINFORMATION_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM SamplerInformation
{
public:
    enum Type
    {
        SAMPLER_1D,       // dimension 1
        SAMPLER_2D,       // dimension 2
        SAMPLER_3D,       // dimension 3
        SAMPLER_CUBE,     // dimension 2 (a set of 2D images)
        SAMPLER_PROJ,     // dimension 2
        MAX_SAMPLER_TYPES
    };

    // Construction and destruction.  The name, sampler type, and texture
    // unit are stored in the shader program files.  The dimension is
    // deduced from the sampler type.  The sampler unit is created when
    // loading a shader program.  The filter mode and wrap modes are specific
    // to a texture object and stored by such an object.  TO DO:  When a
    // file system *.wmfx is implemented, it will store filter and wrap mode
    // values.  A mechanism needs to be created to provide these to texture
    // objects.
    SamplerInformation (const std::string& rkName, Type eType,
        int iTextureUnit);
    ~SamplerInformation ();

    // Member read-only access.
    const std::string& GetName () const;
    Type GetType () const;
    int GetTextureUnit () const;
    int GetDimension () const;

private:
    std::string m_kName;
    Type m_eType;
    int m_iTextureUnit;
    int m_iDimension;
};

#include "Wm4SamplerInformation.inl"

}

#endif
