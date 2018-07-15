#include "Map.h"



Map::Map()
{
	ReadBlockFile();
	for (GLfloat i = -0.45;i <= 0.45;i=i+0.1)
	{
		Wall* m = new Wall(i, 0.45);
		AllBlock.push_back(m);
		Wall* n = new Wall(i, -0.45);
		AllBlock.push_back(n);
	}
	for (GLfloat i = -0.35;i <= 0.35;i=i+ 0.1)
	{
		Wall* m = new Wall(-0.45, i);
		AllBlock.push_back(m);
		Wall* n = new Wall(0.45, i);
		AllBlock.push_back(n);
	}
}


Map::~Map()
{
}
