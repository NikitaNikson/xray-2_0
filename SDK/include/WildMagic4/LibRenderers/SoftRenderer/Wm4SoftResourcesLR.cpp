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
void SoftRenderer::OnLoadVProgram (ResourceIdentifier*& rpkID,
    VertexProgram* pkVProgram)
{
    VProgramID* pkResource = WM4_NEW VProgramID;
    rpkID = pkResource;

    // This will be used to resize the data array for the outputs of the
    // vertex program.  It is also used by the edge buffer system to determine
    // where the texture coordinates are (for affine versus perspective
    // coordinates).
    pkResource->OAttr = pkVProgram->GetOutputAttributes();

    // The software vertex programs are self-registering.  Look up the vertex
    // program for the current vertex shader.
    assert(ms_pkVPrograms && ms_pkVPrograms->size() > 0);
    std::map<std::string,VProgram>::iterator pkIter =
        ms_pkVPrograms->find(pkVProgram->GetName());
    assert(pkIter != ms_pkVPrograms->end());
    pkResource->ID = pkIter->second;
    assert(pkResource->ID);
}
//----------------------------------------------------------------------------
void SoftRenderer::OnReleaseVProgram (ResourceIdentifier* pkID)
{
    VProgramID* pkResource = (VProgramID*)pkID;
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnLoadPProgram (ResourceIdentifier*& rpkID,
    PixelProgram* pkPProgram)
{
    PProgramID* pkResource = WM4_NEW PProgramID;
    rpkID = pkResource;

    // The software pixel programs are self-registering.  Look up the pixel
    // program for the current pixel shader.
    assert(ms_pkPPrograms && ms_pkPPrograms->size() > 0);
    std::map<std::string,PProgram>::iterator pkIter =
        ms_pkPPrograms->find(pkPProgram->GetName());
    assert(pkIter != ms_pkPPrograms->end());
    pkResource->ID = pkIter->second;
    assert(pkResource->ID);
}
//----------------------------------------------------------------------------
void SoftRenderer::OnReleasePProgram (ResourceIdentifier* pkID)
{
    PProgramID* pkResource = (PProgramID*)pkID;
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnLoadTexture (ResourceIdentifier*& rpkID,
    Texture* pkTexture)
{
    TextureID* pkResource = WM4_NEW TextureID;
    rpkID = pkResource;

    // Create a sampler for the software renderer.
    pkResource->ID = SoftSampler::Create(pkTexture);
    assert(pkResource->ID);
    m_kSamplers.insert(pkResource->ID);
}
//----------------------------------------------------------------------------
void SoftRenderer::OnReleaseTexture (ResourceIdentifier* pkID)
{
    TextureID* pkResource = (TextureID*)pkID;
    m_kSamplers.erase(pkResource->ID);
    WM4_DELETE pkResource->ID;
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnLoadVBuffer (ResourceIdentifier*& rpkID,
    const Attributes& rkIAttr, const Attributes& rkOAttr,
    VertexBuffer* pkVBuffer)
{
    VBufferID* pkResource = WM4_NEW VBufferID;
    rpkID = pkResource;
    pkResource->IAttr = rkIAttr;
    pkResource->OAttr = rkOAttr;
    pkResource->VQuantity = pkVBuffer->GetVertexQuantity();
    pkResource->IVertex = 0;  // allocated by BuildCompatibleArray
    pkVBuffer->BuildCompatibleArray(rkIAttr,false,pkResource->Channels,
        pkResource->IVertex);
}
//----------------------------------------------------------------------------
void SoftRenderer::OnReleaseVBuffer (ResourceIdentifier* pkID)
{
    VBufferID* pkResource = (VBufferID*)pkID;
    WM4_DELETE[] pkResource->IVertex;
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnLoadIBuffer (ResourceIdentifier*& rpkID,
    IndexBuffer* pkIBuffer)
{
    IBufferID* pkResource = WM4_NEW IBufferID;
    rpkID = pkResource;

    // Create an "internal" index buffer.
    pkResource->IBuffer = pkIBuffer;
}
//----------------------------------------------------------------------------
void SoftRenderer::OnReleaseIBuffer (ResourceIdentifier* pkID)
{
    IBufferID* pkResource = (IBufferID*)pkID;
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
