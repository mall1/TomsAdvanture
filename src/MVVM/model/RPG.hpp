#pragma once
#include "Weapon.hpp"
#include"RPGBullet.hpp"
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
    RPG(double x, double y) :Weapon(x, y) { weapontype = Base::rpg;Damage = 6;AttackSpeed = 1000;Width = 0.1;Height = 0.05;isDisCard = true;AllWeapon.push_back(this); }
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

            Graphic::gameDrawRect(PositionX-Width/2, PositionX + Width/2, PositionY+ Height/2, PositionY-Height/2, 0,0xffff00ff);
		}
	}
    void Shoot(double x, double y, int m, int n, bool i)
	{
		RPGBullet *t = new RPGBullet(x, y, m, n, Damage,i);
	}
};

