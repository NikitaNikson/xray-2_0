// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTRESOURCES_H
#define WM4SOFTRESOURCES_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftRenderer.h"

namespace Wm4
{

class WM4_RENDERER_ITEM VProgramID : public ResourceIdentifier
{
public:
    SoftRenderer::VProgram ID;
    Attributes OAttr;
};

class WM4_RENDERER_ITEM PProgramID : public ResourceIdentifier
{
public:
    SoftRenderer::PProgram ID;
};

class WM4_RENDERER_ITEM VBufferID : public ResourceIdentifier
{
public:
    Attributes IAttr;  // For matching inputs when doing multipass.
    Attributes OAttr;  // For tcoord information during mipmapping.
    int VQuantity;
    float* IVertex;
    int Channels;
};

class WM4_RENDERER_ITEM IBufferID : public ResourceIdentifier
{
public:
    const IndexBuffer* IBuffer;
};

class WM4_RENDERER_ITEM TextureID : public ResourceIdentifier
{
public:
    SoftSampler* ID;
    Texture* TextureObject;
};

}

#endif
