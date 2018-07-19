#pragma once
#include"Base.h"
#include"Enemy.h"
class MapUnit
{
protected:
	Base::Block MiniTurn[20][20];
	Base::MapUnitState FightState;//before in done fight
	Base::MapType TypeofMap;//across or fight
	Base::MapUnitEventKind EventKind;//start end npc ...
	GLfloat PositionX;
	GLfloat PositionY;
	MapUnit* Up;
	MapUnit* Down;
	MapUnit* Left;
	MapUnit* Right;
public:
	bool IsonType(Base::MapType t) { return (TypeofMap == t); }

	Base::MapUnitEventKind GetEventKind() { return EventKind; }

	Base::MapUnitState GetFightState() { return FightState; }
	void SetFightState(Base::MapUnitState t) { FightState = t; }

	GLfloat GetPositionX() { return PositionX; }
	GLfloat GetPositionY() { return PositionY; }
	MapUnit * GetUpMap() { return Up; }
	void SetUpMap(MapUnit* t) { Up = t; }
	MapUnit * GetDownMap() { return Down; }
	void SetDownMap(MapUnit* t) { Down = t; }
	MapUnit * GetLeftMap() { return Left; }
	void SetLeftMap(MapUnit* t) { Left = t; }
	MapUnit * GetRightMap() { return Right; }
	void SetRightMap(MapUnit* t) { Right = t; }

	bool IsInMapUnit(GLfloat x, GLfloat y)
	{
		return x >= PositionX - Base::Block_Size*Base::FightMapWidth / 2 && x <= PositionX + Base::Block_Size*Base::FightMapWidth / 2 && y >= PositionY - Base::Block_Size*Base::FightMapWidth / 2 && y <= PositionY + Base::Block_Size*Base::FightMapWidth / 2;
	}
	/*bool IsInMapUnit(int x, int y)
	{
		GLfloat a = 2.0 * x / Base::Window_Width;
		GLfloat b = 2.0 * y / Base::Window_Height;
		return IsInMapUnit(x, y);
	}*/

	Base::Block GetBlockState(GLfloat x, GLfloat y)
	{
		int m = (x - PositionX + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		int n = (y - PositionY + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		return MiniTurn[Base::FightMapWidth-n-1][m];
	}
	Base::Block GetBlockState(GLfloat x, GLfloat y,int &node)
	{
		int m = (x - PositionX + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		int n = (y - PositionY + Base::Block_Size*Base::FightMapWidth / 2) / Base::Block_Size;
		if (TypeofMap == Base::fightmap)
			node = (Base::FightMapWidth - n - 1)*Base::FightMapWidth + m + 1;
		else if (Up == NULL)
			node = (Base::FightMapWidth - n - Base::FightMapWidth / 3)*Base::FightMapWidth + m + 1;
		else
			node = (Base::FightMapWidth - n - 1)*(Base::FightMapWidth - 2 * (Base::FightMapWidth / 3) + 2) + m - Base::FightMapWidth / 3 + 2;
		return MiniTurn[Base::FightMapWidth - n - 1][m];
	}

	void EnemyGenerate(int num);

	void NoneEnemyJudge()
	{
		if (Enemy::AllEnemy.size() == 0)
		FightState = Base::fightdone;
	}

	MapUnit();
	~MapUnit();
	virtual void Generate() = 0;
};

