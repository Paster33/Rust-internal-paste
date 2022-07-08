#include "includes.h"
#include "shared/utl/sapphire_crt.hpp"
#include "impl/hooks/sapphire_hook.hpp"
#include "shared/utl/sapphire_importer.hpp"
#include "impl/hooks/hooks.hpp"
#include "kiero/minhook/include/MinHook.h"
#include <iostream>
#include "shared/utl/lazy_importer.hpp"
#include "settings.hpp"
#include "rust/features/visuals.hpp"
#include "setting.h"
#include <filesystem>

#pragma warning( disable : 4244 )


void embraceTheDarkness()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(8.00f, 8.00f);
	style.FramePadding = ImVec2(5.00f, 2.00f);
	style.ItemSpacing = ImVec2(6.00f, 6.00f);
	style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.FrameBorderSize = 1;
	style.TabBorderSize = 1;
	style.WindowRounding = 7;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;
	style.TabRounding = 4;
}

void customstyle()
{
	


}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool menuopen = true;

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


namespace ImGui {
	IMGUI_API  bool TabLabels(int numTabs, const char** tabLabels, int& selectedIndex, const char** tabLabelTooltips, bool autoLayout, int* pOptionalHoveredIndex) {
		ImGuiStyle& style = ImGui::GetStyle();

		const ImVec2 itemSpacing = style.ItemSpacing;
		const ImVec4 color = style.Colors[ImGuiCol_Button];
		const ImVec4 colorActive = style.Colors[ImGuiCol_ButtonActive];
		const ImVec4 colorHover = style.Colors[ImGuiCol_ButtonHovered];
		style.ItemSpacing.x = 1;
		style.ItemSpacing.y = 1;


		if (numTabs > 0 && (selectedIndex < 0 || selectedIndex >= numTabs)) selectedIndex = 0;
		if (pOptionalHoveredIndex) *pOptionalHoveredIndex = -1;

		// Parameters to adjust to make autolayout work as expected:----------
		// The correct values are probably the ones in the comments, but I took some margin so that they work well
		// with a (medium size) vertical scrollbar too [Ok I should detect its presence and use the appropriate values...].
		const float btnOffset = 2.f * style.FramePadding.x;   // [2.f*style.FramePadding.x] It should be: ImGui::Button(text).size.x = ImGui::CalcTextSize(text).x + btnOffset;
		const float sameLineOffset = 2.f * style.ItemSpacing.x;    // [style.ItemSpacing.x]      It should be: sameLineOffset = ImGui::SameLine().size.x;
		const float uniqueLineOffset = 2.f * style.WindowPadding.x;  // [style.WindowPadding.x]    Width to be sutracted by windowWidth to make it work.
		//--------------------------------------------------------------------

		float windowWidth = 0.f, sumX = 0.f;
		if (autoLayout) windowWidth = ImGui::GetWindowWidth() - uniqueLineOffset;

		bool selection_changed = false;
		for (int i = 0; i < numTabs; i++)
		{
			// push the style
			if (i == selectedIndex)
			{
				style.Colors[ImGuiCol_Button] = colorActive;
				style.Colors[ImGuiCol_ButtonActive] = colorActive;
				style.Colors[ImGuiCol_ButtonHovered] = colorActive;
			}
			else
			{
				style.Colors[ImGuiCol_Button] = color;
				style.Colors[ImGuiCol_ButtonActive] = colorActive;
				style.Colors[ImGuiCol_ButtonHovered] = colorHover;
			}

			ImGui::PushID(i);   // otherwise two tabs with the same name would clash.

			if (!autoLayout) { if (i > 0) ImGui::SameLine(); }
			else if (sumX > 0.f) {
				sumX += sameLineOffset;   // Maybe we can skip it if we use SameLine(0,0) below
				sumX += ImGui::CalcTextSize(tabLabels[i]).x + btnOffset;
				if (sumX > windowWidth) sumX = 0.f;
				else ImGui::SameLine();
			}

			// Draw the button
			if (ImGui::Button(tabLabels[i])) { selection_changed = (selectedIndex != i); selectedIndex = i; }
			if (autoLayout && sumX == 0.f) {
				// First element of a line
				sumX = ImGui::GetItemRectSize().x;
			}
			if (pOptionalHoveredIndex) {
				if (ImGui::IsItemHovered()) {
					*pOptionalHoveredIndex = i;
					if (tabLabelTooltips && tabLabelTooltips[i] && strlen(tabLabelTooltips[i]) > 0)  ImGui::SetTooltip("%s", tabLabelTooltips[i]);
				}
			}
			else if (tabLabelTooltips && tabLabelTooltips[i] && ImGui::IsItemHovered() && strlen(tabLabelTooltips[i]) > 0) ImGui::SetTooltip("%s", tabLabelTooltips[i]);
			ImGui::PopID();
		}

		// Restore the style
		style.Colors[ImGuiCol_Button] = color;
		style.Colors[ImGuiCol_ButtonActive] = colorActive;
		style.Colors[ImGuiCol_ButtonHovered] = colorHover;
		style.ItemSpacing = itemSpacing;

		return selection_changed;
	}
} // namespace ImGui


