#pragma once
#include "MapUnit.h"
class FightMap :
	public MapUnit
{
private:
	bool isStart;
	bool isEnd;
public:
	FightMap(GLfloat x,GLfloat y,bool s,bool e);
	FightMap(GLfloat x, GLfloat y, bool s, bool e, MapUnit* u, MapUnit* d, MapUnit* l, MapUnit* r);
	~FightMap();
	void Generate();
};

