#include "../ImGui DirectX 11 Kiero Hook/impl/hooks/hooks.hpp"


#pragma warning( disable : 4267 )


auto impl::hooks::hk_pwm_client_input(rust::classes::c_walk_movement* base_player, std::uintptr_t* input_state, rust::classes::c_model_state* state) -> void
{
	impl::hooks::pwm_client_input.get_original< decltype(&impl::hooks::hk_pwm_client_input) >()(base_player, input_state, state);


	state->remove_flag(rust::enums::e_model_state_flag::flying);
}