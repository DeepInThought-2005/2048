#include "Tool.h"
#include "Panel.h"
#include "Game.h"

int main()
{
	SetConsoleTitle(L"2048中文版");
	system("mode con cols=52 lines=28 ");
	system("COLOR 79");
	Initnum();
	PlayGame();
	return 0;
}