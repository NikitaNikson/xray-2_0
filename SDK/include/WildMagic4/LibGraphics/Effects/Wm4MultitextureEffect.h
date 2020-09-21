// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MULTITEXTUREEFFECT_H
#define WM4MULTITEXTUREEFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ShaderEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM MultitextureEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    MultitextureEffect (int iTextureQuantity);
    virtual ~MultitextureEffect ();

    // Selection of the textures to be used by the effect.  The first call
    // should be SetTextureQuantity for the desired number of textures.  For
    // each texture, specify its image with SetImageName.  Texture 0 is used
    // as is (replace mode).  Texture i is blended with texture i-1
    // (for i > 0) according to the modes specified by alpha state i to
    // produce the current colors.  After setting all the texture names and
    // all the blending modes, call Configure() to activate the correct shader
    // program for the current set of textures.
    void SetTextureQuantity (int iTextureQuantity);
    int GetTextureQuantity () const;
    void SetTextureName (int i, const std::string& rkTextureName);
    const std::string& GetTextureName (int i) const;
    void Configure ();

protected:
    // streaming support
    MultitextureEffect ();

    int m_iTextureQuantity;
    std::string* m_akTextureName;
};

WM4_REGISTER_STREAM(MultitextureEffect);
typedef Pointer<MultitextureEffect> MultitextureEffectPtr;

}

#endif
