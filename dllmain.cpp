#include "frame.h"

void steamhook()
{
	HWND fn_window = FindWindow(0, (L"Fortnite  "));

	// Initalize Steam hook

	auto address = Scanners::PatternScan(SteamHelper::GetSteamdModule(), xorthis("48 89 6C 24 18 48 89 74 24 20 41 56 48 83 EC 20 41 8B E8"));
	SteamHelper::InsertHook(address, (uintptr_t)present_hk, (long long*)&presenth);

	address = Scanners::PatternScan(SteamHelper::GetSteamdModule(), xorthis("48 89 6C 24 18 48 89 74 24 20 41 56 48 83 EC 20 41 8B E8"));
	SteamHelper::InsertHook(address, (uintptr_t)present_hk, (long long*)&resizeh);

	WindowProcess = (WNDPROC)SetWindowLongPtr(fn_window, GWLP_WNDPROC, (LONG_PTR)WndProc);
}
void sigs()
{
	Details.UWORLD = SDK::Utilities::Scanners::PatternScan(xorthis("48 8B 05 ? ? ? ? 4D 8B C2"));
	Details.UWORLD = RVA(Details.UWORLD, 7);

	if (!SDK::Utilities::valid_pointer(Details.UWORLD)) {
		SDK::Utilities::SpoofCall(MessageBoxA, (HWND)0, (LPCSTR)xorthis("UWORLD OUTDATED"), (LPCSTR)0, (UINT)0);
	}

	LineOfS = SDK::Utilities::Scanners::PatternScan(xorthis("E8 ? ? ? ? 48 8B 0D ? ? ? ? 33 D2 40 8A F8"));
	LineOfS = RVA(LineOfS, 5);
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		steamhook();
		sigs();
	}

	return TRUE;
}