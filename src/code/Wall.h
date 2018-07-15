#pragma once
#include"BaseWall.h"
class Map;
class Wall:
	public BaseWall
{
public:
	void ReDraw()
	{
		glPixelZoom(0.05*Base::Window_Width / Base::Block_Width, 0.05*Base::Window_Height / Base::Block_Width);
		glRasterPos2f(PositionX - Base::Block_Width / Base::Window_Width, PositionY - Base::Block_Width / Base::Window_Height);
		glDrawPixels(Base::Block_Width, Base::Block_Width, GL_BGR_EXT, GL_UNSIGNED_BYTE, Base::PixelData[0]);
	}

	Wall();
	Wall(GLfloat x, GLfloat y)
	{
		BlockName = Base::Block::wall;
		PositionX = x;
		PositionY = y;
		CanDestroy = false;
		//Map::AddToWall(this);
		//GameMap->AddToWall(this);
	}
	~Wall();
};

