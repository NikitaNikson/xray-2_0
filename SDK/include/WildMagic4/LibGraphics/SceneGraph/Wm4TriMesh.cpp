// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4TriMesh.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,TriMesh,Triangles);
WM4_IMPLEMENT_STREAM(TriMesh);
WM4_IMPLEMENT_DEFAULT_NAME_ID(TriMesh,Triangles);

//----------------------------------------------------------------------------
TriMesh::TriMesh ()
{
    Type = GT_TRIMESH;
}
//----------------------------------------------------------------------------
TriMesh::TriMesh (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer,
    bool bUpdateModelNormals, int iTangentSpaceType)
    :
    Triangles(pkVBuffer,pkIBuffer)
{
    Type = GT_TRIMESH;

    if (bUpdateModelNormals)
    {
        UpdateModelNormals();
    }

    if (iTangentSpaceType > (int)GU_TANGENT_SPACE_NONE)
    {
        UpdateModelTangentSpace(iTangentSpaceType);
    }
}
//----------------------------------------------------------------------------
TriMesh::~TriMesh ()
{
}
//----------------------------------------------------------------------------
bool TriMesh::GetTriangle (int i, int& riV0, int& riV1, int& riV2) const
{
    if (0 <= i && i < GetTriangleQuantity())
    {
        const int* piIndex = &IBuffer->GetData()[3*i];
        riV0 = *piIndex++;
        riV1 = *piIndex++;
        riV2 = *piIndex;
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void TriMesh::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    Triangles::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(TriMesh);
}
//----------------------------------------------------------------------------
void TriMesh::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Triangles::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool TriMesh::Register (Stream& rkStream) const
{
    return Triangles::Register(rkStream);
}
//----------------------------------------------------------------------------
void TriMesh::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    Triangles::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(TriMesh);
}
//----------------------------------------------------------------------------
int TriMesh::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Triangles::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* TriMesh::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Triangles::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
