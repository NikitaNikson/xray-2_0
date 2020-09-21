////////////////////////////////////////////////////////////////////////////
//	Created		: 16.02.2009
//	Author		: Mykhailo Parfeniuk
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED

#include <xray/render/core/res_constant_table.h>
//#include "constant_cache.h>
#include <xray/render/core/res_constant_buffer.h>
#include <xray/render/core/vertex_stream.h>
#include <xray/render/core/index_stream.h>
#include <xray/render/core/sampler_slot.h>
#include <xray/render/core/res_xs.h>

#include <xray/render/core/res_vs_hw.h>
#include <xray/render/core/res_gs_hw.h>
#include <xray/render/core/res_ps_hw.h>

#include <xray/render/core/res_declaration.h>
#include <xray/render/core/res_input_layout.h>
#include <xray/render/core/res_rt.h>

#include <xray/render/core/backend_handlers.h>

//#include <xray/render/core/sorted_vector.h>

namespace xray {
namespace render_dx10 {


enum enum_render_target_enum
{
	enum_target_rt0 = 0,
	enum_target_rt1,
	enum_target_rt2,
	//enum_target_rt3,
	enum_target_count,
	enum_target_zb // Used only in bit set. Use special function set_depth_stencil_target() to set depth stencil target;
};

class backend : public quasi_singleton<backend>
{
public:

	backend( ID3DDevice* device);
	~backend();

	inline	void reset();
	inline	void flush();

	inline	void set_rasterizer_state		( ID3DRasterizerState * ras_state);
	inline	void set_septh_stencil_state	( ID3DDepthStencilState * ds_State);
	inline	void set_stencil_ref			( u32 stencil_ref);

	inline	void set_blend_state			( ID3DBlendState * bl_State);
	inline	void set_sample_mask			( u32 sample_mask);

			// This may need to be moved to resource_manager 
			// Find way to make "res_sampler_state *" const.
			void				register_sampler		( char const * name, res_sampler_state * sampler);
			res_sampler_state *	find_registered_sampler	( char const * name);

			constant_host *			register_constant_host	( constant const& constant);
			constant_host *			register_constant_host	( shared_string name);
			constant_host const *	find_constant_host		( shared_string name, bool create_if_not = true);

	inline 	void set_vb		( res_buffer * vb, u32 vb_stride, u32 offset = 0 /*in bytes*/);
	inline 	void set_ib		( res_buffer * ib, u32 offset = 0/*in bytes*/);

 	inline 	void set_vs		( res_vs_hw * vs);
	inline 	void set_ps		( res_ps_hw * ps);

	inline	void set_declaration( res_declaration * decl);
	inline	void set_input_layout( res_input_layout * layout);

	inline void set_vs_constants( res_constant_table * ctable);
	inline void set_gs_constants( res_constant_table * ctable);
	inline void set_ps_constants( res_constant_table * ctable);

	inline void set_vs_textures	( res_texture_list * textures);
	inline void set_gs_textures	( res_texture_list * textures);
	inline void set_ps_textures	( res_texture_list * textures);

	inline void set_vs_samplers	( res_sampler_list * samplers);
	inline void set_gs_samplers	( res_sampler_list * samplers);
	inline void set_ps_samplers	( res_sampler_list * samplers);
	
	inline void set_constant( constant_host const * c, float				value);
	inline void set_constant( constant_host const * c, math::float2			value);
	inline void set_constant( constant_host const * c, math::float3			value);
	inline void set_constant( constant_host const * c, math::float4	const&	value);
	inline void set_constant( constant_host const * c, float4x4b const&		value);
	inline void set_constant( constant_host const * c, int	value);
	inline void set_constant( constant_host const * c, math::int2	value);

// 	template <typename T>
// 	void set_constant( shared_string name, const T& arg);

	template <typename T>
	void set_ca( shared_string name, u32 index, const T& arg);

	inline void get_viewport ( D3D_VIEWPORT & viewport);
	inline void set_viewport ( D3D_VIEWPORT const & viewports);
	inline void get_viewports ( u32 & count/*in/out*/, D3D_VIEWPORT * viewports);
	inline void set_viewports ( u32 count, D3D_VIEWPORT const * viewports);

// 	void set_constant( constant_host const * c, float x, float y, float z, float w);
// 	void set_ca( constant_host const * c, u32 index, float x, float y, float z, float w);
// 	void set_constant( shared_string name, float x, float y, float z, float w);
// 	void set_ca( shared_string name, u32 index, float x, float y, float z, float w);

	inline	void set_render_target			( enum_render_target_enum slot, res_rt const * rt);
	inline	void set_render_targets			( res_rt const * rt0, res_rt const * rt1, res_rt const * rt2);

	inline	void set_depth_stencil_target	( res_rt const * zrt);

	// Reset to base targets
	inline	void reset_render_targets		( bool only_the_base = false);
	inline	void reset_depth_stencil_target	();

	inline void clear_render_targets		( math::color color);
	inline void clear_depth_stencil			( u32 flags, float z_value, u8 stencil_value);

	//inline void clear( u32 flags, u32 color, float z_value, u8 stencil_value);

