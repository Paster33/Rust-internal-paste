#pragma once

namespace rust
{
	namespace enums
	{
		enum e_player_flags : int {
			unused_1 = ( 1 << 0 ),
			unused_2 = ( 1 << 1 ),
			is_admin = ( 1 << 2 ),
			receiving_snapshot = ( 1 << 3 ),
			sleeping = ( 1 << 4 ),
			spectating = ( 1 << 5 ),
			wounded = ( 1 << 6 ),
			is_developer = ( 1 << 7 ),
			connected = ( 1 << 8 ),
			third_person_viewmode = ( 1 << 10 ),
			eyes_viewmode = ( 1 << 11 ),
			chat_mute = ( 1 << 12 ),
			no_sprint = ( 1 << 13 ),
			aiming = ( 1 << 14 ),
			display_sash = ( 1 << 15 ),
			relaxed = ( 1 << 16 ),
			safe_zone = ( 1 << 17 ),
			server_fall = ( 1 << 18 ),
			workbench_1 = ( 1 << 20 ),
			workbench_2 = ( 1 << 21 ),
			workbench_3 = ( 1 << 22 ),
		};
		enum class e_PlayerFlags
		{
			Unused1 = 1,
			Unused2 = 2,
			IsAdmin = 4,
			ReceivingSnapshot = 8,
			Sleeping = 16,
			Spectating = 32,
			Wounded = 64,
			IsDeveloper = 128,
			Connected = 256,
			ThirdPersonViewmode = 1024,
			EyesViewmode = 2048,
			ChatMute = 4096,
			NoSprint = 8192,
			Aiming = 16384,
			DisplaySash = 32768,
			Relaxed = 65536,
			SafeZone = 131072,
			ServerFall = 262144,
			Workbench1 = 1048576,
			Workbench2 = 2097152,
			Workbench3 = 4194304,
		};
		enum class e_model_state_flag {
			ducked = 1,
			jumped = 2,
			on_ground = 4,
			sleeping = 8,
			sprinting = 16,
			on_ladder = 32,
			flying = 64,
			aiming = 128,
			prone = 256,
			mounted = 512,
			relaxed = 1024,
		};
	}
}