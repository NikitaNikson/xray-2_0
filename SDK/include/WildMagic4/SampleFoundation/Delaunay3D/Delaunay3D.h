// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef DELAUNAY3D_H
#define DELAUNAY3D_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class Delaunay3D : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Delaunay3D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    TriMesh* CreateSphere () const;
    TriMesh* CreateTetra (int iIndex) const;
    void ChangeTetraStatus (int iIndex, const ColorRGBA& rkColor,
        bool bWireframe);
    void ChangeLastTetraStatus (int iIndex, int iVOpposite,
        const ColorRGBA& rkColor, const ColorRGBA& rkOppositeColor);
    void DoSearch ();

    NodePtr m_spkScene;
    Culler m_kCuller;
    Delaunay3f* m_pkDel;
    Vector3f m_kMin, m_kMax;
};

WM4_REGISTER_INITIALIZE(Delaunay3D);

#endif
