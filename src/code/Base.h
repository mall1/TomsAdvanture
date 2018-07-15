#pragma once
#include"GL/glut.h"
#include"map"
#include"list"
#include"vector"


class Map;
class Base {
public:
	static int Window_Width;
	static int Window_Height;

	static GLint Block_Width;
	static GLint Block_PixelLength;

	static GLubyte* PixelData[2];

	static Map* GameMap;


	enum Skill { a1, b1 ,SkillLimit};
	enum Item { c1, d1 ,ItemLimit};
	enum State { e1, f1 ,StateLimit};
	enum Block { wall, floorblock, BlockLimit };

	//std::map<Skill, > SkillPicture;//value为相应图片信息
	//std::map<Item, > ItemPicture;
	//std::map<State, > StatePicture;
};
