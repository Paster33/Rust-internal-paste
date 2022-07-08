#include <string>
#include "../hooks.hpp"
#include "../../../shared/chaiscript/system/chai_wrapper.hpp"

auto impl::hooks::hk_ddraw_ongui( std::uintptr_t rcx ) -> void
{
	sapphire::rendering::init( );

	SAPPHIRE_METHOD( get_current_event_fn, "UnityEngine::Event.get_current()", 0, "", -1, std::uintptr_t( * )( ) );
	SAPPHIRE_METHOD( get_type_fn, "UnityEngine::Event.get_type()", 0, "", -1, unity::event_type( * )( std::uintptr_t ) );

	const auto current = get_current_event_fn( );
	const auto event_type = get_type_fn( current );

	if ( event_type == unity::event_type::repaint )
	{
		sapphire::features::visuals::object.run( );

	}
}