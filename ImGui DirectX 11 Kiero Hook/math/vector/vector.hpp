#pragma once
#include <cmath>
#include <cfloat>
#undef sqrtf

namespace math 
{
	struct vector_2d_t
	{
		float x, y;

		vector_2d_t( ) {}
		vector_2d_t( float x, float y ) : x( x ), y( y ) {}

		vector_2d_t operator-( const vector_2d_t& vector ) const
		{
			return vector_2d_t( x - vector.x, y - vector.y );
		}

		vector_2d_t& operator+=( const vector_2d_t& vector )
		{
			x += vector.x;
			y += vector.y;

			return *this;
		}
		vector_2d_t& operator-=( const vector_2d_t& vector )
		{
			x -= vector.x;
			y -= vector.y;

			return *this;
		}

		static float sqrtf( float number )
		{
			long        i;
			float       x2, y;
			const float threehalfs = 1.5F;

			x2 = number * 0.5F;
			y = number;
			i = *( long* )&y; // floating point bit level hacking [sic]
			i = 0x5f3759df - ( i >> 1 ); // Newton's approximation
			y = *( float* )&i;
			y = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
			y = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration

			return 1 / y;
		}

		inline float length( )
		{
			return sqrtf( ( x * x ) + ( y * y ) );
		}
	};

	struct vector_t
	{
		float x;
		float y;
		float z;

		vector_t( )
		{}

		vector_t( float x, float y, float z )
			: x( x ), y( y ), z( z )
		{}

		bool is_empty( ) { return x == 0 && y == 0 && z == 0; }

		static float sqrtf( float number )
		{
			long        i;
			float       x2, y;
			const float threehalfs = 1.5F;

			x2 = number * 0.5F;
			y = number;
			i = *( long* )&y; // floating point bit level hacking [sic]
			i = 0x5f3759df - ( i >> 1 ); // Newton's approximation
			y = *( float* )&i;
			y = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
			y = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration

			return 1 / y;
		}

		auto length( ) -> float { return sqrtf( ( x * x ) + ( y * y ) + ( z * z ) ); }
		auto length_2d( ) -> float { return sqrtf( ( x * x ) + ( z * z ) ); }

		template<typename T>
		T get_remainder( T val, T min, T max )
		{
			while ( val > max )
				val -= max * 2;
			while ( val < min )
				val += max * 2;
			return val;
		}

		auto clamp( ) -> vector_t
		{
			constexpr auto yaw_limit = static_cast< float >( 180 );
			constexpr auto pitch_limit = static_cast< float >( 90 );

			this->y = get_remainder( this->y, -yaw_limit, yaw_limit );
			this->x = get_remainder( this->x, -pitch_limit, pitch_limit );

			if ( this->x != this->x )
				this->x = 0;
			if ( this->y != this->y )
				this->y = 0;
			if ( this->z != this->z )
				this->z = 0;

			return *this;
		}

		auto dot( const vector_t& vector ) -> float { return x * vector.x + y * vector.y + z * vector.z; }

//#undef powf
#define _powf(n) (n)*(n)

		auto distance3d( const vector_t& vector ) -> float { return sqrtf( _powf( x - vector.x ) + _powf( y - vector.y ) + _powf( z - vector.z ) ); }
		auto distance( const vector_t& vector ) -> float { return sqrtf( ( x - vector.x ) * ( x - vector.x ) + ( y - vector.y ) * ( y - vector.y ) + ( z - vector.z ) * ( z - vector.z ) ); }

		vector_t normalized( ) {
			float len = length( );
			return vector_t( x / len, y / len, z / len );
		}
		inline vector_t Normalize()
		{
			float mag = length();
			if (mag > 0.00001f)
			{
				x = x / mag;
				y = y / mag;
				z = z / mag;
			}
			else
			{
				x = 0;
				y = 0;
				z = 0;
			}
			return *this;
		}

		 static vector_t MoveTowards(vector_t current, vector_t target, float maxDistanceDelta)
		{
			float num = target.x - current.x;
			float num2 = target.y - current.y;
			float num3 = target.z - current.z;
			float num4 = num * num + num2 * num2 + num3 * num3;
			bool flag = num4 == 0.f || (maxDistanceDelta >= 0.f && num4 <= maxDistanceDelta * maxDistanceDelta);
			vector_t result;
			if (flag)
			{
				result = target;
			}
			else
			{
				float num5 = (float)sqrtf((double)num4);
				result = vector_t(current.x + num / num5 * maxDistanceDelta, current.y + num2 / num5 * maxDistanceDelta, current.z + num3 / num5 * maxDistanceDelta);
			}
			return result;
		}

		vector_t& operator+=( const vector_t& vector )
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;

			return *this;
		}

		vector_t& operator-=( const vector_t& vector )
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;

