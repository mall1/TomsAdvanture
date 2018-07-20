#pragma once
#include "Living.hpp"
#include"MapUnit.hpp"
class Tom :
	public Living
{
private:
	MapUnit * NowMapUnit;
public:
	void Shoot(int x, int y)
	{
		NowWeapon->Shoot(PositionX + Width * x / (2 * sqrt(x*x + y * y)), PositionY + Width * y / (2 * sqrt(x*x + y * y)), x, y, false);
		//bullet* t = new bullet(PositionX + Width * x / (2 * sqrt(x*x+y*y)), PositionY + Width * y / (2 *sqrt(x*x+y*y)), x, y);
		//bullet::AllBullet.push_back(t);
	}
	MapUnit* GetNowMapUnit() { return NowMapUnit; }
	void SetNowMapUnit(MapUnit* t) { NowMapUnit = t; }
	void ChangeMapUnit(MapUnit* t)
	{
		if (t->IsonType(Base::fightmap)&&t->GetFightState() == Base::fightbefore)
		{
			t->SetFightState(Base::fighting);
		}
		//glTranslatef(t->GetPositionX() - PositionX, t->GetPositionY() - PositionY, 0);
		//NowMapUnit = t;
	}
	void ReDraw()
	{
		/*glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex2f(PositionX - Width / 2, PositionY + Height / 2 + 0.02);
		glVertex2f(PositionX - Width / 2, PositionY + Height / 2 + 0.05);
		glVertex2f(PositionX + Width / 2, PositionY + Height / 2 + 0.05);
		glVertex2f(PositionX + Width / 2, PositionY + Height / 2 + 0.02);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(PositionX - Width / 2, PositionY + Height / 2 + 0.02);
		glVertex2f(PositionX - Width / 2, PositionY + Height / 2 + 0.05);
		glVertex2f(PositionX - Width / 2 + Width * 1.0*NowHp / MaxHp, PositionY + Height / 2 + 0.05);
		glVertex2f(PositionX - Width / 2 + Width * 1.0*NowHp / MaxHp, PositionY + Height / 2 + 0.02);
		glEnd();
		MapUnit*t = Base::GameMap->GetWhichMapUnit(PositionX, PositionY);
		if (NowMapUnit != t)
		{
			glTranslatef(-t->GetPositionX() + NowMapUnit->GetPositionX(), -t->GetPositionY() + NowMapUnit->GetPositionY(), 0);
			NowMapUnit = t;
		}

		float R = Height / 2;
		float Pi = 3.14159;
		glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		for (int i = 0;i < 100;i++)
			glVertex2f(PositionX + R * cos(2 * Pi / 10 * i), PositionY + R * sin(2 * Pi / 10 * i));
		glEnd();*/
	}
	//void Hurt(){}
	void IsDied(){}
	//void 
	//void MoveJudge(){}
	Tom()
	{
		PositionX = 0;
		PositionY = 0;
		Height = Base::Block_Size*0.8;
		Width = Height;
		MaxHp = 50;
		NowHp = 50;
		Speed = 1;
		enable = true;
		//NowMapUnit = Base::GameMap->GetWhichMapUnit(0, 0);
	}
	Tom(GLfloat x, GLfloat y, int mhp, int nhp)
	{
		PositionX = x;
		PositionY = y;
		Speed = 1;
		MaxHp = mhp;
		NowHp = nhp;
		enable = true;
	}
	~Tom() {};
};

