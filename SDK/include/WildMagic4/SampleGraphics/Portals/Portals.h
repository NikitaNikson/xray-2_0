// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PORTALS_H
#define PORTALS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class Portals : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Portals ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateCenterCube (const std::string& rkFloor,
        const std::string& rkCeiling, const std::string& rkWall,
        const std::string& rkPicture0, const std::string& rkPicture1,
        const std::string& rkPicture2, const std::string& rkPicture3,
        Node*& rpkCube, Portal**& rapkPortal);

    void CreateAxisConnector (const std::string& rkFloor,
        const std::string& rkCeiling, const std::string& rkWall,
        Node*& rpkCube, Portal**& rapkPortal);

    void CreateEndCube (const std::string& rkFloor,
        const std::string& rkCeiling, const std::string& rkWall,
        Node*& rpkCube, Portal**& rapkPortal);

    void CreateDiagonalConnector (const std::string& rkFloor,
        const std::string& rkCeiling, const std::string& rkWall,
        Node*& rpkCube, Portal**& rapkPortal);

    TriMesh* CreateOutside ();
    ConvexRegionManager* CreateBspTree ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(Portals);

#endif
