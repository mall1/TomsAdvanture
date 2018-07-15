#pragma once
#include"Base.h"
class Living
{
protected:
	bool enable;
	GLfloat PositionX;
	GLfloat PositionY;
	
	int NowHp;
	int MaxHp;
	int NowAD;//攻击
	int MaxAD;

	Base::Skill sk;//技能栏
	Base::Item it;//道具栏

	std::vector<Base::State> AllState;//状态

	//int AttackAngle;//弹道偏角

public:
	virtual void Redraw() = 0;//重绘函数
	virtual bool IsDied() = 0;//死亡判断
	Living();
	~Living();
};

