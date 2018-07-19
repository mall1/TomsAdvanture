#pragma once
#include "Living.h"
#include"Map.h"
#include"bullet.h"
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
	//发射子弹，传入中心点为原点的鼠标位置
	void MoveStep(Base::Rotate r)
	{
		BaseWall* tl, *tr, *tu, *td;
		if (NowMapUnit->GetFightState() == Base::fighting)
		{
			switch (r)
			{
			case Base::up:
				tl = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX, Height / 2 + PositionY + Speed * Base::step);
				tr = Base::GameMap->GetWhichBlock(Width / 2 + PositionX, Height / 2 + PositionY + Speed * Base::step);
				if (tl->IsOnType(Base::wall) || tl->IsOnType(Base::door) || tr->IsOnType(Base::wall) || tr->IsOnType(Base::door)) PositionY = tl->GetGLfloatPositionY() - Base::Block_Size / 2 - Height / 2 - Base::ForgiveValue;
				else PositionY += Speed * Base::step;
				break;
			case Base::down:
				tl = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX, -Height / 2 + PositionY - Speed * Base::step);
				tr = Base::GameMap->GetWhichBlock(Width / 2 + PositionX, -Height / 2 + PositionY - Speed * Base::step);
				if (tl->IsOnType(Base::wall) || tl->IsOnType(Base::door) || tr->IsOnType(Base::wall) || tr->IsOnType(Base::door)) PositionY = tl->GetGLfloatPositionY() + Base::Block_Size / 2 + Height / 2 + Base::ForgiveValue;
				else PositionY -= Speed * Base::step;
				break;
			case Base::left:
				tu = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX - Speed * Base::step, Height / 2 + PositionY);
				td = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX - Speed * Base::step, -Height / 2 + PositionY);
				if (tu->IsOnType(Base::wall) || tu->IsOnType(Base::door) || td->IsOnType(Base::wall) || td->IsOnType(Base::door)) PositionX = tu->GetGLfloatPositionX() + Base::Block_Size / 2 + Width / 2 + Base::ForgiveValue;
				else PositionX -= Speed * Base::step;
				break;
			case Base::right:
				tu = Base::GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step, Height / 2 + PositionY);
				td = Base::GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step, -Height / 2 + PositionY);
				if (tu->IsOnType(Base::wall) || tu->IsOnType(Base::door) || td->IsOnType(Base::wall) || td->IsOnType(Base::door)) PositionX = tu->GetGLfloatPositionX() - Base::Block_Size / 2 - Width / 2 - Base::ForgiveValue;
				else PositionX += Speed * Base::step;
				break;
			}
		}
		else
		{
			switch (r)
			{
			case Base::up:
				tl = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX, Height / 2 + PositionY + Speed * Base::step);
				tr = Base::GameMap->GetWhichBlock(Width / 2 + PositionX, Height / 2 + PositionY + Speed * Base::step);
				if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) PositionY = tl->GetGLfloatPositionY() - Base::Block_Size / 2 - Height / 2 - Base::ForgiveValue;
				else if (tl->IsOnType(Base::door) || tr->IsOnType(Base::door)) { PositionY = tl->GetGLfloatPositionY() + Base::Block_Size / 2 + Height / 2 + Base::ForgiveValue; ChangeMapUnit(NowMapUnit->GetUpMap()); }
				else PositionY += Speed * Base::step;
				break;
			case Base::down:
				tl = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX, -Height / 2 + PositionY - Speed * Base::step);
				tr = Base::GameMap->GetWhichBlock(Width / 2 + PositionX, -Height / 2 + PositionY - Speed * Base::step);
				if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) PositionY = tl->GetGLfloatPositionY() + Base::Block_Size / 2 + Height / 2 + Base::ForgiveValue;
				else if (tl->IsOnType(Base::door) || tr->IsOnType(Base::door)) { PositionY = tl->GetGLfloatPositionY() - Base::Block_Size / 2 - Height / 2 - Base::ForgiveValue;ChangeMapUnit(NowMapUnit->GetDownMap()); }
				else PositionY -= Speed * Base::step;
				break;
			case Base::left:
				tu = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX - Speed * Base::step, Height / 2 + PositionY);
				td = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX - Speed * Base::step, -Height / 2 + PositionY);
				if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall)) PositionX = tu->GetGLfloatPositionX() + Base::Block_Size / 2 + Width / 2 + Base::ForgiveValue;
				else if (tu->IsOnType(Base::door) || td->IsOnType(Base::door)) { PositionX = tu->GetGLfloatPositionX() - Base::Block_Size / 2 - Height / 2 - Base::ForgiveValue; ChangeMapUnit(NowMapUnit->GetLeftMap());
				}
				else PositionX -= Speed * Base::step;
				break;
			case Base::right:
				tu = Base::GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step, Height / 2 + PositionY);
				td = Base::GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step, -Height / 2 + PositionY);
				if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall)) PositionX = tu->GetGLfloatPositionX() - Base::Block_Size / 2 - Width / 2 - Base::ForgiveValue;
				else if (tu->IsOnType(Base::door) || td->IsOnType(Base::door)) { PositionX = tu->GetGLfloatPositionX() + Base::Block_Size / 2 + Height / 2 + Base::ForgiveValue; ChangeMapUnit(NowMapUnit->GetRightMap());
				}
				else PositionX += Speed * Base::step;
				break;
			}
		}
	}
	//判断碰撞
	MapUnit* GetNowMapUnit() { return NowMapUnit; }
	void ChangeMapUnit(MapUnit* t)
	{
		if (t->IsonType(Base::fightmap)&&t->GetFightState() == Base::fightbefore)
		{
			t->SetFightState(Base::fighting);
			if (t->GetEventKind() == Base::end)
				t->EnemyGenerate(1);
			else
				t->EnemyGenerate(4);
		}
		//glTranslatef(t->GetPositionX() - PositionX, t->GetPositionY() - PositionY, 0);
		//NowMapUnit = t;
	}
	void ReDraw()
	{
		glBegin(GL_POLYGON);
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
		glEnd();
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
		NowMapUnit = Base::GameMap->GetWhichMapUnit(0, 0);
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

