// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4DYNAMICTEXTURE_H
#define WM4DYNAMICTEXTURE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Texture.h"

// TO DO.  This class has been added as a hack to WM4 just to provide the
// functionality for dynamic textures in the short term.  For now, you
// get access to the entire texture image.  Subrectangle support will not
// occur until WM5.  The architecture of Texture will change in WM5,
// supporting static or dynamic textures.

namespace Wm4
{

class WM4_GRAPHICS_ITEM DynamicTexture : public Texture
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    DynamicTexture (const char* acTextureName, Image* pkImage);
    virtual ~DynamicTexture ();

    // Call Renderer::Lock to get a pointer to the texture image data in VRAM.
    // After reading and/or writing the data of the pointer returned by Lock,
    // call Renderer::Unlock.  Typical usage:
    //     DynamicTexture* pkTexture = <some texture>;
    //     float* afData = pkRenderer->Lock(pkTexture, Renderer::DT_WRITE);
    //     <write values to afData[...]>;
    //     pkRenderer->Unlock(pkTexture);
    // If the Lock fails, a null pointer is returned.  In this case, you do
    // not have to call Unlock.

    // To set image data, use the Lock and Unlock functions, allowing you to
    // access the VRAM data directly.
    //
    // WARNING:  This function disables the ability to set the m_spkImage data
    // member.  SetImage does NOT replace the m_spkImage value set by the
    // constructor.  The constructor image format persists for the life of
    // this object.
    virtual void SetImage (Image* pkImage);

    // WARNING:  For now, only nonmipmapped dynamic textures are supported.
    // SetFilterType will reassign mipmap filters NEAREST_* to NEAREST and
    // mipmap filters LINEAR_* to LINEAR.
    virtual void SetFilterType (FilterType eFType);

protected:
    // Streaming support.
    DynamicTexture ();
};

WM4_REGISTER_STREAM(DynamicTexture);
typedef Pointer<DynamicTexture> DynamicTexturePtr;

}

#endif
