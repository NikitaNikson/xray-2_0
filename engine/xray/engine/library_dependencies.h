////////////////////////////////////////////////////////////////////////////
//	Created		: 21.09.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_ENGINE_LIBRARY_DEPENDENCIES_H_INCLUDED
#define XRAY_ENGINE_LIBRARY_DEPENDENCIES_H_INCLUDED

#include <xray/core/library_linkage.h>

#include <xray/collision/library_linkage.h>
#include <xray/physics/library_linkage.h>

#include <xray/animation/library_linkage.h>
#include <xray/rtp/library_linkage.h>

#include <xray/network/library_linkage.h>

#include <xray/sound/library_linkage.h>

#include <xray/input/library_linkage.h>

#include <xray/render/base/library_linkage.h>
#ifndef XRAY_STATIC_LIBRARIES
#	include <xray/render/library_linkage.h>
#endif // #ifndef XRAY_STATIC_LIBRARIES

#include <xray/ui/library_linkage.h>

#include <xray/editor/world/library_linkage.h>

#endif // #ifndef XRAY_ENGINE_LIBRARY_DEPENDENCIES_H_INCLUDED