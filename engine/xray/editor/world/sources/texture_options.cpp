////////////////////////////////////////////////////////////////////////////
//	Created		: 11.02.2010
//	Author		: Evgeniy Obertyukh
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "texture_options.h"
#include <xray/editor/base/managed_delegate.h>
#include "resource_editor.h"

#include <xray/thm.h>
#include <amd/compress/texture_compressor/api.h>
#include <amd/compress/ATI_Compress.h>

using namespace System;

namespace xray {
namespace editor {

	static void set_default_parameters(texture_options* );

		texture_options::texture_options			(fs::path_string absolute_resource_path, xray::fs::path_string file_path):
	resource_options(absolute_resource_path, file_path),
	type(type_2d),
	width(0),
	height(0),
	alpha_blend_mode(none),
	pack_mode(packed),
	has_mip_levels(true),
	normal_name(""),
	color_name(""),
	detail_name(""),
	detail_scale(0),
	bump_mode(paralax),
	bump_name(""),
	material_id(0.0),
	tile(128),
	m_is_default_values(true)
{
	this->type = get_type_from_name(this->m_resource_name.c_str());
	set_default_parameters(this);
}

		texture_options::texture_options			(fs::path_string absolute_resource_path, configs::lua_config_ptr config):
	resource_options(absolute_resource_path), m_is_default_values(false)
{
	this->m_resource_name.append(config->get_file_name());
	this->type = get_type_from_name(this->m_resource_name.c_str());
	load(config);
}

texture_options::ETType	texture_options::get_type_from_name(pcstr name)
{
	fs::path_string resource_path = name;
	fs::path_string resource_name;

	resource_name.assign(resource_path.begin()+resource_path.rfind('/')+1, resource_path.end());

	if(resource_name.find("terrain") == 0)
	{
		if( resource_name.find( "bump", resource_name.rfind('_') ) != -1 )			return texture_options::terrain_bump;
		if( resource_name.find( "color", resource_name.rfind('_') ) != -1 )			return texture_options::terrain_color;
		return texture_options::terrain;
	}
	else
	{
		if( resource_name.find( "sky", resource_name.rfind('_') ) != -1 ) 			return texture_options::sky;
		if( resource_name.find( "bump", resource_name.rfind('_') ) != -1 )			return texture_options::bump;
		if( resource_name.find( "nmap", resource_name.rfind('_') ) != -1 )			return texture_options::normal_map;
		return texture_options::type_2d;
	}
}

static void set_default_parameters(texture_options* options)
{
	switch(options->type)
	{
	case texture_options::sky:
		options->has_mip_levels = false;
		break;
	case texture_options::bump:
		options->alpha_blend_mode = texture_options::blend;
		break;
	//case normal_map:
	//case terrain:
	//case terrain_bump:
	//case terrain_color:
	//case type_2d:
	}
}

void	texture_options::load							(configs::lua_config_ptr config)
{
	//get config root
	configs::lua_config_value const& config_root = config->get_root();

	configs::lua_config_value table = config_root["options"]; 

	//Getting properties
	width					=		table["width"];
	height					=		table["height"];

	alpha_blend_mode		=		static_cast<ETAlphaBlendMode>((u32)table["alpha_blend_mode"]); 
	pack_mode				=		static_cast<ETPackMode>((u32)table["pack_mode"]); 
	has_mip_levels			=		((u32)table["has_mip_levels"]) != 0;

	// detail ext
	normal_name				=		(pcstr)table["normal_name"];
	color_name				=		(pcstr)table["color_name"];
	detail_name				=		(pcstr)table["detail_name"];
	detail_scale			=		table["detail_scale"];
	// bump	
	bump_mode				=		static_cast<ETBumpMode>((u32)table["bump_mode"]);
	bump_name				=		(pcstr)table["bump_name"];
	material_id				=		table["material_id"];

	tile					=		table["tile"];
}

void	texture_options::save							()
{
	//create correct path
	
	String^ file_path = Path::GetFullPath(gcnew String(m_absolute_resource_path.c_str())+"/textures_new/sources/"+(gcnew String(m_resource_name.c_str()))+".options");
	
	//open config file and get root of it
	configs::lua_config_ptr	const&		config	= configs::create_lua_config(unmanaged_string(file_path).c_str());
	configs::lua_config_value config_options	= config->get_root()["options"];

	//store data to config file
	
	config_options["width"]					= width;
	config_options["height"]				= height;

	config_options["alpha_blend_mode"]		= safe_cast<Int32>(alpha_blend_mode);
	config_options["pack_mode"]				= safe_cast<Int32>(pack_mode);
	config_options["has_mip_levels"]		= safe_cast<Int32>(has_mip_levels);

	config_options["normal_name"]			= normal_name.c_str();
	config_options["color_name"]			= color_name.c_str();
	config_options["detail_name"]			= detail_name.c_str();
	config_options["detail_scale"]		    = detail_scale;

	config_options["bump_mode"]				= safe_cast<Int32>(bump_mode);
	config_options["bump_name"]				= bump_name.c_str();
	config_options["material_id"]			= material_id;

	config_options["tile"]					= tile;
	//save config file to disk
	config->save();

	// save thm
	memory::writer thm(g_allocator);

	thm.open_chunk(THM_CHUNK_TEXTUREPARAM);
	thm.w_u32(0); // format
	thm.w_u32(0); // flags
	thm.w_u32(0); // border color
	thm.w_u32(0); // fade color
	thm.w_u32(0); // fade amount
	thm.w_u32(0); // mip filter
	thm.w_u32(width);
	thm.w_u32(height);
	thm.close_chunk();

	thm.open_chunk(THM_CHUNK_DETAIL_EXT);
	thm.w_stringZ(detail_name.c_str()); // detail name
	thm.w_float(detail_scale); // detail scale
	thm.close_chunk();

	thm.open_chunk(THM_CHUNK_MATERIAL);
	thm.w_u32(0); // material id
	thm.w_float(material_id); // material weight
	thm.close_chunk();

	thm.open_chunk(THM_CHUNK_BUMP);
	thm.w_float(0.0); // virtual height
	thm.w_u32(0); // bump mode
	thm.w_stringZ(bump_name.c_str());
	thm.close_chunk();

	fs::path_string thm_path = m_absolute_resource_path;
	thm_path += "/textures/";
	thm_path += m_resource_name;
	thm_path += ".thm";

	thm.save_to(thm_path.c_str());

	// update texture
	struct texture_updater
	{
		ATI_TC_FORMAT format;
		fs::path_string dds_path;

		void execute(resources::queries_result& result)
		{
			if(result.is_successful())
			{
				resources::pinned_ptr_const<u8> ptr( result[0].get_managed_resource() );

				u32 buf_size;
				u8* dds_buf = create_texture(buf_size, allocate, deallocate, 
					ptr.c_ptr(), format, texture_compressor::compression_speed_fast, true);

				FILE* f;
				if(fs::open_file(&f, fs::open_file_create|fs::open_file_truncate|fs::open_file_write, dds_path.c_str(), false))
				{
					fwrite(dds_buf, 1, buf_size, f);
					fclose(f);
				}

				MT_FREE(dds_buf);
			}

			MT_DELETE(this);
		}

		private:
		static pvoid allocate(u32 size, bool)
		{
			return MT_MALLOC(size, "texture_compressor");
		}

		static void deallocate(pvoid ptr)
		{
			MT_FREE(ptr);
		}
	};

	texture_updater* tu = MT_NEW(texture_updater);

	fs::path_string dds_path = m_absolute_resource_path;
	dds_path += "/textures/";
	dds_path += m_resource_name;
	dds_path += ".dds";

	tu->dds_path = dds_path;

	ATI_TC_FORMAT fmt = ATI_TC_FORMAT_RGB_888;

	if(pack_mode == packed)
	{
		switch(alpha_blend_mode)
		{
			case none:		fmt = ATI_TC_FORMAT_DXT1; break;
			case reference:	fmt = ATI_TC_FORMAT_DXT3; break;
			case blend:		fmt = ATI_TC_FORMAT_DXT5; break;
		}
	}
	else
	{
		switch (alpha_blend_mode)
		{
			case none:		//fmt = ATI_TC_FORMAT_RGB_888; break;
			case reference:
			case blend:		fmt = ATI_TC_FORMAT_ARGB_8888; break;
		}
	}

	tu->format = fmt;

	fs::path_string tga_path;// = m_absolute_resource_path;
	tga_path += "resources/textures_new/sources/";
	tga_path += m_resource_name;
	tga_path += ".tga";

	resources::query_resource(
		tga_path.c_str(),
		resources::raw_data_class,
		boost::bind(&texture_updater::execute, tu, _1),
		g_allocator);
}

}//namespace editor
}//namespace xray