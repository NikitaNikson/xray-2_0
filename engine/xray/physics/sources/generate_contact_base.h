////////////////////////////////////////////////////////////////////////////
//	Created 	: 03.02.2008
//	Author		: Konstantin Slipchenko
//	Description : gen_contact_base
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_PHYSICS_GENERATE_CONTACT_BASE_H_INCLUDED
#define XRAY_PHYSICS_GENERATE_CONTACT_BASE_H_INCLUDED

#include <xray/collision/contact_info.h>

class island;

struct generate_contact_base:
	public xray::collision::on_contact,
	private boost::noncopyable
{
	island	&isl;
	u32		number;

	inline									generate_contact_base	( island	&i ): isl( i ),number(0){} ;
	virtual	memory::base_allocator*			alocator				( )	{ return physics::g_allocator; }

#ifdef DEBUG
	virtual render::debug::renderer&	renderer				( )	;
#endif // #ifdef DEBUG

}; // struct generate_contact_base

#endif // #ifndef XRAY_PHYSICS_GENERATE_CONTACT_BASE_H_INCLUDED