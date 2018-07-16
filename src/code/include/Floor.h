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
		/*float R = Base::Block_Size / 2;
		float Pi = 3.14159;
		glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		for (int i = 0;i < 10;i++)
			glVertex2f(PositionX + R * cos(2 * Pi / 10 * i), PositionY + R * sin(2 * Pi / 10 * i));
		glEnd();*/
		GLfloat size = Base::Block_Size / 2;
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, bmpTexture.getTextureByName(GROUND_BLUE));
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 1);
		glVertex3f(PositionX + size, PositionY + size * 1.75, 0);
		glTexCoord2f(1, 0);
		glVertex3f(PositionX + size, PositionY - size * 1.75, 0);
		glTexCoord2f(0, 0);
		glVertex3f(PositionX - size, PositionY - size * 1.75, 0);
		glTexCoord2f(0, 1);
		glVertex3f(PositionX - size, PositionY + size * 1.75, 0);
		glEnd();
	}
};
