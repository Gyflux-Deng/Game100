#include "utils.h"

/*!
 * @brief AABB collision check between mouse and rectangle objects
 * @param area_center_x X pos of the center point of the rectangle
 * @param area_center_y Y pos of the center point of the rectangle
 * @param area_width Width of the rectangle
 * @param area_height Heigt of the rectangle
 * @param click_x X position of the mouse on screen
 * @param click_y Y position of the mouse on screen
 * @return 1 if the mouse position is inside the rectangle, 0 if the mouse position is outside
*/
int Is_Area_Clicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{	
	// check mouse pos x and y, whether its outside of the rectangle boundary
	if (click_x < area_center_x - area_width / 2 || click_x > area_center_x + area_width / 2 || click_y < area_center_y - area_height / 2 || click_y > area_center_y + area_height / 2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*!
 * @brief Distance check from mouse to center point of circle objects, 
 * if the distance is less than the radius of the circle,
 * it means the mouse position is inside the circle
 * @param circle_center_x X pos of the center point of the circle
 * @param circle_center_y Y pos of the center point of the circle
 * @param diameter Diameter of the circle
 * @param click_x X position of the mouse on screen
 * @param click_y Y position of the mouse on screen
 * @return 1 if the mouse position is inside the circle, 0 if the mouse position is outside
*/
int Is_Circle_Clicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
	// get distance between mouse pos and the center point of the circle
	float distance = CP_Math_Distance(click_x, click_y, circle_center_x, circle_center_y);
	if (distance < diameter / 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*!
 * @brief Converts the angle in radians to a 2d vector
 * @param radian_angle The angle in radians
 * @return The 2d vector after calculation
*/
CP_Vector Angle_To_Vector(float radian_angle)
{
    CP_Vector ret;
	ret.x = cosf(radian_angle);
	ret.y = sinf(radian_angle);
    return ret;
}