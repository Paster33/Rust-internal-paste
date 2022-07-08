#include "visuals.hpp"
#include "../../imgui/imgui.h"
#include "../../settings.hpp"

#pragma warning( disable : 4267 )

enum BoneList : int
{
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};

auto sapphire::features::c_visuals::run( ) -> void
{
	auto get_client_entities = [ & ]( ) { client_entities = il2cpp_lib::field( "BaseNetworkable", "clientEntities", false ); };

	if ( !client_entities )
		get_client_entities( );

	const auto entity_list = reinterpret_cast< managed_system::list_dictionary* >( client_entities );

	if ( !entity_list )
	{
		get_client_entities( );
		return;
	}

	const auto buffer = entity_list->buffer< std::uintptr_t >( );

	for ( size_t idx{ 0 }; idx <= entity_list->size( ); idx++ )
	{
		auto current_object = *reinterpret_cast< std::uintptr_t* >( buffer + 0x20 + ( idx * 0x8 ) );
		if ( !current_object )
			continue;

		auto base_object = *reinterpret_cast< std::uintptr_t* >( current_object + 0x10 );
		if ( !base_object )
			continue;

		auto object = *reinterpret_cast< std::uintptr_t* >( base_object + 0x30 );
		if ( !object )
			continue;

		const auto tag = *reinterpret_cast< std::uint16_t* >( object + 0x54 );
		if ( tag != 6 )
			continue;

		const auto ent = *reinterpret_cast< std::uintptr_t* >( base_object + 0x28 );
		if ( !ent )
			continue;

		const auto player = reinterpret_cast< rust::classes::c_base_player* >( ent );

		if (!player->playerModel())
			continue;

	//	if (player->npc())
	//		continue;

		if (player->is_local_player())
			continue;

		if ( player->sleeping( ) )
			continue;

		if (!player->alive())
			continue;

		render_player( player );
	}


	
}

inline void DrawBox(const math::vector_2d_t &vecStart, const math::vector_2d_t& vecEnd, ImU32 col, float thickness)
{
	DrawList->AddRect(ImVec2(vecStart.x, vecStart.y), ImVec2(vecStart.x + vecEnd.x, vecStart.y + vecEnd.y), col, 0, 0, thickness);
}

inline void DrawFilledBox(const math::vector_2d_t& vecStart, const math::vector_2d_t& vecEnd, ImU32 col, float thickness)
{
	DrawList->AddRectFilled(ImVec2(vecStart.x, vecStart.y), ImVec2(vecStart.x + vecEnd.x, vecStart.y + vecEnd.y), col, 0, 0);
}
inline void DrawFilledBox(const math::vector_2d_t& vecStart, const math::vector_2d_t& vecEnd, ImU32 col)
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(vecStart.x, vecStart.y), ImVec2(vecStart.x + vecEnd.x, vecStart.y + vecEnd.y), col);
}

void bone2bone(rust::classes::c_base_player* player, BoneList t1, BoneList t2)
{
	auto bone1 = player->get_bone_transform(t1);
	auto bone2 = player->get_bone_transform(t2);

	auto firstpos = unity::screen_transform(bone1->position());
	auto secondpos = unity::screen_transform(bone2->position());

	if (firstpos.is_empty() || secondpos.is_empty())
		return;


	DrawList->AddLine(ImVec2(firstpos.x, firstpos.y), ImVec2(secondpos.x, secondpos.y), ImColor(settings::colors::SkeletonColor[0] * 255, settings::colors::SkeletonColor[1] * 255, settings::colors::SkeletonColor[2] * 255, settings::colors::SkeletonColor[3] * 255), settings::skeletonthickness);
}