char pendingSettingsName[0x100];
bool bPendingSettingsSave = false;

void configsystem()
{
	size_t sz = 0;
	char* buf = nullptr;
	std::string lcDirectory;

	if (_dupenv_s(&buf, &sz, "APPDATA") == 0 && buf != nullptr)
	{
		lcDirectory = std::string(buf) + "\\SIPHON\\";

		if (!std::filesystem::exists(lcDirectory))
		{
			std::filesystem::create_directory(lcDirectory);
		}

		lcDirectory += "RUST\\";

		free(buf);
	}
	else
	{

	}

	if (std::filesystem::exists(lcDirectory))
	{
		if (!std::filesystem::exists(lcDirectory + std::string("Default.json")))
		{
			Settings::SaveSettings(lcDirectory + "Default.json");
		}
	}
	else
	{
		std::filesystem::create_directory(lcDirectory);
	}

	if (std::filesystem::exists(lcDirectory))
	{
		if (!std::filesystem::exists(lcDirectory + std::string("Default.json")))
		{
			Settings::SaveSettings(lcDirectory + "Default.json");
		}

		for (auto& p : std::filesystem::directory_iterator(lcDirectory))
		{
			auto path = p.path().generic_string();
			auto fileName = path.substr(path.find_last_of("/\\") + 1);
			std::string::size_type const p(fileName.find_last_of('.'));
			fileName = fileName.substr(0, p);

			bool hasNameBeenAdded = false;
			for (auto name : ConfigList)
			{
				if (strcmp(name.data(), fileName.c_str()) == 0)
				{
					hasNameBeenAdded = true;
				}
			}

			if (!hasNameBeenAdded)
			{
				ConfigList.push_back(fileName);
			}
		}
		ImGui::Begin("Config.wtf");
		ImGui::SetNextItemWidth(130);
		if (ImGui::BeginCombo("Setting Profiles", currentConfig.data()))
		{
			for (auto config : ConfigList)
			{
				bool is_selected = (config == currentConfig);
				if (ImGui::Selectable(config.data(), is_selected))
				{
					currentConfig = config;
					Settings::LoadSettings(config);
				}

				if (is_selected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}

			ImGui::EndCombo();
		}
	}
	else
	{
		std::filesystem::create_directory(lcDirectory);
	}
	if (bPendingSettingsSave)
	{
		ImGui::SetNextItemWidth(130);
		ImGui::InputText("Config Name", pendingSettingsName, IM_ARRAYSIZE(pendingSettingsName));
	}

	if (bPendingSettingsSave)
	{
		if (ImGui::Button("Confirm Save Config"))
		{
			bPendingSettingsSave = false;
			Settings::SaveSettings(lcDirectory + std::string(pendingSettingsName) + ".json");
			memset(pendingSettingsName, 0, 16);
		}
	}
	else
	{
		if (ImGui::Button("Save Config"))
		{
			bPendingSettingsSave = true;
		}

		ImGui::SameLine();

		if (ImGui::Button("Delete Config"))
		{


			if (DeleteFileA((lcDirectory + currentConfig + ".json").data()))
			{
				auto itr = std::find(ConfigList.begin(), ConfigList.end(), currentConfig);
				if (itr != ConfigList.end()) ConfigList.erase(itr);

				currentConfig = "DELETED";
			}
		}
	}
	ImGui::End();
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{


		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			Settings::LoadSettingsChar("Default");
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}
	
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	//if (GetAsyncKeyState(VK_HOME) < 0 && shift == false)
	//{
	//	shift = true;
	//}
	//if (GetAsyncKeyState(VK_HOME) == 0 && shift == true)
	//{
	//	shift = false;
	//}
	if (unity::get_keydown(unity::key_code::Home))
	{
		menuopen = !menuopen;
	}
	
	//if (unity::get_keydown(unity::key_code::Home))
	////if (GetKeyState(VK_HOME) & 0x8000)
	//{
	//	menuopen = !menuopen;
	//}

	if (menuopen)
	{
		static const char* tabNames[] = { "Visuals","Aimbot","Weapon","Misc" };
		static const int numTabs = sizeof(tabNames) / sizeof(tabNames[0]);
		static const char* tabTooltips[numTabs] = { "","","","" };
		static int selectedTab = 0;
		static int optionalHoveredTab = 0;
		//ImGui::Text("\nTab Page For Tab: \"%s\" here.\n", tabNames[selectedTab]);
		//if (optionalHoveredTab >= 0) ImGui::Text("Mouse is hovering Tab Label: \"%s\".\n\n", tabNames[optionalHoveredTab]);
		//embraceTheDarkness();
		embraceTheDarkness();

		configsystem();

		ImGui::Begin("Siphon.wtf");
		/*const bool tabSelectedChanged =*/ImGui::TabLabels(numTabs, tabNames, selectedTab, tabTooltips, true, &optionalHoveredTab);

		switch (selectedTab) {
		case 0:		

				ImGui::Checkbox("Name Esp", &settings::nameesp);
				ImGui::SameLine();
				ImGui::ColorEdit4("Name Color", settings::colors::NameColor, ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoLabel);
				ImGui::Checkbox("Weapon Esp", &settings::weaponesp);
				ImGui::SameLine();
				ImGui::ColorEdit4("Weapon Color", settings::colors::WeaponColor, ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoLabel);
				ImGui::Checkbox("Head Esp", &settings::headesp);
				ImGui::SameLine();
				ImGui::ColorEdit4("Head Color", settings::colors::HeadCircleColor, ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoLabel);
				ImGui::Checkbox("Box Esp", &settings::boxesp);
				ImGui::SameLine();
				ImGui::ColorEdit4("Box Color", settings::colors::BoxColor, ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoLabel);
				ImGui::Checkbox("Skeleton Esp", &settings::skeleton_esp);
				ImGui::SameLine();
				ImGui::ColorEdit4("Skeleton Color", settings::colors::SkeletonColor, ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoLabel);
				ImGui::SliderFloat("Thickness", &settings::skeletonthickness, 1, 2);
				ImGui::Checkbox("Health Esp", &settings::healthbar);
				ImGui::Checkbox("Filled Box Esp", &settings::filledbox);
				ImGui::NextColumn();
	
			
			break;
		case 1:
			
				ImGui::Checkbox("Silent Aim", &settings::silentaim);
				ImGui::Checkbox("Draw Fov", &settings::fovcircle);
				ImGui::SameLine();
				ImGui::ColorEdit4("Fov Color", settings::colors::FovCircleColor, ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_::ImGuiColorEditFlags_NoLabel);
				ImGui::SliderFloat("Fov", &settings::fov, 0, 999);
				ImGui::Checkbox("Pierce", &settings::pierce);
				ImGui::Checkbox("Magic Bullet", &settings::magicbullet);
			break;
		case 2:
				ImGui::Checkbox("No Recoil", &settings::norecoil);
				ImGui::SliderFloat("Recoil", &settings::recoil, 0, 100);
				ImGui::Checkbox("No Spread", &settings::nospread);
				ImGui::SliderFloat("Spread", &settings::spread, 0, 100);
				ImGui::Checkbox("Thick Bullet", &settings::thickbullet);
				ImGui::SliderFloat("Thickness", &settings::thickness, 0, 1);
			
			break;
		case 3:
			ImGui::Columns(2, nullptr, true);
			ImGui::SetColumnOffset(1, 200);
			{
				ImGui::Separator();
				ImGui::Text("Local");
				ImGui::Checkbox("Admin Mode", &settings::adminmode);
				ImGui::Checkbox("Nofall", &settings::nofall);
				ImGui::Checkbox("Always Attack", &settings::alwaysattack);
				ImGui::NextColumn();
				ImGui::Text("Movement");
				ImGui::Checkbox("Omni Sprint", &settings::omnisprint);
				ImGui::Checkbox("Infinite Jump", &settings::infinitejump);
				ImGui::Checkbox("Forcewield", &settings::forcewield);

				
				
			}
			
			break;
		default:
			break;
		};


		ImGui::End();
	}
	
	DrawList = ImGui::GetBackgroundDrawList();

	sapphire::features::visuals::object.run();

	if (settings::fovcircle)
	{
		DrawList->AddCircle({ 1920 / 2, 1080 / 2 }, settings::fov, ImColor(settings::colors::FovCircleColor[0] * 255, settings::colors::FovCircleColor[1] * 255, settings::colors::FovCircleColor[2] * 255, settings::colors::FovCircleColor[3] * 255), 30);
	}
	ImGui::Render();
	
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}


inline void InitHook() {
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) {
		std::cout << "Failed to initialize Hook" << std::endl;
		return;
	}
}

