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

	static GLfloat Block_Size;//�ɱ䶯�ĸ��Ӵ�С
	static int FightMapWidth;//�ɱ䶯��С��ͼ���߸���

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

	//std::map<Skill, > SkillPicture;//valueΪ��ӦͼƬ��Ϣ
	//std::map<Item, > ItemPicture;
	//std::map<State, > StatePicture;
};
