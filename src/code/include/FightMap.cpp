#include "FightMap.h"
#include"Map.h"


FightMap::FightMap(GLfloat x, GLfloat y, bool s,bool e)
{
	TypeofMap = Base::fightmap;
	PositionX = x;
	PositionY = y;
	isEnd = e;
	isStart = s;
	Base::GameMap->AddToMapUnit(this);
}

FightMap::FightMap(GLfloat x, GLfloat y, bool s, bool e, MapUnit * u, MapUnit * d, MapUnit * l, MapUnit * r)
{
	TypeofMap = Base::fightmap;
	PositionX = x;
	PositionY = y;
	isStart = s;
	isEnd = e;
	Up = u;
	Down = d;
	Left = l;
	Right = r;
	Base::GameMap->AddToMapUnit(this);
}


FightMap::~FightMap()
{
	Base::GameMap->DeleteMapUnit(this);
}

void FightMap::Generate()
{
	for (int i = 0;i < Base::FightMapWidth;i++)
		for (int j = 0;j < Base::FightMapWidth;j++)
			MiniTurn[i][j] = Base::floorblock;
	for (int i = 0;i < Base::FightMapWidth;i++)
	{
		MiniTurn[i][0] = Base::Block::wall;
		MiniTurn[i][Base::FightMapWidth - 1] = Base::Block::wall;
		MiniTurn[0][i] = Base::Block::wall;
		MiniTurn[Base::FightMapWidth - 1][i] = Base::Block::wall;
	}
	for (int i = Base::FightMapWidth / 3;i <= 2 * Base::FightMapWidth / 3;i++)
	{
		if (Up != NULL)MiniTurn[0][i] = Base::floorblock;
		if (Down != NULL)MiniTurn[Base::FightMapWidth - 1][i] = Base::floorblock;
		if (Left != NULL)MiniTurn[i][0] = Base::floorblock;
		if (Right != NULL)MiniTurn[i][Base::FightMapWidth - 1] = Base::floorblock;
	}
	//if (isStart);
	 if (isEnd);
	else
	{
		for (int t = 0;t < (Base::FightMapWidth - 2)*(Base::FightMapWidth - 2) / 32;t++)
		{
			int i = rand() % (Base::FightMapWidth / 2 - 1);
			int j = rand() % (Base::FightMapWidth / 2 - 1);
			//if (MiniTurn[i + 1][j + 1] == Base::wall)
			//	t--;
			//else
			//{
			MiniTurn[i + 1][j + 1] = Base::wall;
			MiniTurn[Base::FightMapWidth - i - 2][Base::FightMapWidth - j - 2] = Base::wall;
			//}
		}
		for (int t = 0;t < (Base::FightMapWidth - 2)*(Base::FightMapWidth - 2) / 16;t++)
		{
			int i = rand() % (Base::FightMapWidth / 2 - 1);
			int j = rand() % (Base::FightMapWidth / 2 - 1);
			//if (MiniTurn[Base::FightMapWidth - i - 2][j + 1] == Base::wall)
				//t--;
			//else
			//{
			MiniTurn[Base::FightMapWidth - i - 2][j + 1] = Base::wall;
			MiniTurn[i + 1][Base::FightMapWidth - j - 2] = Base::wall;
			//}
		}
	}
	GLfloat left = (1 - Base::FightMapWidth)*Base::Block_Size / 2;
	GLfloat right = (Base::FightMapWidth - 1)*Base::Block_Size / 2;
	for (int i = 0;i < Base::FightMapWidth;i++)
	{
		for (int j = 0;j < Base::FightMapWidth;j++)
		{
			if (MiniTurn[i][j] == Base::wall)
				Wall* t = new Wall(left + Base::Block_Size*(GLfloat)j + PositionX, right - Base::Block_Size*(GLfloat)i + PositionY);
			else
				Floor*t = new Floor(left + Base::Block_Size*(GLfloat)j + PositionX, right - Base::Block_Size*(GLfloat)i + PositionY);
		}
	}
}
