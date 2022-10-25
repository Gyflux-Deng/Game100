#include <stdio.h>
#include <stdlib.h>
#include "level1_test.h"

/*
-------------------------------------DEFINE--------------------------------------------------------------
*/
//boolean system
#define TRUE 1
#define FALSE 0
//set the size for the game map
#define GRID_SYSTEM_COLS 30
#define GRID_SYSTEM_ROWS 30
//dead = collisions
#define GRID_DEAD 0
//alive = no collision + number of tiles for enemies to count
#define GRID_ALIVE 1
//2d array
int gGrid[GRID_SYSTEM_COLS][GRID_SYSTEM_ROWS];


/*
-------------------------------------INITIALIZATION--------------------------------------------------------------
*/
void Level_1_Test_Init(void)
{
	//init timing to 0.
	levelTimer = 0.0;
	
	//init grid
	//set every grid alive. alive = nothing is on the grid 
	for (int row = 0; row < GRID_SYSTEM_ROWS; ++row)
	{
		for (int col = 0; col < GRID_SYSTEM_COLS; ++col)
		{
			gGrid[row][col] = GRID_ALIVE;
		}

	}
	gridHeight = CP_System_GetDisplayHeight() / GRID_SYSTEM_ROWS;
	gridWidth = CP_System_GetDisplayWidth() / GRID_SYSTEM_COLS;
}

/*
-------------------------------------GRIDSYSTEM--------------------------------------------------------------
*/
void Level_1_Grid_System(void)
{

	
}

/*
-------------------------------------INPUT------------------------------------------------------------------
*/
void Level_1_Userinput_System(void)
{
	// temporary exit back to main menu
	// main implementation will be via the pause menu
	if (CP_Input_KeyDown(KEY_Q))
	{
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}
/*
-------------------------------------GAME LOGIC-------------------------------------------------------------
*/
void Level_1_Gamelogic_System(void)
{
	levelTimer += CP_System_GetDt();
}
/*
-------------------------------------RENDERING--------------------------------------------------------------
*/
void Level_1_Render_System(void)
{
	
	//rendering the grid so i can have a rough image on how many grid in the game
	//draw everything from corner
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_RectMode(CP_POSITION_CORNER);
	for (int row = 0; row < GRID_SYSTEM_ROWS; ++row)
	{
		for (int col = 0; col < GRID_SYSTEM_COLS; ++col)
		{
			if (gGrid[row][col] == GRID_ALIVE)
			{
				CP_Graphics_DrawRect(row * gridWidth, col * gridHeight, gridWidth, gridHeight);
			}
		}
	}
	// TODO: placeholder background image for the level
	// render level timer for testing purposes
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Settings_TextSize(30.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	//CP_Font_DrawText("Time: ", CP_System_GetWindowWidth() - 150, 100);
	char buffer[50] = { 0 };
	sprintf_s(buffer, _countof(buffer), "Time: %.2f", levelTimer);
	CP_Font_DrawText(buffer, CP_System_GetWindowWidth() - 150, 100);

}
/*
-------------------------------------UPDATE--------------------------------------------------------------
*/
void Level_1_Test_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(50, 50, 0, 255));
	Level_1_Userinput_System();
	Level_1_Gamelogic_System();
	Level_1_Render_System();	
}
/*
-------------------------------------EXIT--------------------------------------------------------------
*/
void Level_1_Test_Exit(void)
{

}
