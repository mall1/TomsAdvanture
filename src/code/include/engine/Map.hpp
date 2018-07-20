#pragma once
#include"BaseWall.hpp"
#include"AcrossMap.hpp"
#include"FightMap.hpp"

#include "Map.hpp"
#include <vector>
class Map
{
private:
	std::vector<MapUnit*>AllMapUnit;
public:
	MapUnit * ForeachMapUnit(int i)
	{
		if (i >= AllMapUnit.size())return NULL;
		return AllMapUnit[i];
	}
	void AddToMapUnit(MapUnit* t) { AllMapUnit.push_back(t); }
	void DeleteMapUnit(MapUnit*t)
	{
		std::vector<MapUnit*>::iterator it;
		for (it = AllMapUnit.begin();it != AllMapUnit.end();it++)
		{
			if (*it == t)
			{
				AllMapUnit.erase(it);
				break;
			}
		}
	}

	BaseWall* GetWhichBlock(GLfloat x, GLfloat y)
	{
		int m, n;
		MapUnit* t = GetWhichMapUnit(x, y);
		return t->GetBlock(x, y);
		
    }
	bool IsBlockWall(GLfloat x, GLfloat y)
	{
		MapUnit* t = GetWhichMapUnit(x, y);
		if (t->GetBlockState(x, y) == Base::wall|| t->GetBlockState(x, y) == Base::door)return true;
		return false;
    }
	MapUnit* GetWhichMapUnit(GLfloat x, GLfloat y)
	{
		for (int i = 0;i < AllMapUnit.size();i++)
		{
			if (AllMapUnit[i]->IsInMapUnit(x, y))
				return AllMapUnit[i];
		}
		return NULL;
	}
	MapUnit* GetWhichMapUnit(GLfloat x, GLfloat y,int &node)
	{
		node = -1;
		for (int i = 0;i < AllMapUnit.size();i++)
		{
			if (AllMapUnit[i]->IsInMapUnit(x, y))
				return AllMapUnit[i];
			else
			{
				if (AllMapUnit[i]->IsonType(Base::fightmap))
					node += Base::FightMapWidth*Base::FightMapWidth;
				else if (AllMapUnit[i]->IsonType(Base::acrossmap))
					node += Base::FightMapWidth*(2 + Base::FightMapWidth - 2 * int(Base::FightMapWidth / 3));
			}
		}
		return NULL;
	}
	//qu


	void ReDraw()
	{
		for (int i = 0;i < AllMapUnit.size();i++)
			AllMapUnit[i]->ReDraw();
	}

    Map(){}
    void MapGenerate(int num);
    ~Map(){}
};




void Map::MapGenerate(int num)
{
	int n;//node
	int rotate;
	srand((unsigned)time(NULL));
	for (int i = 0;i < num;i++)
	{
		if (i == 0)
		{
			FightMap* t = new FightMap(0, 0, Base::start);
			AllMapUnit.push_back(t);
		}
		else if (i == num - 1)
		{
			rotate = rand() % 4;
			switch (rotate)
			{
			case 0:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetUpMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() + 2 * Base::Block_Size*Base::FightMapWidth) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() + 2 * Base::Block_Size*Base::FightMapWidth, Base::end, NULL, AllMapUnit[n], NULL, NULL);
					AllMapUnit[n]->SetUpMap(t);
					AcrossMap*m = new AcrossMap(true, t, AllMapUnit[n]);
					AllMapUnit.push_back(AllMapUnit[n]);
					AllMapUnit.push_back(m);
					AllMapUnit[n] = t;
					/*AllMapUnit.pop_back();
					AllMapUnit.pop_back();
					AllMapUnit.push_back(m);
					AllMapUnit.push_back(AllMapUnit[n]);
					AllMapUnit[n] = t;*/
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 1:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetDownMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() - 2 * Base::Block_Size*Base::FightMapWidth) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() - 2 * Base::Block_Size*Base::FightMapWidth, Base::end, AllMapUnit[n], NULL, NULL, NULL);
					AllMapUnit[n]->SetDownMap(t);
					AcrossMap*m = new AcrossMap(true, AllMapUnit[n], t);
					AllMapUnit.push_back(m);
					AllMapUnit.push_back(t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 2:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetLeftMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX() - 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY()) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() - 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), Base::end, NULL, NULL, NULL, AllMapUnit[n]);
					AllMapUnit[n]->SetLeftMap(t);
					AcrossMap*m = new AcrossMap(false, t, AllMapUnit[n]);
					AllMapUnit.push_back(m);
					AllMapUnit.push_back(t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 3:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetRightMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX() + 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY()) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() + 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), Base::end, NULL, NULL, AllMapUnit[n], NULL);
					AllMapUnit[n]->SetRightMap(t);
					AcrossMap*m = new AcrossMap(false, AllMapUnit[n], t);
					AllMapUnit.push_back(m);
					AllMapUnit.push_back(t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			}
		}
		else
		{
			//srand((unsigned)time(NULL));
			//t = rand() % i;
			rotate = rand() % 4;
			switch (rotate)
			{
			case 0:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap)&&AllMapUnit[n]->GetUpMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() + 2 * Base::Block_Size*Base::FightMapWidth) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() + 2 * Base::Block_Size*Base::FightMapWidth, Base::fight, NULL, AllMapUnit[n], NULL, NULL);
					AllMapUnit[n]->SetUpMap(t);
					AcrossMap*m = new AcrossMap(true, t, AllMapUnit[n]);
					AllMapUnit.push_back(AllMapUnit[n]);
					AllMapUnit.push_back(m);
					AllMapUnit[n] = t;
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 1:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetDownMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() - 2 * Base::Block_Size*Base::FightMapWidth) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() - 2 * Base::Block_Size*Base::FightMapWidth, Base::fight, AllMapUnit[n], NULL, NULL, NULL);
					AllMapUnit[n]->SetDownMap(t);
					AcrossMap*m = new AcrossMap(true, AllMapUnit[n], t);
					AllMapUnit.push_back(m);
					AllMapUnit.push_back(t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 2:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetLeftMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX() - 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY()) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() - 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), Base::fight, NULL, NULL, NULL, AllMapUnit[n]);
					AllMapUnit[n]->SetLeftMap(t);
					AcrossMap*m = new AcrossMap(false, t, AllMapUnit[n]);
					AllMapUnit.push_back(m);
					AllMapUnit.push_back(t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 3:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetRightMap() == NULL)
				{
					if (GetWhichMapUnit(AllMapUnit[n]->GetPositionX() + 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY()) != NULL)
					{
						i--;continue;
					}
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() + 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), Base::fight, NULL, NULL, AllMapUnit[n], NULL);
					AllMapUnit[n]->SetRightMap(t);
					AcrossMap*m = new AcrossMap(false, AllMapUnit[n], t);
					AllMapUnit.push_back(m);
					AllMapUnit.push_back(t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			}
		}
	}
	for (int i = 0;i < AllMapUnit.size();i++)
		AllMapUnit[i]->Generate();
}



