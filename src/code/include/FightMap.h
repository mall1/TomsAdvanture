#pragma once
#include "MapUnit.h"
class FightMap :
	public MapUnit
{
private:
	Base::Block MiniTurn[20][20];
	bool isStart;
	bool isEnd;
public:
	FightMap(GLfloat x,GLfloat y,bool s,bool e);
	FightMap(GLfloat x, GLfloat y, bool s, bool e, MapUnit* u, MapUnit* d, MapUnit* l, MapUnit* r);
	~FightMap();
	void Generate();
};

