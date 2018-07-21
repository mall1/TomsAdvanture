#pragma once
#include "bullet.hpp"
#include"Game_State.hpp"
#include"Tom.hpp"
#include "Enemy.hpp"
using namespace Game_State;
class NormalBullet :
	public bullet
{
public:
    NormalBullet(double x, double y, int x1, int y1, int d,bool i)
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
        double x=PositionX+Base::BaseX;
        double y=PositionY+BaSE::BaseY;
        if (!isEnemy)
            Graphic::gameDrawTom(x, y,R,0xffffffff);
        else
            Graphic::gameDrawTom(x, y,R,0xff000000);
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
			if (tom->isCollision(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			{
				tom->Hurt(Damage);
				delete this;
				return;
			}
		}
		if (GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
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

