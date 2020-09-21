// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4OPENGLRESOURCES_H
#define WM4OPENGLRESOURCES_H

#include "Wm4OpenGLRendererLIB.h"
#include "Wm4Attributes.h"
#include "Wm4Bindable.h"

namespace Wm4
{

class WM4_RENDERER_ITEM VProgramID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
};

class WM4_RENDERER_ITEM PProgramID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
};

class WM4_RENDERER_ITEM TextureID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
    Texture* TextureObject;
    unsigned int PBOHandle;  // For dynamic textures (pixel buffer objects).
};

class WM4_RENDERER_ITEM VBufferID : public ResourceIdentifier
{
public:
    Attributes IAttr;  // For matching inputs when doing multipass.
    Attributes OAttr;
    unsigned int ID;   // OpenGL's identifier for the resource.
};

class WM4_RENDERER_ITEM IBufferID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
};

}

#endif
