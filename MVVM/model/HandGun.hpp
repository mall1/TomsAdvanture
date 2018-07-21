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
    HandGun(double x, double y) :Weapon(x, y) { weapontype = Base::handgun;Damage = 2;AttackSpeed = 100;Width = 0.1;Height = 0.05; }
	~HandGun(){}
	void ReDraw()
	{
		if (isDisCard)
		{
            Graphic::gameDrawRect(PositionX-Width / 2, PositionX+Width / 2,PositionY + Height/2, PositionY-Height/2,0,0xff00ffff);
		}
	}
    void Shoot(double x, double y, int m, int n,bool i)
	{
		NormalBullet* t = new NormalBullet(x, y, m, n, Damage,i);
	}
};

