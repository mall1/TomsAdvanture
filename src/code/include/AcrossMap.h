#pragma once
#include "MapUnit.h"
class AcrossMap :
	public MapUnit
{
private:
	Base::Block Across[20][20];
	bool isUpDown;//trueÊúµÄ£¬falseºáµÄ
public:
	AcrossMap();
	AcrossMap(bool i, MapUnit* ul, MapUnit* dr);
	~AcrossMap();
	void Generate();
};

