#pragma once
#include "bullet.hpp"
#include"Game_State.hpp"
#include "Tom.hpp"
using namespace Game_State;
class RPGBullet :
	public bullet
{
private:
	GLfloat BoomSize;
public:
	RPGBullet(){}
	RPGBullet(GLfloat x, GLfloat y, int x1, int y1, int d, bool i)
	{
		PositionX = x;PositionY = y;AngleX = x1;AngleY = y1;Damage = d;BulletSize = Base::Block_Size;Speed = 2;countjump = 3;isEnemy = i;BoomSize = Base::Block_Size*5;
		AllBullet.push_back(this);
	}
	~RPGBullet()
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
			glColor3f(0, 0, 1);
		for (int i = 0;i < 10;i++)
			glVertex2f(PositionX + R * cos(2 * Pi / 10 * i), PositionY + R * sin(2 * Pi / 10 * i));
		glEnd();
	}
	void MoveJudge()
	{
		if (BulletSize != Base::Block_Size)
		{
			if (BulletSize >= BoomSize)
			{
				if (!isEnemy)
				{
					for (int i = 0;i < Enemy::AllEnemy.size();i++)
					{
						if (Enemy::AllEnemy[i]->GetPositionX() >= PositionX - BoomSize / 2 && Enemy::AllEnemy[i]->GetPositionX() <= PositionX + BoomSize / 2 && Enemy::AllEnemy[i]->GetPositionY() >= PositionY - BoomSize / 2 && Enemy::AllEnemy[i]->GetPositionY() <= PositionY + BoomSize / 2)
							Enemy::AllEnemy[i]->Hurt(Damage);
					}
				}
				else
				{
					if (tom->GetPositionX() >= PositionX - BoomSize / 2 && tom->GetPositionX() <= PositionX + BoomSize / 2 && tom->GetPositionY() >= PositionY - BoomSize / 2 && tom->GetPositionY() <= PositionY + BoomSize / 2)
						tom->Hurt(Damage);
				}
				delete this;
				return;
			}
			else
			{
				BulletSize += Base::step;
				return;
			}

		}
		if (!isEnemy)
		{
			for (int i = 0;i < Enemy::AllEnemy.size();i++)
			{
				if (Enemy::AllEnemy[i]->isCollision(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
				{
					Enemy::AllEnemy[i]->Hurt(Damage);
					BulletSize += Base::step;
					//delete this;
					return;
				}
			}
		}
		else
		{
			if (tom->isCollision(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			{
				tom->Hurt(Damage);
				BulletSize += Base::step;
				//delete this;
				return;
			}
		}
		if (GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			BulletSize += Base::step;
			//delete this;
		else
		{
			PositionX += Base::step*Speed * AngleX / (abs(AngleX) + abs(AngleY));
			PositionY += Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY));
		}
	}
};

