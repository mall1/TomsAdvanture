#pragma once
#include"GL/glut.h"
#include"graphic/bmptexture.hpp"
#include"ctime"
#include"vector"
#include"math.h"


class Map;
class MiniMap;
class Base {
public:
	static int Window_Width;
	static int Window_Height;

	static GLfloat Block_Size;//可变动格子大小 
	static int FightMapWidth;//可变动小地图单边格数 
	
	static GLfloat step;
	static GLfloat ForgiveValue;//计算碰撞体积的原谅系数 

	static GLint Block_Width;
	static GLint Block_PixelLength;

	static GLubyte* PixelData[2];

	static Map* GameMap;
	static MiniMap* SMap;
	static Tom* tom;


	enum Skill { a1, b1 ,SkillLimit};
	enum Item { c1, d1 ,ItemLimit};
	enum State { e1, f1 ,StateLimit};
	enum Block { wall, floorblock, BlockLimit };
	enum MapType{fightmap,acrossmap,MapLimit};
	enum Rotate{up,down,left,right,RotateLimit};

	//std::map<Skill, > SkillPicture;//value脦陋脧脿脫艩脥艗脝卢脨脜脧垄
	//std::map<Item, > ItemPicture;
	//std::map<State, > StatePicture;
};
