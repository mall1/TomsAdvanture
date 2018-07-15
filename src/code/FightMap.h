#pragma once
#include "MiniMap.h"
class FightMap :
	public MiniMap
{
private:
	Base::Block MiniTurn[10][10];
	bool isStart;
	bool isEnd;
public:
	FightMap(GLfloat x,GLfloat y,bool s,bool e);
	FightMap(GLfloat x, GLfloat y, bool s, bool e, MiniMap* u, MiniMap* d, MiniMap* l, MiniMap* r);
	~FightMap();
	void Generate();
};

