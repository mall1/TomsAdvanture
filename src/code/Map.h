#pragma once
#pragma warning(disable:4996)
#include"Wall.h"
#include"Floor.h"
#include"MiniMap.h"

class Map
{
private:
	//std::map<Base::Block, std::vector<BaseWall*>>AllBlock;
	std::vector<Wall*> AllWall;//暂时无用
	std::vector<Floor*>AllFloor;//暂时无用
	std::vector<BaseWall*>AllBlock;
	std::vector<MiniMap*>AllMiniMap;
public:
	Wall * ForeachWall(int i)
	{
		if (i >= AllWall.size())return NULL;
		return AllWall[i];
	}
	void AddToWall(Wall* t) { AllWall.push_back(t); }
	void DeleteWall(Wall*t)
	{
		std::vector<Wall*>::iterator it;
		for (it = AllWall.begin();it != AllWall.end();it++)
		{
			if (*it == t)
			{
				AllWall.erase(it);
				break;
			}
		}
	}

	Floor * ForeachFloor(int i)
	{
		if (i >= AllFloor.size())return NULL;
		return AllFloor[i];
	}
	void AddToFloor(Floor* t) { AllFloor.push_back(t); }
	void DeleteFloor(Floor*t)
	{
		std::vector<Floor*>::iterator it;
		for (it = AllFloor.begin();it != AllFloor.end();it++)
		{
			if (*it == t)
			{
				AllFloor.erase(it);
				break;
			}
		}
	}

	BaseWall * ForeachBlock(int i)
	{
		if (i >= AllBlock.size())return NULL;
		return AllBlock[i];
	}
	void AddToBlock(BaseWall* t) { AllBlock.push_back(t); }
	void DeleteBlock(BaseWall*t)
	{
		std::vector<BaseWall*>::iterator it;
		for (it = AllBlock.begin();it != AllBlock.end();it++)
		{
			if (*it == t)
			{
				AllBlock.erase(it);
				break;
			}
		}
	}

	MiniMap * ForeachMiniMap(int i)
	{
		if (i >= AllMiniMap.size())return NULL;
		return AllMiniMap[i];
	}
	void AddToMiniMap(MiniMap* t) { AllMiniMap.push_back(t); }

	BaseWall* GetWhichBlock(int x, int y)
	{
		for (int i = 0;i < AllWall.size();i++)
			if (AllWall[i]->IsInBlock(x, y))
				return AllWall[i];
		for (int i = 0;i < AllFloor.size();i++)
			if (AllFloor[i]->IsInBlock(x, y))
				return AllFloor[i];
	}

	void ReadBlockFile()
	{
		FILE * pFile=NULL;
		for (Base::Block t = Base::Block::wall;t < Base::Block::BlockLimit;t = (Base::Block)(t + 1))
		{
			switch (t) 
			{
			case Base::Block::wall:pFile = fopen("E://C++//PictureTomV//bmp//wall.bmp", "rb");break;
			case Base::Block::floorblock:pFile = fopen("E://C++//PictureTomV//bmp//ground.bmp", "rb");break;
			}
			if (pFile == 0)
				break;
			fseek(pFile, 0x0012, SEEK_SET);
			//fread(&Block_Width, sizeof(Block_Width), 1, pFile);
			fread(&Base::Block_Width, sizeof(Base::Block_Width), 1, pFile);
			Base::Block_PixelLength = Base::Block_Width * 3;
			while (Base::Block_PixelLength % 4 != 0)
				++Base::Block_PixelLength;
			Base::Block_PixelLength *= Base::Block_Width;
			Base::PixelData[t] = (GLubyte*)malloc(Base::Block_PixelLength);
			if (Base::PixelData[t] == 0)
				exit(0);
			fseek(pFile, 54, SEEK_SET);  //跳过文件头和信息头
			fread(Base::PixelData[t], Base::Block_PixelLength, 1, pFile);
			//Base::PixelData[t] = Base::PixelData[t];
			fclose(pFile);
		}
	}

	void ReDraw()
	{
		//for (int i = 0;i < AllFloor.size();i++)
			//AllFloor[i]->ReDraw();
		for (int i = 0;i < AllBlock.size();i++)
			AllBlock[i]->ReDraw();
		/*glPixelZoom(3, 3);
		glRasterPos2f(0, 0);
		glDrawPixels(20, 20, GL_BGR_EXT, GL_UNSIGNED_BYTE, Base::PixelData[0]);*/
	}

	Map();
	void MapGenerate(int num);
	~Map();
};

//std::vector<Wall*> AllWall;