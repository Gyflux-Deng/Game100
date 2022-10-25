#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#include "utils.h"
#include "mainmenu.h"
#include "level1_test.h"
#include "settings.h"
#include "credits.h"


int n = 0;

void Main_Menu_Init()
{	
	
}

void Main_Menu_Update()
{
	CP_Color backgroundColor = CP_Color_Create(128, 128, 128, 255);
	CP_Graphics_ClearBackground(backgroundColor);
	//Setting Rectangle Box Color
	CP_Color textboxColor = CP_Color_Create(0, 128, 0, 255);
	//Setting Text Color
	CP_Color textColor = CP_Color_Create(0, 0, 0, 255);
	//Declaring Variables
	float rect1x, rect1y, rect2y, rect3y, rect4y, rectWidth, rectHeight;
	//Setting the Rectangle to position using their center value
	CP_Settings_RectMode(CP_POSITION_CENTER);
	//Setting 1st Rectangle Y value
	rect1y = (CP_System_GetWindowHeight() / 5) * 3;
	//Setting 2nd Rectangle Y value
	rect2y = rect1y + 75;
	rect3y = rect2y + 75;
	rect4y = rect3y + 75;
	//Setting Rectangle X value
	rect1x = CP_System_GetWindowWidth() / 2;
	rectWidth = 150;
	rectHeight = 40;
	//Calling the color
	CP_Settings_Fill(textboxColor);
	//Draw Rectangle
	CP_Graphics_DrawRect(rect1x, rect1y, rectWidth, rectHeight);
	CP_Graphics_DrawRect(rect1x, rect2y,rectWidth, rectHeight);
	CP_Graphics_DrawRect(rect1x, rect3y, rectWidth, rectHeight);
	CP_Graphics_DrawRect(rect1x, rect4y, rectWidth, rectHeight);
	//Calling the text color
	CP_Settings_Fill(textColor);
	//Aligning the text
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER,CP_TEXT_ALIGN_V_MIDDLE);
	//Setting text size
	CP_Settings_TextSize(30.0f);
	//Write the text
	CP_Font_DrawText("Start", rect1x, rect1y);
	CP_Font_DrawText("Settings", rect1x, rect2y);
	CP_Font_DrawText("Credits", rect1x, rect3y);
	CP_Font_DrawText("Quit", rect1x, rect4y);
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Stay In School", (CP_System_GetWindowWidth() / 2), ((CP_System_GetWindowHeight() / 5) * 2));

	float mouseX = CP_Input_GetMouseX();
	float mouseY = CP_Input_GetMouseY();

	/*if (CP_Input_KeyDown(KEY_Q))
	{
		CP_Engine_Terminate();
	}*/


	// transition to level 1 test
	if (CP_Input_MouseClicked() && Is_Area_Clicked(rect1x, rect1y, rectWidth, rectHeight, mouseX, mouseY))
	{
		CP_Engine_SetNextGameState(Level_1_Test_Init, Level_1_Test_Update, Level_1_Test_Exit);
	}

	// transition to Settings
	if (CP_Input_MouseClicked() && Is_Area_Clicked(rect1x, rect2y, rectWidth, rectHeight, mouseX, mouseY))
	{
		CP_Engine_SetNextGameState(Settings_Init, Settings_Update, Settings_Exit);
	}

	// transition to Credits
	if (CP_Input_MouseClicked() && Is_Area_Clicked(rect1x, rect3y, rectWidth, rectHeight, mouseX, mouseY))
	{
		CP_Engine_SetNextGameState(Credits_Init, Credits_Update, Credits_Exit);
	}

	//to close the program
	if (CP_Input_KeyTriggered(KEY_Q) || (CP_Input_MouseClicked() && Is_Area_Clicked(rect1x, rect4y, rectWidth, rectHeight, mouseX, mouseY)))
	{
		CP_Engine_Terminate();
	}
}

void Main_Menu_Exit()
{
	if (n == 1)
	{
		//CP_Engine_SetNextGameState(Car_Level_Init, Car_Level_Update, Car_Leve_Exit);
		CP_Engine_Run();
	}
	if (n == 2)
	{
		CP_Engine_Terminate();
	}	
}