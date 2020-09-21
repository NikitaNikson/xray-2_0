////////////////////////////////////////////////////////////////////////////
//	Created		: 15.04.2009
//	Author		: Mykhailo Parfeniuk
//	Copyright ( C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
//#include "dx9_world.h"
#include <xray/render/engine/stage_skybox.h>
#include <xray/render/engine/environment.h>
#include <xray/render/core/effect_descriptor.h>
#include <xray/render/core/effect_compiler.h>
#include <xray/render/core/effect_manager.h>
#include <xray/render/core/resource_manager.h>
#include <xray/render/core/backend.h>

namespace xray {
namespace render_dx10 {

class effect_skybox : public effect
{
public:
	virtual void compile( effect_compiler& compiler, const effect_compilation_options& options)
	{
		XRAY_UNREFERENCED_PARAMETER	( options);
		shader_defines_list	defines;
		make_defines( defines);

		compiler.begin_technique( /*sky box*/)
			.begin_pass( "sky2", "sky2", defines)
				.set_depth( false, false)
				.set_stencil( false)
				.def_sampler ( "s_sky0", D3D_TEXTURE_ADDRESS_CLAMP, D3D_FILTER_MIN_MAG_LINEAR_MIP_POINT)
				.def_sampler ( "s_sky1", D3D_TEXTURE_ADDRESS_CLAMP, D3D_FILTER_MIN_MAG_LINEAR_MIP_POINT)
				.set_texture ( "t_sky0", "sky/sky_9_cube")
				.set_texture ( "t_sky1", "sky/sky_19_cube")
				//.def_sampler_rtf( "s_tonemap", "$user$tonemap")
			.end_pass()
		.end_technique();
	}
};

#pragma pack( push,1)
struct v_skybox				{
	float3	p;
	u32			color;
	float3	uv	[2];

