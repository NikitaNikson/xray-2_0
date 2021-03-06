////////////////////////////////////////////////////////////////////////////
//	Created 	: 11.02.2008
//	Author		: Konstantin Slipchenko
//	Description : joint_ball
////////////////////////////////////////////////////////////////////////////
#include	"pch.h"
#include	"joint_ball.h"
#include	"ode_include.h"
#include	"ode_convert.h"
#include	"joint_ode.h"

dxJoint*	joint_ball::create_ode( )
{
	return create_ode_ball();
}

joint_ball::joint_ball( ):
	joint_single_base_impl( create_ode() )
{
	
}

joint_ball::~joint_ball()
{
	detach( m_joint );
	destroy_joint( m_joint );
}



void	joint_ball::set_anchor( const float3	&anchor )
{
	dJointSetBallAnchor( m_joint, anchor.x, anchor.y, anchor.z ) ;
}

void	joint_ball::get_anchor( float3	&anchor )const
{
	dVector3 res;
	dJointGetBallAnchor( dJointID( m_joint ), res );
	anchor = cast_xr( res );
}