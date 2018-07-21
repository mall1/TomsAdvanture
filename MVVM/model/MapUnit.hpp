#pragma once
#include "Base.hpp"
#include"Wall.hpp"
#include"Door.hpp"
#include"Floor.hpp"
#include "MapUnit.hpp"
class MapUnit
{
protected:
	Base::MapUnitState FightState;//before in done fight
	Base::MapType TypeofMap;//across or fight
	Base::MapUnitEventKind EventKind;//start end npc ...
    double PositionX;
    double PositionY;
	MapUnit* Up;
	MapUnit* Down;
	MapUnit* Left;
	MapUnit* Right;
public:
	Base::Block MiniTurn[20][20];
	std::vector<BaseWall*> AllBlock;

	BaseWall * ForeachBlock(int i)
	{
		if (i >= AllBlock.size())return NULL;
		return AllBlock[i];
	}
	void AddToBlock(BaseWall* t) { AllBlock.push_back(t); }
	void DeleteAllBlock(BaseWall*t)
	{
		std::vector<BaseWall*>::iterator it;
		for (it = AllBlock.begin();it != AllBlock.end();it++)
		{
			if (*it == t)
			{
				AllBlock.erase(it);
				break;
			}
		}
	}

	bool IsonType(Base::MapType t) { return (TypeofMap == t); }

	Base::MapUnitEventKind GetEventKind() { return EventKind; }

	Base::MapUnitState GetFightState() { return FightState; }
	void SetFightState(Base::MapUnitState t) { FightState = t; }

    double GetPositionX() { return PositionX; }
    double GetPositionY() { return PositionY; }
	MapUnit * GetUpMap() { return Up; }
	void SetUpMap(MapUnit* t) { Up = t; }
	MapUnit * GetDownMap() { return Down; }
	void SetDownMap(MapUnit* t) { Down = t; }
	MapUnit * GetLeftMap() { return Left; }
	void SetLeftMap(MapUnit* t) { Left = t; }
	MapUnit * GetRightMap() { return Right; }
	void SetRightMap(MapUnit* t) { Right = t; }

	void ReDraw()
	{
		for (int i = 0;i < AllBlock.size();i++)
			AllBlock[i]->ReDraw();
	}

    bool IsInMapUnit(double x, double y)
	{
		return x >= PositionX - Base::Block_Size*Base::FightMapWidth / 2 && x <= PositionX + Base::Block_Size*Base::FightMapWidth / 2 && y >= PositionY - Base::Block_Size*Base::FightMapWidth / 2 && y <= PositionY + Base::Block_Size*Base::FightMapWidth / 2;
	}
	/*bool IsInMapUnit(int x, int y)
	{
        double a = 2.0 * x / Base::Window_Width;
        double b = 2.0 * y / Base::Window_Height;
		return IsInMapUnit(x, y);
	}*/

    Base::Block GetBlockState(double x, double y)
	{
		int m = (x - PositionX + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		int n = (y - PositionY + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		return MiniTurn[Base::FightMapWidth-n-1][m];
	}
    BaseWall* GetBlock(double x, double y)
	{
		int node = 1;
		int m = (x - PositionX + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		int n = (y - PositionY + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		if (TypeofMap == Base::fightmap)
			node = (Base::FightMapWidth - n - 1)*Base::FightMapWidth + m + 1;
		else if (Up == NULL)
			node = (Base::FightMapWidth - n - Base::FightMapWidth / 3)*Base::FightMapWidth + m + 1;
		else
			node = (Base::FightMapWidth - n - 1)*(Base::FightMapWidth - 2 * (Base::FightMapWidth / 3) + 2) + m - Base::FightMapWidth / 3 + 2;
		return AllBlock[node-1];
	}

	void EnemyGenerate(int num);

	/*void NoneEnemyJudge()
	{
		if (Enemy::AllEnemy.size() == 0)
		FightState = Base::fightdone;
	}
*/
	MapUnit(){}
	~MapUnit(){}
	virtual void Generate() = 0;
};

//std::vector<BaseWall*> MapUnit::AllBlock;


void MapUnit::EnemyGenerate(int num)
{
	/*int i = rand() % Base::FightMapWidth;
	int j = rand() % Base::FightMapWidth;
	for (int c = 0;c < num;c++)
	{
		while (MiniTurn[i][j] != Base::floorblock)
		{
			i = rand() % Base::FightMapWidth;
			j = rand() % Base::FightMapWidth;
		}
		MiniTurn[i][j] = Base::BlockLimit;
	}
	for (i = 0;i < Base::FightMapWidth;i++)
	{
		for (j = 0;j < Base::FightMapWidth;j++)
		{
			if (MiniTurn[i][j] == Base::BlockLimit)
			{
				MiniTurn[i][j] = Base::floorblock;
				if(EventKind==Base::end)
					MachineArmor* t=new MachineArmor(PositionX - Base::Block_Size*Base::FightMapWidth / 2 + Base::Block_Size / 2 + i * Base::Block_Size, PositionY + Base::Block_Size*Base::FightMapWidth / 2 - Base::Block_Size / 2 - j * Base::Block_Size);
				else
				HandGunSoldier* t = new HandGunSoldier(PositionX - Base::Block_Size*Base::FightMapWidth / 2 + Base::Block_Size / 2 + i * Base::Block_Size, PositionY + Base::Block_Size*Base::FightMapWidth / 2 - Base::Block_Size / 2 - j * Base::Block_Size);
			}
		}
	}*/
}


