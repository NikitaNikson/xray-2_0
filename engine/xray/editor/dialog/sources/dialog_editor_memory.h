////////////////////////////////////////////////////////////////////////////
//	Created		: 26.05.2010
//	Author		: Sergey Pryshchepa
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#ifndef DIALOG_EDITOR_MEMORY_H_INCLUDED
#define DIALOG_EDITOR_MEMORY_H_INCLUDED

#include <xray/buffer_vector.h>
#include <xray/fixed_vector.h>
#include <xray/associative_vector.h>
#include <xray/hash_multiset.h>

#include <map>
#include <vector>
#include <set>

#include <xray/editor/dialog/api.h>

namespace xray {
namespace dialog_editor {

extern allocator_type*							g_allocator;

#define USER_ALLOCATOR							*::xray::dialog_editor::g_allocator
#include <xray/std_containers.h>
#undef USER_ALLOCATOR

} // namespace dialog_editor
} // namespace xray

#define NEW( type )								XRAY_NEW_IMPL(		*::xray::dialog_editor::g_allocator, type )
#define DELETE( pointer )						XRAY_DELETE_IMPL(	*::xray::dialog_editor::g_allocator, pointer )
#define MALLOC( size, description )				XRAY_MALLOC_IMPL(	*::xray::dialog_editor::g_allocator, size, description )
#define REALLOC( pointer, size, description )	XRAY_REALLOC_IMPL(	*::xray::dialog_editor::g_allocator, pointer, size, description )
#define FREE( pointer )							XRAY_FREE_IMPL(		*::xray::dialog_editor::g_allocator, pointer )
#define ALLOC( type, count )					XRAY_ALLOC_IMPL(	*::xray::dialog_editor::g_allocator, type, count )

#endif // #ifndef DIALOG_EDITOR_MEMORY_H_INCLUDED