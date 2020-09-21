////////////////////////////////////////////////////////////////////////////
//	Created 	: 14.10.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef XRAY_MATH_FLOAT2_INLINE_H_INCLUDED
#define XRAY_MATH_FLOAT2_INLINE_H_INCLUDED

namespace xray {
namespace math {

inline float2& float2_pod::operator -				( )
{
	x			= -x;
	y			= -y;

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::operator +=			( float2_pod const& other )
{
	x			+= other.x;
	y			+= other.y;
	
	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::operator +=			( type const value )
{
	x			+= value;
	y			+= value;

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::operator -=			( float2_pod const& other )
{
	x			-= other.x;
	y			-= other.y;

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::operator -=			( type const value )
{
	x			-= value;
	y			-= value;

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::operator *=			( type const value )
{
	x			*= value;
	y			*= value;

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::operator /=			( type const value )
{
	ASSERT		( !is_zero( value ) );

	x			/= value;
	y			/= value;

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::operator ^=			( float2_pod const& other )
{
	return		( cross_product( other ) );
}

inline float2::type& float2_pod::operator [ ]	( int index )
{
	ASSERT		( index < 2 );
	return		( elements[ index ] );
}

inline const float2::type& float2_pod::operator [ ]	( int index ) const
{
	ASSERT		( index < 2 );
	return		( elements[ index ] );
}

inline float2& float2_pod::set					( float2_pod::type vx, float2_pod::type vy )
{
	x			= vx;
	y			= vy;
	return		( static_cast<float2&>(*this) );
}

inline float2::type float2_pod::dot_product		( float2_pod const& other ) const
{
	return		( x*other.x + y*other.y );
}

inline float2& float2_pod::cross_product		( float2_pod const& other )
{
	x			= other.y;
	y			= -other.x;

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::normalize			( )
{
	return		( *this /= magnitude( ) );
}

inline float2::type float2_pod::normalize_r		( )
{
	type const	magnitude = this->magnitude( );
	*this		/= magnitude;
	return		( magnitude );
}

inline float2& float2_pod::normalize_safe		( float2_pod const& result_in_case_of_zero )
{
	type const	magnitude = this->magnitude( );
	if ( !is_zero( magnitude ) )
		return	( *this	/= magnitude );

	*this		= result_in_case_of_zero;
	return		( static_cast<float2&>(*this) );
}

inline float2::type float2_pod::normalize_safe_r( float2_pod const& result_in_case_of_zero )
{
	type const	magnitude = this->magnitude( );
	if ( !is_zero( magnitude ) ) {
		*this	/= magnitude;
		return	( magnitude );
	}

	*this		= result_in_case_of_zero;
	return		( magnitude );
}

inline float2& float2_pod::abs					( )
{
	x			= math::abs( x );
	y			= math::abs( y );

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::min					( float2_pod const& other )
{
	x			= math::min( x, other.x );
	y			= math::min( y, other.y );

	return		( static_cast<float2&>(*this) );
}

inline float2& float2_pod::max					( float2_pod const& other )
{
	x			= math::max( x, other.x );
	y			= math::max( y, other.y );

	return		( static_cast<float2&>(*this) );
}

inline float2::type float2_pod::magnitude		( ) const
{
	return		( sqrt( square_magnitude( ) ) );
}

inline float2::type float2_pod::square_magnitude( ) const
{
	return		( sqr( x ) + sqr( y ) );
}

inline bool float2_pod::similar					( float2_pod const& other, float epsilon ) const
{
	if ( !math::similar( x, other.x, epsilon ) )
		return	( false );

	if ( !math::similar( y, other.y, epsilon ) )
		return	( false );

	return		( true );
}

inline bool float2_pod::valid					( ) const
{
	return		( math::valid( x ) && math::valid( y ) );
}

inline float2::float2							( ) 
{
	x			= SNaN;
	y			= SNaN;
}

inline float2::float2							( type const other_x, type const other_y )
{
	x			= other_x;
	y			= other_y;
}

inline float2::float2							( float2 const& other )
{
	x			= other.x;
	y			= other.y;
}

inline float2::float2							( float2_pod const& other )
{
	x			= other.x;
	y			= other.y;
}

inline float2 operator+							( float2_pod const& left, float2_pod const& right )
{
	return		( float2 ( left.x + right.x, left.y + right.y ) );
}

inline float2 operator+							( float2_pod const& left, float2_pod::type const& value )
{
	return		( float2 ( left.x + value, left.y + value ) );
}

inline float2 operator-							( float2_pod const& left, float2_pod const& right )
{
	return		( float2 ( left.x - right.x, left.y - right.y ) );
}

inline float2 operator-							( float2_pod const& left, float2_pod::type const& value )
{
	return		( float2 ( left.x - value, left.y - value ) );
}

inline float2 operator*							( float2_pod const& left, float2_pod::type const& value )
{
	return		( float2 ( left.x * value, left.y * value ) );
}

inline float2 operator*							( float2_pod::type const& value, float2_pod const& right )
{
	return		( float2 ( value * right.x , value * right.y ) );
}

inline float2 operator/							( float2_pod const& left, float2_pod::type const& value )
{
	ASSERT		( !is_zero( value ) );
	return		( float2 ( left.x / value, left.y / value ) );
}

inline float2 operator /						( float2_pod::type const& left, float2_pod const& right )
{
	ASSERT		( !is_zero( right.x ) );
	ASSERT		( !is_zero( right.y ) );

	return		( float2 ( left / right.x, left / right.y ) );
}

inline bool operator <							( float2_pod const& left, float2_pod const& right )
{
	return		( ( left.x < right.x ) && ( left.y < right.y ) );
}

inline bool operator <=							( float2_pod const& left, float2_pod const& right )
{
	return		( ( left.x <= right.x ) && ( left.y <= right.y ) );
}

inline bool operator >							( float2_pod const& left, float2_pod const& right )
{
	return		( ( left.x > right.x ) && ( left.y > right.y ) );
}

inline bool operator >=							( float2_pod const& left, float2_pod const& right )
{
	return		( ( left.x >= right.x ) && ( left.y >= right.y ) );
}

inline bool	operator !=							( float2_pod const& left, float2_pod const& right )
{
	return		!(left == right);
}

inline bool	operator ==							( float2_pod const& left, float2_pod const& right )
{
	return		( ( left.x == right.x ) && ( left.y == right.y ) );
}

inline float2::type dot_product					( float2_pod const& left, float2_pod const& right )
{
	return		( left.dot_product( right ) );
}

inline float2::type operator |					( float2_pod const& left, float2_pod const& right )
{
	return		( dot_product( left, right ) );
}

inline float2 cross_product						( float2_pod const& object )
{
	return		( float2( object.y, -object.x )  );
}

inline float2 normalize							( float2_pod const& object )
{
	float2::type const magnitude = object.magnitude( );
	ASSERT		( !is_zero( magnitude ) );
	return		( float2( object.x/magnitude, object.y/magnitude ) );
}

inline float2 normalize_safe					( float2_pod const& object, float2_pod const& result_in_case_of_zero )
{
	float2::type const magnitude = object.magnitude( );
	if ( !is_zero( magnitude ) )
		return	( float2( object.x/magnitude, object.y/magnitude ) );

	return		( float2( result_in_case_of_zero ) );
}

} // namespace math
} // namespace xray

#endif // #ifndef XRAY_MATH_FLOAT2_INLINE_H_INCLUDED