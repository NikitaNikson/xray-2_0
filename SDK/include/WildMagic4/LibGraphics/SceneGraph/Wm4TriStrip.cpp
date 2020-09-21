// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4TriStrip.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,TriStrip,Triangles);
WM4_IMPLEMENT_STREAM(TriStrip);
WM4_IMPLEMENT_DEFAULT_NAME_ID(TriStrip,Triangles);

//----------------------------------------------------------------------------
TriStrip::TriStrip ()
{
    Type = GT_TRISTRIP;
}
//----------------------------------------------------------------------------
TriStrip::TriStrip (VertexBuffer* pkVBuffer, bool bUpdateModelNormals,
    int iTangentSpaceType)
    :
    Triangles(pkVBuffer,0)
{
    Type = GT_TRISTRIP;

    int iVQuantity = pkVBuffer->GetVertexQuantity();
    IBuffer = WM4_NEW IndexBuffer(iVQuantity);
    int* piIndex = IBuffer->GetData();
    for (int i = 0; i < iVQuantity; i++)
    {
        *piIndex++ = i;
    }

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
TriStrip::TriStrip (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer,
    bool bUpdateModelNormals, int iTangentSpaceType)
    :
    Triangles(pkVBuffer,pkIBuffer)
{
    Type = GT_TRISTRIP;

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
TriStrip::~TriStrip ()
{
}
//----------------------------------------------------------------------------
bool TriStrip::GetTriangle (int i, int& riV0, int& riV1, int& riV2) const
{
    if (0 <= i && i < GetTriangleQuantity())
    {
        const int* aiIndex = IBuffer->GetData();
        riV0 = aiIndex[i];
        if (i & 1)
        {
            riV1 = aiIndex[i+2];
            riV2 = aiIndex[i+1];
        }
        else
        {
            riV1 = aiIndex[i+1];
            riV2 = aiIndex[i+2];
        }

        // Degenerate triangles are assumed to have been added for swaps and
        // turns in the triangle strip.  They are considered invalid for other
        // purposes in the engine.
        return (riV0 != riV1 && riV0 != riV2 && riV1 != riV2);
    }
    return false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void TriStrip::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    Triangles::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(TriStrip);
}
//----------------------------------------------------------------------------
void TriStrip::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Triangles::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool TriStrip::Register (Stream& rkStream) const
{
    return Triangles::Register(rkStream);
}
//----------------------------------------------------------------------------
void TriStrip::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    Triangles::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(TriStrip);
}
//----------------------------------------------------------------------------
int TriStrip::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Triangles::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* TriStrip::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Triangles::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
