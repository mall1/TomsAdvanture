#pragma once
#include "BaseWall.hpp"
class Door :
	public BaseWall
{
public:
	void ReDraw()
	{
        float R = Base::Block_Size / 2;
        double x=PositionX+Base::BaseX;
        double y=PositionY+Base::BaseY;
        Graphic::gameDrawRect(x-R, x+R, y+R, y-R, 0, 0xffff0000);
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



