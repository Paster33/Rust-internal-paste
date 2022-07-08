#pragma once
#include "include.hpp"

class rust::classes::c_model_state 
{
public:
	auto set_flag( rust::enums::e_model_state_flag flag ) -> void {
		int flags = *reinterpret_cast< int* >( this + 0x24 );
		*reinterpret_cast< int* >( this + 0x24 ) = flags |= ( int )flag;
	}

	void remove_flag(rust::enums::e_model_state_flag flag) {
		int flags = *reinterpret_cast<int*>((uintptr_t)this + 0x24);
		flags &= ~(int)flag;

		*reinterpret_cast<int*>((uintptr_t)this + 0x24) = flags;
	}
};