/*
 * vector2i.hpp
 *
 *  Created on: 2009-jun-12
 *      Author: Ali Mosavian
 */

#ifndef __VECTOR2I_HPP__
#define __VECTOR2I_HPP__

#include "common.h"

class Vector2i
{
public:
	sint32	m_x;
	sint32	m_y;

	/**
	 * Constructor
	 *
	 */
	Vector2i ( sint32 x = 0,
			   sint32 y = 0 )
	: m_x( x ),
	  m_y( y )
	{
	}

	/**
	 * Constructor
	 *
	 */
	Vector2i ( const Vector2i &v )
	: m_x( v.m_x ),
	  m_y( v.m_y )
	{
	}


	/**
	 * Add two vectors
	 *
	 */
	Vector2i operator + ( const Vector2i &v ) const
	{
		return Vector2i( m_x+v.m_x, m_y+v.m_y );
	}


	/**
	 * Subtract two vectors
	 *
	 */
	Vector2i operator - ( const Vector2i &v ) const
	{
		return Vector2i( m_x-v.m_x, m_y-v.m_y );
	}


	/**
	 * Per element multiplication
	 *
	 */
	Vector2i operator * ( const Vector2i &v ) const
	{
		return Vector2i( m_x*v.m_x, m_y*v.m_y );
	}


	/**
	 * Multiply with scalar
	 *
	 */
	Vector2i operator * ( sint32 s ) const
	{
		return Vector2i( m_x*s, m_y*s );
	}


	/**
	 * Divide by scalar
	 *
	 */
	Vector2i operator / ( sint32 s ) const
	{
		return Vector2i( m_x/s, m_y/s );
	}


	/**
	 * Divide with scalar
	 *
	 */
	Vector2i & operator /= ( sint32 s )
	{
		m_x /= s;
		m_y /= s;
		return *this;
	}


	/**
	 * Assignment
	 *
	 */
	Vector2i & operator = ( const Vector2i &v )
	{
		m_x = v.m_x;
		m_y = v.m_y;
		return *this;
	}

	sint32 dot ( const Vector2i &v ) const
	{
		return m_x*v.m_x+m_y*v.m_y;
	}

	sint32 length ( void ) const
	{
		return (sint32)sqrt( this->dot( *this ) );
	}

	sint32 cross ( const Vector2i &v ) const
	{
		return m_x*v.m_y - m_y*v.m_x;
	}
};

#endif /* VECTOR2I_HPP_ */
