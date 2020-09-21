// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Delaunay2DInsertRemove.h"

WM4_WINDOW_APPLICATION(Delaunay2DInsertRemove);

const int g_iSize = 512;

//----------------------------------------------------------------------------
Delaunay2DInsertRemove::Delaunay2DInsertRemove ()
    :
    WindowApplication2("Delaunay2DInsertRemove",0,0,g_iSize,g_iSize,
        ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
    m_pkDelaunay = 0;
    m_iVQuantity = 0;
    m_akVertex = 0;
    m_iTQuantity = 0;
    m_aiTVertex = 0;
    m_aiTAdjacent = 0;
}
//----------------------------------------------------------------------------
bool Delaunay2DInsertRemove::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

    // generate random points and triangulate
    m_iVQuantity = 32;
    m_akVertex = WM4_NEW Vector2f[m_iVQuantity];
    int i;
    for (i = 0; i < m_iVQuantity; i++)
    {
        m_akVertex[i].X() = g_iSize*Mathf::IntervalRandom(0.125f,0.875f);
        m_akVertex[i].Y() = g_iSize*Mathf::IntervalRandom(0.125f,0.875f);
    }

    m_pkDelaunay = WM4_NEW IncrementalDelaunay2f(0.0f, 0.0f, (float)g_iSize,
        (float)g_iSize);

    for (i = 0; i < m_iVQuantity; i++)
    {
        m_pkDelaunay->Insert(m_akVertex[i]);
    }

    GetMesh();

    DoFlip(true);
    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void Delaunay2DInsertRemove::OnTerminate ()
{
    WM4_DELETE m_pkDelaunay;
    WM4_DELETE[] m_akVertex;
    WM4_DELETE[] m_aiTVertex;
    WM4_DELETE[] m_aiTAdjacent;
    WindowApplication2::OnTerminate();
}
//----------------------------------------------------------------------------
void Delaunay2DInsertRemove::OnDisplay ()
{
    ClearScreen();

    Color kGray(128,128,128);
    Color kBlue(0,0,255);
    int i, iX0, iY0, iX1, iY1, iX2, iY2;
    Vector2f kV0, kV1, kV2, kP;
    const std::vector<Vector2f>& rkVertex = m_pkDelaunay->GetVertices();

    // Draw the triangle mesh.
    std::set<Vector2f> kUsed;
    for (i = 0; i < m_iTQuantity; i++)
    {
        kV0 = rkVertex[m_aiTVertex[3*i]];
        iX0 = (int)(kV0.X() + 0.5f);
        iY0 = (int)(kV0.Y() + 0.5f);

        kV1 = rkVertex[m_aiTVertex[3*i+1]];
        iX1 = (int)(kV1.X() + 0.5f);
        iY1 = (int)(kV1.Y() + 0.5f);

        kV2 = rkVertex[m_aiTVertex[3*i+2]];
        iX2 = (int)(kV2.X() + 0.5f);
        iY2 = (int)(kV2.Y() + 0.5f);

        DrawLine(iX0,iY0,iX1,iY1,kGray);
        DrawLine(iX1,iY1,iX2,iY2,kGray);
        DrawLine(iX2,iY2,iX0,iY0,kGray);

        kUsed.insert(kV0);
        kUsed.insert(kV1);
        kUsed.insert(kV2);
    }

    // Draw the vertices.
    std::set<Vector2f>::iterator pkIter = kUsed.begin();
    for (/**/; pkIter != kUsed.end(); pkIter++)
    {
        kV0 = *pkIter;
        iX0 = (int)(kV0.X() + 0.5f);
        iY0 = (int)(kV0.Y() + 0.5f);
        SetThickPixel(iX0,iY0,2,kBlue);
    }

    WindowApplication2::OnDisplay();
}
//----------------------------------------------------------------------------
bool Delaunay2DInsertRemove::OnMouseClick (int iButton, int iState, int iX,
    int iY, unsigned int uiModifiers)
{
    Vector2f kP((float)iX,(float)(g_iSize - 1 - iY));

    if (iButton == MOUSE_LEFT_BUTTON && iState == MOUSE_DOWN)
    {
        if (uiModifiers & KEY_SHIFT)
        {
            // Remove a point from the triangulation.
            int i = m_pkDelaunay->GetContainingTriangle(kP);
            if (i >= 0)
            {
                float afBary[3];
                m_pkDelaunay->GetBarycentricSet(i,kP,afBary);
                int aiIndex[3];
                m_pkDelaunay->GetIndexSet(i,aiIndex);

                float fMax = afBary[0];
                int iMax = 0;
                if (afBary[1] > fMax)
                {
                    fMax = afBary[1];
                    iMax = 1;
                }
                if (afBary[2] > fMax)
                {
                    fMax = afBary[2];
                    iMax = 2;
                }

                Vector2f kRemovePoint =
                    m_pkDelaunay->GetVertices()[aiIndex[iMax]];
                m_pkDelaunay->Remove(kRemovePoint);
                GetMesh();
                OnDisplay();
            }
        }
        else
        {
            // Insert a point into the triangulation.
            m_pkDelaunay->Insert(kP);
            GetMesh();
            OnDisplay();
        }
    }

    return true;
}
//----------------------------------------------------------------------------
void Delaunay2DInsertRemove::GetMesh ()
{
    m_pkDelaunay->GenerateRepresentation();

    m_iTQuantity = m_pkDelaunay->GetNumTriangles();
    WM4_DELETE[] m_aiTVertex;
    m_aiTVertex = WM4_NEW int[3*m_iTQuantity];
    size_t uiSize = 3*m_iTQuantity*sizeof(int);
    System::Memcpy(m_aiTVertex,uiSize,m_pkDelaunay->GetIndices(),uiSize);
    WM4_DELETE[] m_aiTAdjacent;
    m_aiTAdjacent = WM4_NEW int[3*m_iTQuantity];
    System::Memcpy(m_aiTAdjacent,uiSize,m_pkDelaunay->GetAdjacencies(),
        uiSize);
}
//----------------------------------------------------------------------------
