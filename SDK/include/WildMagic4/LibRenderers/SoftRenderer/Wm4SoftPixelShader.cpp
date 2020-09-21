// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4SoftRendererPCH.h"
#include "Wm4SoftRenderer.h"
#include "Wm4ShaderEffect.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void SoftRenderer::ApplyPixelShader (int iX, int iY, float fDepth,
    float /* fInverseW */,  const float* afInPixel)
{
    int iIndex = iX + m_iWidth*iY;

    // Process the stencil tests first.  If stenciling is enabled and a
    // stencil test fails at a pixel, then the color and depth at the pixel
    // are not modified.
    if (m_auiStencilBuffer)
    {
        StencilState* pkStencilState = GetStencilState();
        if (pkStencilState->Enabled)
        {
            bool bStencilPass = ApplyStencilCompare(iIndex);
            if (!bStencilPass)
            {
                ApplyStencilOperation(iIndex,pkStencilState->OnFail);
                return;
            }
        }
    }

    if (m_auiDepthBuffer)
    {
        ZBufferState* pkZBufferState = GetZBufferState();
        unsigned int uiDepth =
            WM4_UNIT_FLOAT_TO_UINT(fDepth,m_uiMaxDepthValue);

        StencilState* pkStencilState = GetStencilState();
        if (pkZBufferState->Enabled)
        {
            bool bZPass = ApplyZBufferCompare(iIndex,uiDepth);
            if (!bZPass)
            {
                if (pkStencilState->Enabled)
                {
                    ApplyStencilOperation(iIndex,pkStencilState->OnZFail);
                }
                return;
            }
        }

        if (pkZBufferState->Writable)
        {
            m_auiDepthBuffer[iIndex] = uiDepth;
            m_afDepthBuffer[iIndex] = fDepth;
        }

        if (pkStencilState->Enabled)
        {
            ApplyStencilOperation(iIndex,pkStencilState->OnZPass);
        }
    }

    if (m_auiColorBuffer && m_uiColorMask != 0)
    {
        // Draw the pixel.
        const float* afRegister = m_kPRegister.GetData();
        SoftSampler** apkSampler;
        if (m_kPSampler.size() > 0)
        {
            apkSampler = &m_kPSampler.front();
            for (int i = 0; i < (int)m_kPSampler.size(); i++)
            {
                if (apkSampler[i]->MipmappingEnabled())
                {
                    apkSampler[i]->CurrentPixel(iX,iY);
                }
            }
        }
        else
        {
            apkSampler = 0;
        }
        ColorRGBA kSrcColor = m_oPProgram(afRegister,apkSampler,afInPixel);
        kSrcColor.Clamp();

        AlphaState* pkAlphaState = GetAlphaState();
        if (!pkAlphaState->BlendEnabled)
        {
            // No blending, so write the source color to the color buffer.
            SetColorBuffer(iX,iY,iIndex,kSrcColor);
            return;
        }

        // The current color buffer value.
        ColorRGBA kDstColor = m_akColorBuffer[iIndex];

        // The final color after blending.
        ColorRGBA kFinalColor = GetBlendedColor(kSrcColor,kDstColor);
        kFinalColor.Clamp();

        SetColorBuffer(iX,iY,iIndex,kFinalColor);
    }
}
//----------------------------------------------------------------------------
bool SoftRenderer::ApplyStencilCompare (int iIndex)
{
    StencilState* pkStencilState = GetStencilState();
    unsigned int uiReference = pkStencilState->Reference;
    unsigned int uiMask = pkStencilState->Mask;
    unsigned int uiStencil = m_auiStencilBuffer[iIndex];
    bool bStencilPass;

    switch (pkStencilState->Compare)
    {
    case StencilState::CF_NEVER:
        bStencilPass = false;
        break;
    case StencilState::CF_LESS:
        bStencilPass = ((uiReference & uiMask) < (uiStencil & uiMask));
        break;
    case StencilState::CF_EQUAL:
        bStencilPass = ((uiReference & uiMask) == (uiStencil & uiMask));
        break;
    case StencilState::CF_LEQUAL:
        bStencilPass = ((uiReference & uiMask) <= (uiStencil & uiMask));
        break;
    case StencilState::CF_GREATER:
        bStencilPass = ((uiReference & uiMask) > (uiStencil & uiMask));
        break;
    case StencilState::CF_NOTEQUAL:
        bStencilPass = ((uiReference & uiMask) != (uiStencil & uiMask));
        break;
    case StencilState::CF_GEQUAL:
        bStencilPass = ((uiReference & uiMask) >= (uiStencil & uiMask));
        break;
    case StencilState::CF_ALWAYS:
        bStencilPass = true;
        break;
    default:
        assert(false);
        bStencilPass = false;
        break;
    }

    return bStencilPass;
}
//----------------------------------------------------------------------------
void SoftRenderer::ApplyStencilOperation (int iIndex,
    StencilState::OperationType eType)
{
    StencilState* pkStencilState = GetStencilState();
    unsigned int uiOldStencil = m_auiStencilBuffer[iIndex];
    unsigned int uiNewStencil;

    switch (eType)
    {
    case StencilState::OT_KEEP:
        uiNewStencil = uiOldStencil;
        break;
    case StencilState::OT_ZERO:
        uiNewStencil = 0;
        break;
    case StencilState::OT_REPLACE:
        uiNewStencil = pkStencilState->Reference;
        break;
    case StencilState::OT_INCREMENT:
        uiNewStencil = uiOldStencil;
        if (++uiNewStencil > m_uiMaxStencilValue)
        {
            uiNewStencil = m_uiMaxStencilValue;
        }
        break;
    case StencilState::OT_DECREMENT:
        uiNewStencil = uiOldStencil;
        if (uiNewStencil > 0)
        {
            uiNewStencil--;
        }
        break;
    case StencilState::OT_INVERT:
        uiNewStencil = ~uiOldStencil;
        break;
    default:
        assert(false);
        uiNewStencil = 0;
        break;
    }

    m_auiStencilBuffer[iIndex] =
        (uiOldStencil & ~pkStencilState->WriteMask) |
        (uiNewStencil & pkStencilState->WriteMask);
}
//----------------------------------------------------------------------------
bool SoftRenderer::ApplyZBufferCompare (int iIndex, unsigned int uiDepth)
{
    ZBufferState* pkZBufferState = GetZBufferState();
    unsigned int uiCurrentDepth = m_auiDepthBuffer[iIndex];
    bool bZPass;

    switch (pkZBufferState->Compare)
    {
    case ZBufferState::CF_NEVER:
        bZPass = false;
        break;
    case ZBufferState::CF_LESS:
        bZPass = (uiDepth < uiCurrentDepth);
        break;
    case ZBufferState::CF_EQUAL:
        bZPass = (uiDepth == uiCurrentDepth);
        break;
    case ZBufferState::CF_LEQUAL:
        bZPass = (uiDepth <= uiCurrentDepth);
        break;
    case ZBufferState::CF_GREATER:
        bZPass = (uiDepth > uiCurrentDepth);
        break;
    case ZBufferState::CF_NOTEQUAL:
        bZPass = (uiDepth != uiCurrentDepth);
        break;
    case ZBufferState::CF_GEQUAL:
        bZPass = (uiDepth >= uiCurrentDepth);
        break;
    case ZBufferState::CF_ALWAYS:
        bZPass = true;
        break;
    default:
        assert(false);
        bZPass = false;
        break;
    }

    return bZPass;
}
//----------------------------------------------------------------------------
ColorRGBA SoftRenderer::GetBlendedColor (const ColorRGBA& rkSrcColor,
    const ColorRGBA& rkDstColor)
{
    AlphaState* pkAlphaState = GetAlphaState();
    ColorRGBA kFinalColor;

    switch (pkAlphaState->SrcBlend)
    {
    case AlphaState::SBF_ZERO:
        // kFinalColor = 0.0f*rkSrcColor
        kFinalColor[0] = 0.0f;
        kFinalColor[1] = 0.0f;
        kFinalColor[2] = 0.0f;
        kFinalColor[3] = 0.0f;
        break;
    case AlphaState::SBF_ONE:
        // kFinalColor = 1.0f*rkSrcColor
        kFinalColor = rkSrcColor;
        break;
    case AlphaState::SBF_DST_COLOR:
        kFinalColor = rkDstColor*rkSrcColor;
        break;
    case AlphaState::SBF_ONE_MINUS_DST_COLOR:
        kFinalColor = (ColorRGBA::WHITE - rkDstColor)*rkSrcColor;
        break;
    case AlphaState::SBF_SRC_ALPHA:
        kFinalColor = rkSrcColor.A()*rkSrcColor;
        break;
    case AlphaState::SBF_ONE_MINUS_SRC_ALPHA:
        kFinalColor = (1.0f - rkSrcColor.A())*rkSrcColor;
        break;
    case AlphaState::SBF_DST_ALPHA:
        kFinalColor = rkDstColor.A()*rkSrcColor;
        break;
    case AlphaState::SBF_ONE_MINUS_DST_ALPHA:
        kFinalColor = (1.0f - rkDstColor.A())*rkSrcColor;
        break;
    case AlphaState::SBF_SRC_ALPHA_SATURATE:
    {
        float fMin = 1.0f - rkDstColor.A();
        if (rkSrcColor.A() < fMin)
        {
            fMin = rkSrcColor.A();
        }
        kFinalColor[0] = fMin*rkSrcColor[0];
        kFinalColor[1] = fMin*rkSrcColor[1];
        kFinalColor[2] = fMin*rkSrcColor[2];
        kFinalColor[3] = rkSrcColor[3];
        break;
    }
    case AlphaState::SBF_CONSTANT_COLOR:
        kFinalColor = pkAlphaState->ConstantColor*rkSrcColor;
        break;
    case AlphaState::SBF_ONE_MINUS_CONSTANT_COLOR:
        kFinalColor = (ColorRGBA::WHITE - pkAlphaState->ConstantColor) *
            rkSrcColor;
        break;
    case AlphaState::SBF_CONSTANT_ALPHA:
        kFinalColor = pkAlphaState->ConstantColor.A()*rkSrcColor;
        break;
    case AlphaState::SBF_ONE_MINUS_CONSTANT_ALPHA:
        kFinalColor = (1.0f - pkAlphaState->ConstantColor.A())*rkSrcColor;
        break;
    default:
        assert(false);
        break;
    }

    switch (pkAlphaState->DstBlend)
    {
    case AlphaState::DBF_ZERO:
        // kFinalColor += 0.0f*rkDstColor
        break;
    case AlphaState::DBF_ONE:
        // kFinalColor += 1.0f*rkDstColor
        kFinalColor += rkDstColor;
        break;
    case AlphaState::DBF_SRC_COLOR:
        kFinalColor += rkSrcColor*rkDstColor;
        break;
    case AlphaState::DBF_ONE_MINUS_SRC_COLOR:
        kFinalColor += (ColorRGBA::WHITE - rkSrcColor)*rkDstColor;
        break;
    case AlphaState::DBF_SRC_ALPHA:
        kFinalColor += rkSrcColor.A()*rkDstColor;
        break;
    case AlphaState::DBF_ONE_MINUS_SRC_ALPHA:
        kFinalColor += (1.0f - rkSrcColor.A())*rkDstColor;
        break;
    case AlphaState::DBF_DST_ALPHA:
        kFinalColor += rkDstColor.A()*rkDstColor;
        break;
    case AlphaState::DBF_ONE_MINUS_DST_ALPHA:
        kFinalColor += (1.0f - rkDstColor.A())*rkDstColor;
        break;
    case AlphaState::DBF_CONSTANT_COLOR:
        kFinalColor += pkAlphaState->ConstantColor*rkDstColor;
        break;
    case AlphaState::DBF_ONE_MINUS_CONSTANT_COLOR:
        kFinalColor += (ColorRGBA::WHITE - pkAlphaState->ConstantColor) *
            rkDstColor;
        break;
    case AlphaState::DBF_CONSTANT_ALPHA:
        kFinalColor += pkAlphaState->ConstantColor.A()*rkDstColor;
        break;
    case AlphaState::DBF_ONE_MINUS_CONSTANT_ALPHA:
        kFinalColor += (1.0f - pkAlphaState->ConstantColor.A())*rkDstColor;
        break;
    default:
        assert(false);
        break;
    }

    return kFinalColor;
}
//----------------------------------------------------------------------------
