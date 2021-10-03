#include "utilitys.h"
#include "sdk.h"
#include "OnlyLoop.h"
//#include "handler.h"
ID3D11Device* device = nullptr;
ID3D11DeviceContext* immediateContext = nullptr;
ID3D11RenderTargetView* renderTargetView = nullptr;

HRESULT(*presenth)(IDXGISwapChain* swapChain, UINT syncInterval, UINT flags) = nullptr;
HRESULT(*resizeh)(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) = nullptr;

WNDPROC WindowProcess = NULL;
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

HWND hwnd = NULL;

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam) && settings::menu)
	{
		return true;
	}
	return CallWindowProc(WindowProcess, hWnd, msg, wParam, lParam);
}



ImVec2 p;

static int tabs = 1;
namespace SettingsColor {
	float FovCircle_float[4] = { 255, 231, 94, 255 };
	ImColor FovCircle = ImColor(255, 231, 94, 255);



	//Players ESP VISIBLE
	float Box_float[4] = { 255, 231, 94, 255 };
	ImColor Box = ImColor(255, 231, 94, 255);

	float Skeleton_float[4] = { 255, 231, 94, 255 };
	ImColor Skeleton = ImColor(255, 231, 94, 255);

	float Distance_float[4] = { 255, 231, 94, 255 };
	ImColor Distance = ImColor(255, 231, 94, 255);

	float Snaplines_float[4] = { 255, 231, 94, 255 };
	ImColor Snaplines = ImColor(255, 231, 94, 255);

	float Box_notvisible_float[4] = { 255, 231, 94, 255 };
	ImColor Box_notvisible = ImColor(255, 231, 94, 255);

	float Skeleton_notvisible_float[4] = { 255, 231, 94, 255 };
	ImColor Skeleton_notvisible = ImColor(255, 231, 94, 255);

	float Distance_notvisible_float[4] = { 255, 231, 94, 255 };
	ImColor Distance_notvisible = ImColor(255, 231, 94, 255);

	float Snaplines_notvisible_float[4] = { 255, 231, 94, 255 };
	ImColor Snaplines_notvisible = ImColor(255, 231, 94, 255);


	//Loot ESP

	float ChestESP_float[4] = { 255, 231, 94, 255 };
	ImColor ChestESP = ImColor(255, 231, 94, 255);

	float AmmoBox_float[4] = { 255, 231, 94, 255 };
	ImColor AmmoBox = ImColor(255, 231, 94, 255);

	float LootESP_float[4] = { 255, 231, 94, 255 };
	ImColor LootESP = ImColor(255, 231, 94, 255);

	float LLamaESP_float[4] = { 255, 231, 94, 255 };
	ImColor LLamaESP = ImColor(255, 231, 94, 255);

	float VehicleESP_float[4] = { 255, 231, 94, 255 };
	ImColor VehicleESP = ImColor(255, 231, 94, 255);
}
struct Config
{
	void CheatLoverz();
	void BypassAC();
	void Applecheats();
	void MakFN();
	void CWIN();
	void Vegeance();
};
Config g_Config;
namespace Render
{
	struct vec_2
	{
		int x, y;
	};

	struct Colors
	{
		ImColor red = { 255, 0, 0, 255 };
		ImColor green = { 0, 255, 0, 255 };
		ImColor blue = { 0, 136, 255, 255 };
		ImColor aqua_blue = { 0, 255, 255, 255 };
		ImColor cyan = { 0, 210, 210, 255 };
		ImColor royal_purple = { 102, 0, 255, 255 };
		ImColor dark_pink = { 255, 0, 174, 255 };
		ImColor black = { 0, 0, 0, 255 };
		ImColor white = { 255, 255, 255, 255 };
		ImColor purple = { 255, 0, 255, 255 };
		ImColor yellow = { 255, 255, 0, 255 };
		ImColor orange = { 255, 140, 0, 255 };
		ImColor gold = { 234, 255, 0, 255 };
		ImColor royal_blue = { 0, 30, 255, 255 };
		ImColor dark_red = { 150, 5, 5, 255 };
		ImColor dark_green = { 5, 150, 5, 255 };
		ImColor dark_blue = { 100, 100, 255, 255 };
		ImColor navy_blue = { 0, 73, 168, 255 };
		ImColor light_gray = { 200, 200, 200, 255 };
		ImColor dark_gray = { 150, 150, 150, 255 };
	};
	Colors color;

