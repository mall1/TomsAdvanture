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

	static GLfloat Block_Size;//�ɱ䶯���Ӵ�С 
	static int FightMapWidth;//�ɱ䶯С��ͼ���߸��� 
	
	static GLfloat step;
	static GLfloat ForgiveValue;//������ײ�����ԭ��ϵ�� 

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

	//std::map<Skill, > SkillPicture;//valueÎªÏàÓŠÍŒÆ¬ÐÅÏ¢
	//std::map<Item, > ItemPicture;
	//std::map<State, > StatePicture;
};
