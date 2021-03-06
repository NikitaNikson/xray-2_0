////////////////////////////////////////////////////////////////////////////
//	Created		: 18.02.2009
//	Author		: Andrew Kolomiets
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "stats.h"
#include <xray/ui/ui.h>
#include <xray/ui/world.h>

using stalker2::stats;

stats::stats(xray::ui::world& ui_world)
:m_ui_world(ui_world)
{
	create	();
}

stats::~stats()
{
	m_ui_world.destroy_window(m_main_window);
}

void stats::draw(render::world& w)
{
	m_main_window->draw(w);
}

void stats::set_fps_stats(float fps)
{
	string64		buff;
	xray::sprintf	(buff, "%3.2f", fps);
	m_fps->set_text	(buff);
}

void stats::set_camera_stats(float3 const& pos, float3 const& dir)
{
	string64		buff;
	xray::sprintf	(buff, "cam pos:%3.2f %3.2f %3.2f", pos.x, pos.y, pos.z);
	m_camera_position->set_text	(buff);

	xray::sprintf	(buff, "cam dir:%3.2f %3.2f %3.2f", dir.x, dir.y, dir.z);
	m_camera_direction->set_text	(buff);
}

void stats::create()
{
	m_main_window						= m_ui_world.create_window();
	m_main_window->set_visible			(true);
	m_main_window->set_position			(float2(0.0f, 0.0f));
	m_main_window->set_size				(float2(1024.0f, 768.0f));
	
	m_fps								= m_ui_world.create_text();
	m_fps->w()->set_visible				(true);
	m_fps->w()->set_position			(float2(0.0f, 0.0f));
	m_fps->w()->set_size				(float2(50.0f, 20.0f));
	m_fps->set_font						(xray::ui::fnt_arial);
	m_fps->set_text_mode				(xray::ui::tm_default);
	m_fps->set_color					(0xffffffff);
	m_main_window->add_child			(m_fps->w(), true);

	m_camera_position					= m_ui_world.create_text();
	m_camera_position->w()->set_visible	(true);
	m_camera_position->w()->set_position(float2(0.0f, 20.0f));
	m_camera_position->w()->set_size	(float2(100.0f, 20.0f));
	m_camera_position->set_font			(xray::ui::fnt_arial);
	m_camera_position->set_text_mode	(xray::ui::tm_default);
	m_camera_position->set_color		(0xffffffff);
	m_main_window->add_child			(m_camera_position->w(), true);

	m_camera_direction					= m_ui_world.create_text();
	m_camera_direction->w()->set_visible(true);
	m_camera_direction->w()->set_position(float2(0.0f, 40.0f));
	m_camera_direction->w()->set_size	(float2(100.0f, 20.0f));
	m_camera_direction->set_font		(xray::ui::fnt_arial);
	m_camera_direction->set_text_mode	(xray::ui::tm_default);
	m_camera_direction->set_color		(0xffffffff);
	m_main_window->add_child			(m_camera_direction->w(), true);
}
