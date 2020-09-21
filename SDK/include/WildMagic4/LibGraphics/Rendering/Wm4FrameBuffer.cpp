// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4FrameBuffer.h"
#include "Wm4Renderer.h"
#include "Wm4Texture.h"
#include "Wm4Image.h"
using namespace Wm4;

FrameBuffer::Creator FrameBuffer::ms_aoCreate[Renderer::MAX_RENDERER_TYPES];
FrameBuffer::Destroyer FrameBuffer::ms_aoDestroy[
    Renderer::MAX_RENDERER_TYPES];

//----------------------------------------------------------------------------
FrameBuffer* FrameBuffer::Create (FormatType eFormat, DepthType eDepth,
    StencilType eStencil, BufferingType eBuffering,
    MultisamplingType eMultisampling, Renderer* pkRenderer, Texture* pkTarget)
{
    Creator oCreator = ms_aoCreate[pkRenderer->GetType()];
    assert(oCreator);
    if (oCreator)
    {
        return oCreator(eFormat,eDepth,eStencil,eBuffering,eMultisampling,
            pkRenderer,pkTarget);
    }
    return 0;
}
//----------------------------------------------------------------------------
void FrameBuffer::Destroy (FrameBuffer* pkBuffer)
{
    Renderer* pkRenderer = pkBuffer->GetRenderer();
    Destroyer oDestroyer = ms_aoDestroy[pkRenderer->GetType()];
    assert(oDestroyer);
    if (oDestroyer)
    {
        oDestroyer(pkBuffer);
    }
}
//----------------------------------------------------------------------------
FrameBuffer::FrameBuffer (FormatType eFormat, DepthType eDepth,
    StencilType eStencil, BufferingType eBuffering,
    MultisamplingType eMultisampling, Renderer* pkRenderer, Texture* pkTarget)
{
    m_eFormat = eFormat;
    m_eDepth = eDepth;
    m_eStencil = eStencil;
    m_eBuffering = eBuffering;
    m_eMultisampling = eMultisampling;
    m_pkRenderer = pkRenderer;
    m_pkTarget = pkTarget;
}
//----------------------------------------------------------------------------
FrameBuffer::~FrameBuffer ()
{
}
//----------------------------------------------------------------------------