	void		set			( const float3& _p, u32 _c, const float3& _tc)
	{
		p					= _p;
		color				= _c;
		uv[0]				= _tc;
		uv[1]				= _tc;
	}
};

//const	u32 v_skybox_fvf	= D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX2 | D3DFVF_TEXCOORDSIZE3( 0) | D3DFVF_TEXCOORDSIZE3( 1);
const D3D_INPUT_ELEMENT_DESC v_skybox_fvf[] = 
{
	{"POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT,		0, 0,	D3D_INPUT_PER_VERTEX_DATA, 0},
	{"COLOR",		0, DXGI_FORMAT_R8G8B8A8_UNORM,		0, 12, 	D3D_INPUT_PER_VERTEX_DATA, 0},
	{"TEXCOORD",	0, DXGI_FORMAT_R32G32B32_FLOAT,		0, 16, 	D3D_INPUT_PER_VERTEX_DATA, 0},
	{"TEXCOORD",	1, DXGI_FORMAT_R32G32B32_FLOAT,		0, 28, 	D3D_INPUT_PER_VERTEX_DATA, 0}
};

struct v_clouds				{
	float3	p;
	u32			color;
	u32			intensity;
	void		set			( const float3& _p, u32 _c, u32 _i)
	{
		p					= _p;
		color				= _c;
		intensity			= _i;
	}
};
//const	u32 v_clouds_fvf	= D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR;
#pragma pack( pop)

stage_skybox::stage_skybox( scene_context* context): stage( context)
{
	effect_skybox	b_skybox;

	m_sh_sky = effect_manager::ref().create_effect( &b_skybox, "skybox_2t");
	m_g_skybox = resource_manager::ref().create_geometry( v_skybox_fvf, sizeof(v_skybox), backend::ref().vertex.buffer(), backend::ref().index.buffer());
}

stage_skybox::~stage_skybox()
{
}

//////////////////////////////////////////////////////////////////////////
// half box def
static	float	hbox_verts[24][3]	=
{
	{-1.f,	-1.f,	-1.f}, {-1.f,	-1.01f,	-1.f},	// down
	{ 1.f,	-1.f,	-1.f}, { 1.f,	-1.01f,	-1.f},	// down
	{-1.f,	-1.f,	 1.f}, {-1.f,	-1.01f,	 1.f},	// down
	{ 1.f,	-1.f,	 1.f}, { 1.f,	-1.01f,	 1.f},	// down
	{-1.f,	 1.f,	-1.f}, {-1.f,	 1.f,	-1.f},
	{ 1.f,	 1.f,	-1.f}, { 1.f,	 1.f,	-1.f},
	{-1.f,	 1.f,	 1.f}, {-1.f,	 1.f,	 1.f},
	{ 1.f,	 1.f,	 1.f}, { 1.f,	 1.f,	 1.f},
	{-1.f,	 0.f,	-1.f}, {-1.f,	-1.f,	-1.f},	// half
	{ 1.f,	 0.f,	-1.f}, { 1.f,	-1.f,	-1.f},	// half
	{ 1.f,	 0.f,	 1.f}, { 1.f,	-1.f,	 1.f},	// half
	{-1.f,	 0.f,	 1.f}, {-1.f,	-1.f,	 1.f}	// half
};
static	u16			hbox_faces[20*3]	=
{
	0,	 2,	 3,
	3,	 1,	 0,
	4,	 5,	 7,
	7,	 6,	 4,
	0,	 1,	 9,
	9,	 8,	 0,
	8,	 9,	 5,
	5,	 4,	 8,
	1,	 3,	10,
	10,	 9,	 1,
	9,	10,	 7,
	7,	 5,	 9,
	3,	 2,	11,
	11,	10,	 3,
	10,	11,	 6,
	6,	 7,	10,
	2,	 0,	 8,
	8,	11,	 2,
	11,	 8,	 4,
	4,	 6,	11
};

void stage_skybox::execute()
{
	PIX_EVENT( stage_skybox);

	backend::ref().set_render_targets( &*m_context->m_rt_generic_0, &*m_context->m_rt_generic_1, 0);
	backend::ref().reset_depth_stencil_target();

	render_sky();
	//	Render clouds before combine without Z-test
	//	to avoid siluets. However, it's a bit slower process.
	render_clouds();
}

void stage_skybox::render_sky()
{
	// clouds_sh.create		( "clouds","null");
	//. this is the bug-fix for the case when the sky is broken
	//. for some unknown reason the geoms happen to be invalid sometimes
	//. if vTune show this in profile, please add simple cache ( move-to-forward last found) 
	//. to the following functions:
	//.		CResourceManager::_CreateDecl
	//.		CResourceManager::CreateGeom

	//if( env.bNeed_re_create_env)
	//{
	//	sh_2sky.create			( &m_b_skybox,"skybox_2t");
	//	sh_2geom.create			( v_skybox_fvf,RCache.Vertex.Buffer(), RCache.Index.Buffer());
	//	clouds_sh.create		( "clouds","null");
	//	clouds_geom.create		( v_clouds_fvf,RCache.Vertex.Buffer(), RCache.Index.Buffer());
	//	env.bNeed_re_create_env		= FALSE;
	//}
	rm_far();

	//dxEnvDescriptorMixerRender &mixRen = *( dxEnvDescriptorMixerRender*)&*env.CurrentEnv->m_pDescriptorMixer;

	// draw sky box
	float4x4	mat_sky;
	mat_sky = math::create_rotation_y/*rotateY*/( /*env.CurrentEnv->sky_rotation*/0);
	mat_sky = math::mul4x3( math::create_translation/*translate_over*/( m_context->get_view_pos()), mat_sky);

	u32	i_offset, v_offset;
	u32	C = utils::color_rgba( 226, 226, 226, 215/*iFloor( env.CurrentEnv->sky_color.x*255.f), iFloor( env.CurrentEnv->sky_color.y*255.f), iFloor( env.CurrentEnv->sky_color.z*255.f), iFloor( env.CurrentEnv->weight*255.f)*/);

	// Fill index buffer
	u16*	pib	= backend::ref().index.lock( 20*3, i_offset);
	CopyMemory( pib, hbox_faces, 20*3*sizeof(u16));
	backend::ref().index.unlock();

	// Fill vertex buffer
	v_skybox* pv = ( v_skybox*)backend::ref().vertex.lock( 12, sizeof(v_skybox)/*m_g_skybox->get_stride()*/, v_offset);
	for ( u32 v=0; v<12; v++)
		pv[v].set( float3( hbox_verts[v*2][0], hbox_verts[v*2][1], hbox_verts[v*2][2]), C, float3( hbox_verts[v*2+1][0], hbox_verts[v*2+1][1], hbox_verts[v*2+1][2]));
	backend::ref().vertex.unlock();

	// Render
	m_context->set_w( mat_sky);

	m_g_skybox->apply();
	m_sh_sky->apply();

	backend::ref().render_indexed( D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, 20*3, i_offset, v_offset);

	// Sun
	rm_normal();

	m_context->set_w_identity();
}

void stage_skybox::render_clouds()
{
	//::Render->rmFar				();

	//float4x4						mXFORM, mScale;
	//mScale.scale				( 10,0.4f,10);
	//mXFORM.rotateY				( env.CurrentEnv->sky_rotation);
	//mXFORM.mulB_43				( mScale);
	//mXFORM.translate_over		( Device.vCameraPosition);

	//Fvector wd0,wd1;
	//float4 wind_dir;
	//wd0.setHP					( PI_DIV_4,0);
	//wd1.setHP					( PI_DIV_4+PI_DIV_8,0);
	//wind_dir.set				( wd0.x,wd0.z,wd1.x,wd1.z).mul( 0.5f).add( 0.5f).mul( 255.f);
	//u32		i_offset,v_offset;
	//u32		C0					= utils::color_rgba( iFloor( wind_dir.x),iFloor( wind_dir.y),iFloor( wind_dir.w),iFloor( wind_dir.z));
	//u32		C1					= utils::color_rgba( iFloor( env.CurrentEnv->clouds_color.x*255.f),iFloor( env.CurrentEnv->clouds_color.y*255.f),iFloor( env.CurrentEnv->clouds_color.z*255.f),iFloor( env.CurrentEnv->clouds_color.w*255.f));

	//// Fill index buffer
	//u16*	pib					= RCache.Index.Lock	( env.CloudsIndices.size(),i_offset);
	//CopyMemory					( pib,&env.CloudsIndices.front(),env.CloudsIndices.size()*sizeof( u16));
	//RCache.Index.Unlock			( env.CloudsIndices.size());

	//// Fill vertex buffer
	//v_clouds* pv				= ( v_clouds*)	RCache.Vertex.Lock	( env.CloudsVerts.size(),clouds_geom.stride(),v_offset);
	//for ( FvectorIt it=env.CloudsVerts.begin(); it!=env.CloudsVerts.end(); it++,pv++)
	//	pv->set					( *it,C0,C1);
	//RCache.Vertex.Unlock		( env.CloudsVerts.size(),clouds_geom.stride());

	//// Render
	//RCache.set_xform_world		( mXFORM);
	//RCache.set_Geometry			( clouds_geom);
	//RCache.set_Shader			( clouds_sh);
	//dxEnvDescriptorMixerRender	&mixRen = *( dxEnvDescriptorMixerRender*)&*env.CurrentEnv->m_pDescriptorMixer;
	//RCache.set_Textures			( &mixRen.clouds_r_textures);
	//RCache.Render				( D3DPT_TRIANGLELIST,v_offset,0,env.CloudsVerts.size(),i_offset,env.CloudsIndices.size()/3);

	//::Render->rmNormal			();
}


} // namespace render
} // namespace xray

