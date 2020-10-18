#pragma once

#include "Tool.h"
#include "Game.h"


#define PANEL_X 10
#define PANEL_Y 5
#define PANEL_WIDTH 32
#define PANEL_LENGTH 16
#define S_PANEL_Y PANEL_Y+PANEL_LENGTH+2
#define S_PANEL_LENGTH 4


/* draw panel line*/
void dpl(int width, int length);

/* draw line*/
void dl();

/* draw setting panel line*/
void dspl();

/* draw setting panel*/
void dsp();

/* draw panel*/
void dp();

/* menu */
void menu();