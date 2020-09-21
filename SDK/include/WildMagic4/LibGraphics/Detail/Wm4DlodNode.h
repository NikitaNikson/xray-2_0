// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4DLODNODE_H
#define WM4DLODNODE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4SwitchNode.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM DlodNode : public SwitchNode
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    DlodNode ();
    virtual ~DlodNode ();

    // center for level of detail
    Vector3f& ModelCenter ();
    const Vector3f& GetModelCenter () const;
    const Vector3f& GetWorldCenter () const;

    // distance intervals for children
    void SetModelDistance (int i, float fMinDist, float fMaxDist);
    float GetModelMinDistance (int i) const;
    float GetModelMaxDistance (int i) const;
    float GetWorldMinDistance (int i) const;
    float GetWorldMaxDistance (int i) const;

protected:
    // switch the child based on distance from world LOD center to camera
    void SelectLevelOfDetail (const Camera* pkCamera);

    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    // point whose distance to camera determines correct child
    Vector3f m_kModelLodCenter;
    Vector3f m_kWorldLodCenter;

    // squared distances for each LOD interval
    std::vector<float> m_kModelMinDist;
    std::vector<float> m_kModelMaxDist;
    std::vector<float> m_kWorldMinDist;
    std::vector<float> m_kWorldMaxDist;
};

WM4_REGISTER_STREAM(DlodNode);
typedef Pointer<DlodNode> DlodNodePtr;
#include "Wm4DlodNode.inl"

}

#endif
