#pragma once
#include"GL/glut.h"
#include"bmptexture.h"
#include"ctime"
#include"vector"
#include"math.h"
#include"iostream"


class Map;
class MiniMap;
class Tom;
class Base {
public:
	static int Window_Width;
	static int Window_Height;

	static int CounterAll;
	static int Clk;

	static GLfloat Block_Size;//�ɱ䶯�ĸ��Ӵ�С
	static int FightMapWidth;//�ɱ䶯��С��ͼ���߸���

	static GLfloat step;
	static GLfloat ForgiveValue;//������ײ�����ԭ��ϵ��

	//static GLint Block_Width;
	//static GLint Block_PixelLength;

	//static GLubyte* PixelData[2];

	static Map* GameMap;
	static MiniMap* SMap;
	static Tom* tom;


	enum Skill { a1, b1 ,SkillLimit};
	enum Item { c1, d1 ,ItemLimit};
	enum State { e1, f1 ,StateLimit};
	enum Block { wall, floorblock, door, BlockLimit };
	enum MapType{fightmap,acrossmap,MapLimit};
	enum WeaponType{handgun,rpg,WeaponLimit};
	enum Rotate{up,down,left,right,RotateLimit};
	enum MapUnitEventKind{start,fight,end,MapUnitKindLimit};
	enum MapUnitState{fightbefore,fighting,fightdone,MapUnitStateLimit};

	//std::map<Skill, > SkillPicture;//valueΪ��ӦͼƬ��Ϣ
	//std::map<Item, > ItemPicture;
	//std::map<State, > StatePicture;
};
