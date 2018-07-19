#include "Door.h"
#include"Map.h"


Door::Door()
{
}

Door::Door(GLfloat x, GLfloat y)
{
	BlockName = Base::Block::door;
	PositionX = x;
	PositionY = y;
	CanDestroy = false;
	//Map::AddToWall(this);
	Base::GameMap->AddToBlock(this);
}


Door::~Door()
{
	Base::GameMap->DeleteBlock(this);
}
