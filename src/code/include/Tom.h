#pragma once
#include "Living.h"
#include"Map.h"
#include"bullet.h"
class Tom :
	public Living
{
private:
	
public:
	void Shoot(int x, int y)
	{
		bullet* t = new bullet(PositionX + Width * x / (2 * sqrt(x*x+y*y)), PositionY + Width * y / (2 *sqrt(x*x+y*y)), x, y);
		//bullet::AllBullet.push_back(t);
	}
	//发射子弹，传入中心点为原点的鼠标位置
	void MoveStep(Base::Rotate r)
	{
		BaseWall* tl, *tr, *tu, *td;
		switch (r)
		{
		case Base::up:
			tl = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX, Height/2 + PositionY + Speed * Base::step);
			tr = Base::GameMap->GetWhichBlock(Width / 2 + PositionX, Height/2 + PositionY + Speed * Base::step);
			if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) PositionY = tl->GetGLfloatPositionY() - Base::Block_Size / 2 - Height / 2 - Base::ForgiveValue;
			else PositionY += Speed * Base::step;
			break;
		case Base::down:
			tl = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX, -Height / 2 + PositionY - Speed * Base::step);
			tr = Base::GameMap->GetWhichBlock(Width / 2 + PositionX, -Height / 2 + PositionY - Speed * Base::step);
			if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) PositionY = tl->GetGLfloatPositionY() + Base::Block_Size / 2 + Height / 2 + Base::ForgiveValue;
			else PositionY -= Speed * Base::step;
			break;
		case Base::left:
			tu = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX - Speed * Base::step, Height / 2 + PositionY);
			td = Base::GameMap->GetWhichBlock(-Width / 2 + PositionX - Speed * Base::step, -Height / 2 + PositionY);
			if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall)) PositionX = tu->GetGLfloatPositionX() + Base::Block_Size / 2 + Width / 2 + Base::ForgiveValue;
			else PositionX -= Speed * Base::step;
			break;
		case Base::right:
			tu = Base::GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step, Height / 2 + PositionY);
			td = Base::GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step, -Height / 2 + PositionY);
			if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall)) PositionX = tu->GetGLfloatPositionX() - Base::Block_Size / 2 - Width / 2 - Base::ForgiveValue;
			else PositionX += Speed * Base::step;
			break;
		}
	}
	//判断碰撞
	void ReDraw()
	{
		float R = Height / 2;
		float Pi = 3.14159;
		glBegin(GL_POLYGON);
		glColor3f(0, 0, 0);
		for (int i = 0;i < 100;i++)
			glVertex2f(PositionX + R * cos(2 * Pi / 10 * i), PositionY + R * sin(2 * Pi / 10 * i));
		glEnd();
	}
	void Hurt(){}
	bool IsDied() { return false; }
	//void 
	//void MoveJudge(){}
	Tom()
	{
		PositionX = 0;
		PositionY = 0;
		Height = Base::Block_Size*0.8;
		Width = Height;
		MaxHp = 5;
		NowHp = 5;
		Speed = 1;
		enable = true;
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

