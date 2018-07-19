#pragma once
#include "bullet.h"
#include"Tom.h"
#include "Enemy.h"
class NormalBullet :
	public bullet
{
public:
	NormalBullet(GLfloat x, GLfloat y, int x1, int y1, int d,bool i)
	{
		PositionX = x;PositionY = y;AngleX = x1;AngleY = y1;Damage = d;BulletSize = Base::Block_Size / 2;Speed = 2;countjump = 3;isEnemy = i;
		AllBullet.push_back(this);
	}
	~NormalBullet()
	{
		std::vector<bullet*>::iterator it;
		for (it = AllBullet.begin();it != AllBullet.end();it++)
		{
			if (*it == this)
			{
				AllBullet.erase(it);
				break;
			}
		}
	}
	void ReDraw()
	{
		float R = BulletSize / 2;
		float Pi = 3.14159;
		glBegin(GL_POLYGON);
		if (!isEnemy)
			glColor3f(1, 1, 1);
		else
			glColor3f(0, 0, 0);
		for (int i = 0;i < 10;i++)
			glVertex2f(PositionX + R * cos(2 * Pi / 10 * i), PositionY + R * sin(2 * Pi / 10 * i));
		glEnd();
	}
	void MoveJudge()
	{
		if (!isEnemy)
		{
			for (int i = 0;i < Enemy::AllEnemy.size();i++)
			{
				if (Enemy::AllEnemy[i]->isCollision(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
				{
					Enemy::AllEnemy[i]->Hurt(Damage);
					delete this;
					return;
				}
			}
		}
		else
		{
			if (Base::tom->isCollision(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			{
				Base::tom->Hurt(Damage);
				delete this;
				return;
			}
		}
		if (Base::GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			delete this;
		else
		{
			PositionX += Base::step*Speed * AngleX / (abs(AngleX) + abs(AngleY));
			PositionY += Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY));
		}
		/*if (countjump == 0)delete this;
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
		}*/
	}
};

