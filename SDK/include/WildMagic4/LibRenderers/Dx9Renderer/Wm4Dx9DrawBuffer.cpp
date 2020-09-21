// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4Dx9RendererPCH.h"
#include "Wm4Dx9Renderer.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void Dx9Renderer::Draw (const unsigned char* aucBuffer)
{
    if (!aucBuffer)
    {
        return;
    }

    IDirect3DSurface9* pkBackBuffer = 0;
    ms_hResult = m_pqDevice->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,
        &pkBackBuffer);
    assert( pkBackBuffer );
    assert(SUCCEEDED(ms_hResult));
    if (FAILED(ms_hResult) || !pkBackBuffer)
    {
        return;
    }

    RECT kSrcRect = { 0, 0, m_iWidth-1, m_iHeight-1 };
    ms_hResult = D3DXLoadSurfaceFromMemory(pkBackBuffer,0,0,aucBuffer,
        D3DFMT_R8G8B8,3*m_iWidth,0,&kSrcRect,D3DX_FILTER_NONE,0);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
