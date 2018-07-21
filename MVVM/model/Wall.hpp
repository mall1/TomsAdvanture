#pragma once
#include"BaseWall.hpp"

class Wall:
	public BaseWall
{
public:
	void ReDraw()
    {
        float R = Base::Block_Size / 2;
        Graphic::gameDrawRect(PositionX-R, PositionX+R, PositionY+R, PositionY-R, 0, 0xffff0000);

	}

	Wall();
    Wall(double x, double y);
	~Wall();
};
Wall::Wall()
{
	BlockName = Base::Block::wall;
	CanDestroy = false;
	//Map::AddToWall(this);
}

Wall::Wall(double x, double y)
{
	BlockName = Base::Block::wall;
	PositionX = x;
	PositionY = y;
    CanDestroy = false;
    //Map::AddToWall(this);
   // Base::GameMap->AddToBlock(this);
}


Wall::~Wall()
{
     //Base::GameMap->DeleteBlock(this);
}