auto sapphire::features::c_visuals::render_player(rust::classes::c_base_player* player) -> void
{
	DrawList = ImGui::GetBackgroundDrawList();

	if (!DrawList)
		return;



	SAPPHIRE_METHOD(get_transform_fn, "UnityEngine::Component.get_transform()", 0, "", -1, rust::classes::c_transform * (*)(void*));

	auto transform = get_transform_fn(player);

	if (!transform)
		return;

	auto base_pos = unity::screen_transform(transform->position());
	auto head_pos = unity::screen_transform(player->get_bone_transform(48)->position());
	auto standing_pos = unity::screen_transform(transform->position() + math::vector_t{ 0, 1.9f, 0, });

	if (base_pos.is_empty() || head_pos.is_empty() || standing_pos.is_empty())
		return;
//
//

	if (settings::skeleton_esp)
	{


		//	bone2bone(player, 0, 0);
		bone2bone(player, BoneList::head, BoneList::spine4);
		bone2bone(player, BoneList::spine4, BoneList::l_upperarm);
		bone2bone(player, BoneList::spine4, BoneList::r_upperarm);
		bone2bone(player, BoneList::l_upperarm, BoneList::l_forearm);
		bone2bone(player, BoneList::r_upperarm, BoneList::r_forearm);
		bone2bone(player, BoneList::l_forearm, BoneList::l_hand);
		bone2bone(player, BoneList::r_forearm, BoneList::r_hand);
		bone2bone(player, BoneList::spine4, BoneList::pelvis);
		bone2bone(player, BoneList::pelvis, BoneList::l_knee);
		bone2bone(player, BoneList::pelvis, BoneList::r_knee);
		bone2bone(player, BoneList::r_knee, BoneList::r_foot);
		bone2bone(player, BoneList::l_knee, BoneList::l_foot);

	}

	if (settings::headesp)
	{
		auto jaw = unity::screen_transform(player->get_bone_transform(47)->position());

		DrawList->AddCircle({ jaw.x, jaw.y }, 8, ImColor(0,0,0), 15, settings::skeletonthickness);
		DrawList->AddCircle({ jaw.x, jaw.y }, 8, ImColor(settings::colors::HeadCircleColor[0] * 255, settings::colors::HeadCircleColor[1] * 255, settings::colors::HeadCircleColor[2] * 255, settings::colors::HeadCircleColor[3] * 255), 15, settings::skeletonthickness);
	}

	const auto box_width = (base_pos.y - standing_pos.y) * 0.45f;
	const auto box_height = (base_pos.y - head_pos.y) * 1.15f;

	const auto box = box_t{ { base_pos.x - box_width * 0.5f, base_pos.y - box_height  }, { box_width, box_height } };

	if (settings::filledbox)
	{
		DrawFilledBox(math::vector_2d_t(box.pos.x, box.pos.y), math::vector_2d_t(box.size.x, box.size.y), ImColor(0, 0, 0,50));
	}
	if (settings::boxesp)
	{
		DrawBox(math::vector_2d_t(box.pos.x - 1, box.pos.y - 1), math::vector_2d_t(box.size.x + 2, box.size.y + 2), ImColor(0, 0, 0), 1.f);
		DrawBox(math::vector_2d_t(box.pos.x, box.pos.y), math::vector_2d_t(box.size.x, box.size.y), ImColor(settings::colors::BoxColor[0] * 255, settings::colors::BoxColor[1] * 255, settings::colors::BoxColor[2] * 255, settings::colors::BoxColor[3] * 255), 1.f);
		DrawBox(math::vector_2d_t(box.pos.x + 1, box.pos.y + 1), math::vector_2d_t(box.size.x - 2, box.size.y - 2), ImColor(0, 0, 0), 1.f);
	}

	const auto npc = player->npc( );
	const auto health = box_t{ { box.pos.x - 5, box.pos.y + ( box.size.y - box.size.y * ( player->_health( ) ) / ( npc ? player->_maxHealth( ) : 100 ) ) }, { 2, box.size.y * ( player->_health( ) ) / ( npc ? player->_maxHealth( ) : 100 ) } };
	const auto health_bg = box_t{ { box.pos.x - 5, box.pos.y }, { 2, box.size.y } };

	if (settings::healthbar)
	{
		DrawFilledBox(math::vector_2d_t(health_bg.pos.x, health_bg.pos.y - 1), math::vector_2d_t(health_bg.size.x + 1, health_bg.size.y + 2), ImColor(0, 0, 0));
		DrawFilledBox(math::vector_2d_t(health.pos.x + 1, health.pos.y), math::vector_2d_t(health.size.x - 1, health.size.y), ImColor(135, 186, 49));

	}


	float textdistance = 0;
	if (auto name = player->name())
	{

		std::wstring NameW(name);
		std::string NameString(NameW.begin(), NameW.end());

			auto namesize = ImGui::CalcTextSize(NameString.c_str());

			if (settings::nameesp)
			{
				DrawList->AddText(ImVec2(box.pos.x + (box.size.x / 2) - namesize.x / 2 + 1, box.pos.y + 1 - namesize.y), ImColor(0, 0, 0), NameString.c_str());
				DrawList->AddText(ImVec2(box.pos.x + (box.size.x / 2) - namesize.x / 2, box.pos.y - namesize.y), ImColor(settings::colors::NameColor[0] * 255, settings::colors::NameColor[1] * 255, settings::colors::NameColor[2] * 255, settings::colors::NameColor[3] * 255), NameString.c_str());

				//textdistance += 12;
			}
	}

		if (auto weapon = player->weapon())
		{
			if (auto weaponname = weapon->name())
			{
				
					std::wstring NameWeapon(weaponname);
					std::string WeaponString(NameWeapon.begin(), NameWeapon.end());

					auto weaponsize = ImGui::CalcTextSize(WeaponString.c_str());
					if (settings::weaponesp)
					{

						DrawList->AddText(ImVec2(box.pos.x + (box.size.x / 2) - weaponsize.x / 2 + 1, box.pos.y + 1 + box.size.y), ImColor(0, 0, 0), WeaponString.c_str());
						DrawList->AddText(ImVec2(box.pos.x + (box.size.x / 2) - weaponsize.x / 2, box.pos.y + box.size.y), ImColor(settings::colors::WeaponColor[0] * 255, settings::colors::WeaponColor[1] * 255, settings::colors::WeaponColor[2] * 255, settings::colors::WeaponColor[3] * 255), WeaponString.c_str());
					//DrawList->AddText(ImVec2(box.pos.x + box.size.x + 3 + 1, box.pos.y + 1 + textdistance - 2), ImColor(0, 0, 0), WeaponString.c_str());
					//DrawList->AddText(ImVec2(box.pos.x + box.size.x + 3, box.pos.y + textdistance - 2), ImColor(255, 255, 255), WeaponString.c_str());
				}
			}
		}



}

