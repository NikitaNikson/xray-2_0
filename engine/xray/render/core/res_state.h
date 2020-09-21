////////////////////////////////////////////////////////////////////////////
//	Created		: 29.03.2010
//	Author		: Armen Abroyan
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#ifndef RES_STATE_H_INCLUDED
#define RES_STATE_H_INCLUDED

#include "res_common.h"

namespace xray {
namespace render_dx10 {


class res_state :
	public res_flagged,
	public res_id,
	public boost::noncopyable
{
	friend class resource_manager;

protected:
	// Only state_generator will be able create state instances.
	res_state(	ID3DRasterizerState*		rasterizer_state, 
					ID3DDepthStencilState*		depth_stencil_state, 
					ID3DBlendState*				blend_state, 
					u32							stencil_ref);	

public:
	~res_state	();
	void _free	() const;

	// ?
	void	apply() const;
	u32		stencil_ref			( ) { return m_stencil_ref; }

private:

	//	All states are supposed to live along all application lifetime
	ID3DRasterizerState		*	m_rasterizer_state;		//	Weak link
	ID3DDepthStencilState	*	m_depth_stencil_state;	//	Weak link
	ID3DBlendState			*	m_blend_state;			//	Weak link

// 	D3D_RASTERIZER_DESC		m_rasterizer_desc;
// 	D3D_DEPTH_STENCIL_DESC	m_depth_stencil_desc;
// 	D3D_BLEND_DESC			m_effect_desc;

	u32						m_stencil_ref;

};

typedef xray::intrusive_ptr<res_state, res_base, threading::single_threading_policy>	ref_state;

} // namespace render
} // namespace xray

#endif // #ifndef RES_STATE_H_INCLUDED