#pragma once
#include"Base.hpp"
class Weapon
{
protected:
    double PositionX;
    double PositionY;
    double Width;
    double Height;
	Base::WeaponType weapontype;//only read
	Base::Skill weaponskill;//only read
	int Damage;
	int AttackSpeed;//smaller,faster
	bool isDisCard;
public:
	static std::vector<Weapon*>AllWeapon;
	static void AllWeaponReDraw()
	{
		for (int i = 0;i < AllWeapon.size();i++)
			AllWeapon[i]->ReDraw();
	}

    void SetPositionX(double x) { PositionX = x; }
    void SetPositionY(double y) { PositionY = y; }
    double GetPositionX() { return PositionX; }
    double GetPositionY() { return PositionY; }

	int GetAttackSpeed() { return AttackSpeed; }

	Base::WeaponType GetWeaponType() { return weapontype; }
	Base::Skill GetSkill() { return weaponskill; }
	Weapon() 
	{
		/*weapontype = Base::handgun;
		weaponskill = Base::a1;
		isDisCard = false;
		Damage = 2;*/
	}
    Weapon(double x, double y)
	{
		PositionX = x;PositionY = y;isDisCard = true;
		int t = rand() % Base::SkillLimit;
		switch (t)
		{
		case 0:weaponskill = Base::a1;
		case 1:weaponskill = Base::b1;
		}
	}
    ~Weapon() {}
	virtual void ReDraw() = 0;
    virtual void Shoot(double x, double y, int m, int n,bool i) = 0;
};


std::vector<Weapon*> Weapon::AllWeapon;
