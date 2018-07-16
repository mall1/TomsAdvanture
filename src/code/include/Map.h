#pragma once
#pragma warning(disable:4996)
#include"Wall.h"
#include"Floor.h"
#include"MapUnit.h"

class Map
{
private:
	//std::map<Base::Block, std::vector<BaseWall*>>AllBlock;
	std::vector<Wall*> AllWall;//ÔÝÊ±ÎÞÓÃ
	std::vector<Floor*>AllFloor;//ÔÝÊ±ÎÞÓÃ
	std::vector<BaseWall*>AllBlock;
	std::vector<MapUnit*>AllMapUnit;
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

	BaseWall* GetWhichBlock(int x, int y)
	{
		for (int i = 0;i < AllWall.size();i++)
			if (AllBlock[i]->IsInBlock(x, y))
				return AllBlock[i];
	}
	BaseWall* GetWhichBlock(GLfloat x, GLfloat y)
	{
		for (int i = 0;i < AllWall.size();i++)
			if (AllBlock[i]->IsInBlock(x, y))
				return AllBlock[i];
	}
	//Ž«ÈëÖÐÐÄÎª×ø±êÔ­µãµÄ×ø±ê£¬·µ»ØËùÔÚ¿éÖžÕë
	MapUnit* GetWhichMapUnit(int x, int y)
	{
		for (int i = 0;i < AllMapUnit.size();i++)
		{
			if (AllMapUnit[i]->IsInMapUnit(x, y))
				return AllMapUnit[i];
		}
	}
	MapUnit* GetWhichMapUnit(GLfloat x, GLfloat y)
	{
		for (int i = 0;i < AllMapUnit.size();i++)
		{
			if (AllMapUnit[i]->IsInMapUnit(x, y))
				return AllMapUnit[i];
		}
	}
	//Ž«ÈëÖÐÐÄÎªÔ­µãµÄ×ø±ê£¬·µ»ØËùÔÚµØÍŒµ¥Ôª£šÕœ¶·ºÍÍšµÀ£©ÖžÕë

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
			fseek(pFile, 54, SEEK_SET);  //Ìø¹ýÎÄŒþÍ·ºÍÐÅÏ¢Í·
			fread(Base::PixelData[t], Base::Block_PixelLength, 1, pFile);
			//Base::PixelData[t] = Base::PixelData[t];
			fclose(pFile);
		}
	}

	void ReDraw()
	{
		for (int i = 0;i < AllBlock.size();i++)
			AllBlock[i]->ReDraw();
	}

	Map();
	void MapGenerate(int num);//Ž«ÈëµØÍŒ¿éÊý
	~Map();
};

//std::vector<Wall*> AllWall;
