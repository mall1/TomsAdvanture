#pragma once
#include"Base.h"
#include"Weapon.h"
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

	float Speed;

	Weapon* NowWeapon;

	//Base::Skill sk;//¼¼ÄÜÀ¸
	//Base::Item it;//µÀ¾ßÀ¸

	//std::vector<Base::State> AllState;//×´Ì¬

	//int AttackAngle;//µ¯µÀÆ«½Ç

public:

	void SetPositionX(GLfloat x) { PositionX = x; }
	void SetPositionY(GLfloat y) { PositionY = y; }
	GLfloat GetPositionX() { return PositionX; }
	GLfloat GetPositionY() { return PositionY; }

	void ChangeWeapon(Weapon* n) { NowWeapon = n; }
	Weapon* GetNowWeapon() { return NowWeapon; }

	bool isCollision(GLfloat x,GLfloat y)
	{
		GLfloat f = Base::ForgiveValue;
		return ((x + f > PositionX - Width / 2) && (x - f < PositionX + Width / 2) && (y + f > PositionY - Height / 2) && (y - f < PositionY + Height / 2));
	}

	virtual void ReDraw() = 0;//ÖØ»æº¯Êý
	//virtual void MoveStep(Base::Rotate r) = 0;
	void Hurt(int d)
	{
		NowHp -= d;
		std::cout << "-" << d << std::endl;
	}
	virtual void IsDied() = 0;//ËÀÍöÅÐ¶Ï
	Living();
	~Living();
};