void HookFunction(void* Function, void** Original, void* Detour, bool autoEnable = true) {
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) { std::cout << ("Failed to initialize MinHook") << std::endl; return; }
	MH_CreateHook(Function, Detour, Original);
	if (autoEnable)
		MH_EnableHook(Function);
}

typedef bool(__fastcall* canholditems)(void*, void*);
inline canholditems original_canholditems;

typedef void(__fastcall* handleduckcrawl)(void*, void*,bool,bool,bool);
inline handleduckcrawl original_handleduckcrawl;

typedef bool(__fastcall* canattack)(void*);
inline canattack original_canattack;

typedef void(__fastcall* domovement)(rust::classes::c_projectile*,float);
inline domovement original_domovement;

typedef void(__fastcall* addpunch)(void*,math::vector_t, float);
inline addpunch original_addpunch;

typedef float(__fastcall* aimcone)(rust::classes::c_base_projectile*);
inline aimcone original_aimcone;

typedef void(__fastcall* timedlootaction)(rust::classes::c_ItemIcon*);
inline timedlootaction original_timedlootaction;

typedef bool(__fastcall* dohit)(rust::classes::c_projectile*, rust::classes::c_hittest*, math::vector_t, math::vector_t);
inline dohit original_dohit;

typedef bool(__fastcall* doricochet)(rust::classes::c_projectile*, rust::classes::c_hittest*, math::vector_t, math::vector_t);
inline doricochet original_doricochet;

