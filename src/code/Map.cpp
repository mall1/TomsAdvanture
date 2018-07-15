#include "Map.h"
#include"FightMap.h"
#include"AcrossMap.h"

Map::Map()
{
	ReadBlockFile();
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
				if (AllMiniMap[n]->GetUpMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX(), AllMiniMap[n]->GetPositionY() + 2, false, true, NULL, AllMiniMap[n], NULL, NULL);
					AllMiniMap[n]->SetUpMap(t);
					AcrossMap*m = new AcrossMap(true, t, AllMiniMap[n]);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 1:n = rand() % i;
				if (AllMiniMap[n]->GetDownMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX(), AllMiniMap[n]->GetPositionY() - 2, false, true, AllMiniMap[n], NULL, NULL, NULL);
					AllMiniMap[n]->SetDownMap(t);
					AcrossMap*m = new AcrossMap(true, AllMiniMap[n], t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 2:n = rand() % i;
				if (AllMiniMap[n]->GetLeftMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX() - 2, AllMiniMap[n]->GetPositionY(), false, true, NULL, NULL, NULL, AllMiniMap[n]);
					AllMiniMap[n]->SetLeftMap(t);
					AcrossMap*m = new AcrossMap(false, t, AllMiniMap[n]);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 3:n = rand() % i;
				if (AllMiniMap[n]->GetRightMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX() + 2, AllMiniMap[n]->GetPositionY(), false, true, NULL, NULL, AllMiniMap[n], NULL);
					AllMiniMap[n]->SetRightMap(t);
					AcrossMap*m = new AcrossMap(false, AllMiniMap[n], t);
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
				if (AllMiniMap[n]->GetUpMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX(), AllMiniMap[n]->GetPositionY() + 2, false, false, NULL, AllMiniMap[n], NULL, NULL);
					AllMiniMap[n]->SetUpMap(t);
					AcrossMap*m = new AcrossMap(true, t, AllMiniMap[n]);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 1:n = rand() % i;
				if (AllMiniMap[n]->GetDownMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX(), AllMiniMap[n]->GetPositionY() - 2, false, false, AllMiniMap[n], NULL, NULL, NULL);
					AllMiniMap[n]->SetDownMap(t);
					AcrossMap*m = new AcrossMap(true, AllMiniMap[n], t);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 2:n = rand() % i;
				if (AllMiniMap[n]->GetLeftMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX() - 2, AllMiniMap[n]->GetPositionY(), false, false, NULL, NULL, NULL, AllMiniMap[n]);
					AllMiniMap[n]->SetLeftMap(t);
					AcrossMap*m = new AcrossMap(false, t, AllMiniMap[n]);
				}
				else
				{
					i--;
					continue;
				}
				break;
			case 3:n = rand() % i;
				if (AllMiniMap[n]->GetRightMap() == NULL)
				{
					FightMap*t = new FightMap(AllMiniMap[n]->GetPositionX() + 2, AllMiniMap[n]->GetPositionY(), false, false, NULL, NULL, AllMiniMap[n], NULL);
					AllMiniMap[n]->SetRightMap(t);
					AcrossMap*m = new AcrossMap(false, AllMiniMap[n], t);
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
	for (int i = 0;i < AllMiniMap.size();i++)
		AllMiniMap[i]->Generate();
}


Map::~Map()
{
}
