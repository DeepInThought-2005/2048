#include "Tool.h"

void scp(int x, int y)
{
	printf("\033[%d;%dH", y, x);
}

//定义隐藏光标函数
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void Fill(int x, int y, int width, int length, int color)
{
	scp(x, y);
	printf("\033[%dm", color);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf(" ");
		}
		scp(x, y + i);
	}
	printf("\033[0m");
}