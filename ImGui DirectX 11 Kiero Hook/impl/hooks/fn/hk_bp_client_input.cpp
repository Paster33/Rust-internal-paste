#include "../hooks.hpp"
#include "../../../shared/chaiscript/system/chai_wrapper.hpp"
#include <thread>
#include "../../../settings.hpp"
#pragma warning( disable : 4267 )

static bool has_initialized{ false };

math::vector_t Cross(math::vector_t first_vec, math::vector_t second_vec)
{
	math::vector_t returnme = math::vector_t();
	returnme.x = first_vec.y * second_vec.z - first_vec.z * second_vec.y;
	returnme.y = first_vec.z * second_vec.x - first_vec.x * second_vec.z; //first_vec.x * second_vec.z - first_vec.z * second_vec.x;
	returnme.z = first_vec.x * second_vec.y - first_vec.y * second_vec.x;
	return returnme;
}

 math::vec4_t QuaternionLookRotation(math::vector_t forward, math::vector_t upDirection)
{
	math::vector_t up = upDirection;

	forward.Normalize();

	math::vector_t first_vec = forward.Normalize();;
	math::vector_t cross_value = Cross(up, first_vec);
	math::vector_t second_vec = cross_value.Normalize();
	math::vector_t third_vec = Cross(first_vec, second_vec);

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

auto impl::hooks::hk_bp_client_input( rust::classes::c_base_player* base_player, std::uintptr_t* input_state ) -> void
{
	if ( !has_initialized )
	{

		has_initialized = true;
	}



	//if ( base_player )
	//{
	//	if ( !sapphire::globals::local )
	//		sapphire::globals::local = base_player;

	//	sapphire::features::aimbot::object.find_aimbot_target( );

	//	if (settings::adminmode)
	//	base_player->set_admin_flag(rust::enums::e_PlayerFlags::IsAdmin);
	//	if (settings::silentaim)
	//	{
	//		if (unity::get_key(unity::key_code::Mouse4))
	//		{
	//			if (sapphire::features::aimbot::object.m_aim_target)
	//			{
	//				auto localpos = base_player->eyes()->position();
	//				auto target_head = sapphire::features::aimbot::object.m_aim_target->get_bone_transform(48)->position();

	//				auto rotation = QuaternionLookRotation(target_head - localpos, math::vector_t(0, 1, 0));

	//				base_player->eyes()->Rotation() = rotation;
	//			}
	//		}
	//	}
	//}

	impl::hooks::bp_client_input.get_original< decltype( &impl::hooks::hk_bp_client_input ) >( )( base_player, input_state );
}


