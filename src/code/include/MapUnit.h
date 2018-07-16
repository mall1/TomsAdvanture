#pragma once
#include"Base.h"
class MapUnit
{
protected:
	Base::MapType TypeofMap;
	GLfloat PositionX;
	GLfloat PositionY;
	MapUnit* Up;
	MapUnit* Down;
	MapUnit* Left;
	MapUnit* Right;
public:
	bool IsonType(Base::MapType t) { return (TypeofMap == t); }
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
	bool IsInMapUnit(int x, int y)
	{
		GLfloat a = 2.0 * x / Base::Window_Width;
		GLfloat b = 2.0 * y / Base::Window_Height;
		return IsInMapUnit(x, y);
	}

	MapUnit(){};
	~MapUnit(){};
	virtual void Generate() = 0;
};

