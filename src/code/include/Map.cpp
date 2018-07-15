#include "Map.h"
#include"FightMap.h"
#include"AcrossMap.h"

Map::Map()
{
	//ReadBlockFile();
	//for (GLfloat i = -0.45;i <= 0.45;i=i+0.1)
	//{
	//	Wall* m = new Wall(i, 0.45);
	//	//AllBlock.push_back(m);
	//	Wall* n = new Wall(i, -0.45);
	//	//AllBlock.push_back(n);
	//}
	//for (GLfloat i = -0.35;i <= 0.35;i=i+ 0.1)
	//{
	//	Wall* m = new Wall(-0.45, i);
	//	//AllBlock.push_back(m);
	//	Wall* n = new Wall(0.45, i);
	//	//AllBlock.push_back(n);
	//}
	//for (GLfloat i = -0.35;i <= 0.35;i = i + 0.1)
	//{
	//	for (GLfloat j = -0.35;j <= 0.35;j = j + 0.1) 
	//	{
	//		Floor *m = new Floor(i, j);
	//		//AllBlock.push_back(m);
	//	}
	//}
}

//随机生成地图

void Map::MapGenerate(int num)
{
	int n;//node
	int rotate;
	srand((unsigned)time(NULL));
	for (int i = 0;i < num;i++)
	{
		if (i == 0)
			FightMap* t = new FightMap(0, 0, true, false);
		else if (i == num - 1)
		{
			srand((unsigned)time(NULL));
			//t = rand() % i;
			rotate = rand() % 4;
			switch (rotate)
			{
			case 0:n = rand() % i;
				if (AllMapUnit[n]->IsonType(Base::fightmap) && AllMapUnit[n]->GetUpMap() == NULL)
				{
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() + 2 * Base::Block_Size*Base::FightMapWidth, false, true, NULL, AllMapUnit[n], NULL, NULL);
					AllMapUnit[n]->SetUpMap(t);
					AcrossMap*m = new AcrossMap(true, t, AllMapUnit[n]);
					AllMapUnit.pop_back();
					//AllMapUnit.pop_back();
					//AllMapUnit.push_back(m);
					AllMapUnit.push_back(AllMapUnit[n]);
					AllMapUnit[n] = m;//使上通道保证在前被重绘
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
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() - 2 * Base::Block_Size*Base::FightMapWidth, false, true, AllMapUnit[n], NULL, NULL, NULL);
					AllMapUnit[n]->SetDownMap(t);
					AcrossMap*m = new AcrossMap(true, AllMapUnit[n], t);
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
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() - 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), false, true, NULL, NULL, NULL, AllMapUnit[n]);
					AllMapUnit[n]->SetLeftMap(t);
					AcrossMap*m = new AcrossMap(false, t, AllMapUnit[n]);
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
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() + 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), false, true, NULL, NULL, AllMapUnit[n], NULL);
					AllMapUnit[n]->SetRightMap(t);
					AcrossMap*m = new AcrossMap(false, AllMapUnit[n], t);
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
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() + 2 * Base::Block_Size*Base::FightMapWidth, false, false, NULL, AllMapUnit[n], NULL, NULL);
					AllMapUnit[n]->SetUpMap(t);
					AcrossMap*m = new AcrossMap(true, t, AllMapUnit[n]);
					AllMapUnit.pop_back();
					//AllMapUnit.pop_back();
					//AllMapUnit.push_back(m);
					AllMapUnit.push_back(AllMapUnit[n]);
					AllMapUnit[n] = m;//使上通道保证在前被重绘
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
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX(), AllMapUnit[n]->GetPositionY() - 2 * Base::Block_Size*Base::FightMapWidth, false, false, AllMapUnit[n], NULL, NULL, NULL);
					AllMapUnit[n]->SetDownMap(t);
					AcrossMap*m = new AcrossMap(true, AllMapUnit[n], t);
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
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() - 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), false, false, NULL, NULL, NULL, AllMapUnit[n]);
					AllMapUnit[n]->SetLeftMap(t);
					AcrossMap*m = new AcrossMap(false, t, AllMapUnit[n]);
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
					FightMap*t = new FightMap(AllMapUnit[n]->GetPositionX() + 2 * Base::Block_Size*Base::FightMapWidth, AllMapUnit[n]->GetPositionY(), false, false, NULL, NULL, AllMapUnit[n], NULL);
					AllMapUnit[n]->SetRightMap(t);
					AcrossMap*m = new AcrossMap(false, AllMapUnit[n], t);
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


Map::~Map()
{
}
