////////////////////////////////////////////////////////////////////////////
//	Created		: 04.02.2009
//	Author		: Igor Lobanchikov
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef D3D_DEFS_H_INCLUDED
#define D3D_DEFS_H_INCLUDED

namespace xray {
namespace render {


typedef	IDirect3DVertexShader9	ID3DVertexShader;
typedef	IDirect3DPixelShader9	ID3DPixelShader;
typedef	ID3DXBuffer				ID3DBlob;
typedef	D3DXMACRO				D3D_SHADER_MACRO;
typedef	IDirect3DQuery9			ID3DQuery;
typedef	D3DVIEWPORT9			D3D_VIEWPORT;
typedef	ID3DXInclude			ID3DInclude;
typedef	IDirect3DTexture9		ID3DTexture2D;
typedef	IDirect3DSurface9		ID3DRenderTargetView;
typedef	IDirect3DSurface9		ID3DDepthStencilView;
typedef	IDirect3DBaseTexture9	ID3DBaseTexture;
typedef	D3DSURFACE_DESC			D3D_TEXTURE2D_DESC;
typedef IDirect3DVertexBuffer9	ID3DVertexBuffer;
typedef IDirect3DIndexBuffer9	ID3DIndexBuffer;
typedef	IDirect3DVolumeTexture9	ID3DTexture3D;
typedef	IDirect3DStateBlock9	ID3DState;
typedef	IDirect3DDevice9		ID3DDevice;
typedef IDirect3DSurface9		ID3DSurface;
typedef IDirect3DBaseTexture9	ID3DTexture;

#define DX10_ONLY(expr)			do {} while (0)

} // namespace render 
} // namespace xray 


#endif // #ifndef D3D_DEFS_H_INCLUDED