	void Text(int posx, int posy, ImColor clr, const char* text)
	{
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx, posy), ImColor(clr), text);
	}

	void OutlinedText(int posx, int posy, ImColor clr, const char* text)
	{
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx - 1, posy - 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx - 1, posy - 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx, posy), ImColor(clr), text);
	}

	void ShadowText(int posx, int posy, ImColor clr, const char* text)
	{
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 2), ImColor(0, 0, 0, 200), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 2), ImColor(0, 0, 0, 200), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx, posy), ImColor(clr), text);
	}

	void Rect(int x, int y, int w, int h, ImColor color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0, thickness);
	}

	void RectFilledGradient(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void RectFilled(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void Checkbox(const char* v, bool* option, float x, float y, const char* title)
	{
		ImGui::SetCursorPos({ x, y });
		ImGui::Checkbox(v, option);

		p = ImGui::GetWindowPos();

		ImGui::SetCursorPos({ x + 2, y - 20 });
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 245, 245)));
		ImGui::Text(title);
		ImGui::PopStyleColor();

		Render::RectFilled(p.x + x + 3, p.y + y + 3, 16, 16, ImColor(200, 200, 200));

		if (*option)
		{
			Render::RectFilled(p.x + x + 7, p.y + y + 7, 8, 8, ImColor(0, 0, 0, 255));
		}
	}

	void Slider(const char* v, float* option, float x, float y, float min, float max, const char* title)
	{
		ImGui::SetCursorPos({ x, y });
		ImGui::SliderFloat(v, option, min, max);

		ImGui::SetCursorPos({ x + 2, y - 20 });
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 245, 245)));
		ImGui::Text(title);
		ImGui::PopStyleColor();
	}

	void Tab(const char* v, float size_x, float size_y, static int tab_name, int tab_next)
	{
		if (ImGui::Button(v, ImVec2{ size_x, size_y })) tab_name = tab_next;
	}
}

namespace PS
{
	void CL_ToggleButton(const char* v, bool* option, float x, float y, float x2)
	{
		ImGui::SetCursorPos({ x + x2, y });

		ImVec2 pos = ImGui::GetWindowPos();
		float height = 20;
		float width = 40;

		if (ImGui::Button(v, ImVec2{ width, height }))
			*option = !*option;

		Render::Rect(pos.x + x + x2, pos.y + y, 40, 20, ImColor(50, 50, 50), 2);
		Render::RectFilled(pos.x + x + x2, pos.y + y, 40, 20, ImColor(100, 100, 100, 255));
		Render::ShadowText(pos.x + x - 5, pos.y + y, ImColor(255, 187, 0, 200), v);

		if (*option)
		{
			Render::RectFilled(pos.x + x + x2, pos.y + y, 20, 20, ImColor(0, 200, 0, 255));
		}
		else
		{
			Render::RectFilled(pos.x + x + 20 + x2, pos.y + y, 20, 20, ImColor(200, 0, 0, 255));
		}
	}

	void CL_Tab(const char* v, int tab_next, float x, float y)
	{
		ImGui::SetCursorPos({ x, y });
		if (ImGui::Button(v, ImVec2(120, 35))) tabs = tab_next;

		ImVec2 pos = ImGui::GetWindowPos();
		Render::RectFilled(pos.x + x, pos.y + y, 120, 35, ImColor(1, 133, 182, 255));
		Render::Rect(pos.x + x, pos.y + y, 120, 35, ImColor(0, 67, 91, 255), 2);
		Render::ShadowText(pos.x + x + 33, pos.y + y + 6, ImColor(255, 187, 0, 200), v);
	}

