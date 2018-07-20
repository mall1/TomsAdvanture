#pragma once
#include "Weapon.hpp"
#include"NormalBullet.hpp"
class HandGun :
	public Weapon
{
public:
	HandGun() 
	{
		weapontype = Base::handgun;
		weaponskill = Base::a1;
		isDisCard = false;
		Damage = 2;
		AttackSpeed = 100;
	}
	HandGun(GLfloat x, GLfloat y) :Weapon(x, y) { weapontype = Base::handgun;Damage = 2;AttackSpeed = 100;Width = 0.1;Height = 0.05; }
	~HandGun(){}
	void ReDraw()
	{
		if (isDisCard)
		{
			glColor3f(0, 1, 1);
			glBegin(GL_POLYGON);
			glVertex2f(PositionX - Width / 2, PositionY - Height / 2);
			glVertex2f(PositionX - Width / 2, PositionY + Height / 2);
			glVertex2f(PositionX + Width / 2, PositionY + Height / 2);
			glVertex2f(PositionX + Width / 2, PositionY - Height / 2);
			glEnd();
		}
	}
	void Shoot(GLfloat x, GLfloat y, int m, int n,bool i)
	{
		NormalBullet* t = new NormalBullet(x, y, m, n, Damage,i);
	}
};

