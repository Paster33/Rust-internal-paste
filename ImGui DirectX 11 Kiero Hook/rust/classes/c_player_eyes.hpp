#pragma once
#include "rust.hpp"

class rust::classes::c_player_eyes 
{
public:
	DECLARE_MEMBER( math::vector_t, "PlayerEyes", viewOffset )
	

	auto position( ) -> math::vector_t {
		SAPPHIRE_METHOD( get_position_fn, "PlayerEyes.get_position()", 0, "", -1, math::vector_t( * )( void* ) );
		return get_position_fn( this );
	}

	math::vec4_t& Rotation() {
		return *reinterpret_cast<math::vec4_t*>((uintptr_t)this + 0x44);
	}
};