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
	Floor(GLfloat x, GLfloat y)
	{
		BlockName = Base::Block::floorblock;
		PositionX = x;
		PositionY = y;
		CanDestroy = false;
		//Map::AddToFloor(this);
		//GameMap->AddToFloor(this);
	}
	~Floor();
	void ReDraw()
	{
		glPixelZoom(0.1*Base::Window_Width / Base::Block_Width, 0.1*Base::Window_Height / Base::Block_Width);
		glRasterPos2f(PositionX - Base::Block_Width / 2, PositionY - Base::Block_Width / 2);
		glDrawPixels(Base::Block_Width, Base::Block_Width, GL_BGR_EXT, GL_UNSIGNED_BYTE, Base::PixelData[1]);
	}
};

