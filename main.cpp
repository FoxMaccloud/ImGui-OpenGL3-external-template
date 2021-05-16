#include "menu.h"


int main()
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
	Sleep(1000);
	Menu::Shutdown();
	return 0;
}