	void CL_Slider(const char* v, float* option, float x, float y, float min, float max, const char* title)
	{
		ImGui::SetCursorPos({ x, y });
		ImGui::SliderFloat(v, option, min, max);

		ImGui::SetCursorPos({ x + 2, y - 20 });
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 245, 245)));
		ImGui::Text(title);
		ImGui::PopStyleColor();
	}

	///////////////////////////////////////

	void AC_Checkbox(const char* v, bool* option, float x, float y, const char* title)
	{
		ImGui::SetCursorPos({ x, y });
		ImGui::Checkbox(v, option);

		p = ImGui::GetWindowPos();

		ImGui::SetCursorPos({ x + 2, y - 20 });
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 0, 0, 255)));
		ImGui::Text(title);
		ImGui::PopStyleColor();

		Render::RectFilled(p.x + x + 3, p.y + y + 3, 16, 16, ImColor(200, 200, 200));
		Render::Text(p.x + x + 28, p.y + y + 2, ImColor(0, 0, 0, 255), v);

		if (*option)
		{
			Render::RectFilled(p.x + x + 7, p.y + y + 7, 8, 8, ImColor(0, 0, 0, 255));
		}
	}

	void AC_Tab(const char* v, int tab_next, float x, float y)
	{
		ImGui::SetCursorPos({ x, y });
		if (ImGui::Button(v, ImVec2(140, 30))) tabs = tab_next;

		ImVec2 pos = ImGui::GetWindowPos();
		Render::RectFilled(pos.x + x, pos.y + y, 140, 30, ImColor(234, 234, 234, 255));
		Render::Rect(pos.x + x, pos.y + y, 140, 30, ImColor(175, 175, 175, 255), 1);
		Render::Text(pos.x + x + 48, pos.y + y + 6, ImColor(0, 0, 0, 255), v);
	}
}





































void gui()

