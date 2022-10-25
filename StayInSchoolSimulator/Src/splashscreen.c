#include "splashscreen.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "mainmenu.h"

CP_Image logo;


void splash_screen_init(void)
{	
	logo = CP_Image_Load("Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);
	CP_System_SetWindowSize(CP_System_GetDisplayWidth(), CP_System_GetDisplayHeight());
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	alpha = 0;
	maxAlpha = 255;
	timeTaken = 2;
}

void splash_screen_update(void)
{	
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	//0.f, 0.f = the x,y cooridinates of the image.
	float x = (CP_System_GetWindowWidth() - CP_Image_GetWidth(logo)) / 2;
	float y = (CP_System_GetWindowHeight() - CP_Image_GetHeight(logo)) / 2;
	CP_Image_Draw(logo, x, y, CP_Image_GetWidth(logo), CP_Image_GetHeight(logo), alpha);

	//float mousex = CP_Input_GetMouseX();
	//float mousey = CP_Input_GetMouseY();
	//CP_Graphics_DrawCircle(mousex,mousey,30);

	//static int flip = 1;

	/*
	//When alpha value less than or = 0
	if (alpha <= 0)
	{
		flip = 1;
	}
	//When alpha value less than or = 255
	else if (alpha >= maxalpha)
	{
		flip = -1;
	}
	*/
	//increase or decrease the alpha depending on flip.

	alpha += (maxAlpha / timeTaken) * CP_System_GetDt();

	if (alpha >= maxAlpha)
	{
		//go next screen 
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}
}

void splash_screen_exit(void)
{
	//CP_Image_Free(&logo);
}