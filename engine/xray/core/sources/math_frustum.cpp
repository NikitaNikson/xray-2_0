////////////////////////////////////////////////////////////////////////////
//	Created 	: 23.10.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"

using xray::math::frustum;
using xray::math::intersection;
using xray::math::aabb;
using xray::math::float4x4;
using xray::math::sphere;
using xray::math::plane;

frustum::frustum						( float4x4 const& transform )
{
	m_planes[ 0 ].plane.vector.x	= -( transform.e03 + transform.e00 );
	m_planes[ 0 ].plane.vector.y	= -( transform.e13 + transform.e10 );
	m_planes[ 0 ].plane.vector.z	= -( transform.e23 + transform.e20 );
	m_planes[ 0 ].plane.vector.w	= -( transform.e33 + transform.e30 );
															   
	m_planes[ 1 ].plane.vector.x	= -( transform.e03 - transform.e00 );
	m_planes[ 1 ].plane.vector.y	= -( transform.e13 - transform.e10 );
	m_planes[ 1 ].plane.vector.z	= -( transform.e23 - transform.e20 );
	m_planes[ 1 ].plane.vector.w	= -( transform.e33 - transform.e30 );
															   
	m_planes[ 2 ].plane.vector.x	= -( transform.e03 - transform.e01 );
	m_planes[ 2 ].plane.vector.y	= -( transform.e13 - transform.e11 );
	m_planes[ 2 ].plane.vector.z	= -( transform.e23 - transform.e21 );
	m_planes[ 2 ].plane.vector.w	= -( transform.e33 - transform.e31 );
															   
	m_planes[ 3 ].plane.vector.x	= -( transform.e03 + transform.e01 );
	m_planes[ 3 ].plane.vector.y	= -( transform.e13 + transform.e11 );
	m_planes[ 3 ].plane.vector.z	= -( transform.e23 + transform.e21 );
	m_planes[ 3 ].plane.vector.w	= -( transform.e33 + transform.e31 );
															   
	m_planes[ 4 ].plane.vector.x	= -( transform.e03 - transform.e02 );
	m_planes[ 4 ].plane.vector.y	= -( transform.e13 - transform.e12 );
	m_planes[ 4 ].plane.vector.z	= -( transform.e23 - transform.e22 );
	m_planes[ 4 ].plane.vector.w	= -( transform.e33 - transform.e32 );
															   
	m_planes[ 5 ].plane.vector.x	= -( transform.e03 + transform.e02 );
	m_planes[ 5 ].plane.vector.y	= -( transform.e13 + transform.e12 );
	m_planes[ 5 ].plane.vector.z	= -( transform.e23 + transform.e22 );
	m_planes[ 5 ].plane.vector.w	= -( transform.e33 + transform.e32 );

	aabb_plane*	i					= m_planes;
	aabb_plane const* const e		= m_planes + plane_count;
	for ( ; i != e; ++i)
		( *i ).normalize			( );
}
