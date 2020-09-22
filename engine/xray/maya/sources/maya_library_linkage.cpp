////////////////////////////////////////////////////////////////////////////
//	Created		: 07.05.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <xray/core/library_linkage.h>
#include <xray/physics/library_linkage.h>
#include <xray/animation/library_linkage.h>
#include <xray/maya_animation/library_linkage.h>

#pragma comment( lib, "opengl32.lib" )
#pragma comment( lib, "OpenMayaUI.lib" )
#pragma comment( lib, "Foundation.lib" )
#pragma comment( lib, "OpenMaya.lib" )
#pragma comment( lib, "OpenMayaAnim.lib" )
#if _MSC_VER == 1500
	#pragma comment( lib, "TootleSoftwareOnlyStatic_2k8_MTDLL.lib" )
#else
	#ifdef WIN64
		#pragma comment( lib, "TootleSoftwareOnlyStatic_2013_MTDLL_64.lib" )
		
	#else
		#pragma comment( lib, "TootleSoftwareOnlyStatic_2013_MTDLL.lib" )
	#endif
#endif