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

	//Base::Skill sk;//������
	//Base::Item it;//������

	//std::vector<Base::State> AllState;//״̬

	//int AttackAngle;//����ƫ��

public:

	void SetPositionX(GLfloat x) { PositionX = x; }
	void SetPositionY(GLfloat y) { PositionY = y; }
	GLfloat GetPositionX() { return PositionX; }
	GLfloat GetPositionY() { return PositionY; }

	virtual void ReDraw() = 0;//�ػ溯��
	virtual void MoveStep(Base::Rotate r) = 0;
	virtual void Hurt() = 0;
	virtual bool IsDied() = 0;//�����ж�
	Living();
	~Living();
};

