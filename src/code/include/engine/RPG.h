#pragma once
#include "Weapon.h"
#include"RPGBullet.h"
class RPG :
	public Weapon
{
public:
	RPG()
	{
		weapontype = Base::rpg;
		weaponskill = Base::a1;
		isDisCard = false;
		Damage = 6;
		AttackSpeed = 400;
		AllWeapon.push_back(this);
	}
	RPG(GLfloat x, GLfloat y) :Weapon(x, y) { weapontype = Base::rpg;Damage = 6;AttackSpeed = 1000;Width = 0.1;Height = 0.05;isDisCard = true;AllWeapon.push_back(this); }
	~RPG()
	{
		std::vector<Weapon*>::iterator it;
		for (it = AllWeapon.begin();it != AllWeapon.end();it++)
		{
			if (*it == this)
			{
				AllWeapon.erase(it);
				break;
			}
		}
	}
	void ReDraw()
	{
		if (isDisCard)
		{
			glColor3f(1, 0, 1);
			glBegin(GL_POLYGON);
			glVertex2f(PositionX - Width / 2, PositionY - Height / 2);
			glVertex2f(PositionX - Width / 2, PositionY + Height / 2);
			glVertex2f(PositionX + Width / 2, PositionY + Height / 2);
			glVertex2f(PositionX + Width / 2, PositionY - Height / 2);
			glEnd();
		}
	}
	void Shoot(GLfloat x, GLfloat y, int m, int n, bool i)
	{
		RPGBullet *t = new RPGBullet(x, y, m, n, Damage,i);
	}
};

