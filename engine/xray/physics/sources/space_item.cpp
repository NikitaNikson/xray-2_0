////////////////////////////////////////////////////////////////////////////
//	Created 	: 30.01.2008
//	Author		: Konstantin Slipchenko
//	Description : space_item
////////////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "space_item.h"
#include <xray/collision/space_partitioning_tree.h>
#include "space_object.h"
#include "scheduler.h"
#include "island.h"
#include "physics_world.h"
#include "temp_storage_holder.h"

enum query_types_enum {
	query_type_object	= u32(1<<0),
}; // enum query_types_enum

namespace xray {
namespace physics {

struct space_detail :
	private boost::noncopyable
{
	island&				m_island;
	space_object&		m_space_object;

	space_detail		( island& i, space_object& o ) :
		m_island		( i ),
		m_space_object	( o )
	{
	}
}; // struct space_detail



space_item::space_item		( space_object	&so )
:m_space_object( so ),
m_space(0)
{
	collision::object::set_type( 0 );
}

space_item::~space_item		( )
{
	if( m_space )
		space_remove	( );
}

void	space_item::space_insert( xray::collision::space_partitioning_tree &space )
{
	ASSERT( !m_space );
	m_space = &space;
	float3 center, radius;
	m_space_object.aabb( center, radius );
	m_space->insert( this, center, radius );
    //m_space->insert( this, float3(0,0,0), float3(2,2,2) );
}

void	space_item::space_remove	( )
{
	ASSERT( m_space );
//	m_space->remove( this );
	m_space = 0;
}

void	space_item::collide( island& island )
{
	static xray::collision::objects_type &res = island.get_sheduler().world().get_temp_storage_holder().space_collision_results();
	res.clear();
	m_space->aabb_query( query_type_object, create_center_radius( get_aabb_center(), get_aabb_extents()  ), res );
	
	//it may be better to move results to stack allocated buffer and clean res immediately
	// to avoid memory fragmentation

	xray::collision::objects_type::iterator			i = res.begin();
	xray::collision::objects_type::const_iterator	e = res.end();

	for( ; i!=e; ++i )
	{
		
		
		//if i get const object on query
		//but i do want to integerate it
		// i need to move and change velocity
		//it seems to mean to change it
		//what can i do?
		//const_cast it !!!
		collision::object * o = const_cast<collision::object*>  ( *i );
	

		ASSERT( o );
		physics::space_detail details(island, m_space_object);
		space_item* item = o->cast_space_item();

		if ( item )
			item->on_physics_space_collide( details ); 
	}
}

void	space_item::on_physics_space_collide ( physics::space_detail& sd )
{
	if( &(m_space_object) == & (sd.m_space_object) )
		 return; //ignore self
	 m_space_object.collide(  sd.m_island, sd.m_space_object );
}


void	space_item::on_move( )
{
	ASSERT( m_space );
	
	float3 center, radius;
	m_space_object.aabb( center, radius );
	m_space->move( this, center, radius );
}

bool space_item::aabb_test		( math::aabb const& aabb ) const
{
	return m_space_object.aabb_test( aabb );
}

bool space_item::cuboid_test	( math::cuboid const& cuboid ) const
{
	XRAY_UNREFERENCED_PARAMETER	( cuboid );
	UNREACHABLE_CODE(return false);
}

bool space_item::ray_test		( float3 const& origin, float3 const& direction, float max_distance, float& distance  ) const
{
	XRAY_UNREFERENCED_PARAMETERS	( &origin, &direction, &max_distance, &distance );
	UNREACHABLE_CODE(return false);
}

void space_item::add_triangles	( collision::triangles_type& triangles ) const
{
	XRAY_UNREFERENCED_PARAMETER	( triangles );
	UNREACHABLE_CODE();
}

bool space_item::aabb_query		( math::aabb const& aabb, xray::collision::triangles_type& results ) const
{
	XRAY_UNREFERENCED_PARAMETERS	( &aabb, &results );
	UNREACHABLE_CODE(return false);
}

bool space_item::cuboid_query	( math::cuboid const& cuboid, xray::collision::triangles_type& results ) const
{
	XRAY_UNREFERENCED_PARAMETERS	( &cuboid, &results );
	UNREACHABLE_CODE(return false);
}

bool space_item::ray_query		( float3 const& origin, float3 const& direction, float max_distance, float& distance, xray::collision::ray_triangles_type& results, xray::collision::triangles_predicate_type const& predicate ) const
{
	XRAY_UNREFERENCED_PARAMETERS	( &origin, &direction, &max_distance, &distance, &predicate, &results );
	UNREACHABLE_CODE(return false);
}

void	space_item::render			( xray::render::debug::renderer& renderer ) const 
{
	m_space_object.render( renderer );
}

} // namespace physics
} // namespace xray
