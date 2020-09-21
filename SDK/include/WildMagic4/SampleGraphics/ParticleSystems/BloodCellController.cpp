// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "BloodCellController.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,BloodCellController,ParticleController);
WM4_IMPLEMENT_STREAM(BloodCellController);
WM4_IMPLEMENT_DEFAULT_NAME_ID(BloodCellController,ParticleController);

//----------------------------------------------------------------------------
BloodCellController::BloodCellController ()
{
}
//----------------------------------------------------------------------------
void BloodCellController::UpdatePointMotion (float)
{
    Particles* pkParticle = StaticCast<Particles>(m_pkObject);

    int iLQuantity = pkParticle->Locations->GetQuantity();
    Vector3f* akLocation = pkParticle->Locations->GetData();
    float* afSize = pkParticle->Sizes->GetData();
    for (int i = 0; i < iLQuantity; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            akLocation[i][j] += 0.01f*Mathf::SymmetricRandom();
            if (akLocation[i][j] > 1.0f)
            {
                akLocation[i][j] = 1.0f;
            }
            else if (akLocation[i][j] < -1.0f)
            {
                akLocation[i][j] = -1.0f;
            }
        }

        afSize[i] *= (1.0f + 0.01f*Mathf::SymmetricRandom());
        if (afSize[i] > 0.25f)
        {
            afSize[i] = 0.25f;
        }
    }

    pkParticle->VBuffer->Release();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void BloodCellController::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;
    ParticleController::Load(rkStream,pkLink);
    WM4_END_DEBUG_STREAM_LOAD(BloodCellController);
}
//----------------------------------------------------------------------------
void BloodCellController::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ParticleController::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool BloodCellController::Register (Stream& rkStream) const
{
    return ParticleController::Register(rkStream);
}
//----------------------------------------------------------------------------
void BloodCellController::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;
    ParticleController::Save(rkStream);
    WM4_END_DEBUG_STREAM_SAVE(BloodCellController);
}
//----------------------------------------------------------------------------
int BloodCellController::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ParticleController::GetDiskUsed(rkVersion);
}
//----------------------------------------------------------------------------
StringTree* BloodCellController::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(ParticleController::SaveStrings());
    return pkTree;
}
//----------------------------------------------------------------------------
