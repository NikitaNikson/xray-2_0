////////////////////////////////////////////////////////////////////////////
//	Created 	: 13.11.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <xray/buffer_vector.h>
#include <xray/fixed_vector.h>
#include <xray/associative_vector.h>
#include <xray/hash_multiset.h>

namespace xray {
namespace engine {

extern memory::doug_lea_allocator_type			g_allocator;

#define USER_ALLOCATOR							::xray::engine::g_allocator
#include <xray/std_containers.h>
#undef USER_ALLOCATOR

} // namespace engine
} // namespace xray

#define NEW( type )								XRAY_NEW_IMPL(		::xray::engine::g_allocator, type )
#define DELETE( pointer )						XRAY_DELETE_IMPL(	::xray::engine::g_allocator, pointer )
#define MALLOC( size, description )				XRAY_MALLOC_IMPL(	::xray::engine::g_allocator, size, description )
#define REALLOC( pointer, size, description )	XRAY_REALLOC_IMPL(	::xray::engine::g_allocator, pointer, size, description )
#define FREE( pointer )							XRAY_FREE_IMPL(		::xray::engine::g_allocator, pointer )
#define ALLOC( type, count )					XRAY_ALLOC_IMPL(	::xray::engine::g_allocator, type, count )

#endif // #ifndef MEMORY_H_INCLUDED