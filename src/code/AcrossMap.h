#pragma once
#include "MiniMap.h"
class AcrossMap :
	public MiniMap
{
private:
	Base::Block Across[10][10];
	bool isUpDown;//true���ģ�false���
public:
	AcrossMap();
	AcrossMap(bool i, MiniMap* ul, MiniMap* dr);
	~AcrossMap();
	void Generate();
};

