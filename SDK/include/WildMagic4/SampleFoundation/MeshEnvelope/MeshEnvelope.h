// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef MESHENVELOPE_H
#define MESHENVELOPE_H

#include "Wm4WindowApplication2.h"
#include "Wm4PlanarGraph.h"
#include <vector>
using namespace Wm4;

class MeshEnvelope : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    MeshEnvelope ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

protected:
    enum
    {
        X_SIZE = 512,
        Y_SIZE = 512
    };

    // mesh
    int m_iVQuantity;
    Vector2f* m_akVertex;
    int m_iIQuantity;
    int* m_aiIndex;

    // envelope of mesh
    int m_iEQuantity;
    Vector2f* m_akEVertex;
};

WM4_REGISTER_INITIALIZE(MeshEnvelope);

#endif