typedef void(__fastcall* flintdoattack)(rust::classes::c_base_projectile*);
inline flintdoattack original_flintdoattack;

typedef void(__fastcall* handlejumping)(rust::classes::c_walk_movement*, rust::classes::c_model_state*, bool , bool );
inline handlejumping original_handlejumping;

typedef void(__fastcall* onland)(rust::classes::c_walk_movement*, float);
inline onland original_onland;

typedef void(__fastcall* pwminput)(rust::classes::c_walk_movement*, uintptr_t, rust::classes::c_model_state*);
inline pwminput original_pwm_input;

typedef void(__fastcall* bpinput)(rust::classes::c_base_player* , std::uintptr_t );
inline bpinput original_bp_input;

typedef math::vector_t(__fastcall* modaimcone)(float aimCone, math::vector_t, bool);
inline modaimcone original_modaimcone;

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);

			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}



bool __fastcall CanHoldItems(void* a1, void* a2) {

	if (settings::forcewield)
	{ 
		return true;
		}
		return original_canholditems(a1,a2);
}

void __fastcall HandleRunDuckCrawl(void* a1, void* a2, bool wantsRun, bool wantsDuck, bool wantsCrawl) 
{
	if (settings::omnisprint)
	{
		return original_handleduckcrawl(a1, a2, 5.5, wantsDuck, wantsCrawl);
	}

	return original_handleduckcrawl(a1, a2, wantsRun, wantsDuck, wantsCrawl);
}

