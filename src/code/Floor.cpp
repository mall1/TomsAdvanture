#include "Floor.h"
#include"Map.h"

Floor::Floor(GLfloat x, GLfloat y)
{
	BlockName = Base::Block::floorblock;
	PositionX = x;
	PositionY = y;
	CanDestroy = false;
	//Map::AddToFloor(this);
	Base::GameMap->AddToBlock(this);
}

Floor::~Floor()
{
	Base::GameMap->DeleteBlock(this);
}
