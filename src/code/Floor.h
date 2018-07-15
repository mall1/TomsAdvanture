#pragma once
#include "BaseWall.h"
class Floor :
	public BaseWall
{
public:
	Floor()
	{
		BlockName = Base::Block::floorblock;
		CanDestroy = false;
		//GameMap->AddToFloor(this);
		//Map::AddToFloor(this);
	}
	Floor(GLfloat x, GLfloat y);
	~Floor();
	void ReDraw()
	{
		/*glPixelZoom(0.05*Base::Window_Width / Base::Block_Width, 0.05*Base::Window_Height / Base::Block_Width);
		glRasterPos2f(PositionX - Base::Block_Width / Base::Window_Width, PositionY - Base::Block_Width / Base::Window_Height);
		glDrawPixels(Base::Block_Width, Base::Block_Width, GL_BGRA_EXT, GL_UNSIGNED_BYTE, Base::PixelData[1]);*/
		float R = 0.05;
		float Pi = 3.14159;
		glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		for (int i = 0;i < 1000;i++)
			glVertex2f(PositionX + R * cos(2 * Pi / 1000 * i), PositionY + R * sin(2 * Pi / 1000 * i));
		glEnd();
	}
};

