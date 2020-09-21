#ifndef TEXTURE_COMPRESSOR_API_H
#define TEXTURE_COMPRESSOR_API_H

#include <amd/compress/ATI_Compress.h>

namespace xray {
namespace texture_compressor {

	enum compression_speed
	{
			compression_speed_normal = ATI_TC_Speed_Normal,
			compression_speed_fast = ATI_TC_Speed_Fast,
			compression_speed_super_fast = ATI_TC_Speed_SuperFast
	};

#pragma pack(push,1)
	struct TgaHeader
	{
		u8 id_length;
		u8 color_map_type;
		u8 image_type;

		u16 color_map_origin;
		u16 color_map_length;
		u8 color_map_entry_size;

		u16 x_origin;
		u16 y_origin;

		u16 width;
		u16 height;

		u8 pixel_size;
		u8 image_descriptor;
	};
#pragma pack(pop)

void load_tga(pvoid (*allocate_func)(u32,bool),void (*free_func)(pvoid),const u8* tga_buf,ATI_TC_Texture& texture);
ATI_TC_FORMAT parse_format(char* fmt);
char* get_format_dest(ATI_TC_FORMAT fmt);

} // namepsace texture_compressor
} // namespace xray

u8* create_texture(u32& size, pvoid (*allocate_func)(u32,bool), void (*free_func)(pvoid), const u8* tga_buf, ATI_TC_FORMAT format,
				   xray::texture_compressor::compression_speed speed, bool mt);

#endif