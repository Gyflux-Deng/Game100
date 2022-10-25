#pragma once
#include <math.h>
#include "Cprocessing.h"

int Is_Area_Clicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y);
int Is_Circle_Clicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y);
union CP_Vector Angle_To_Vector(float radian_angle);