{
	if (GetAsyncKeyState(VK_F8) & 1)
	{
		settings::menu = !settings::menu;
	}
	if (GetAsyncKeyState(VK_F7) & 1)
	{
		settings::ColorAdjuster = !settings::ColorAdjuster;
	}

	if (settings::menu)
	{

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_WindowBg] = ImColor(1, 133, 182, 255);
		colors[ImGuiCol_Button] = ImColor();
		colors[ImGuiCol_ButtonActive] = ImColor();
		colors[ImGuiCol_ButtonHovered] = ImColor();
		colors[ImGuiCol_FrameBg] = ImColor();
		colors[ImGuiCol_FrameBgHovered] = ImColor();
		colors[ImGuiCol_FrameBgActive] = ImColor();

		ImGuiStyle* style = &ImGui::GetStyle();
		style->WindowPadding = ImVec2(15, 15);
		style->WindowRounding = 0.0f;
		style->FramePadding = ImVec2(2, 2);
		style->FrameRounding = 0.0f;
		style->ItemSpacing = ImVec2(8, 8);
		style->ItemInnerSpacing = ImVec2(8, 6);
		style->IndentSpacing = 25.0f;
		style->ScrollbarSize = 15.0f;
		style->ScrollbarRounding = 0.0f;
		style->GrabMinSize = 10.0f;
		style->GrabRounding = 0.0f;
		style->ChildRounding = 0.f;

		style->WindowTitleAlign.x = 0.50f;
		style->FrameRounding = 2.0f;




		if (settings::ColorAdjuster)
		{
			if (ImGui::Begin(xorthis("color adjuster"), 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize))
			{
				ImGui::SetWindowPos(ImVec2(700, 50), ImGuiCond_FirstUseEver);
				//	ImGui::SeparatorRainbow(color_red, color_green, color_blue);

				ImGui::Columns(1, NULL, false);

				ImGui::Text(xorthis("colors"));
				ImGui::BeginChild(xorthis("##config_colors"), ImVec2(530, 350), true);

				ImGui::ColorEdit4(xorthis("##BoxESPvis"), SettingsColor::Box_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorthis("##BoxESPnotvis"), SettingsColor::Box_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Box Visible / Not Visible");
				ImGui::ColorEdit4(xorthis("##SkeletonESPvis"), SettingsColor::Skeleton_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorthis("##SkeletonESPnotvis"), SettingsColor::Skeleton_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Skeleton Visible / Not Visible");
				ImGui::ColorEdit4(xorthis("##DistanceESPvis"), SettingsColor::Distance_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorthis("##DistanceESPnotvis"), SettingsColor::Distance_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Distance Visible / Not Visible");
				ImGui::ColorEdit4(xorthis("##Snaplinesvis"), SettingsColor::Snaplines_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::ColorEdit4(xorthis("##Snaplinesnotvis"), SettingsColor::Snaplines_notvisible_float, ImGuiColorEditFlags_NoInputs); ImGui::SameLine(); ImGui::Text("Snaplines Visible / Not Visible");

				ImGui::ColorEdit4(xorthis("Chest ESP"), SettingsColor::ChestESP_float, ImGuiColorEditFlags_NoInputs);
				ImGui::ColorEdit4(xorthis("AmmoBox ESP"), SettingsColor::AmmoBox_float, ImGuiColorEditFlags_NoInputs);
				ImGui::ColorEdit4(xorthis("Loot ESP"), SettingsColor::LootESP_float, ImGuiColorEditFlags_NoInputs);
				ImGui::ColorEdit4(xorthis("LLama ESP"), SettingsColor::LLamaESP_float, ImGuiColorEditFlags_NoInputs);
				ImGui::ColorEdit4(xorthis("Vehicle ESP"), SettingsColor::VehicleESP_float, ImGuiColorEditFlags_NoInputs);

				ImGui::ColorEdit4(xorthis("Fov Circle"), SettingsColor::FovCircle_float, ImGuiColorEditFlags_NoInputs);










				SettingsColor::FovCircle = ImColor(SettingsColor::FovCircle_float[0], SettingsColor::FovCircle_float[1], SettingsColor::FovCircle_float[2], SettingsColor::FovCircle_float[3]);


				//PlayersESP colors
				SettingsColor::Box = ImColor(SettingsColor::Box_float[0], SettingsColor::Box_float[1], SettingsColor::Box_float[2], SettingsColor::Box_float[3]);
				SettingsColor::Skeleton = ImColor(SettingsColor::Skeleton_float[0], SettingsColor::Skeleton_float[1], SettingsColor::Skeleton_float[2], SettingsColor::Skeleton_float[3]);
				SettingsColor::Distance = ImColor(SettingsColor::Distance_float[0], SettingsColor::Distance_float[1], SettingsColor::Distance_float[2], SettingsColor::Distance_float[3]);
				SettingsColor::Snaplines = ImColor(SettingsColor::Snaplines_float[0], SettingsColor::Snaplines_float[1], SettingsColor::Snaplines_float[2], SettingsColor::Snaplines_float[3]);

				SettingsColor::Box_notvisible = ImColor(SettingsColor::Box_notvisible_float[0], SettingsColor::Box_notvisible_float[1], SettingsColor::Box_notvisible_float[2], SettingsColor::Box_notvisible_float[3]);
				SettingsColor::Skeleton_notvisible = ImColor(SettingsColor::Skeleton_notvisible_float[0], SettingsColor::Skeleton_notvisible_float[1], SettingsColor::Skeleton_notvisible_float[2], SettingsColor::Skeleton_notvisible_float[3]);
				SettingsColor::Distance_notvisible = ImColor(SettingsColor::Distance_notvisible_float[0], SettingsColor::Distance_notvisible_float[1], SettingsColor::Distance_notvisible_float[2], SettingsColor::Distance_notvisible_float[3]);
				SettingsColor::Snaplines_notvisible = ImColor(SettingsColor::Snaplines_notvisible_float[0], SettingsColor::Snaplines_notvisible_float[1], SettingsColor::Snaplines_notvisible_float[2], SettingsColor::Snaplines_notvisible_float[3]);



				//LootESP colors
				SettingsColor::ChestESP = ImColor(SettingsColor::ChestESP_float[0], SettingsColor::ChestESP_float[1], SettingsColor::ChestESP_float[2], SettingsColor::ChestESP_float[3]);
				SettingsColor::AmmoBox = ImColor(SettingsColor::AmmoBox_float[0], SettingsColor::AmmoBox_float[1], SettingsColor::AmmoBox_float[2], SettingsColor::AmmoBox_float[3]);
				SettingsColor::LootESP = ImColor(SettingsColor::LootESP_float[0], SettingsColor::LootESP_float[1], SettingsColor::LootESP_float[2], SettingsColor::LootESP_float[3]);
				SettingsColor::LLamaESP = ImColor(SettingsColor::LLamaESP_float[0], SettingsColor::LLamaESP_float[1], SettingsColor::LLamaESP_float[2], SettingsColor::LLamaESP_float[3]);
				SettingsColor::VehicleESP = ImColor(SettingsColor::VehicleESP_float[0], SettingsColor::VehicleESP_float[1], SettingsColor::VehicleESP_float[2], SettingsColor::VehicleESP_float[3]);



				ImGui::EndChild();
				ImGui::End();
			}
		}
















		ImGui::SetNextWindowSize({ 520, 580 });
		ImGui::Begin("##CheatLoverz", NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

		p = ImGui::GetWindowPos();

		Render::ShadowText(p.x + 8, p.y + 5, ImColor(255, 187, 0, 200), "Cheetos Remake CL l FREE VERSION");

		Render::Rect(p.x, p.y, 520, 580, ImColor(0, 67, 91, 255), 2);
		Render::RectFilled(p.x + 10, p.y + 70, 500, 500, ImColor(0, 67, 91));

		PS::CL_Tab("Visuals", 1, 10, 30);
		PS::CL_Tab("Aimbot", 2, 140, 30);
	    //PS::CL_Tab("Mods", 3, 388, 30);
		PS::CL_Tab("Exploits", 4, 260, 30);

		if (tabs == 1) // VISUALS
		{
			PS::CL_ToggleButton("Characters ESP", &settings::corner, 25, 80, 400);
			PS::CL_ToggleButton("Skeleton ESP", &settings::bones, 25, 110, 400);
			PS::CL_ToggleButton("Distance ESP", &settings::Distance, 25, 140, 400);
			PS::CL_ToggleButton("Loot ESP", &settings::chest, 25, 170, 400);
			PS::CL_ToggleButton("Lines ESP", &settings::Lines, 25, 200, 400);
			PS::CL_ToggleButton("Vehicles ESP", &settings::Vehicles, 25, 230, 400);


			//PS::CL_ToggleButton("Characters ESP", &settings::corner, 25, 80, 400);
			//PS::CL_ToggleButton("Distance ESP", &settings::Distance, 25, 80, 400);
			//PS::CL_ToggleButton("Lines ESP", &settings::Lines, 25, 80, 400);
			//PS::CL_ToggleButton("Vehicles ESP", &settings::Vehicles, 25, 80, 400);
			//PS::CL_ToggleButton("Skeleton ESP", &settings::bones, 25, 110, 400);
			////PS::CL_ToggleButton("Skeleton Only Behind Walls", &settings::vischeck, 25, 140, 400);
			//PS::CL_ToggleButton("Loot ESP", &settings::chest, 25, 170, 400);
		}


		if (tabs == 2) // AIMBOT
		{
			PS::CL_ToggleButton("Aimbot", &settings::aimbot, 25, 80, 400);
			PS::CL_ToggleButton("Silent Mode", &settings::silentaim, 25, 110, 400);
			PS::CL_ToggleButton("FOV CIRCLE", &settings::aimbotfov, 25, 140, 400);
			PS::CL_Slider("FOV Slider", &settings::radius, 38, 200, 90, 150, " Aimbot Fov");
			PS::CL_Slider("FOV Slider", &settings::smoothing, 38, 230, 90, 150, "Aimbot Smooth");
		}



		//if (tabs == 3) // MISC
		//{
			//PS::CL_ToggleButton("Rapid Fire", &settings::Rapid_Fire, 25, 80, 400);
			//PS::CL_ToggleButton("No Bloom", &settings::No_Bloom, 25, 110, 400);
			//PS::CL_ToggleButton("Instant Revive", &settings::InstaRevive, 25, 140, 400);
			//PS::CL_ToggleButton("Aim in air", &settings::AimAir, 25, 170, 400);
			//PS::CL_ToggleButton("Aimbot", &settings::corner, 25, 200, 400);
			//PS::CL_ToggleButton("Animations disable", &settings::NoAnimation, 25, 230, 400);
			//PS::CL_ToggleButton("Instant Reload", &settings::InstaReload, 25, 260, 400);




			//Render::ShadowText(p.x + 100, p.y + 100, ImColor(255, 255, 255, 255), "all credits go too: lil peep no cap kuh!");
		//}


if (tabs == 4) // MISC
{
	PS::CL_ToggleButton("Rapid Fire", &settings::Rapid_Fire, 25, 80, 400);
	PS::CL_ToggleButton("No Bloom", &settings::No_Bloom, 25, 110, 400);
	PS::CL_ToggleButton("Instant Revive", &settings::InstaRevive, 25, 140, 400);
	PS::CL_ToggleButton("Aim while jumping", &settings::AimAir, 25, 200, 400);
	PS::CL_ToggleButton("Animations disable", &settings::NoAnimation, 25, 230, 400);
	PS::CL_ToggleButton("Instant Reload", &settings::InstaReload, 25, 260, 400);




	//Render::ShadowText(p.x + 100, p.y + 100, ImColor(255, 255, 255, 255), "all credits go too: lil peep no cap kuh!");
}

ImGui::End();
//ImGui::EndFrame();
	}
}


float X1 = GetSystemMetrics(0) / 2 - 1;
float Y1 = GetSystemMetrics(1) / 2 - 1;

HRESULT present_hk(IDXGISwapChain* swapchain, UINT sync, UINT flags)
{
	if (!device)
	{
		ID3D11Texture2D* renderTarget = 0;
		ID3D11Texture2D* backBuffer = 0;
		D3D11_TEXTURE2D_DESC backBufferDesc = { 0 };
		swapchain->GetDevice(__uuidof(device), (PVOID*)&device);
		device->GetImmediateContext(&immediateContext);

		swapchain->GetBuffer(0, __uuidof(renderTarget), (PVOID*)&renderTarget);
		device->CreateRenderTargetView(renderTarget, nullptr, &renderTargetView);
		renderTarget->Release();
		swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (PVOID*)&backBuffer);
		backBuffer->GetDesc(&backBufferDesc);

		Screen_X = backBufferDesc.Width;
		Screen_Y = backBufferDesc.Height;

		backBuffer->Release();
		if (!hwnd)
		{
			hwnd = FindWindowW(L"UnrealWindow", L"Fortnite  ");

			if (!hwnd)
				hwnd = GetForegroundWindow();
		}

		ImGuiIO& io = ImGui::GetIO(); (void)io;

		X = (float)backBufferDesc.Width;
		Y = (float)backBufferDesc.Height;

		io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 18);

		ImGui_ImplDX11_Init(hwnd, device, immediateContext);
		ImGui_ImplDX11_CreateDeviceObjects();
	}
	immediateContext->OMSetRenderTargets(1, &renderTargetView, nullptr);
	auto& window = Scene::CreateScene();

	gui();
	SetLoop::PlayersLoop(window);
	if (settings::aimbotfov)
	{
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(X1, Y1), settings::radius, ImColor(255, 255, 255, 210), 100, 1);
	}
	if (settings::menu)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImGui::GetIO().MousePos, ImVec2(ImGui::GetIO().MousePos.x + 7.f, ImGui::GetIO().MousePos.y + 7.f), ImColor(92, 52, 235));
	}

	Scene::DestroyScene(window);
	return presenth(swapchain, sync, flags);
}

HRESULT resize_hk(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) {
	ImGui_ImplDX11_Shutdown();
	renderTargetView->Release();
	immediateContext->Release();
	device->Release();
	device = nullptr;
	return resizeh(swapChain, bufferCount, width, height, newFormat, swapChainFlags);
}

ImGuiWindow& Scene::CreateScene() {
	ImGui_ImplDX11_NewFrame();
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	ImGui::Begin(("##"), nullptr, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar);

	auto& io = ImGui::GetIO();
	ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);

	return *ImGui::GetCurrentWindow();
}

VOID Scene::DestroyScene(ImGuiWindow& window) {
	window.DrawList->PushClipRectFullScreen();
	ImGui::End();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
	ImGui::Render();
}