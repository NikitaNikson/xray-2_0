////////////////////////////////////////////////////////////////////////////
//	Created 	: 23.01.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <xray/os_include.h>
#include "threading_functions.h"
#include <process.h>				// for _beginthreadex
#include "debug_platform.h"

namespace xray {
namespace threading {

u32 current_thread_id						( )
{
	return				( GetCurrentThreadId( ) );
}

void yield				( u32 milliseconds )
{
	if ( milliseconds ) {
		Sleep					( milliseconds );
		return;
	}

	if ( SwitchToThread( ) )
		return;

	Sleep						( 0 );
}

void set_thread_name_impl	( pcstr name_for_debugger )
{
#ifndef MASTER_GOLD
#	pragma pack(push,8)
	struct thread_profile {
		u32		type;
		pcstr	name;
		u32		thread_id;
		u32		flags;
	};
#	pragma pack(pop)

	thread_profile				profile;
	profile.type				= 4096;
	profile.name				= name_for_debugger;
	profile.thread_id			= u32(-1);
	profile.flags				= 0;

	__try {
		RaiseException			( 0x406D1388, 0, sizeof( profile )/ sizeof( u32 ), ( ULONG_PTR const* ) &profile );
	}
	__except( EXCEPTION_CONTINUE_EXECUTION ) {
	}
#else // #ifndef MASTER_GOLD
	XRAY_UNREFERENCED_PARAMETER	( name_for_debugger );
#endif // #ifndef MASTER_GOLD
}

u32 tls_create_key		( )
{
	return						TlsAlloc( );
}

void tls_delete_key	( u32 key )
{
	TlsFree						( key );
}

void tls_set_value		( u32 key, pvoid value )
{
	TlsSetValue					( key, value );
}

pvoid tls_get_value	( u32 key )
{
	return						TlsGetValue( key );
}

u32 tls_get_invalid_key( )
{
	return						TLS_OUT_OF_INDEXES;
}

bool tls_is_valid_key			( u32 key )
{
	return						key != tls_get_invalid_key();
}

void thread_entry	( pvoid argument );

static DWORD __stdcall thread_entry_protected	( pvoid argument )
{
	xray::debug::protected_call		( &thread_entry, argument );
	return							0;
}

thread_id_type spawn_internal		(
		thread_entry_params& argument,
		u32 const stack_size
	)
{
	DWORD	result;
	HANDLE const handle	=
		CreateThread(
			0, 
			stack_size, 
			&thread_entry_protected, 
			&argument,
			0, 
			&result
		);

	if ( !handle ) {
		DWORD const error_code	= GetLastError( ); 
		pstr error_message		=	xray::core::debug::platform::fill_format_message	( error_code );
		LOGI_ERROR					( "debug", "CreateThread failed with error_code %d: %s", error_code, error_message );
		xray::core::debug::platform::free_format_message	( error_message );
	}

	R_ASSERT_U							( handle, "can't spawn thread!" );
	return								result;
}

} // namespace threading
} // namespace xray