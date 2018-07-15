#include "AcrossMap.h"
#include "Map.h"


AcrossMap::AcrossMap()
{
}

AcrossMap::AcrossMap(bool i, MiniMap * ul, MiniMap * dr)
{
	isUpDown = i;
	if (isUpDown)
	{
		Up = ul;
		Down = dr;
		for (int i = 0;i < 10;i++)
			for (int j = 0;j < 10;j++)
			{
				if (j == 2 || j == 7)
					Across[i][j] = Base::wall;
				else
					Across[i][j] = Base::floorblock;
			}
	}
	else
	{
		Left = ul;
		Right = dr;
		for (int i = 0;i < 10;i++)
			for (int j = 0;j < 10;j++)
			{
				if (i == 2 || i == 7)
					Across[i][j] = Base::wall;
				else
					Across[i][j] = Base::floorblock;
			}
	}
	PositionX = (ul->GetPositionX() + dr->GetPositionX()) / 2;
	PositionY = (ul->GetPositionY() + dr->GetPositionY()) / 2;
	Base::GameMap->AddToMiniMap(this);
}


AcrossMap::~AcrossMap()
{
}

void AcrossMap::Generate()
{
	if (isUpDown)
	{
		for(int i=0;i<10;i++)
			for (int j = 2;j < 8;j++)
			{
				if(Across[i][j]==Base::wall)
					Wall* t= new Wall(-0.45 + 0.1*(GLfloat)j + PositionX, 0.45 - 0.1*(GLfloat)i + PositionY);
				else
					Floor*t = new Floor(-0.45 + 0.1*(GLfloat)j + PositionX, 0.45 - 0.1*(GLfloat)i + PositionY);
			}
	}
	else
	{
		for (int i = 2;i < 8;i++)
			for (int j = 0;j < 10;j++)
			{
				if (Across[i][j] == Base::wall)
					Wall* t = new Wall(-0.45 + 0.1*(GLfloat)j + PositionX, 0.45 - 0.1*(GLfloat)i + PositionY);
				else
					Floor*t = new Floor(-0.45 + 0.1*(GLfloat)j + PositionX, 0.45 - 0.1*(GLfloat)i + PositionY);
			}
	}
}
