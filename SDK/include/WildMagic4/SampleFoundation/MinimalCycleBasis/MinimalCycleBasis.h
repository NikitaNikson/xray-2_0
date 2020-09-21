// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef MINIMALCYCLEBASIS_H
#define MINIMALCYCLEBASIS_H

#include "Wm4WindowApplication2.h"
#include "Wm4PlanarGraph.h"
#include <vector>
using namespace Wm4;

class MinimalCycleBasis : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    MinimalCycleBasis ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

protected:
    typedef PlanarGraph<IVector2> Graph;
    Graph m_kGraph;
    std::vector<Graph::Primitive*> m_kPrimitives;
    Color* m_akColor;
};

WM4_REGISTER_INITIALIZE(MinimalCycleBasis);

#endif
