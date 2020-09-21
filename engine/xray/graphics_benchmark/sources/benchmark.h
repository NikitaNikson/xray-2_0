////////////////////////////////////////////////////////////////////////////
//	Created		: 09.06.2010
//	Author		: Nikolay Partas
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#ifndef BENCHMARK_H_INCLUDED
#define BENCHMARK_H_INCLUDED

#include "benchmark_nested_types.h"
#include "benchmark_renderer.h"
#include "counters_result.h"

namespace xray {
namespace graphics_benchmark {

class gpu_timer;
class benchmark_test;


class benchmark: public boost::noncopyable
{
public:

	benchmark						( benchmark_target_enum bt, char const* benchmark_file);
	~benchmark						( );

	void register_test_class		( creator_func_type creator_func, char const* class_name);

	bool execute_benchmark_file		( char const* file_name);
	void execute					( group_to_execute& group, test_to_execute& test, gpu_timer& gtimer);

	void show_compared_results		( );

	u32 get_current_test_index		( )	{ return m_current_test_index;}

	benchmark_renderer& renderer	( )	{ return m_benchmark_renderer;}

	friend class cpu_timer;
	friend class gpu_timer;
	
	void get_window_resolution		( u32& out_size_x, u32& out_size_y) { out_size_x = m_window_size_x; out_size_y = m_window_size_y;}

	void start_execution();

private:

	benchmark_class* get_benchmark_class( char const* class_name) const;

	void on_load_benchmark_file		( resources::queries_result & in_result );

	static std::string target_to_string ( benchmark_target_enum t);
	
	bool initialize						( benchmark_target_enum bt);
	bool post_initialize				( benchmark_target_enum bt);

	void finalize						( );

	bool initialize_d3d					( );
	void finalize_d3d					( );

	bool initialize_ati					( );
	bool initialize_nvidia				( );
	bool initialize_xbox				( );
	bool initialize_ps3					( );

	void pre_finalize					( );

	void finalize_ati					( );
	void finalize_nvidia				( );
	void finalize_xbox					( );
	void finalize_ps3					( );

	void get_empty_frame_elapsed_time	( double& out_sec, u64& out_ticks);

	void begin_test						( u32& num_passes);
	void end_test						( counters_result& out_results);
	
	ID3DDevice* d3d_device				( ) const;
	
	HWND get_new_window					( u32 window_size_x, u32 window_size_y);

private:
	
	std::vector<group_to_execute>		m_groups;
	std::string							m_log_file_name;
	u32									m_current_test_index;
	u32									m_start_gpu_time;

	HWND								m_hwnd;
	u32									m_window_size_x;
	u32									m_window_size_y;
	bool								m_is_full_screen;

	benchmark_target_enum				m_benchmark_target;

	typedef std::multimap<std::string, counters_result> results_type;

	results_type m_results;

	bool								m_counters_valid;

	// Don't change order of members!
	render_dx10::resource_manager		m_res_mgr;
	bool								m_benchmark_loaded;
	render_dx10::device					m_device;
	render_dx10::backend				m_backend;
	render_dx10::effect_manager			m_sh_mgr;

	benchmark_renderer					m_benchmark_renderer;

	benchmark_class*					first_class;
}; // class benchmark

} // namespace graphics_benchmark
} // namespace xray

#endif // #ifndef BENCHMARK_H_INCLUDED