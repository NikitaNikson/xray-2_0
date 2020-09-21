// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4BINDABLE_H
#define WM4BINDABLE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"
#include "Wm4Attributes.h"
#include "Wm4Renderer.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ResourceIdentifier
{
public:
    // Abstract base class.  The destructor is *NOT* virtual so that the
    // derived-class destructors hide it.  This is intentional to avoid a
    // virtual function table pointer, a safe thing here because the base
    // class has no data.  This allows the derived classes that represent
    // vertex buffer information to store the input attributes first, and
    // allow typecasting of the following form.
    //
    //   class VBufferIdentifier : public ResourceIdentifier
    //   {
    //   public:  Attributes IAttr;
    //   }
    //   VBufferIdentifier* pkID = <some identifier>;
    //   Attributes& rkIAttr = *(Attributes*)pkID;

    ~ResourceIdentifier () {/**/}

protected:
    ResourceIdentifier () {/**/}
};

class WM4_GRAPHICS_ITEM Bindable
{
public:
    Bindable ();
    ~Bindable ();

    // Use this function when the resource has a unique representation in
    // VRAM (all resources except for vertex buffers).
    ResourceIdentifier* GetIdentifier (Renderer* pkUser) const;

    // Use these functions when the resource has multiple representations in
    // VRAM (vertex buffers).
    int GetInfoQuantity () const;
    int GetInfoQuantity (Renderer* pkUser) const;
    ResourceIdentifier* GetIdentifier (int i, Renderer* pkUser) const;

    void Release ();

private:
    friend class Renderer;

    void OnLoad (Renderer* pkUser, Renderer::ReleaseFunction oRelease,
        ResourceIdentifier* pkID);

    void OnRelease (Renderer* pkUser, ResourceIdentifier* pkID);

    struct Info
    {
        // The renderer to which the resource is bound.
        Renderer* User;

        // The renderer function to call to release the resource.
        Renderer::ReleaseFunction Release;

        // The identifier of the resource for the renderer's use.
        ResourceIdentifier* ID;
    };

    std::vector<Info> m_kInfoArray;
};

};

#endif
