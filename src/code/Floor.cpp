#include "Floor.h"
#include"Map.h"

Floor::~Floor()
{
	Base::GameMap->DeleteBlock(this);
}