			return *this;
		}

		vector_t& operator*=( float number )
		{
			x *= number;
			y *= number;
			z *= number;

			return *this;
		}

		vector_t& operator/=( float number )
		{
			x /= number;
			y /= number;
			z /= number;

			return *this;
		}

		bool operator==( const vector_t& vector ) const
		{
			return x == vector.x && y == vector.y && z == vector.z;
		}

		bool operator!=( const vector_t& vector ) const
		{
			return x != vector.x || y != vector.y || z != vector.z;
		}

		vector_t operator+( const vector_t& vector ) const
		{
			return vector_t( x + vector.x, y + vector.y, z + vector.z );
		}

		vector_t operator-( const vector_t& vector ) const
		{
			return vector_t( x - vector.x, y - vector.y, z - vector.z );
		}

		vector_t operator-( ) const
		{
			return vector_t( -x, -y, -z );
		}

		vector_t operator*( float number ) const
		{
			return vector_t( x * number, y * number, z * number );
		}

		vector_t operator/( float number ) const
		{
			return vector_t( x / number, y / number, z / number );
		}
	};

	class vec4_t
	{
	public:
		float x;
		float y;
		float z;
		float w;

		vec4_t( ) {}
		vec4_t( float x, float y, float z, float w ) : x( x ), y( y ), z( z ), w( w ) {}

		auto dot( const vec4_t& vector ) -> float { return x * vector.x + y * vector.y + z * vector.z + w * vector.w; }
		auto distance( const vec4_t& vector ) -> float { return sqrtf( ( x - vector.x ) * ( x - vector.x ) + ( y - vector.y ) * ( y - vector.y ) + ( z - vector.z ) * ( z - vector.z ) + ( w - vector.w ) * ( w - vector.w ) ); }

		static math::vector_t MyCross(math::vector_t first_vec, math::vector_t second_vec)
		{
			math::vector_t returnme = math::vector_t();
			returnme.x = first_vec.y * second_vec.z - first_vec.z * second_vec.y;
			returnme.y = first_vec.z * second_vec.x - first_vec.x * second_vec.z; //first_vec.x * second_vec.z - first_vec.z * second_vec.x;
			returnme.z = first_vec.x * second_vec.y - first_vec.y * second_vec.x;
			return returnme;
		}

		static math::vec4_t MyQuaternionLookRotation(math::vector_t forward, math::vector_t upDirection)
		{
			math::vector_t up = upDirection;

			forward.Normalize();

			math::vector_t first_vec = forward.Normalize();;
			math::vector_t cross_value = MyCross(up, first_vec);
			math::vector_t second_vec = cross_value.Normalize();
			math::vector_t third_vec = MyCross(first_vec, second_vec);

			float m00 = second_vec.x;
			float m01 = second_vec.y;
			float m02 = second_vec.z;

			float m10 = third_vec.x;
			float m11 = third_vec.y;
			float m12 = third_vec.z;

			float m20 = first_vec.x;
			float m21 = first_vec.y;
			float m22 = first_vec.z;

			float num8 = (m00 + m11) + m22;

			math::vec4_t quaternion = math::vec4_t();

			if (num8 > 0.f)
			{
				float num = sqrtf(num8 + 1.f);
				quaternion.w = num * 0.5f;
				num = 0.5f / num;
				quaternion.x = (m12 - m21) * num;
				quaternion.y = (m20 - m02) * num;
				quaternion.z = (m01 - m10) * num;
				return quaternion;
			}

			if ((m00 >= m11) && (m00 >= m22))
			{
				float num7 = sqrtf(((1.f + m00) - m11) - m22);
				float num4 = 0.5f / num7;
				quaternion.x = 0.5f * num7;
				quaternion.y = (m01 + m10) * num4;
				quaternion.z = (m02 + m20) * num4;
				quaternion.w = (m12 - m21) * num4;
				return quaternion;
			}
			if (m11 > m22)
			{
				float num6 = sqrtf(((1.f + m11) - m00) - m22);
				float num3 = 0.5f / num6;
				quaternion.x = (m10 + m01) * num3;
				quaternion.y = 0.5f * num6;
				quaternion.z = (m21 + m12) * num3;
				quaternion.w = (m20 - m02) * num3;
				return quaternion;
			}

			float num5 = sqrtf(((1.f + m22) - m00) - m11);
			float num2 = 0.5f / num5;
			quaternion.x = (m20 + m02) * num2;
			quaternion.y = (m21 + m12) * num2;
			quaternion.z = 0.5f * num5;
			quaternion.w = (m01 - m10) * num2;
			return quaternion;
		}
		

		bool operator==( const vec4_t& vector ) const
		{
			return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
		}

		bool operator!=( const vec4_t& vector ) const
		{
			return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
		}

		vec4_t operator+( const vec4_t& vector ) const
		{
			return vec4_t( x + vector.x, y + vector.y, z + vector.z, w + vector.w );
		}

		vec4_t operator-( const vec4_t& vector ) const
		{
			return vec4_t( x - vector.x, y - vector.y, z - vector.z, w - vector.w );
		}

		vec4_t operator-( ) const
		{
			return vec4_t( -x, -y, -z, -w );
		}

		vec4_t operator*( float number ) const
		{
			return vec4_t( x * number, y * number, z * number, w * number );
		}

		vec4_t operator/( float number ) const
		{
			return vec4_t( x / number, y / number, z / number, w / number );
		}

		vec4_t& operator+=( const vec4_t& vector )
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;
			w += vector.w;
			return *this;
		}

		vec4_t& operator-=( const vec4_t& vector )
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			w -= vector.w;
			return *this;
		}

		vec4_t& operator*=( float number )
		{
			x *= number;
			y *= number;
			z *= number;
			w *= number;
			return *this;
		}

		vec4_t& operator/=( float number )
		{
			x /= number;
			y /= number;
			z /= number;
			w /= number;
			return *this;
		}
	};
}