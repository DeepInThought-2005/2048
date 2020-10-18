#pragma once
#include <time.h>
#include "Panel.h"

int nums[4][4];
int score;
int judge;
int jd; //judge direction

void Initnum();

void onemore();

void drawnum();

void control();

void PlayGame();

void empty();

void judgeLose();