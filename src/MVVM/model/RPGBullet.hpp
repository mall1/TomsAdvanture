#pragma once
#include "bullet.hpp"
#include "Game_State.hpp"
#include "Tom.hpp"
using namespace Game_State;
class RPGBullet :
	public bullet
{
private:
    double BoomSize;
public:
	RPGBullet(){}
    RPGBullet(double x, double y, int x1, int y1, int d, bool i)
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
		double x=PositionX+Base::BaseX;
        double y=PositionY+Base::BaseY;
        float R = BulletSize / 2;
        if (!isEnemy)
            Graphic::gameDrawTom(x, y,R,0xffffffff);
        else
            Graphic::gameDrawTom(x, y,R,0xff0000ff);

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

