#pragma once
#include"GL/glut.h"
#include"bmptexture.h"
#include"ctime"
#include"vector"
#include"math.h"


class Map;
class MiniMap;
class Base {
public:
	static int Window_Width;
	static int Window_Height;

	static GLfloat Block_Size;//可变动的格子大小
	static int FightMapWidth;//可变动的小地图单边格数

	static GLint Block_Width;
	static GLint Block_PixelLength;

	static GLubyte* PixelData[2];

	static Map* GameMap;
	static MiniMap* SMap;


	enum Skill { a1, b1 ,SkillLimit};
	enum Item { c1, d1 ,ItemLimit};
	enum State { e1, f1 ,StateLimit};
	enum Block { wall, floorblock, BlockLimit };
	enum MapType{fightmap,acrossmap,MapLimit};

	//std::map<Skill, > SkillPicture;//value为相应图片信息
	//std::map<Item, > ItemPicture;
	//std::map<State, > StatePicture;
};
