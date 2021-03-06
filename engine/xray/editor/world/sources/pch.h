////////////////////////////////////////////////////////////////////////////
//	Created 	: 26.08.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef PCH_H_INCLUDED
#define PCH_H_INCLUDED

#define XRAY_EDITOR_BUILDING


#define XRAY_LOG_MODULE_INITIATOR	"editor"
#include <xray/editor/base/editor_extensions.h>

#pragma managed(push,off)
#include "editor_memory.h"
#pragma managed(pop)

namespace xray {
namespace editor {
#	include <xray/editor/base/unmanaged_string.h>
} // namespace editor
} // namespace xray

using Microsoft::Win32::RegistryKey;
RegistryKey^ get_sub_key(RegistryKey^ root, System::String^ name);

#endif // #ifndef PCH_H_INCLUDED