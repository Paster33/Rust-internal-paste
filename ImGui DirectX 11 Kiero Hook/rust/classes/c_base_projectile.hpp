#pragma once
#include "include.hpp"

// todo; put in own file

class c_magazine {
public:
	auto ammo_type( ) -> rust::classes::c_item_definition* {
		return *reinterpret_cast< rust::classes::c_item_definition** >( this + 0x20 );
	}
};

struct weapon_stats_t {
	float initial_velocity;
	float gravity_modifier;
};

enum weapon_types : int32_t {
	spear_stone = 1602646136,
	spear_wooden = 1540934679,
	snowball_gun = 1103488722,
	ak47 = 1545779598,
	lr300 = -1812555177,
	bolt = 1588298435,
	l96 = -778367295,
	m39 = -28201841,
	semi_rifle = -904863145,
	m249 = -2069578888,
	thompson = -1758372725,
	custom = 1796682209,
	mp5 = 1318558775,
	python = 1373971859,
	semi_pistol = 818877484,
	revolver = 649912614,
	m92 = -852563019,
	eoka = -75944661,
	nailgun = 1953903201,
	crossbow = 1965232394,
	compoundbow = 884424049,
	bow = 1443579727,
	pump_shotgun = 795371088,
	spas12 = -41440462,
	waterpipe = -1367281941,
	double_barrel = -765183617,
	iceak47 = -1335497659,
	hmlmg = -1214542497
};

class rust::classes::c_base_projectile 
{
public:
	DECLARE_MEMBER( bool, "BaseProjectile", automatic )
	DECLARE_MEMBER( float, "BaseProjectile", projectileVelocityScale )
	DECLARE_MEMBER( float, "BaseProjectile", aimCone )
	DECLARE_MEMBER( float, "BaseProjectile", hipAimCone )
	DECLARE_MEMBER( float, "BaseProjectile", aimConePenaltyMax )
	DECLARE_MEMBER( float, "BaseProjectile", aimconePenaltyPerShot )
	DECLARE_MEMBER( float, "BaseProjectile", stancePenaltyScale )
	DECLARE_MEMBER( float, "BaseProjectile", aimSway )
	DECLARE_MEMBER( float, "BaseProjectile", aimSwaySpeed )
	DECLARE_MEMBER(bool, "FlintStrikeWeapon", _didSparkThisFrame)
	DECLARE_MEMBER( c_magazine*, "BaseProjectile", primaryMagazine );

	auto list_size( ) -> std::uint32_t { return *reinterpret_cast< std::uint32_t* >( this + 0x18 ); }

	auto remove_recoil( ) -> void
	{
		SAPPHIRE_FIELD( "BaseProjectile", recoil );
		auto recoil_properties = *reinterpret_cast< std::uintptr_t* >( this + recoil );

		*reinterpret_cast< float* >( recoil_properties + 0x18 ) = 0.f;
		*reinterpret_cast< float* >( recoil_properties + 0x1C ) = 0.f;
		*reinterpret_cast< float* >( recoil_properties + 0x20 ) = 0.f;
		*reinterpret_cast< float* >( recoil_properties + 0x24 ) = 0.f;
	}

	auto remove_sway( ) -> void 
	{
		this->aimSway( ) = 0.f;
		this->aimSwaySpeed( ) = 0.f;
	}





	int32_t get_item_definition_id()
	{
		const auto     item_definition = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x20);
		if (!item_definition)
			return 0;

		return *reinterpret_cast<int32_t*>(item_definition + 0x18);
	}

	auto remove_spread( ) -> void 
	{
		this->aimCone( ) = 0.f;
		this->hipAimCone( ) = 0.f;
		this->aimConePenaltyMax( ) = 0.f;
		this->aimconePenaltyPerShot( ) = 0.f;
		this->aimconePenaltyPerShot( ) = 0.f;
	}
};