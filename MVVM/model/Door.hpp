#pragma once
#include "BaseWall.hpp"
class Door :
	public BaseWall
{
public:
	void ReDraw()
	{
        float R = Base::Block_Size / 2;
        Graphic::gameDrawRect(PositionX-R, PositionX+R, PositionY+R, PositionY-R, 0, 0xffff0000);
	}
	Door(){}
    Door(double x, double y);
	~Door(){}
};



Door::Door(double x, double y)
{
	BlockName = Base::Block::door;
	PositionX = x;
	PositionY = y;
	CanDestroy = false;
	//Map::AddToWall(this);
	//Base::GameMap->AddToBlock(this);
}



