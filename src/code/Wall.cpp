#include "Wall.h"
#include"Map.h"

Wall::Wall()
{
	BlockName = Base::Block::wall;
	CanDestroy = false;
	//Map::AddToWall(this);
}


Wall::~Wall()
{
     Base::GameMap->DeleteBlock(this);
}
