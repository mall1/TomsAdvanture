#include "FightMap.h"
#include"Map.h"


FightMap::FightMap(GLfloat x, GLfloat y, bool s,bool e)
{
	PositionX = x;
	PositionY = y;
	isEnd = e;
	isStart = s;
	Base::GameMap->AddToMiniMap(this);
}

FightMap::FightMap(GLfloat x, GLfloat y, bool s, bool e, MiniMap * u, MiniMap * d, MiniMap * l, MiniMap * r)
{
	PositionX = x;
	PositionY = y;
	isStart = s;
	isEnd = e;
	Up = u;
	Down = d;
	Left = l;
	Right = r;
	Base::GameMap->AddToMiniMap(this);
}


FightMap::~FightMap()
{
}

void FightMap::Generate()
{
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++)
			MiniTurn[i][j] = Base::floorblock;
	for (int i = 0;i < 10;i++)
	{
		MiniTurn[i][0] = Base::Block::wall;
		MiniTurn[i][9] = Base::Block::wall;
		MiniTurn[0][i] = Base::Block::wall;
		MiniTurn[9][i] = Base::Block::wall;
	}
	for (int i = 3;i < 7;i++)
	{
		if (Up != NULL)MiniTurn[0][i] = Base::floorblock;
		if (Down != NULL)MiniTurn[9][i] = Base::floorblock;
		if (Left != NULL)MiniTurn[i][0] = Base::floorblock;
		if (Right != NULL)MiniTurn[i][9] = Base::floorblock;
	}
	//if (isStart)return;
	//if (isEnd)return;//´ýÌî³ä
	//srand((unsigned)time(NULL));
	for (int t = 0;t < 4;t++)
	{
		int i = rand() % 4;
		int j = rand() % 4;
		if (MiniTurn[i + 1][j + 1] == Base::wall)
			t--;
		else
		{
			MiniTurn[i + 1][j + 1] = Base::wall;
			MiniTurn[8 - i][8 - j] = Base::wall;
		}
	}
	for (int t = 0;t < 4;t++)
	{
		int i = rand() % 4;
		int j = rand() % 4;
		if (MiniTurn[8 - i][j + 1] == Base::wall)
			t--;
		else
		{
			MiniTurn[8 - i][j + 1] = Base::wall;
			MiniTurn[i + 1][8 - j] = Base::wall;
		}
	}
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if (MiniTurn[i][j] == Base::wall)
				Wall* t = new Wall(-0.45 + 0.1*(GLfloat)j + PositionX, 0.45 - 0.1*(GLfloat)i + PositionY);
			else
				Floor*t = new Floor(-0.45 + 0.1*(GLfloat)j + PositionX, 0.45 - 0.1*(GLfloat)i + PositionY);
		}
	}
}
