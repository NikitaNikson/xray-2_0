// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int SoftRenderer::GetType () const
{
    return Renderer::SOFTWARE;
}
//----------------------------------------------------------------------------
inline const char* SoftRenderer::GetExtension () const
{
    return "sft";
}
//----------------------------------------------------------------------------
inline char SoftRenderer::GetCommentCharacter () const
{
    return '/';
}
//----------------------------------------------------------------------------
inline float* SoftRenderer::GetOutputVertex (int i)
{
    return &m_kOutputVertex.GetData()[m_iNumOutputChannels*i];
}
//----------------------------------------------------------------------------
