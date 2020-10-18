#include "Game.h"

void Initnum()
{
	srand((unsigned)time(NULL));
	int i, j = 0;
	for (int k = 0; k < 2; k++)
	{
		i = rand() % 4;
		j = rand() % 4;
		do {
			nums[i][j] = rand() % 5;
		} while (nums[i][j] == 3 || nums[i][j] == 1 || nums[i][j] == 0);
	}
}

void drawnum() 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nums[i][j] < 100) {
				if (nums[i][j] == 2)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 43);
					printf("\033[43;37m");
				}
				else if(nums[i][j] == 4)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 42);
					printf("\033[42;37m");
				}
				else if (nums[i][j] == 8)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 46);
					printf("\033[46;37m");
				}
				else if (nums[i][j] == 16)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 44);
					printf("\033[44;37m");
				}
				else if(nums[i][j] == 32)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 45);
					printf("\033[45;37m");
				}
				else if (nums[i][j] == 64)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 41);
					printf("\033[41;37m");
				}
				else if (nums[i][j] == 128)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 40);
					printf("\033[40;37m");
				}
				scp(PANEL_X + 4 + i * PANEL_WIDTH / 4, PANEL_Y + 2 + j * PANEL_LENGTH / 4);
				printf("%d", nums[i][j]);
				printf("\033[47;34m");
				if (nums[i][j] == 0)
				{
					printf("\b ");
				}
			}
			else if (nums[i][j] > 100) {
				if (nums[i][j] == 2)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 43);
					printf("\033[43;37m");
				}
				else if (nums[i][j] == 4)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 42);
					printf("\033[42;37m");
				}
				else if (nums[i][j] == 8)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 46);
					printf("\033[46;37m");
				}
				else if (nums[i][j] == 16)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 44);
					printf("\033[44;37m");
				}
				else if (nums[i][j] == 32)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 45);
					printf("\033[45;37m");
				}
				else if (nums[i][j] == 64)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 41);
					printf("\033[41;37m");
				}
				else if (nums[i][j] == 128)
				{
					Fill(PANEL_X + PANEL_WIDTH / 4 * i + 2, PANEL_Y + PANEL_LENGTH / 4 * j + 1, PANEL_WIDTH / 4 - 2, PANEL_LENGTH / 4, 40);
					printf("\033[40;37m");
				}
				scp(PANEL_X + 3 + i * PANEL_WIDTH / 4, PANEL_Y + 2 + j * PANEL_LENGTH / 4);
				printf("%d", nums[i][j]);
				printf("\033[47;35m");
				if (nums[i][j] == 0)
				{
					printf("\b ");
				}
			}
		}
	}
}

void control()
{
	jd = 0;
	char dir = _getch();
	switch (dir)
	{
	case 75:
	case 'a'://←
		for (int i = 3; i > 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				if (nums[i][j] != nums[i - 1][j])
				{
					if (nums[i][j] != 0 && nums[i - 1][j] != 0)
					{
						jd += 1;
					}	
				}
			}
		}
		if (jd == 12)
		{
			control();
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 4; j++)
			{
				if (nums[j][i] == nums[j - 1][i])
				{
					nums[j - 1][i] *= 2;
					nums[j][i] = 0;
					score += nums[j - 1][i];
				}
			}
		}
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 3; j > 0; j--)
				{
					if (nums[j - 1][i] == 0)
					{
						nums[j - 1][i] = nums[j][i];
						nums[j][i] = 0;
					}
				}
			}
		}
		
		break;
	case 72:
	case 'w'://↑
		for (int i = 3; i > 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				if (nums[j][i] != nums[j][i - 1])
				{
					if (nums[j][i] != 0 && nums[j][i - 1] != 0) {
						jd += 1;
					}
				}
			}
		}
		if (jd == 12)
		{
			control();
		}
		for (int j = 0; j < 4; j++) {
			for (int i = 1; i < 4; i++)
			{
				if (nums[j][i] == nums[j][i - 1])
				{
					nums[j][i - 1] *= 2;
					nums[j][i] = 0;
					score += nums[j][i - 1];
				}
			}
		}
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 4; j++) {
				for (int i = 3; i > 0; i--)
				{
					if (nums[j][i - 1] == 0)
					{
						nums[j][i - 1] = nums[j][i];
						nums[j][i] = 0;
					}
				}
			}
		}
		
		break;
	case 77:
	case 'd'://→
		for (int i = 2; i >= 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				if (nums[i][j] != nums[i + 1][j])
				{
					if (nums[i][j] != 0 && nums[i + 1][j] != 0) {
						jd += 1;
					}
				}
			}
		}
		if (jd == 12)
		{
			control();
		}
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j < 4; j++)
			{
				if (nums[i + 1][j] == nums[i][j]) {
					nums[i + 1][j] *= 2;
					nums[i][j] = 0;
					score += nums[i + 1][j];
				}
			}
		}
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 3; j++)
				{
					if (nums[j + 1][i] == 0)
					{
						nums[j + 1][i] = nums[j][i];
						nums[j][i] = 0;
					}
				}
			}
		}
		
		break;
	case 80:
	case 's'://↓
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (nums[j][i] != nums[j][i + 1])
				{
					if (nums[j][i] != 0 && nums[j][i + 1]) {
						jd += 1;
					}
				}
			}
		}
		if (jd == 12)
		{
			control();
		}
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j < 4; j++)
			{
				if (nums[j][i] == nums[j][i + 1]) {
					nums[j][i + 1] *= 2;
					nums[j][i] = 0;
					score += nums[j][i + 1];
				}
			}
		}
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 3; i++)
				{
					if (nums[j][i + 1] == 0)
					{
						nums[j][i + 1] = nums[j][i];
						nums[j][i] = 0;
					}
				}
			}
		}
		
		break;
	case 27:
		system("cls");
		menu();
		break;
	default:
		control();
	}
	
}

void onemore()
{
	int i, j = 0;
	i = rand() % 4;
	j =    rand() % 4;
	while(nums[i][j] != 0){
		i = rand() % 4;
		j = rand() % 4;
	}
	do {
		nums[i][j] = rand() % 4 + 1;
	} while (nums[i][j] == 3 || nums[i][j] == 1);
}

void judgeLose()
{
	judge = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nums[i][j] != nums[i + 1][j])
			{
				if (nums[i][j] != 0 || nums[i + 1][j] != 0) {
					judge += 1;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nums[j][i] != nums[j][i + 1])
			{
				if (nums[j][i] != 0 && nums[j][i + 1] != 0) {
					judge += 1;
				}
			}
		}
	}
	if (judge == 24)
	{
		drawnum();
		Sleep(3000);
		system("cls");
		//Fill(PANEL_X, PANEL_Y, PANEL_WIDTH + 1, PANEL_LENGTH + 1, 47, 33);
		scp(PANEL_X + PANEL_WIDTH / 2 - 4, PANEL_Y + PANEL_LENGTH / 2);
		printf("游戏结束！");
		scp(PANEL_X + PANEL_WIDTH - 16, PANEL_Y + PANEL_LENGTH - 1);
		printf("按任意键继续...");
		Sleep(2000);
		_getch();
		system("cls");
		empty();
		Initnum();
		menu();
	}
}

void empty()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			nums[i][j] = 0;
		}
	}
}

void PlayGame()
{	
	while (1)
	{
			
		dp();
		drawnum();
		control();	
		onemore();
		judgeLose();
		system("cls");
	}
}

