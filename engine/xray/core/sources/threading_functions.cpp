////////////////////////////////////////////////////////////////////////////
//	Created 	: 07.10.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "logging.h"
#include <xray/os_include.h>
#include "debug.h"
#include <xray/fixed_string.h>
#include "member_to_functor.h"
#include <functional>
#include "threading_functions.h"
#include <xray/construction.h>

#ifndef NDEBUG
#	define	XRAY_THREADING_INLINE
#	if XRAY_PLATFORM_WINDOWS
#		include <xray/threading_functions_win_inline.h>
#	elif XRAY_PLATFORM_XBOX_360 // #if XRAY_PLATFORM_WINDOWS
#		include <xray/threading_functions_xbox_inline.h>
#	elif XRAY_PLATFORM_PS3 // #elif XRAY_PLATFORM_XBOX_360
#		include <xray/threading_functions_ps3_inline.h>
#	else // #elif XRAY_PLATFORM_PS3
#		error "create an implementation of threading functions for your platform"
#	endif // #ifdef XRAY_PLATFORM_WINDOWS | XRAY_PLATFORM_XBOX_360
#	undef	XRAY_THREADING_INLINE
#endif // #ifndef NDEBUG

namespace xray {

namespace tasks {
	void on_thread_spawn	( );
} // namespace tasks

namespace threading {

//-----------------------------------------------------------------------------------
// spawning new thread
//-----------------------------------------------------------------------------------

void	free_current_thread_logging_name ( );

void thread_entry				( pvoid argument )
{
	thread_entry_params* const params_raw	= ( thread_entry_params* )argument;
	thread_entry_params	params				= *( thread_entry_params const* )argument;

	u32 const name_for_debugger_length		= strings::length(params_raw->thread_name_for_debugger);
	pstr name_for_debugger_in_stack			= pointer_cast<pstr>( ALLOCA( (name_for_debugger_length+1)*sizeof(char) ) );
	strings::copy							( name_for_debugger_in_stack, name_for_debugger_length+1, params_raw->thread_name_for_debugger);

	u32 const name_for_logging_length		= strings::length(params_raw->thread_name_for_logging);
	pstr name_for_logging_in_stack			= pointer_cast<pstr>( ALLOCA( (name_for_logging_length+1)*sizeof(char) ) );
	strings::copy							( name_for_logging_in_stack, name_for_logging_length+1, params_raw->thread_name_for_logging);

	set_thread_name							( name_for_debugger_in_stack, name_for_logging_in_stack );

	XRAY_MEMORY_BARRIER_EXCEPT_READS_BEFORE_WRITES	( );
	params_raw->processed					= true;

	set_current_thread_affinity				( params.hardware_thread );

	xray::core::debug::on_thread_spawn		( );
	xray::logging::on_thread_spawn			( );
	if ( params.tasks_awareness == threading::tasks_aware )
		xray::tasks::on_thread_spawn		( );

	params.function_to_call					( );

	free_current_thread_logging_name		( );
}

thread_id_type spawn_internal		(
		thread_entry_params& argument,
		u32 const stack_size
	);
	
thread_id_type spawn	(
		thread_function_type const& function_to_call,
		pcstr const thread_name_for_debugger,
		pcstr thread_name_for_logging,
		u32 const stack_size,
		u32 const hardware_thread,
		tasks_awareness tasks_awareness,
		pvoid * out_handle
	)
{
	ASSERT								( hardware_thread != u32(-1) );
	ASSERT								( thread_name_for_debugger );
	if ( !thread_name_for_logging )
		thread_name_for_logging			= thread_name_for_debugger;

	thread_entry_params					argument;
	argument.function_to_call			= function_to_call;
	argument.thread_name_for_logging	= thread_name_for_logging;
	argument.thread_name_for_debugger	= thread_name_for_debugger;
	argument.hardware_thread			= hardware_thread;
	argument.tasks_awareness			= tasks_awareness;
	argument.processed					= false;

	thread_id_type const out_thread_id	= spawn_internal( argument, stack_size );

	if ( out_handle )
		*out_handle						= *(pvoid*)&out_thread_id;

	while ( !argument.processed )
		yield							( 0 );

	return								out_thread_id;
}

//-----------------------------------------------------------------------------------
// getting core count
//-----------------------------------------------------------------------------------

command_line::key	g_debug_single_thread("debug_single_thread", "", "threading", "run all in one thread");
command_line::key	g_core_affinity("core_affinity", "", "threading", "string mask with 1 and 0");

static u32	*		s_logical_to_physical_core_index	=	NULL;
static u32			s_logical_core_count				=	0;

void   initialize_core_affinity	( );

u32 logical_to_physical_core ( u32 logical_core )
{
	if ( !s_logical_to_physical_core_index )
		initialize_core_affinity			( );

	ASSERT									( s_logical_to_physical_core_index );
	return									s_logical_to_physical_core_index[logical_core];
}

u32 actual_core_count						( );

void initialize_core_count ( )
{
	u32 const physical_count				= actual_core_count();

	fixed_string512							core_affinity;
	if ( g_debug_single_thread )
		s_logical_core_count				= 1;
	else if ( g_core_affinity.is_set_as_string(& core_affinity) ) 
	{
		if ( !core_affinity.length() )
		{
			FATAL							("command line key: %s requires a non-null value", g_core_affinity.full_name());
			s_logical_core_count			= physical_count;
			return;
		}

		s_logical_core_count				= 0;
		for ( u32 i=0, n=core_affinity.length(); i<n; ++i )
			if ( core_affinity[i] != '0' )
				++s_logical_core_count;

		CURE_ASSERT							(core_affinity.length() <= physical_count, 
											 s_logical_core_count = physical_count, 
											 "core_affinity mask has more cores then system has");
	}
	else
		s_logical_core_count				= physical_count;
}

u32 core_count								( )
{
	if ( !s_logical_core_count )
		initialize_core_count				( );
	return									s_logical_core_count;
}

void initialize_core_affinity				( )
{
	initialize_core_count					( );
	u32 const physical_count				= actual_core_count();

	fixed_string512							core_affinity;
	if ( g_debug_single_thread ) {
		s_logical_to_physical_core_index	= MT_ALLOC(u32, s_logical_core_count);
		s_logical_to_physical_core_index[0]	= 0;
	}
	else if ( g_core_affinity.is_set_as_string(& core_affinity) ) {

		s_logical_to_physical_core_index	= MT_ALLOC(u32, s_logical_core_count);
		u32 current_logical_index			= 0;
		for ( u32 i=0; i<core_affinity.length(); ++i )
			if ( core_affinity[i] != '0' ) {
				s_logical_to_physical_core_index[current_logical_index]	=	i;
				++current_logical_index;
				if ( current_logical_index == s_logical_core_count )
					break;
			}
	}
	else {
		s_logical_to_physical_core_index	= MT_ALLOC(u32, s_logical_core_count);
		for ( u32 i=0; i<physical_count; ++i )
			s_logical_to_physical_core_index[i]	= i;
	}
}

//-----------------------------------------------------------------------------------
// setting and getting affinities
//-----------------------------------------------------------------------------------

void set_current_thread_affinity_impl	( u32 const hardware_thread );

static threading::atomic32_type s_thread_affinity_tls_key = 0;

void set_current_thread_affinity		( u32 const hardware_thread )
{
	if ( !s_thread_affinity_tls_key )
	{
		static atomic32_value_type creation_flag	= 0;
		atomic32_value_type const previous_creation_flag	=	threading::interlocked_exchange(creation_flag, 1);
		if ( previous_creation_flag == 0 )
			interlocked_exchange		( s_thread_affinity_tls_key, (long)tls_create_key() );
		else
			while ( !s_thread_affinity_tls_key ) ;
	}

	u32 const previous_value				=	(u32)tls_get_value(s_thread_affinity_tls_key);
	if ( !previous_value || (previous_value-1) != hardware_thread )
	{
		tls_set_value							(s_thread_affinity_tls_key, (pvoid)(hardware_thread + 1));
		set_current_thread_affinity_impl		(logical_to_physical_core(hardware_thread));
	}
}

u32   current_thread_affinity ()
{
	R_ASSERT									(s_thread_affinity_tls_key, "first call set_current_thread_affinity");
	u32 hardware_thread						=	(u32)tls_get_value(s_thread_affinity_tls_key);
	return										hardware_thread ? (hardware_thread - 1) : u32(-1);
}

//-----------------------------------------------------------------------------------
// thread name
//-----------------------------------------------------------------------------------

static u32	s_thread_logging_name_tls_key	=	tls_get_invalid_key();

void delete_thread_logging_tls_key	( )
{
	if ( s_thread_logging_name_tls_key != tls_get_invalid_key( ) )
		tls_delete_key					(s_thread_logging_name_tls_key);
}

void free_current_thread_logging_name ( )
{
	pvoid		thread_name	=	tls_get_value(s_thread_logging_name_tls_key);
	if ( thread_name )
	{
		tls_set_value			(s_thread_logging_name_tls_key, NULL);
	}
}

pcstr current_thread_logging_name ( )
{
	pcstr		thread_name	= (pcstr)tls_get_value(s_thread_logging_name_tls_key);
	return						thread_name ? thread_name : "undefined";
}

void set_thread_name_impl	( pcstr name_for_debugger );

void set_thread_name		( pcstr name_for_debugger, pcstr logging_name )
{
	XRAY_UNREFERENCED_PARAMETER			( name_for_debugger );

	R_ASSERT							( !tls_get_value(s_thread_logging_name_tls_key) );

	tls_set_value						( s_thread_logging_name_tls_key, (pvoid)logging_name );

	if ( !debug::is_debugger_present() )
		return;

	set_thread_name_impl				( name_for_debugger );
}

//-----------------------------------------------------------------------------------
// initialization
//-----------------------------------------------------------------------------------

void preinitialize							( )
{
	s_thread_logging_name_tls_key		= tls_create_key();
}

void initialize ( )
{
	if ( !s_logical_to_physical_core_index )
		initialize_core_affinity				( );
}


void finalize									( )
{
	free_current_thread_logging_name			( );
	delete_thread_logging_tls_key				( );
	MT_FREE										( s_logical_to_physical_core_index );
}

} // namespace threading
} // namespace xray