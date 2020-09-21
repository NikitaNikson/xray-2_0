////////////////////////////////////////////////////////////////////////////
//	Created 	: 03.03.2008
//	Author		: Konstantin Slipchenko
//	Description : sphere - single triangle tests
////////////////////////////////////////////////////////////////////////////

namespace xray {
namespace collision {
namespace detail {
	
inline		triangle_sphere_contact_tests::triangle_sphere_contact_tests( const sphere_geometry	 &g, 
												 const float4x4 &transform,
												 buffer_vector<triangle_sphere_res>& result_buff,
												 on_contact& c
												 ):
m_geometry( g ), m_transform( transform ),cbr( c, result_buff )
{

}
void triangle_sphere_contact_tests::get_query_aabb(  const float4x4 &transform, const xray::collision::sphere_geometry& og,   math::aabb	&query_aabb )
{ 
	query_aabb = create_min_max(transform.c.xyz(),transform.c.xyz()) + float3( og.radius(), og.radius(), og.radius() ) ;
}

inline	void	triangle_sphere_contact_tests::test( buffer_vector<u32>	&backs,const u32 * ind, float3 const* verts )
{
	triangle_sphere_test( cbr, backs, ind, verts, m_transform.c.xyz(), m_geometry.radius() );
}
inline	bool	triangle_sphere_contact_tests::trash_back( const result &back_tri, float3 const* verts )
{
	return detail::trash_back_by_all_res( back_tri, cbr.res_vec, verts, m_transform.c.xyz() );
}
inline	void	triangle_sphere_contact_tests::back_test( result &back_tri, float3 const* verts )
{
	triangle_sphere_back_test( cbr.back_res, back_tri, verts, m_transform.c.xyz(), m_geometry.radius() );
}

} // namespace detail
} // namespace collision
} // namespace xray