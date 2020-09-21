// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int Renderer::GetMaxLights ()
{
    return ms_iMaxLights;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxColors ()
{
    return ms_iMaxColors;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxTCoords ()
{
    return ms_iMaxTCoords;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxVShaderImages ()
{
    return ms_iMaxVShaderImages;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxPShaderImages ()
{
    return ms_iMaxPShaderImages;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxStencilIndices ()
{
    return ms_iMaxStencilIndices;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxUserClipPlanes ()
{
    return ms_iMaxUserClipPlanes;
}
//----------------------------------------------------------------------------
inline float Renderer::GetMaxAnisotropy ()
{
    return ms_fMaxAnisotropy;
}
//----------------------------------------------------------------------------
inline bool Renderer::IsActive () const
{
    // stub for derived classes
    return true;
}
//----------------------------------------------------------------------------
inline Camera* Renderer::GetCamera () const
{
    return m_pkCamera;
}
//----------------------------------------------------------------------------
inline void Renderer::SetGeometry (Geometry* pkGeometry)
{
    m_pkGeometry = pkGeometry;
}
//----------------------------------------------------------------------------
inline Geometry* Renderer::GetGeometry () const
{
    return m_pkGeometry;
}
//----------------------------------------------------------------------------
inline FrameBuffer::FormatType Renderer::GetFormatType () const
{
    return m_eFormat;
}
//----------------------------------------------------------------------------
inline FrameBuffer::DepthType Renderer::GetDepthType () const
{
    return m_eDepth;
}
//----------------------------------------------------------------------------
inline FrameBuffer::StencilType Renderer::GetStencilType () const
{
    return m_eStencil;
}
//----------------------------------------------------------------------------
inline FrameBuffer::BufferingType Renderer::GetBufferingType () const
{
    return m_eBuffering;
}
//----------------------------------------------------------------------------
inline FrameBuffer::MultisamplingType Renderer::GetMultisamplingType () const
{
    return m_eMultisampling;
}
//----------------------------------------------------------------------------
inline int Renderer::GetWidth () const
{
    return m_iWidth;
}
//----------------------------------------------------------------------------
inline int Renderer::GetHeight () const
{
    return m_iHeight;
}
//----------------------------------------------------------------------------
inline void Renderer::ToggleFullscreen ()
{
    m_bFullscreen = !m_bFullscreen;
}
//----------------------------------------------------------------------------
inline void Renderer::SetClearColor (const ColorRGBA& rkClearColor)
{
    m_kClearColor = rkClearColor;
}
//----------------------------------------------------------------------------
inline const ColorRGBA& Renderer::GetClearColor () const
{
    return m_kClearColor;
}
//----------------------------------------------------------------------------
inline void Renderer::SetClearDepth (float fClearDepth)
{
    m_fClearDepth = fClearDepth;
}
//----------------------------------------------------------------------------
inline float Renderer::GetClearDepth () const
{
    return m_fClearDepth;
}
//----------------------------------------------------------------------------
inline void Renderer::SetClearStencil (unsigned int uiClearStencil)
{
    m_uiClearStencil = uiClearStencil;
}
//----------------------------------------------------------------------------
inline unsigned int Renderer::GetClearStencil () const
{
    return m_uiClearStencil;
}
//----------------------------------------------------------------------------
inline bool Renderer::BeginScene ()
{
    // stub for derived classes
    return true;
}
//----------------------------------------------------------------------------
inline void Renderer::EndScene ()
{
    // stub for derived classes
}
//----------------------------------------------------------------------------
inline void Renderer::SetPointSize (float fSize)
{
    if (fSize > 0.0f)
    {
        m_fPointSize = fSize;
    }
}
//----------------------------------------------------------------------------
inline float Renderer::GetPointSize () const
{
    return m_fPointSize;
}
//----------------------------------------------------------------------------
inline void Renderer::SetLineWidth (float fWidth)
{
    if (fWidth > 0.0f)
    {
        m_fLineWidth = fWidth;
    }
}
//----------------------------------------------------------------------------
inline float Renderer::GetLineWidth () const
{
    return m_fLineWidth;
}
//----------------------------------------------------------------------------
inline void Renderer::SetLineStipple (int iRepeat, unsigned short usPattern)
{
    if (iRepeat < 0)
    {
        iRepeat = 0;
    }
    m_iLineStippleRepeat = iRepeat;
    m_usLineStipplePattern = usPattern;
}
//----------------------------------------------------------------------------
inline int Renderer::GetLineStippleRepeat () const
{
    return m_iLineStippleRepeat;
}
//----------------------------------------------------------------------------
inline unsigned short Renderer::GetLineStipplePattern () const
{
    return m_usLineStipplePattern;
}
//----------------------------------------------------------------------------
inline void Renderer::SetAlphaState (AlphaState* pkState)
{
    m_aspkState[GlobalState::ALPHA] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetCullState (CullState* pkState)
{
    m_aspkState[GlobalState::CULL] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetMaterialState (MaterialState* pkState)
{
    m_aspkState[GlobalState::MATERIAL] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetPolygonOffsetState (PolygonOffsetState* pkState)
{
    m_aspkState[GlobalState::POLYGONOFFSET] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetStencilState (StencilState* pkState)
{
    m_aspkState[GlobalState::STENCIL] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetWireframeState (WireframeState* pkState)
{
    m_aspkState[GlobalState::WIREFRAME] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetZBufferState (ZBufferState* pkState)
{
    m_aspkState[GlobalState::ZBUFFER] = pkState;
}
//----------------------------------------------------------------------------
inline AlphaState* Renderer::GetAlphaState ()
{
    return StaticCast<AlphaState>(m_aspkState[GlobalState::ALPHA]);
}
//----------------------------------------------------------------------------
inline CullState* Renderer::GetCullState ()
{
    return StaticCast<CullState>(m_aspkState[GlobalState::CULL]);
}
//----------------------------------------------------------------------------
inline MaterialState* Renderer::GetMaterialState ()
{
    return StaticCast<MaterialState>(m_aspkState[GlobalState::MATERIAL]);
}
//----------------------------------------------------------------------------
inline PolygonOffsetState* Renderer::GetPolygonOffsetState ()
{
    return StaticCast<PolygonOffsetState>(
        m_aspkState[GlobalState::POLYGONOFFSET]);
}
//----------------------------------------------------------------------------
inline StencilState* Renderer::GetStencilState ()
{
    return StaticCast<StencilState>(m_aspkState[GlobalState::STENCIL]);
}
//----------------------------------------------------------------------------
inline WireframeState* Renderer::GetWireframeState ()
{
    return StaticCast<WireframeState>(m_aspkState[GlobalState::WIREFRAME]);
}
//----------------------------------------------------------------------------
inline ZBufferState* Renderer::GetZBufferState ()
{
    return StaticCast<ZBufferState>(m_aspkState[GlobalState::ZBUFFER]);
}
//----------------------------------------------------------------------------
inline void Renderer::SetReverseCullFace (bool bReverseCullFace)
{
    m_bReverseCullFace = bReverseCullFace;
}
//----------------------------------------------------------------------------
inline bool Renderer::GetReverseCullFace () const
{
    return m_bReverseCullFace;
}
//----------------------------------------------------------------------------
inline void Renderer::SetLight (int i, Light* pkLight)
{
    assert(0 <= i && i < ms_iMaxLights);
    m_aspkLight[i] = (Object*)pkLight;
}
//----------------------------------------------------------------------------
inline Light* Renderer::GetLight (int i)
{
    assert(0 <= i && i < ms_iMaxLights);
    return StaticCast<Light>(m_aspkLight[i]);
}
//----------------------------------------------------------------------------
inline void Renderer::SetProjector (Camera* pkProjector)
{
    m_pkProjector = pkProjector;
}
//----------------------------------------------------------------------------
inline Camera* Renderer::GetProjector ()
{
    return m_pkProjector;
}
//----------------------------------------------------------------------------
inline const Matrix4f& Renderer::GetWorldMatrix () const
{
    return m_kWorldMatrix;
}
//----------------------------------------------------------------------------
inline const Matrix4f& Renderer::GetViewMatrix () const
{
    return m_kViewMatrix;
}
//----------------------------------------------------------------------------
inline const Matrix4f& Renderer::GetProjectionMatrix () const
{
    return m_kProjectionMatrix;
}
//----------------------------------------------------------------------------
