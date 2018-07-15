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
	int NowAD;//����
	int MaxAD;

	Base::Skill sk;//������
	Base::Item it;//������

	std::vector<Base::State> AllState;//״̬

	//int AttackAngle;//����ƫ��

public:
	virtual void Redraw() = 0;//�ػ溯��
	virtual bool IsDied() = 0;//�����ж�
	Living();
	~Living();
};

