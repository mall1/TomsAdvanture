#pragma once
#include "MapUnit.hpp"
class AcrossMap :
	public MapUnit
{
private:
	bool isUpDown;
public:
	AcrossMap(){}
	AcrossMap(bool i, MapUnit* ul, MapUnit* dr);
    ~AcrossMap();
	void Generate();
};

AcrossMap::AcrossMap(bool i, MapUnit * ul, MapUnit * dr)
{
	TypeofMap = Base::acrossmap;
	isUpDown = i;
	if (isUpDown)
	{
		Up = ul;
		Down = dr;
		for (int i = 0;i < Base::FightMapWidth;i++)
			for (int j = 0;j < Base::FightMapWidth;j++)
			{
				if (j == Base::FightMapWidth / 3 - 1 || j == 2 * Base::FightMapWidth / 3 + 1)
					MiniTurn[i][j] = Base::wall;
				else
					MiniTurn[i][j] = Base::floorblock;
			}
		Down->SetUpMap(this);
		Up->SetDownMap(this);
	}
	else
	{
		Left = ul;
		Right = dr;
		for (int i = 0;i < Base::FightMapWidth;i++)
			for (int j = 0;j < Base::FightMapWidth;j++)
			{
				if (i == Base::FightMapWidth / 3 - 1 || i == 2 * Base::FightMapWidth / 3 + 1)
					MiniTurn[i][j] = Base::wall;
				else
					MiniTurn[i][j] = Base::floorblock;
			}
		Left->SetRightMap(this);
		Right->SetLeftMap(this);
	}
	PositionX = (ul->GetPositionX() + dr->GetPositionX()) / 2;
	PositionY = (ul->GetPositionY() + dr->GetPositionY()) / 2;
	//Base::GameMap->AddToMapUnit(this);
}


AcrossMap::~AcrossMap()
{
	//Base::GameMap->DeleteMapUnit(this);
}

void AcrossMap::Generate()
{
	GLfloat left = (1 - Base::FightMapWidth)*Base::Block_Size / 2;
	GLfloat right = (Base::FightMapWidth - 1)*Base::Block_Size / 2;
	if (isUpDown)
	{
		for (int i = 0;i < Base::FightMapWidth;i++)
			for (int j = Base::FightMapWidth / 3 - 1;j < 2 * Base::FightMapWidth / 3 + 2;j++)
			{
				if (MiniTurn[i][j] == Base::wall)
				{
					Wall* t = new Wall(left + Base::Block_Size*(GLfloat)j + PositionX, right - Base::Block_Size*(GLfloat)i + PositionY);
					AllBlock.push_back(t);
				}
				else
				{
					Floor*t = new Floor(left + Base::Block_Size*(GLfloat)j + PositionX, right - Base::Block_Size*(GLfloat)i + PositionY);
					AllBlock.push_back(t);
				}
			}
	}
	else
	{
		for (int i = Base::FightMapWidth / 3 - 1;i < 2 * Base::FightMapWidth / 3 + 2;i++)
			for (int j = 0;j < Base::FightMapWidth;j++)
			{
				if (MiniTurn[i][j] == Base::wall)
				{
					Wall* t = new Wall(left + Base::Block_Size*(GLfloat)j + PositionX, right - Base::Block_Size*(GLfloat)i + PositionY);
					AllBlock.push_back(t);
				}
				else
				{
					Floor*t = new Floor(left + Base::Block_Size*(GLfloat)j + PositionX, right - Base::Block_Size*(GLfloat)i + PositionY);
					AllBlock.push_back(t);
				}
			}
	}
}
