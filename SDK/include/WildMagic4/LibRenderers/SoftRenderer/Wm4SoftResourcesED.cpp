// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4SoftRendererPCH.h"
#include "Wm4SoftRenderer.h"
#include "Wm4SoftResources.h"
#include "Wm4Geometry.h"
#include "Wm4ShaderEffect.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void SoftRenderer::SetVProgramConstant (int eCType, int iBaseRegister,
    int iRegisterQuantity, float* afData)
{
    if (eCType != Renderer::CT_NUMERICAL)
    {
        m_kVRegister.EnsureCapacity(4*(iBaseRegister+iRegisterQuantity));
        for (int j = 0; j < iRegisterQuantity; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                m_kVRegister.Append(*afData++);
            }
        }
    }
}
//----------------------------------------------------------------------------
void SoftRenderer::SetPProgramConstant (int eCType, int iBaseRegister,
    int iRegisterQuantity, float* afData)
{
    if (eCType != Renderer::CT_NUMERICAL)
    {
        m_kPRegister.EnsureCapacity(4*(iBaseRegister+iRegisterQuantity));
        for (int j = 0; j < iRegisterQuantity; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                m_kPRegister.Append(*afData++);
            }
        }
    }
}
//----------------------------------------------------------------------------
void SoftRenderer::OnEnableVProgram (ResourceIdentifier* pkID)
{
    VProgramID* pkResource = (VProgramID*)pkID;
    m_oVProgram = pkResource->ID;
    m_kOAttr = pkResource->OAttr;
    m_iNumOutputChannels = m_kOAttr.GetChannelQuantity();
    m_kVRegister.Clear();
}
//----------------------------------------------------------------------------
void SoftRenderer::OnDisableVProgram (ResourceIdentifier*)
{
    m_oVProgram = 0;
    m_iNumOutputChannels = 0;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnEnablePProgram (ResourceIdentifier* pkID)
{
    PProgramID* pkResource = (PProgramID*)pkID;
    m_oPProgram = pkResource->ID;
    m_kPRegister.Clear();
    m_kPSampler.clear();
}
//----------------------------------------------------------------------------
void SoftRenderer::OnDisablePProgram (ResourceIdentifier*)
{
    m_oPProgram = 0;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnEnableTexture (ResourceIdentifier* pkID)
{
    TextureID* pkResource = (TextureID*)pkID;
    m_kPSampler.push_back(pkResource->ID);
}
//----------------------------------------------------------------------------
void SoftRenderer::OnDisableTexture (ResourceIdentifier*)
{
    // Nothing to do.
}
//----------------------------------------------------------------------------
void SoftRenderer::OnEnableVBuffer (ResourceIdentifier* pkID)
{
    m_pkVBResource = (VBufferID*)pkID;
    m_iNumInputChannels = m_pkVBResource->IAttr.GetChannelQuantity();
}
//----------------------------------------------------------------------------
void SoftRenderer::OnDisableVBuffer (ResourceIdentifier*)
{
    m_pkVBResource = 0;
    m_iNumInputChannels = 0;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnEnableIBuffer (ResourceIdentifier* pkID)
{
    m_pkIBResource = (IBufferID*)pkID;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnDisableIBuffer (ResourceIdentifier*)
{
    m_pkIBResource = 0;
}
//----------------------------------------------------------------------------
