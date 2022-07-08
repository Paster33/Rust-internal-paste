
#include "setting.h"
#include "settings.hpp"
#include "json.hpp"
#include <iosfwd>
#include <windows.h>



#include <fstream>
#include <iomanip>




using json = nlohmann::json;

void Settings::LoadSettingsChar(const char* path)
{
	return Settings::LoadSettings(path);
}

void Settings::LoadSettings(std::string configName)
{
	size_t sz = 0;
	char* buf = nullptr;
	std::string lcDirectory;

	if (_dupenv_s(&buf, &sz, "APPDATA") == 0 && buf != nullptr)
	{
		lcDirectory = std::string(buf) + "\\SIPHON\\RUST\\";
		free(buf);
	}
	std::string path = lcDirectory + configName + ".json";

	std::ifstream inputs(path);
	if (inputs.fail())
	{
		return;
	}
	json loadedSettings;
	inputs >> loadedSettings;
	inputs.close();

	
	

	if (loadedSettings.find("nospread") != loadedSettings.end())
		settings::nospread = loadedSettings["nospread"];
	if (loadedSettings.find("spread") != loadedSettings.end())
		settings::spread = loadedSettings["spread"];
	if (loadedSettings.find("norecoil") != loadedSettings.end())
		settings::norecoil = loadedSettings["norecoil"];
	if (loadedSettings.find("recoil") != loadedSettings.end())
		settings::recoil = loadedSettings["recoil"];
	if (loadedSettings.find("omnisprint") != loadedSettings.end())
		settings::omnisprint = loadedSettings["omnisprint"];
	if (loadedSettings.find("alwaysattack") != loadedSettings.end())
		settings::alwaysattack = loadedSettings["alwaysattack"];
	if (loadedSettings.find("pierce") != loadedSettings.end())
		settings::pierce = loadedSettings["pierce"];
	if (loadedSettings.find("magicbullet") != loadedSettings.end())
		settings::magicbullet = loadedSettings["magicbullet"];
	if (loadedSettings.find("thickbullet") != loadedSettings.end())
		settings::thickbullet = loadedSettings["thickbullet"];
	if (loadedSettings.find("thickness") != loadedSettings.end())
		settings::thickness = loadedSettings["thickness"];
	if (loadedSettings.find("nameesp") != loadedSettings.end())
		settings::nameesp = loadedSettings["nameesp"];
	if (loadedSettings.find("weaponesp") != loadedSettings.end())
		settings::weaponesp = loadedSettings["weaponesp"];
	if (loadedSettings.find("boxesp") != loadedSettings.end())
		settings::boxesp = loadedSettings["boxesp"];
	if (loadedSettings.find("healthbar") != loadedSettings.end())
		settings::healthbar = loadedSettings["healthbar"];
	if (loadedSettings.find("headesp") != loadedSettings.end())
		settings::headesp = loadedSettings["headesp"];
	if (loadedSettings.find("fovcircle") != loadedSettings.end())
		settings::fovcircle = loadedSettings["fovcircle"];
	if (loadedSettings.find("fov") != loadedSettings.end())
		settings::fov = loadedSettings["fov"];
	if (loadedSettings.find("infinitejump") != loadedSettings.end())
		settings::infinitejump = loadedSettings["infinitejump"];
	if (loadedSettings.find("nofall") != loadedSettings.end())
		settings::nofall = loadedSettings["nofall"];
	if (loadedSettings.find("adminmode") != loadedSettings.end())
		settings::adminmode = loadedSettings["adminmode"];
	if (loadedSettings.find("skeleton_esp") != loadedSettings.end())
		settings::skeleton_esp = loadedSettings["skeleton_esp"];
	if (loadedSettings.find("skeletonthickness") != loadedSettings.end())
		settings::skeletonthickness = loadedSettings["skeletonthickness"];
	if (loadedSettings.find("filledbox") != loadedSettings.end())
		settings::filledbox = loadedSettings["filledbox"];
	if (loadedSettings.find("silentaim") != loadedSettings.end())
		settings::silentaim = loadedSettings["silentaim"];
	if (loadedSettings.find("forcewield") != loadedSettings.end())
		settings::forcewield = loadedSettings["forcewield"];

	if (loadedSettings.find("boxcol0") != loadedSettings.end())
		settings::colors::BoxColor[0] = loadedSettings["boxcol0"];

	if (loadedSettings.find("boxcol1") != loadedSettings.end())
		settings::colors::BoxColor[1] = loadedSettings["boxcol1"];

	if (loadedSettings.find("boxcol2") != loadedSettings.end())
		settings::colors::BoxColor[2] = loadedSettings["boxcol2"];

	if (loadedSettings.find("boxcol3") != loadedSettings.end())
		settings::colors::BoxColor[3] = loadedSettings["boxcol3"];

	if (loadedSettings.find("namecol0") != loadedSettings.end())
		settings::colors::NameColor[0] = loadedSettings["namecol0"];

	if (loadedSettings.find("namecol1") != loadedSettings.end())
		settings::colors::NameColor[1] = loadedSettings["namecol1"];

	if (loadedSettings.find("namecol2") != loadedSettings.end())
		settings::colors::NameColor[2] = loadedSettings["namecol2"];

	if (loadedSettings.find("namecol3") != loadedSettings.end())
		settings::colors::NameColor[3] = loadedSettings["namecol3"];

	if (loadedSettings.find("weaponcol0") != loadedSettings.end())
		settings::colors::WeaponColor[0] = loadedSettings["weaponcol0"];

	if (loadedSettings.find("weaponcol1") != loadedSettings.end())
		settings::colors::WeaponColor[1] = loadedSettings["weaponcol1"];

	if (loadedSettings.find("weaponcol2") != loadedSettings.end())
		settings::colors::WeaponColor[2] = loadedSettings["weaponcol2"];

	if (loadedSettings.find("weaponcol3") != loadedSettings.end())
		settings::colors::WeaponColor[3] = loadedSettings["weaponcol3"];

	if (loadedSettings.find("skeletoncol0") != loadedSettings.end())
		settings::colors::SkeletonColor[0] = loadedSettings["skeletoncol0"];

	if (loadedSettings.find("skeletoncol1") != loadedSettings.end())
		settings::colors::SkeletonColor[1] = loadedSettings["skeletoncol1"];

	if (loadedSettings.find("skeletoncol2") != loadedSettings.end())
		settings::colors::SkeletonColor[2] = loadedSettings["skeletoncol2"];

	if (loadedSettings.find("skeletoncol3") != loadedSettings.end())
		settings::colors::SkeletonColor[3] = loadedSettings["skeletoncol3"];

	if (loadedSettings.find("headcirclecol0") != loadedSettings.end())
		settings::colors::HeadCircleColor[0] = loadedSettings["headcirclecol0"];

	if (loadedSettings.find("headcirclecol1") != loadedSettings.end())
		settings::colors::HeadCircleColor[1] = loadedSettings["headcirclecol1"];

	if (loadedSettings.find("headcirclecol2") != loadedSettings.end())
		settings::colors::HeadCircleColor[2] = loadedSettings["headcirclecol2"];

	if (loadedSettings.find("headcirclecol3") != loadedSettings.end())
		settings::colors::HeadCircleColor[3] = loadedSettings["headcirclecol3"];

	if (loadedSettings.find("fovcirclecol0") != loadedSettings.end())
		settings::colors::FovCircleColor[0] = loadedSettings["fovcirclecol0"];

	if (loadedSettings.find("fovcirclecol1") != loadedSettings.end())
		settings::colors::FovCircleColor[1] = loadedSettings["fovcirclecol1"];

	if (loadedSettings.find("fovcirclecol2") != loadedSettings.end())
		settings::colors::FovCircleColor[2] = loadedSettings["fovcirclecol2"];

	if (loadedSettings.find("fovcirclecol3") != loadedSettings.end())
		settings::colors::FovCircleColor[3] = loadedSettings["fovcirclecol3"];
}

