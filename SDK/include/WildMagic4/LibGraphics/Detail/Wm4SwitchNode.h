// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SWITCHNODE_H
#define WM4SWITCHNODE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Node.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM SwitchNode : public Node
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SwitchNode ();
    virtual ~SwitchNode ();

    enum { SN_INVALID_CHILD = -1 };

    void SetActiveChild (int iActiveChild);
    int GetActiveChild () const;
    void DisableAllChildren ();

protected:
    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    int m_iActiveChild;
};

WM4_REGISTER_STREAM(SwitchNode);
typedef Pointer<SwitchNode> SwitchNodePtr;
#include "Wm4SwitchNode.inl"

}

#endif
