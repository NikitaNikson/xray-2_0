// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4DX9RESOURCES_H
#define WM4DX9RESOURCES_H

#include "Wm4Dx9RendererLIB.h"
#include "Wm4Dx9Utility.h"
#include "Wm4Attributes.h"
#include "Wm4Bindable.h"

namespace Wm4
{

class WM4_RENDERER_ITEM VProgramID : public ResourceIdentifier
{
public:
    IDirect3DVertexShader9* ID;
};

class WM4_RENDERER_ITEM PProgramID : public ResourceIdentifier
{
public:
    IDirect3DPixelShader9* ID;
};

class WM4_RENDERER_ITEM TextureID : public ResourceIdentifier
{
public:
    IDirect3DBaseTexture9* ID;
    Texture* TextureObject;
};

class WM4_RENDERER_ITEM VBufferID : public ResourceIdentifier
{
public:
    Attributes IAttr;  // For matching inputs when doing multipass.
    Attributes OAttr;
    IDirect3DVertexBuffer9* ID;
    IDirect3DVertexDeclaration9* Declaration;
    int VertexSize;
};

class WM4_RENDERER_ITEM IBufferID : public ResourceIdentifier
{
public:
    LPDIRECT3DINDEXBUFFER9 ID;
};

}

#endif
