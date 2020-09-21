////////////////////////////////////////////////////////////////////////////
//	Created		: 18.05.2010
//	Author		: Andrew Kolomiets
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#ifndef NODE_IDENTIFIERS_H_INCLUDED
#define NODE_IDENTIFIERS_H_INCLUDED

#define body_node_type_id			0x00700
#define body_node_type_name			"xray_body"

#define body_node_manip_type_id		0x00701
#define body_node_manip_type_name	"xray_bodyManip"


#define collision_node_type_id		0x00600
#define collision_node_type_name	"xray_collision"

#define joint_node_type_id			0x00800
#define joint_node_type_name		"xray_constraint"

#define shader_node_type_id			0x00801
#define shader_node_type_name		"xray_shader"

#define fake_drawing_locator_type_id	0x0010BC08
#define fake_drawing_locator_type_name	"xray_fake_drawing_locator"

// material
#define shader_name_att					"xray_render_shader"
#define doublesided_att_name			"double_sided"

MDagPath get_path_by_name		(MString const& name, MStatus& stat);
MObject get_node_by_name		(MString const& name, MStatus& stat);

#endif // #ifndef NODE_IDENTIFIERS_H_INCLUDED