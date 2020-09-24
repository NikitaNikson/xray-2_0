#ifndef	common_samplers_h_included
#define	common_samplers_h_included

//////////////////////////////////////////////////////////////////////////////////////////
// Geometry phase / deferring               	//

sampler 	smp_nofilter;   //	Use D3DTADDRESS_CLAMP,	D3DTEXF_POINT,			D3DTEXF_NONE,	D3DTEXF_POINT 
sampler 	smp_rtlinear;	//	Use D3DTADDRESS_CLAMP,	D3DTEXF_LINEAR,			D3DTEXF_NONE,	D3DTEXF_LINEAR 
sampler 	smp_linear;		//	Use	D3DTADDRESS_WRAP,	D3DTEXF_LINEAR,			D3DTEXF_LINEAR,	D3DTEXF_LINEAR
sampler 	smp_base;		//	Use D3DTADDRESS_WRAP,	D3DTEXF_ANISOTROPIC, 	D3DTEXF_LINEAR,	D3DTEXF_ANISOTROPIC

Texture2D 	t_base;		//	smp_base
#ifdef USE_MSAA
Texture2DMS<float4, MSAA_SAMPLES>	s_generic;	//	smp_generic
#else
Texture2D   	t_generic;
#endif
Texture2D 	t_bump;             	//
Texture2D 	t_bumpX;                //
Texture2D 	t_detail;               //
Texture2D 	t_detailBump;           //	
Texture2D 	t_detailBumpX;          //	Error for bump detail
//Texture2D 	s_bumpD;                //
Texture2D 	t_hemi;             	//

Texture2D 	t_mask;             	//

Texture2D 	t_dt_r;                	//
Texture2D 	t_dt_g;                	//
Texture2D 	t_dt_b;                	//
Texture2D 	t_dt_a;                	//

Texture2D 	t_dn_r;                	//
Texture2D 	t_dn_g;                	//
Texture2D 	t_dn_b;                	//
Texture2D 	t_dn_a;                	//

//////////////////////////////////////////////////////////////////////////////////////////
// Lighting/shadowing phase                     //

sampler 	smp_material;

//uniform sampler2D       s_depth;                //
#ifdef USE_MSAA
Texture2DMS<float4, MSAA_SAMPLES>	t_position;	//	smp_nofilter or Load
Texture2DMS<float4, MSAA_SAMPLES>	t_normal;	//	smp_nofilter or Load
#else
Texture2D	t_position;	//	smp_nofilter or Load
Texture2D	t_normal;	//	smp_nofilter or Load
#endif
Texture2D	t_lmap;		// 2D/???cube projector lightmap
Texture3D	t_material;	//	smp_material
//uniform sampler1D       s_attenuate;        	//


//////////////////////////////////////////////////////////////////////////////////////////
// Combine phase                                //
#ifdef USE_MSAA
Texture2DMS<float4, MSAA_SAMPLES>	s_diffuse;	// rgb.a = diffuse.gloss
Texture2DMS<float4, MSAA_SAMPLES>	s_accumulator;      	// rgb.a = diffuse.specular
#else
Texture2D	t_diffuse;	// rgb.a = diffuse.gloss
Texture2D	t_accumulator;      	// rgb.a = diffuse.specular
#endif
//uniform sampler2D       s_generic;              //
Texture2D	t_bloom;	//
Texture2D	t_image;	// used in various post-processing
Texture2D	t_tonemap;	// actually MidleGray / exp(Lw + eps)


#endif	//	#ifndef	common_samplers_h_included