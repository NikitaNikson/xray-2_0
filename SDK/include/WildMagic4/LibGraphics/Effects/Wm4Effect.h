// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4EFFECT_H
#define WM4EFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"

namespace Wm4
{

class Geometry;
class Renderer;
class Spatial;
class VisibleObject;

class WM4_GRAPHICS_ITEM Effect : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~Effect ();

    // Override this function to obtain whatever drawing behavior your effect
    // requires.  If this is not overridden, the default behavior is to
    // draw all the Geometry objects in akVisible.
    virtual void Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
        int iMin, int iMax, VisibleObject* akVisible);

    // Override these to allow loading and releasing of any resources your
    // effect requires.  The defaults are to do nothing.  The functions are
    // called by Renderer::LoadResources and Renderer::ReleaseResources for
    // Geometry and Effect objects.
    virtual void LoadResources (Renderer* pkRenderer, Geometry* pkGeometry);
    virtual void ReleaseResources (Renderer* pkRenderer,
        Geometry* pkGeometry);

protected:
    Effect ();
};

WM4_REGISTER_STREAM(Effect);
typedef Pointer<Effect> EffectPtr;

}

#endif