bool __fastcall CanAttack(void* a1) {

	if (settings::alwaysattack)
	{
		return true;
	}

	return original_canattack(a1);
}
void __fastcall DoMovement(rust::classes::c_projectile* _this, float deltatime) {


	if (settings::magicbullet)
	{
		if (sapphire::features::aimbot::object.m_aim_target)
		{
			auto target_head = sapphire::features::aimbot::object.m_aim_target->get_bone_transform(48)->position();

			_this->currentPosition() = target_head;
		}
	}


	//
	/*if (settings::nospread)
	{
		if (_this->mod())
		{
			_this->mod()->projectileSpread() = 0;
			_this->mod()->projectileVelocitySpread() = 0;
		}
	}*/
	if (settings::thickbullet)
	{
		_this->thickness() = settings::thickness;
	}
	else
	{
		_this->thickness() = 0.0f;
	}

	return original_domovement(_this, deltatime);

}

void __fastcall AddPunch(void* _this, math::vector_t amount, float duration)
{
	if (settings::norecoil)
	{
		amount *= settings::recoil / 100.0f;
	}
	return original_addpunch(_this,amount,duration);

}

float weaponvel;
float weapongrav;

float __fastcall Aimcone(rust::classes::c_base_projectile* _this)
{

	//const auto stats = _this->get_stats(_this->get_item_definition_id());

	//weaponvel = stats.initial_velocity;
	//weapongrav = stats.gravity_modifier;
	//if (settings::nospread)
	//{
	//	float originalspread = original_aimcone(_this);

	//	float spread = originalspread *= settings::spread / 100.f;

	//	return originalspread;
	//}
	return original_aimcone(_this);
}

void __fastcall SetTimedLootAction(rust::classes::c_ItemIcon* icon)
{

	return original_timedlootaction(icon);
}

bool __fastcall DoHit(rust::classes::c_projectile* _this, rust::classes::c_hittest* test, math::vector_t point, math::vector_t normal) {


	if (settings::pierce)
	{
		if (test->get_gameobject()->get_layer() != layer::Player_Server)
		{
			return false;
		}
	}

	return original_dohit(_this, test, point, normal);

}

bool __fastcall DoRicochet(rust::classes::c_projectile* _this, rust::classes::c_hittest* test, math::vector_t point, math::vector_t normal) {


		return false;
}
void __fastcall FlintDoAttack(rust::classes::c_base_projectile* _this)
{
	_this->_didSparkThisFrame() = true;
	return original_flintdoattack(_this);
}


void __fastcall HandleJumping(rust::classes::c_walk_movement* _this, rust::classes::c_model_state* state, bool wantsJump, bool jumpInDirection = false)
{
	if (!settings::infinitejump)
	{
		 return original_handlejumping(_this, state, wantsJump, jumpInDirection);
	}
	SAPPHIRE_METHOD(jump_fn, "PlayerWalkMovement.Jump()", -1, "", -1, void(*)(rust::classes::c_walk_movement*, rust::classes::c_model_state*, bool));

	if (!wantsJump)
	{
		return;
	}

	jump_fn(_this, state, jumpInDirection);

	//return original_handlejumping(_this, state,wantsJump,jumpInDirection);
}

void __fastcall OnLand(rust::classes::c_walk_movement* _this, float fvelocity)
{
	if (!settings::nofall)
	{
		return original_onland(_this, fvelocity);
	}

	return;

}
void __fastcall pwm_client_input(rust::classes::c_walk_movement* movement, std::uintptr_t input_state, rust::classes::c_model_state* state)
{

	return original_pwm_input(movement, input_state, state);

	state->remove_flag(rust::enums::e_model_state_flag::flying);
}


