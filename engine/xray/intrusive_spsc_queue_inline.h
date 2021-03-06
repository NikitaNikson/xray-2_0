////////////////////////////////////////////////////////////////////////////
//	Created		: 14.12.2009
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef INTRUSIVE_SPSC_QUEUE_INLINE_H_INCLUDED
#define INTRUSIVE_SPSC_QUEUE_INLINE_H_INCLUDED

namespace xray {

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::intrusive_spsc_queue		( ) :
	m_head					( 0 ),
	m_tail					( 0 ),
	m_push_thread_id		( threading::atomic32_value_type(-1) ),
	m_pop_thread_id			( threading::atomic32_value_type(-1) )
{
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::~intrusive_spsc_queue		( )
{
	R_ASSERT_CMP			( m_head, ==, 0, "do not forget call pop_null_node before destroying queue" );
	R_ASSERT_CMP			( m_tail, ==, 0, "unexpected situation" );
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline void intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::push_back				( T* const value )
{
	R_ASSERT_CMP			( m_head, !=, 0, "do not call push_back after pop_null_node or before push_null_node called" );
	R_ASSERT_CMP			( m_tail, !=, 0, "unexpected situation" );
	R_ASSERT_CMP			( m_push_thread_id, ==, (long)threading::current_thread_id() );

	value->*MemberNext		= 0;
	threading::interlocked_exchange_pointer	( (pvoid&)(m_head->*MemberNext), value );
	m_head					= value;
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline T* intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::pop_front				( T*& item_to_delete )
{
	R_ASSERT_CMP			( m_head, !=, 0, "do not call pop_front after pop_null_node or before push_null_node called" );
	R_ASSERT_CMP			( m_tail, !=, 0, "unexpected situation" );
	R_ASSERT_CMP			( m_pop_thread_id, ==, (long)threading::current_thread_id() );
	T* const node			= m_tail;
	T* const value			= node->*MemberNext;
	if ( !value )
		return				0;

	item_to_delete			= node;
	m_tail					= value;
	return					value;
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline void intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::push_null_node			( T* const null_node )
{
	R_ASSERT_CMP			( m_head, ==, 0, "do not call push_null_node when pop_null_node hasn't been called" );
	R_ASSERT_CMP			( m_tail, ==, 0, "unexpected situation" );
	R_ASSERT_CMP			( m_push_thread_id, ==, (long)threading::current_thread_id() );

	null_node->*MemberNext	= 0;
	m_head = m_tail			= null_node;
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline T* intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::pop_null_node			( )
{
	R_ASSERT_CMP			( m_head, !=, 0, "do not call pop_null_node after pop_null_node or before push_null_node called" );
	R_ASSERT_CMP			( m_tail, !=, 0, "unexpected situation" );
	R_ASSERT_CMP			( m_head, ==, m_tail );
	R_ASSERT_CMP			( m_pop_thread_id, ==, (threading::atomic32_value_type)threading::current_thread_id() );

	T* const result			= m_head;
	m_head = m_tail			= 0;
	return					result;
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline void intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::set_push_thread_id		( )
{
	threading::interlocked_exchange	( m_push_thread_id, threading::current_thread_id() );
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline void intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::set_pop_thread_id		( )
{
	threading::interlocked_exchange	( m_pop_thread_id, threading::current_thread_id() );
}

template < typename T, typename BaseWithMember, T* BaseWithMember::*MemberNext, typename head_type >
inline bool intrusive_spsc_queue<T,BaseWithMember,MemberNext,head_type>::empty					( ) const
{
	R_ASSERT_CMP			( m_head, !=, 0, "do not call push_back after pop_null_node or before push_null_node called" );
	R_ASSERT_CMP			( m_tail, !=, 0, "unexpected situation" );
	return					!(m_tail->*MemberNext);
}

} // namespace xray

#endif // #ifndef INTRUSIVE_SPSC_QUEUE_INLINE_H_INCLUDED