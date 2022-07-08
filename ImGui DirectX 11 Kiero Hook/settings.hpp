#pragma once
#include "includes.h"
#include <list>
#include <vector>
inline ImDrawList* DrawList;
inline std::string currentConfig = "Default";
inline std::vector<std::string> ConfigList = { "Default" };


namespace settings
{
	inline bool nospread;
	inline float spread;
	inline bool norecoil;
	inline float recoil;
	inline bool omnisprint;
	inline bool alwaysattack;
	inline bool pierce;
	inline bool magicbullet;
	inline bool thickbullet;
	inline float thickness;
	inline bool nameesp;
	inline bool weaponesp;
	inline bool boxesp;
	inline bool healthbar;
	inline bool headesp;
	inline bool fovcircle;
	inline float fov = 100;
	inline bool infinitejump;
	inline bool nofall;
	inline bool adminmode;
	inline bool skeleton_esp;
	inline float skeletonthickness = 1.4f;
	inline bool filledbox;
	inline bool silentaim;
	inline bool forcewield;
	namespace colors
	{
		inline float NameColor[] = { 1.f,1.f,1.f,1.f };
		inline float WeaponColor[] = { 1.f,1.f,1.f,1.f };
		inline float BoxColor[] = { 1.f,1.f,1.f,1.f };
		inline float HeadCircleColor[] = { 1.f,0.f,0.f,1.f };
		inline float SkeletonColor[] = { 1.f,0.f,0.f,1.f };
		inline float FovCircleColor[] = { 1.f,0.f,0.f,1.f };
	}
}