double CalcBulletDrop(double height, double DepthPlayerTarget, float velocity, float gravity) {
	double pitch = (atan2f(height, DepthPlayerTarget));
	double BulletVelocityXY = velocity * cosf(pitch);
	double Time = DepthPlayerTarget / BulletVelocityXY;
	double TotalVerticalDrop = (0.5f * gravity * Time * Time);
	return TotalVerticalDrop * 10;
}
#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)
void Prediction(math::vector_t local, math::vector_t& target, math::vector_t targetvel, float bulletspeed, float gravity) {
	float Dist = local.distance3d(target);
	float BulletTime = Dist / bulletspeed;

	math::vector_t vel = math::vector_t(targetvel.x, 0, targetvel.z) * 0.75f;

	math::vector_t PredictVel = vel * BulletTime;

	target += PredictVel;

	double height = target.y - local.y;
	math::vector_t dir = target - local;
	float DepthPlayerTarget = sqrtf(powFFFFFFFFFFFFFFFFFFFFFF(dir.x) + powFFFFFFFFFFFFFFFFFFFFFF(dir.z));

	float drop = CalcBulletDrop(height, DepthPlayerTarget, bulletspeed, gravity);

	target.y += drop;
}


void __fastcall bp_client_input(rust::classes::c_base_player* base_player, std::uintptr_t input_state)
{
	if (base_player)
	{
		if (!sapphire::globals::local)
			sapphire::globals::local = base_player;

		sapphire::features::aimbot::object.find_aimbot_target();

		if (settings::adminmode)
			base_player->set_admin_flag(rust::enums::e_PlayerFlags::IsAdmin);
		/*if (settings::silentaim)
		{
			if (unity::get_key(unity::key_code::Mouse4))
			{
				if (sapphire::features::aimbot::object.m_aim_target)
				{
					auto localpos = base_player->eyes()->position();
					auto target_head = sapphire::features::aimbot::object.m_aim_target->get_bone_transform(48)->position();

					auto rotation = math::vec4_t::MyQuaternionLookRotation(target_head - localpos, math::vector_t(0, 1, 0));

					if (!localpos.is_empty() && !target_head.is_empty())
					{
						base_player->eyes()->Rotation() = rotation;
					}
				}
			}
		}*/
	}
	return original_bp_input(base_player, input_state);

}
weapon_stats_t get_stats(int32_t weapon_id) {

	float velocity = 0.f;
	float gravity_modifier = 0.f;


	switch (weapon_id) {
	case spear_wooden:
		velocity = 25;
		gravity_modifier = 2;

		break;
	case spear_stone:
		velocity = 30;
		gravity_modifier = 2;
		break;
	case ak47:
		velocity = 375;
		break;
	case iceak47:
		velocity = 375;
		break;
	case thompson:
		velocity = 300;
		break;
	case custom:
		velocity = 240;
		break;
	case python:
		velocity = 300;
		break;
	case l96:
		velocity = 1125;
		break;
	case bolt:
		velocity = 656;
		break;
	case lr300:
		velocity = 375;
		break;
	case hmlmg:
		velocity = 525;
		break;
	case m249:
		velocity = 488;
		break;
	case m39:
		velocity = 469;
		break;
	case m92:
		velocity = 300;
		break;
	case nailgun:
		velocity = 50;
		gravity_modifier = .75;
		break;
	case bow:
		velocity = 50;
		gravity_modifier = .75;
		break;
	case compoundbow:
		velocity = 50;
		gravity_modifier = .75;
		break;
	case crossbow:
		velocity = 75;
		gravity_modifier = .75;
		break;
	case semi_pistol:
		velocity = 300;
		break;
	case semi_rifle:
		velocity = 375;
		break;
	case revolver:
		velocity = 300;
		break;
	case pump_shotgun:
		velocity = 225;
		break;
	case eoka:
		velocity = 225;
		break;
	case waterpipe:
		velocity = 225;
		break;
	case spas12:
		velocity = 225;
		break;
	case double_barrel:
		velocity = 225;
		break;
	default:
		velocity = 9999;
		gravity_modifier = 0;
		break;



	}

	return { velocity, gravity_modifier };
}
math::vector_t __fastcall GetModifiedAimConeDirection(float aimCone, math::vector_t inputVec, bool anywhereInside = true)
{

	float originalspread = aimCone;

	float spread = originalspread *= settings::spread / 100.f;

	if (settings::silentaim)
	{
		if (unity::get_key(unity::key_code::Mouse4))
		{
			if (sapphire::globals::local)
			{
				
				if (auto eyes = sapphire::globals::local->eyes())
				{
					auto localpos = eyes->position();

					if (sapphire::features::aimbot::object.m_aim_target)
					{
						auto target_head = sapphire::features::aimbot::object.m_aim_target->get_bone_transform(48)->position();
						auto targetspeed = sapphire::features::aimbot::object.m_aim_target->velocity();

						if (auto baseprojectile = sapphire::globals::local->weapon())
						{
							if (baseprojectile->is_weapon())
							{
								auto itemid = baseprojectile->item_id();

								auto stats = get_stats(itemid);

								Prediction(localpos, target_head, targetspeed, stats.initial_velocity, stats.gravity_modifier);

								math::vector_t direction = math::vector_t(target_head.x - localpos.x, target_head.y - localpos.y, target_head.z - localpos.z);

								return original_modaimcone(spread, direction, anywhereInside);
							}
						}


					}
				}
			}
		}
	}

	if (settings::nospread)
	{
		return original_modaimcone(spread, inputVec, anywhereInside);
	}

	return original_modaimcone(aimCone, inputVec, anywhereInside);
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		il2cpp_lib::init();
		{
			uintptr_t game_assembly_base = LI_MODULE_SAFE_(L"GameAssembly.dll");
			//impl::hooks::bp_client_input.setup("BasePlayer.ClientInput()", &impl::hooks::hk_bp_client_input);
			//impl::hooks::pwm_client_input.setup("PlayerWalkMovement.ClientInput()", &impl::hooks::hk_pwm_client_input);

			//impl::hooks::launch_projectile.setup("BaseProjectile.LaunchProjectile()", &impl::hooks::hk_launch_projectile);
			//impl::hooks::on_attacked.setup("BasePlayer.OnAttacked()", &impl::hooks::hk_on_attacked);
			HookFunction((void*)(game_assembly_base + 0xA52F30), (void**)&original_canholditems, CanHoldItems); // public virtual bool CanHoldItems() { }
			HookFunction((void*)(game_assembly_base + 0xCF3AA0), (void**)&original_handleduckcrawl, HandleRunDuckCrawl); // private void HandleRunDuckCrawl(ModelState state, bool wantsRun, bool wantsDuck, bool wantsCrawl) { }
			HookFunction((void*)(game_assembly_base + 0x734190), (void**)&original_canattack, CanAttack); // public bool CanAttack() { }
			HookFunction((void*)(game_assembly_base + 0x84A7E0), (void**)&original_domovement, DoMovement); // private void DoMovement(float deltaTime) { }
			HookFunction((void*)(game_assembly_base + 0x5D7B50), (void**)&original_addpunch, AddPunch); // public virtual void AddPunch(Vector3 amount, float duration) { }
			HookFunction((void*)(game_assembly_base + 0x90D960), (void**)&original_aimcone, Aimcone); // public virtual float GetAimCone() { }
			//HookFunction((void*)(game_assembly_base + 0x8E9170), (void**)&original_timedlootaction, SetTimedLootAction);
			HookFunction((void*)(game_assembly_base + 0x84A0D0), (void**)&original_dohit, DoHit); // private bool DoHit(HitTest test, Vector3 point, Vector3 normal) { }
			HookFunction((void*)(game_assembly_base + 0x84B500), (void**)&original_doricochet, DoRicochet); // private bool DoRicochet(HitTest test, Vector3 point, Vector3 normal) { }
			HookFunction((void*)(game_assembly_base + 0x79F6B0), (void**)&original_flintdoattack, FlintDoAttack); // public override void DoAttack() { }
			HookFunction((void*)(game_assembly_base + 0xCF3970), (void**)&original_handlejumping, HandleJumping); // private void HandleJumping(ModelState state, bool wantsJump, bool jumpInDirection = False) { }
			HookFunction((void*)(game_assembly_base + 0x7459E0), (void**)&original_onland, OnLand); // public void OnLand(float fVelocity) { }
			HookFunction((void*)(game_assembly_base + 0xCF1A70), (void**)&original_pwm_input, pwm_client_input); // public override void ClientInput(InputState input, ModelState modelState) { }
			HookFunction((void*)(game_assembly_base + 0x7363D0), (void**)&original_bp_input, bp_client_input); // 0x7363D0
			HookFunction((void*)(game_assembly_base + 0xA6FF60), (void**)&original_modaimcone, GetModifiedAimConeDirection); // 0x7363D0
			
		}
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}