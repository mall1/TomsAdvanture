#pragma once
#include"Base.h"
class Living
{
protected:
	bool enable;
	GLfloat PositionX;
	GLfloat PositionY;

	GLfloat Height;
	GLfloat Width;
	
	int NowHp;
	int MaxHp;

	int Speed;

	//Base::Skill sk;//技能栏
	//Base::Item it;//道具栏

	//std::vector<Base::State> AllState;//状态

	//int AttackAngle;//弹道偏角

public:

	void SetPositionX(GLfloat x) { PositionX = x; }
	void SetPositionY(GLfloat y) { PositionY = y; }
	GLfloat GetPositionX() { return PositionX; }
	GLfloat GetPositionY() { return PositionY; }

	virtual void ReDraw() = 0;//重绘函数
	virtual void MoveStep(Base::Rotate r) = 0;
	virtual void Hurt() = 0;
	virtual bool IsDied() = 0;//死亡判断
	Living();
	~Living();
};