void Settings::SaveSettings(std::string path)
{
	//Ulog("Saving to path %s", path.data());

	json settings;

	settings["nospread"] = settings::silentaim;
	settings["spread"] = settings::spread;
	settings["norecoil"] = settings::norecoil;
	settings["recoil"] = settings::recoil;
	settings["omnisprint"] = settings::omnisprint;
	settings["alwaysattack"] = settings::alwaysattack;
	settings["pierce"] = settings::pierce;
	settings["magicbullet"] = settings::magicbullet;
	settings["thickbullet"] = settings::thickbullet;
	settings["thickness"] = settings::thickness;
	settings["nameesp"] = settings::nameesp;
	settings["weaponesp"] = settings::weaponesp;
	settings["boxesp"] = settings::boxesp;
	settings["healthbar"] = settings::healthbar;
	settings["headesp"] = settings::headesp;
	settings["fovcircle"] = settings::fovcircle;
	settings["fov"] = settings::fov;
	settings["infinitejump"] = settings::infinitejump;
	settings["nofall"] = settings::nofall;
	settings["adminmode"] = settings::adminmode;
	settings["skeleton_esp"] = settings::skeleton_esp;
	settings["skeletonthickness"] = settings::skeletonthickness;
	settings["filledbox"] = settings::filledbox;
	settings["silentaim"] = settings::silentaim;
	settings["forcewield"] = settings::forcewield;
	settings["boxcol0"] = settings::colors::BoxColor[0];
	settings["boxcol1"] = settings::colors::BoxColor[1];
	settings["boxcol2"] = settings::colors::BoxColor[2];
	settings["boxcol3"] = settings::colors::BoxColor[3];

	settings["namecol0"] = settings::colors::NameColor[0];
	settings["namecol1"] = settings::colors::NameColor[1];
	settings["namecol2"] = settings::colors::NameColor[2];
	settings["namecol3"] = settings::colors::NameColor[3];

	settings["weaponcol0"] = settings::colors::WeaponColor[0];
	settings["weaponcol1"] = settings::colors::WeaponColor[1];
	settings["weaponcol2"] = settings::colors::WeaponColor[2];
	settings["weaponcol3"] = settings::colors::WeaponColor[3];

	settings["skeletoncol0"] = settings::colors::SkeletonColor[0];
	settings["skeletoncol1"] = settings::colors::SkeletonColor[1];
	settings["skeletoncol2"] = settings::colors::SkeletonColor[2];
	settings["skeletoncol3"] = settings::colors::SkeletonColor[3];

	settings["headcirclecol0"] = settings::colors::HeadCircleColor[0];
	settings["headcirclecol1"] = settings::colors::HeadCircleColor[1];
	settings["headcirclecol2"] = settings::colors::HeadCircleColor[2];
	settings["headcirclecol3"] = settings::colors::HeadCircleColor[3];

	settings["fovcirclecol0"] = settings::colors::FovCircleColor[0];
	settings["fovcirclecol1"] = settings::colors::FovCircleColor[1];
	settings["fovcirclecol2"] = settings::colors::FovCircleColor[2];
	settings["fovcirclecol3"] = settings::colors::FovCircleColor[3];
	
	std::ofstream output(path);
	output << std::setw(4) << settings << std::endl;
	output.close();
}