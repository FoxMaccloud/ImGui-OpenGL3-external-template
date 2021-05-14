#pragma once
#ifndef MENU_H
#define MENU_H

#include <Windows.h>
#include <Psapi.h>

namespace Menu
{
	void Create();
	void Initialize();
	void Render();
	void Shutdown();
};

#endif