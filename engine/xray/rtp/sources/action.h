////////////////////////////////////////////////////////////////////////////
//	Created		: 03.11.2009
//	Author		: Konstantin Slipchenko
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include "iaction.h"


#include <xray/configs.h>

namespace xray {

namespace configs{
	class lua_config_value;
} // namespace configs

namespace rtp {


template<class action>
struct global_actions_params
{
	typedef	typename action::world_space_param_type  world_space_param_type;

	global_actions_params( const world_space_param_type &p ): m_current_position( p ){}

	world_space_param_type m_current_position;
	
	inline world_space_param_type& current_position() { return m_current_position; }

};

template< class action >
class action_base;

template< class space_params, class world_space_params, class action >
class abstract_action:
	public iaction<space_params>,
	private boost::noncopyable
{

public:
	typedef space_params							space_param_type;
	typedef world_space_params						world_space_param_type;
	typedef action									action_type;
	typedef global_actions_params< action_type >	global_actions_params_type;

public:
						abstract_action		( action_base<action_type> &ab );

public:
	virtual						float	reward							( const action_type& a )const=0;
	virtual						float	reward							( const space_params& a )const=0;

	virtual						void	run								( space_params& a, const action_type& from, u32 from_sample, u32 blend_sample )const=0;
	virtual						float	run								( world_space_param_type& w, const space_params& l, const action_type& from, u32 from_sample, u32 blend_sample, u32 step, float time )const=0;

///	virtual						void	render							( const world_space_param_type& a,  xray::render::debug::renderer& renderer ) const = 0;
	virtual						u32		num_blend_samples				( )const=0;
	virtual						bool	taget							( const space_params& a )const=0;
	virtual						bool	is_taget_action					( )const =0;


	virtual						bool	remove_out_of_area_trajectory	( )const { return true; }

public:
	virtual						void	save							( xray::configs::lua_config_value cfg ) const;
	virtual						void	load							( const xray::configs::lua_config_value &cfg );

	virtual						void	construct						( ) {};

	inline						u32		id								( )const{ return m_id; }
								bool	is_my_base						(  const action_base<action_type> &ab )const	;			


	virtual						pcstr	name							( )const{ return "action"; }


public:
	inline action_base<action_type>	&get_action_base					( ){ return m_action_base; }
	inline action_base<action_type>	&get_action_base					( )const{ return m_action_base; }

private:
	u32							m_id;
	xray::rtp::action_base<action_type>	&m_action_base;

}; // class action

} // namespace rtp
} // namespace xray

#include "action_inline.h"

#endif // #ifndef ACTION_H_INCLUDED