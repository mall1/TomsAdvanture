#pragma once
#include "BaseWall.hpp"
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
    Floor(double x, double y);
	~Floor();
	void ReDraw()
    {
        float R = Base::Block_Size / 2;
        Graphic::gameDrawRect(PositionX-R, PositionX+R, PositionY+R, PositionY-R, 0, 0xffff0000);
	}
};

Floor::Floor(double x, double y)
{
	BlockName = Base::Block::floorblock;
	PositionX = x;
	PositionY = y;
	CanDestroy = false;
	//Map::AddToFloor(this);
	//Base::GameMap->AddToBlock(this);
}

Floor::~Floor()
{
	//Base::GameMap->DeleteBlock(this);
}


