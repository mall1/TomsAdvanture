#pragma once
#include "MapUnit.h"
class AcrossMap :
	public MapUnit
{
private:
	bool isUpDown;//true���ģ�false���
public:
	AcrossMap();
	AcrossMap(bool i, MapUnit* ul, MapUnit* dr);
	~AcrossMap();
	void Generate();
};

