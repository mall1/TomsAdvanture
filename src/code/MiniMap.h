#pragma once
#include"Base.h"
class MiniMap
{
protected:
	GLfloat PositionX;
	GLfloat PositionY;
	MiniMap* Up;
	MiniMap* Down;
	MiniMap* Left;
	MiniMap* Right;
public:
	GLfloat GetPositionX() { return PositionX; }
	GLfloat GetPositionY() { return PositionY; }
	MiniMap * GetUpMap() { return Up; }
	void SetUpMap(MiniMap* t) { Up = t; }
	MiniMap * GetDownMap() { return Down; }
	void SetDownMap(MiniMap* t) { Down = t; }
	MiniMap * GetLeftMap() { return Left; }
	void SetLeftMap(MiniMap* t) { Left = t; }
	MiniMap * GetRightMap() { return Right; }
	void SetRightMap(MiniMap* t) { Right = t; }
	MiniMap();
	~MiniMap();
	virtual void Generate() = 0;
};

