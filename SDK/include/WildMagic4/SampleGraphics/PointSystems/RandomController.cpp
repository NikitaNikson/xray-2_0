// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "RandomController.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,RandomController,PointController);
WM4_IMPLEMENT_STREAM(RandomController);
WM4_IMPLEMENT_DEFAULT_NAME_ID(RandomController,PointController);

//----------------------------------------------------------------------------
RandomController::RandomController ()
{
}
//----------------------------------------------------------------------------
void RandomController::UpdatePointMotion (float)
{
    Polypoint* pkPoints = StaticCast<Polypoint>(m_pkObject);

    VertexBuffer* pkVB = pkPoints->VBuffer;
    int iVQuantity = pkVB->GetVertexQuantity();
    for (int i = 0; i < iVQuantity; i++)
    {
        float* afPos = pkVB->PositionTuple(i);
        for (int j = 0; j < 3; j++)
        {
            afPos[j] += 0.01f*Mathf::SymmetricRandom();
            if (afPos[j] > 1.0f)
            {
                afPos[j] = 1.0f;
            }
            else if (afPos[j] < -1.0f)
            {
                afPos[j] = -1.0f;
            }
        }
    }

    pkVB->Release();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void RandomController::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    PointController::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(RandomController);
}
//----------------------------------------------------------------------------
void RandomController::Link (Stream& rkStream, Stream::Link* pkLink)
{
    PointController::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool RandomController::Register (Stream& rkStream) const
{
    return PointController::Register(rkStream);
}
//----------------------------------------------------------------------------
void RandomController::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    PointController::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(RandomController);
}
//----------------------------------------------------------------------------
int RandomController::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return PointController::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* RandomController::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(PointController::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
