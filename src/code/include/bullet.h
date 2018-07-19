#pragma once
#include"Base.h"
#include"Map.h"
class bullet
{
protected:
	GLfloat PositionX;
	GLfloat PositionY;
	//float BulletAngle;//子弹运动角度tan
	int AngleX;
	int AngleY;
	int countjump;
	float Speed;
	int Damage;//伤害
	GLfloat BulletSize;
	bool isEnemy;
	
public:
	static std::vector<bullet*>AllBullet;
	void JumpInfinite()
	{
		if (Base::GameMap->IsBlockWall(PositionX, PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			AngleY = -AngleY;
		else if (Base::GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY))
			AngleX = -AngleX;
		else
		{
			PositionX += Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY));
			PositionY += Base::step*Speed *AngleY / (abs(AngleX) + abs(AngleY));
		}
	}
	void JumpTwice()
	{
		if (countjump == 0)delete this;
		else if (Base::GameMap->IsBlockWall(PositionX, PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
		{
			AngleY = -AngleY;countjump--;
		}
		else if (Base::GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY))
		{
			AngleX = -AngleX;countjump--;
		}
		else
		{
			PositionX += Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY));
			PositionY += Base::step*Speed *AngleY / (abs(AngleX) + abs(AngleY));
		}
	}
	void Normal()
	{
		if (Base::GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			delete this;
		else
		{
			PositionX += Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY));
			PositionY += Base::step*Speed *AngleY / (abs(AngleX) + abs(AngleY));
		}
	}
	virtual void MoveJudge()
	{
		//JumpInfinite();
		JumpTwice();
		//Normal();
	}
	//子弹运动判断：撞墙delete，撞人delete
	virtual void ReDraw()
	{
		float R = BulletSize / 2;
		float Pi = 3.14159;
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		for (int i = 0;i < 10;i++)
			glVertex2f(PositionX + R * cos(2 * Pi / 10 * i), PositionY + R * sin(2 * Pi / 10 * i));
		glEnd();
	}
	static void AllReDraw()
	{
		for (int i = 0;i < AllBullet.size();i++)
			AllBullet[i]->ReDraw();
	}
	static void AllMoveJudge()
	{
		for (int i = 0;i < bullet::AllBullet.size();i++)
			AllBullet[i]->MoveJudge();
	}
	bullet(){}
	//bullet(GLfloat x,GLfloat y,int b,int d){}
	~bullet(){}
};

