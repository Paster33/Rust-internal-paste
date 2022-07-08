#pragma once
#include "include.hpp"

class rust::classes::c_projectile {
public:
	DECLARE_MEMBER( math::vector_t, "Projectile", currentVelocity )
	DECLARE_MEMBER(math::vector_t, "Projectile", currentPosition)
	DECLARE_MEMBER( float, "Projectile", thickness ) 
	DECLARE_MEMBER( float, "Projectile", gravityModifier )
	DECLARE_MEMBER( float, "Projectile", drag )
	DECLARE_MEMBER(rust::classes::c_mod*, "Projectile", mod)
	
};

class rust::classes::c_mod
{
public:

	DECLARE_MEMBER(float, "ItemModProjectile", projectileSpread)
	DECLARE_MEMBER(float, "ItemModProjectile", projectileVelocitySpread)
};

class rust::classes::c_hittest
{
public:

	uintptr_t game_object() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x70);
	}
	DECLARE_MEMBER(rust::classes::c_transform*, "HitTest", HitTransform)
	DECLARE_MEMBER(managed_system::string*, "HitTest", HitMaterial)

	rust::classes::c_gameobject* get_gameobject()
	{
		auto gameObject = game_object();
		if (!gameObject)
			return nullptr;

		return *reinterpret_cast<rust::classes::c_gameobject**>(gameObject + 0x10);
	}
};