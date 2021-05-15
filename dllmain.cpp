// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>
#include "menu.h"

uintptr_t WINAPI MainThread(HMODULE hModule)
{
	Menu::Create();
	Menu::Initialize();
	while (true)
	{
		Menu::Render();
		if (GetAsyncKeyState(VK_DELETE) & 1)
		{
			break;
		}
	}
	Menu::Shutdown();
	Sleep(1000);
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL APIENTRY DllMain(
	HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}