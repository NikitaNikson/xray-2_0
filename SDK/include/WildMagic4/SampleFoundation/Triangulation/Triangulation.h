// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class Triangulation : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    Triangulation ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ClearAll ();

    void DoExample0 ();
    void DoExample1 ();
    void DoExample2 ();
    void DoExample3 ();
    void DoExample4 ();

    std::vector<Vector2f> m_kPositions;
    std::vector<int> m_kOuter, m_kInner0, m_kInner1;
    std::vector<std::vector<int>*> m_kInners;
    TriangulateEC<float>::Tree* m_pkRoot;
    std::vector<Vector2f> m_kFillSeed;
    std::vector<int> m_kTriangles;

    Query::Type m_eType;
    float m_fEpsilon;
    int m_iExample;
};

WM4_REGISTER_INITIALIZE(Triangulation);

#endif
