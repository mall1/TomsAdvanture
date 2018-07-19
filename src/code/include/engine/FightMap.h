#pragma once
#include "MapUnit.h"
class FightMap :
	public MapUnit
{
private:
	
public:
	FightMap(GLfloat x,GLfloat y,Base::MapUnitEventKind t);
	FightMap(GLfloat x, GLfloat y, Base::MapUnitEventKind t, MapUnit* u, MapUnit* d, MapUnit* l, MapUnit* r);
	~FightMap();
	void Generate();
};