	inline void	render_indexed( D3D_PRIMITIVE_TOPOLOGY type, u32 index_count, u32 start_index, u32 base_vertex);
	inline void	render( D3D_PRIMITIVE_TOPOLOGY type, u32 vertex_count, u32 base_vertex);
// 	inline void	render( D3D_PRIMITIVE_TOPOLOGY type, u32 base_vertex, u32 start_vertex, u32 vertex_count, u32 start_index, u32 prim_count);
// 	inline void	render( D3D_PRIMITIVE_TOPOLOGY type, u32 start_vertex, u32 prim_count);

	void on_device_create( ID3DDevice* device);
	void on_device_destroy();

	void reset_constant_update_markers	();
	u32	constant_update_counter			() { return m_constant_update_counter;}

	template<enum_shader_type shader_type>
	inline u32 get_constants_marker		();

public:
	vertex_stream	vertex;
	index_stream	index;

private:
	inline void flush_rt();

	inline void update_input_layout();

	// deprecated 
	void flush_c_cache();
	inline void flush_stages();

	template <typename T>
	void set_c_impl( constant_host const * c, const T& arg);

	template <typename T>
	void set_ca_impl( constant_host const * c, u32 index, const T& arg);

private:

	ID3DDevice*	m_device;

	ID3DRasterizerState*		m_rasterizer_state;
	ID3DDepthStencilState*		m_depth_stencils_state;
	ID3DBlendState*				m_effect_state;
	u32							m_stencil_ref;
	u32							m_sample_mask;

	struct render_dirty_objects
	{
		render_dirty_objects	()	{ reset();}
		inline void reset		()	{ ZeroMemory(this, sizeof(render_dirty_objects));}

//		ifs may be grouped by this test
// 		inline bool any_state	()	{ return rasterizer_state|depth_stencil_state|effect_state;}
// 		inline bool any_vs		()	{ return rasterizer_state|depth_stencil_state|effect_state;}

		bool vertex_buffer;
		bool index_buffer;
		bool input_declaration;
		bool input_layout;

		bool rasterizer_state;
		bool depth_stencil_state;
		bool effect_state;

		bool vertex_shader;
		bool vertex_constants;
		bool vertex_textures;
		bool vertex_samplers;

// 		bool geometry_shader;
// 		bool geometry_constants;
// 		bool geometry_textures;
// 		bool geometry_samplers;

		bool pixel_shader;
		bool pixel_constants;
		bool pixel_textures;
		bool pixel_samplers;

		bool bstat; // ???
	}								m_dirty_objects;	

	struct render_dirty_targets
	{
		render_dirty_targets	()	{ reset();}
		inline void reset		()	{ ZeroMemory(this, sizeof(render_dirty_targets));}
		inline bool any			()	{ COMPILE_ASSERT( enum_target_rt2 == enum_target_count-1, Add_the_list_above_too );
										return depth_stencil 
										|render_targets[enum_target_rt0]
										|render_targets[enum_target_rt1]
										|render_targets[enum_target_rt2];}


		bool render_targets[enum_target_count];
		bool depth_stencil;
	}								m_dirty_targets;

	// TODO
	// Needed members initialization in constructor!
	// maybe ref need to be changed to simple *
	res_buffer*						m_vb;
	res_buffer*						m_ib;
	res_vs_hw*						m_vs;
	res_ps_hw*						m_ps;
	res_gs_hw*						m_gs;

	constants_handler<enum_shader_type_vertex>			m_vs_constants_handler;
	textures_handler<enum_shader_type_vertex>			m_vs_textures_handler;
	samplers_handler<enum_shader_type_vertex>			m_vs_samplers_handler;

	constants_handler<enum_shader_type_geometry>		m_gs_constants_handler;
	textures_handler<enum_shader_type_geometry>			m_gs_textures_handler;
	samplers_handler<enum_shader_type_geometry>			m_gs_samplers_handler;

	constants_handler<enum_shader_type_pixel>			m_ps_constants_handler;
	textures_handler<enum_shader_type_pixel>			m_ps_textures_handler;
	samplers_handler<enum_shader_type_pixel>			m_ps_samplers_handler;

	typedef render::vector<constant_host*>	constant_hosts;
	constant_hosts					m_constant_hosts;

	res_declaration*				m_decl;
	res_input_layout*				m_input_layout;

	ID3DRenderTargetView*			m_targets[enum_target_count];
	ID3DDepthStencilView*			m_zb;

	ID3DRenderTargetView*			m_base_rt;
	ID3DDepthStencilView*			m_base_zb;

	u32	m_vb_stride;
	u32	m_vb_offset;
	u32	m_ib_offset;


// 	/*XRAY_ALIGN( 16)*/ ref_constant_buffer	m_constant_buffer_pixel;
// 	/*XRAY_ALIGN( 16)*/ ref_constant_buffer	m_constant_buffer_vertex;

	enum {texture_stage_count = 16};

	typedef std::pair< name_string, res_sampler_state *>		samplers_registry_record;
	typedef render::vector<samplers_registry_record>			samplers_registry;
	samplers_registry											m_samplers_registry;

	ID3DTexture2D*												m_stages [texture_stage_count];

	u32								m_constant_update_counter;

	u32								m_constant_update_markers[enum_shader_types_count];

}; // class backend

} // namespace render 
} // namespace xray 


#include <xray/render/core/backend_inline.h>

#endif // #ifndef BACKEND_H_INCLUDED