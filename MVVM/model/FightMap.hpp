#pragma once
#include "MapUnit.hpp"
class FightMap :
	public MapUnit
{
private:
	
public:
    FightMap(double x,double y,Base::MapUnitEventKind t);
    FightMap(double x, double y, Base::MapUnitEventKind t, MapUnit* u, MapUnit* d, MapUnit* l, MapUnit* r);
	~FightMap();
	void Generate();
};



FightMap::FightMap(double x, double y, Base::MapUnitEventKind t)
{
	TypeofMap = Base::fightmap;
	PositionX = x;
	PositionY = y;
	EventKind = t;
	if (t==Base::start)
		FightState = Base::fightdone;
	else
		FightState = Base::fightbefore;
	//Base::GameMap->AddToMapUnit(this);
}

FightMap::FightMap(double x, double y, Base::MapUnitEventKind t, MapUnit * u, MapUnit * d, MapUnit * l, MapUnit * r)
{
	TypeofMap = Base::fightmap;
	PositionX = x;
	PositionY = y;
	Up = u;
	Down = d;
	Left = l;
	Right = r;
	EventKind = t;
	if (t == Base::start)
		FightState = Base::fightdone;
	else
		FightState = Base::fightbefore;
	//Base::GameMap->AddToMapUnit(this);
}


FightMap::~FightMap()
{
	//Base::GameMap->DeleteMapUnit(this);
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
		if (Up != NULL)MiniTurn[0][i] = Base::door;
		if (Down != NULL)MiniTurn[Base::FightMapWidth - 1][i] = Base::door;
		if (Left != NULL)MiniTurn[i][0] = Base::door;
		if (Right != NULL)MiniTurn[i][Base::FightMapWidth - 1] = Base::door;
	}
	if (EventKind == Base::start);
	else
	{
		for (int t = 0;t < (Base::FightMapWidth - 2)*(Base::FightMapWidth - 2) / 32;t++)
		{
			int i = rand() % (Base::FightMapWidth / 2 - 1);
			int j = rand() % (Base::FightMapWidth / 2 - 1);
			//if (Up != NULL && i == 0)if (MiniTurn[i][j + 1] == Base::door) { i--;continue; }
			//if (Left != NULL && j == 0)if (MiniTurn[i + 1][j] == Base::door) { i--;continue; }
			//if (MiniTurn[i + 1][j + 1] == Base::wall)
			//	t--;
			//else
			//{
			MiniTurn[i + 1][j + 1] = Base::wall;
			MiniTurn[Base::FightMapWidth - i - 2][Base::FightMapWidth - j - 2] = Base::wall;
			//}
		}
		for (int t = 0;t < (Base::FightMapWidth - 2)*(Base::FightMapWidth - 2) / 32;t++)
		{
			int i = rand() % (Base::FightMapWidth / 2 - 1);
			int j = rand() % (Base::FightMapWidth / 2 - 1);
			//if (Down != NULL && i == 0)if (MiniTurn[Base::FightMapWidth - i - 1][j+1] == Base::door) { i--;continue; }
			//if (Left != NULL && j == 0)if (MiniTurn[Base::FightMapWidth - i - 2][j] == Base::door) { i--;continue; }
			//if (MiniTurn[Base::FightMapWidth - i - 2][j + 1] == Base::wall)
				//t--;
			//else
			//{
			MiniTurn[Base::FightMapWidth - i - 2][j + 1] = Base::wall;
			MiniTurn[i + 1][Base::FightMapWidth - j - 2] = Base::wall;
			//}
		}
	}

	for (int i = Base::FightMapWidth / 3;i <= 2 * Base::FightMapWidth / 3;i++)
	{
		if (Up != NULL)MiniTurn[1][i] = Base::floorblock;
		if (Down != NULL)MiniTurn[Base::FightMapWidth - 2][i] = Base::floorblock;
		if (Left != NULL)MiniTurn[i][1] = Base::floorblock;
		if (Right != NULL)MiniTurn[i][Base::FightMapWidth - 2] = Base::floorblock;
	}

    double left = (1 - Base::FightMapWidth)*Base::Block_Size / 2;
    double right = (Base::FightMapWidth - 1)*Base::Block_Size / 2;
	for (int i = 0;i < Base::FightMapWidth;i++)
	{
		for (int j = 0;j < Base::FightMapWidth;j++)
		{
			if (MiniTurn[i][j] == Base::wall)
			{
                Wall* t = new Wall(left + Base::Block_Size*(double)j + PositionX, right - Base::Block_Size*(double)i + PositionY);
				AllBlock.push_back(t);
			}
			else if (MiniTurn[i][j] == Base::floorblock)
			{
                Floor*t = new Floor(left + Base::Block_Size*(double)j + PositionX, right - Base::Block_Size*(double)i + PositionY);
				AllBlock.push_back(t);
			}
			else
			{
                Door* t = new Door(left + Base::Block_Size*(double)j + PositionX, right - Base::Block_Size*(double)i + PositionY);
				AllBlock.push_back(t);
			}
		}
	}
}

