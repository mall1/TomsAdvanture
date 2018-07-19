#include "Wall.h"
#include"Map.h"

Wall::Wall()
{
	BlockName = Base::Block::wall;
	CanDestroy = false;
	//Map::AddToWall(this);
}

Wall::Wall(GLfloat x, GLfloat y)
{
	BlockName = Base::Block::wall;
	PositionX = x;
	PositionY = y;
	CanDestroy = false;
	//Map::AddToWall(this);
	Base::GameMap->AddToBlock(this);
}


Wall::~Wall()
{
     Base::GameMap->DeleteBlock(this);
}
