// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4CLODTERRAINBLOCK_H
#define WM4CLODTERRAINBLOCK_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Vector2.h"
#include "Wm4Vector3.h"

namespace Wm4
{

class Camera;
class Frustum;
class ClodTerrainPage;
class ClodTerrainVertex;

class WM4_GRAPHICS_ITEM ClodTerrainBlock
{
public:
    int GetX () const;
    int GetY () const;
    int GetStride () const;
    float GetDelta (int i) const;
    float GetDeltaMax () const;
    float GetDeltaL () const;
    float GetDeltaH () const;
    const Vector3f& GetMin () const;
    const Vector3f& GetMax () const;

    void SetEven (bool bSet);
    bool GetEven () const;
    void SetProcessed (bool bSet);
    bool GetProcessed () const;
    void SetVisible (bool bSet);
    bool GetVisible () const;
    void SetVisibilityTested (bool bSet);
    bool GetVisibilityTested () const;

    bool BitsSet () const;
    void ClearBits ();

    // creation of the quadtree
    void Initialize (ClodTerrainPage* pkPage, ClodTerrainBlock* pkBlock,
        int iBlock, int iX, int iY, int iStride, bool bEven);

    // allows for changing the height data during run time
    void UpdateBoundingBox (ClodTerrainPage* pkPage,
        ClodTerrainBlock* pkBlock, int iBlock, int iStride);

    // test for intersection of page's bounding box and view frustum
    void TestIntersectFrustum (const ClodTerrainPage* pkPage,
        const Camera* pkCamera);

    // distant terrain assumption
    void ComputeInterval (const Vector3f& rkModelEye, float fTolerance);

    // close terrain assumption
    void ComputeInterval (const Vector3f& rkModelDir,
        const Vector3f& rkModelEye, float fTolerance, Vector2f& rkLoc,
        float fSpacing);

    void SimplifyVertices (ClodTerrainPage* pkPage,
        const Vector3f& rkModelEye, const Vector3f& rkModelDir,
        float fTolerance, bool bCloseAssumption);

    void Disable (ClodTerrainPage* pkPage);

    // quadtree indexing
    static int GetParentIndex (int iChild);
    static int GetChildIndex (int iParent, int iIndex);
    static bool IsFirstChild (int iIndex);
    static bool IsSibling (int iIndex, int iTest);

protected:
    // bit flags for m_ucFlags
    enum
    {
        EVEN_PARITY       = 0x01,
        PROCESSED         = 0x02,
        VISIBLE           = 0x04,
        VISIBILITY_TESTED = 0x08,
        BITS_MASK         = 0x0E  // all but even parity bit
    };

    void GetVertex9 (unsigned short usSize, ClodTerrainVertex* pkVOrigin,
        ClodTerrainVertex* apkTVertex[9]);

    unsigned char m_ucX, m_ucY, m_ucStride, m_ucFlags;
    float m_fDelta[5], m_fDeltaMax;
    float m_fDeltaL, m_fDeltaH;
    Vector3f m_kMin, m_kMax;
};

#include "Wm4ClodTerrainBlock.inl"

}

#endif
