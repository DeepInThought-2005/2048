#include "Panel.h"

/* draw panel line*/
void dpl(int width, int length)
{
	scp(PANEL_X, PANEL_Y + 1);
	for (int i = 0; i < length; i++)
	{
		printf("┃");
		scp(PANEL_X, PANEL_Y + i + 1);
	}
	scp(PANEL_X + width, PANEL_Y + 1);
	for (int i = 0; i < length; i++)
	{
		printf("┃");
		scp(PANEL_X + width, PANEL_Y + i + 1);
	}
	scp(PANEL_X, PANEL_Y);
	for (int i = 0; i < width + 1; i++)
	{
		printf("━");
		for (int j = 1; j <= 3; j++) {
			if (i == PANEL_WIDTH / 4 * j) {
				printf("\b┳");
			}
		}
	}
	scp(PANEL_X, PANEL_Y + length);
	for (int i = 0; i < width + 1; i++)
	{
		printf("━");
		for (int j = 1; j <= 3; j++) {
			if (i == PANEL_WIDTH / 4 * j) {
				printf("\b┻");
			}
		}
	}
	scp(PANEL_X, PANEL_Y); printf("┏");
	scp(PANEL_X + width, PANEL_Y + length); printf("┛");
	scp(PANEL_X + width, PANEL_Y); printf("┓");
	scp(PANEL_X, PANEL_Y + length); printf("┗");
}

void dl()
{
	for (int i = 0; i < 3; i++)
	{
		scp(PANEL_X + 1, PANEL_Y + PANEL_LENGTH / 4 + (PANEL_LENGTH / 4) * i);
		for (int j = 0; j < PANEL_WIDTH - 1; j++)
		{
			printf("━");
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < PANEL_LENGTH - 1; j++)
		{
			scp(PANEL_X + PANEL_WIDTH / 4 + (PANEL_WIDTH / 4) * i, PANEL_Y + j + 1);
			printf("┃");

		}
	}
}

/* draw setting panel line*/
void dspl()
{
	for (int i = 0; i < S_PANEL_LENGTH; i++)
	{
		scp(PANEL_X, S_PANEL_Y + i);
		printf("║");
	}

	for (int i = 0; i < S_PANEL_LENGTH; i++)
	{
		scp(PANEL_X + PANEL_WIDTH, S_PANEL_Y + i);
		printf("║");
	}

	scp(PANEL_X, S_PANEL_Y);
	for (int i = 0; i < PANEL_WIDTH; i++)
	{
		printf("═");
	}

	scp(PANEL_X, S_PANEL_Y + S_PANEL_LENGTH);
	for (int i = 0; i < PANEL_WIDTH; i++)
	{
		printf("═");
	}

	scp(PANEL_X, S_PANEL_Y); printf("╔");
	scp(PANEL_X + PANEL_WIDTH, S_PANEL_Y); printf("╗");
	scp(PANEL_X, S_PANEL_Y + S_PANEL_LENGTH); printf("╚");
	scp(PANEL_X + PANEL_WIDTH, S_PANEL_Y + S_PANEL_LENGTH); printf("╝");
}

/* draw setting panel*/
void dsp()
{
	dspl();
	scp(PANEL_X + 2, S_PANEL_Y + 1);
	printf(" ↑上-W ←左-A ↓下-S →右-D");
	scp(PANEL_X + 2, S_PANEL_Y + 3);
	printf("  <ESC> 退出    Score: %d", score);
}

/* draw panel */
void dp()
{
	HideCursor();
	/* 画边线 */
	dpl(PANEL_WIDTH, PANEL_LENGTH);
	/* 画交叉线 */
	dl();
	/* 画控制面板 */
	dsp();
}

void menu()
{
	//Fill(PANEL_X, PANEL_Y, PANEL_WIDTH + 1, PANEL_LENGTH, 47, 33);
	scp(PANEL_X + PANEL_WIDTH / 2 - 4, PANEL_Y + PANEL_LENGTH / 2 - 1);
	printf("1-开始游戏");
	scp(PANEL_X + PANEL_WIDTH / 2 - 4, PANEL_Y + PANEL_LENGTH / 2 + 1);
	printf("2-退出程序");
	char choice = _getch();
	if (choice == '1')
	{
		system("cls");
		//Initnum();
		PlayGame();
	}
	else if (choice == '2')
	{
		system("cls");
		//Fill(PANEL_X, PANEL_Y, PANEL_WIDTH + 1, PANEL_LENGTH, 43, 33);
		scp(PANEL_X + PANEL_WIDTH / 2 - 6, PANEL_Y + PANEL_LENGTH / 2);
		printf("已退出游戏!");
		scp(PANEL_X + PANEL_WIDTH / 2 - 4, PANEL_Y + PANEL_LENGTH / 2 + 1);
		printf("欢迎下次再来!");
		scp(1, S_PANEL_Y + 10);
		exit(0);
	}
	else {
		menu();
	}
}