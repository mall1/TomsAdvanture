#include "MapUnit.h"
#include"HandGunSoldier.h"
#include"MachineArmor.h"


void MapUnit::EnemyGenerate(int num)
{
	int i = rand() % Base::FightMapWidth;
	int j = rand() % Base::FightMapWidth;
	for (int c = 0;c < num;c++)
	{
		while (MiniTurn[i][j] != Base::floorblock)
		{
			i = rand() % Base::FightMapWidth;
			j = rand() % Base::FightMapWidth;
		}
		MiniTurn[i][j] = Base::BlockLimit;
	}
	for (i = 0;i < Base::FightMapWidth;i++)
	{
		for (j = 0;j < Base::FightMapWidth;j++)
		{
			if (MiniTurn[i][j] == Base::BlockLimit)
			{
				MiniTurn[i][j] = Base::floorblock;
				if(EventKind==Base::end)
					MachineArmor* t=new MachineArmor(PositionX - Base::Block_Size*Base::FightMapWidth / 2 + Base::Block_Size / 2 + i * Base::Block_Size, PositionY + Base::Block_Size*Base::FightMapWidth / 2 - Base::Block_Size / 2 - j * Base::Block_Size);
				else
				HandGunSoldier* t = new HandGunSoldier(PositionX - Base::Block_Size*Base::FightMapWidth / 2 + Base::Block_Size / 2 + i * Base::Block_Size, PositionY + Base::Block_Size*Base::FightMapWidth / 2 - Base::Block_Size / 2 - j * Base::Block_Size);
			}
		}
	}
}

MapUnit::MapUnit()
{
}


MapUnit::~MapUnit()
{
}
