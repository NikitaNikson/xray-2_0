// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4NODE_H
#define WM4NODE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Spatial.h"
#include "Wm4Culler.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Node : public Spatial
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // construction and destruction
    Node ();
    virtual ~Node ();

    // children
    int GetQuantity () const;
    int AttachChild (Spatial* pkChild);
    int DetachChild (Spatial* pkChild);
    SpatialPtr DetachChildAt (int i);
    SpatialPtr SetChild (int i, Spatial* pkChild);
    SpatialPtr GetChild (int i);

protected:
    // geometric updates
    virtual void UpdateWorldData (double dAppTime);
    virtual void UpdateWorldBound ();

    // render state updates
    virtual void UpdateState (std::vector<GlobalState*>* akGStack,
        std::vector<Light*>* pkLStack);

    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    // children
    std::vector<SpatialPtr> m_kChild;
};

WM4_REGISTER_STREAM(Node);
typedef Pointer<Node> NodePtr;
#include "Wm4Node.inl"

}

#endif
