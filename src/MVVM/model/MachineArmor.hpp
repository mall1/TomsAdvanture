#pragma once
#include"Game_State.hpp"
#include "Enemy.hpp"
#include "Tom.hpp"
#include "HandGun.hpp"
#include "RPG.hpp"
using namespace Game_State;
class MachineArmor :
	public Enemy
{
private:
	int MoveRotate;
public:
    MachineArmor(double x, double y)
	{
		MoveRotate = 0;
		PositionX = x;
		PositionY = y;
		Height = Base::Block_Size;
		Width = Height*0.6;
		MaxHp = 120;
		NowHp = 120;
		Speed = 0.4;
		enable = true;
		HandGun* t = new HandGun();
		//RPG* t = new RPG();
		NowWeapon = t;
		AllEnemy.push_back(this);
	}
	~MachineArmor()
	{
		std::vector<Enemy*>::iterator it;
		for (it = AllEnemy.begin();it != AllEnemy.end();it++)
		{
			if (*it == this)
			{
				AllEnemy.erase(it);
				break;
			}
		}
	}
	void ReDraw()
	{
		float R1 = Width / 2;
        float R2 = Height / 2;
        double x=PositionX+Base::BaseX;
        double y=PositionY+Base::BaseY;
        Graphic::gameDrawTom(x, y,R1,0xff0080ff);
	}
	void IsDied()
	{
		if (NowHp <= 0)delete this;
	}
	void AIJudge()
	{
        double x = tom->GetPositionX() - PositionX;
        double y = tom->GetPositionY() - PositionY;
		float fx = x / sqrt(x * x + y * y);
		float fy = y / sqrt(x * x + y * y);
		float tx = PositionX, ty = PositionY;
		for (float i = 0;i < x / (fx*Base::Block_Size / 2);i++)
		{
			tx += fx * Base::Block_Size / 2;
			ty += fy * Base::Block_Size / 2;
			if (GameMap->IsBlockWall(tx, ty))
			{
				if (Base::CounterAll % 200 == 0)
					MoveRotate = rand() % 2;
				if (MoveRotate == 0)
					MoveStep(fy, -fx);
				else MoveStep(-fy, fx);
				return;
			}
		}
		MoveStep(fx, fy);
		if (Base::CounterAll % 100 == 0)
		{
			HandGun * t1 = new HandGun();
			RPG * t2 = new RPG();
			int i = rand() % Base::WeaponLimit;
			switch (i)
			{
			case 0:delete NowWeapon;NowWeapon = t1;delete t2;break;
			case 1:delete NowWeapon;NowWeapon = t2;delete t1;break;
			}
		}
		if (Base::CounterAll % (NowWeapon->GetAttackSpeed()) / 2 == 0)
		{
            double m, n;
			m = x;n = y;	
			NowWeapon->Shoot(PositionX + Width * m / (2 * sqrt(m * m + n * n)), PositionY + Width * n / (2 * sqrt(m * m + n * n)), m*Base::Window_Width, n*Base::Window_Height, true);
			m = x;n = 2 * y / 3;
			if (y != 0)
			NowWeapon->Shoot(PositionX + Width * m / (2 * sqrt(m * m + n * n)), PositionY + Width * n / (2 * sqrt(m * m + n * n)), m*Base::Window_Width, n*Base::Window_Height, true);
			m = x;n = y / 3;
			if (y != 0)
			NowWeapon->Shoot(PositionX + Width * m / (2 * sqrt(m * m + n * n)), PositionY + Width * n / (2 * sqrt(m * m + n * n)), m*Base::Window_Width, n*Base::Window_Height, true);
			m = x;n = 0;
			if (y != 0)
			NowWeapon->Shoot(PositionX + Width * m / (2 * sqrt(m * m + n * n)), PositionY + Width * n / (2 * sqrt(m * m + n * n)), m*Base::Window_Width, n*Base::Window_Height, true);
			m = 2 * x / 3;n = y;
			if (x != 0)
			NowWeapon->Shoot(PositionX + Width * m / (2 * sqrt(m * m + n * n)), PositionY + Width * n / (2 * sqrt(m * m + n * n)), m*Base::Window_Width, n*Base::Window_Height, true);
			m = x / 3;n = y;
			if (x != 0)
			NowWeapon->Shoot(PositionX + Width * m / (2 * sqrt(m * m + n * n)), PositionY + Width * n / (2 * sqrt(m * m + n * n)), m*Base::Window_Width, n*Base::Window_Height, true);
			m = 0;n = y;
			if (x != 0)
			NowWeapon->Shoot(PositionX + Width * m / (2 * sqrt(m * m + n * n)), PositionY + Width * n / (2 * sqrt(m * m + n * n)), m*Base::Window_Width, n*Base::Window_Height, true);
		}
	}
    void MoveStep(double fx, double fy)
	{
		if (tom->isCollision(-Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY + Speed * Base::step*fy) || tom->isCollision(Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY + Speed * Base::step*fy) || tom->isCollision(-Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY + Speed * Base::step*fy) || tom->isCollision(Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY + Speed * Base::step*fy))
			return;
		for (int i = 0;i < AllEnemy.size();i++)
		{
			if (AllEnemy[i] == this)
				continue;
			else if (AllEnemy[i]->isCollision(-Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY + Speed * Base::step*fy) || AllEnemy[i]->isCollision(Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY + Speed * Base::step*fy) || AllEnemy[i]->isCollision(-Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY + Speed * Base::step*fy) || AllEnemy[i]->isCollision(Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY + Speed * Base::step*fy))
				return;
		}
		BaseWall *tl = GameMap->GetWhichBlock(-Width / 2 + PositionX, Height / 2 + PositionY + Speed * Base::step*fy);
		BaseWall *tr = GameMap->GetWhichBlock(Width / 2 + PositionX, Height / 2 + PositionY + Speed * Base::step*fy);
		BaseWall *dl = GameMap->GetWhichBlock(-Width / 2 + PositionX, -Height / 2 + PositionY + Speed * Base::step*fy);
		BaseWall *dr = GameMap->GetWhichBlock(Width / 2 + PositionX, -Height / 2 + PositionY + Speed * Base::step*fy);
        if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall) || tl->IsOnType(Base::door) || tr->IsOnType(Base::door)) PositionY = tl->GetdoublePositionY() - Base::Block_Size / 2 - Height / 2 - Base::ForgiveValue;
        else if (dl->IsOnType(Base::wall) || dr->IsOnType(Base::wall) || dl->IsOnType(Base::door) || dr->IsOnType(Base::door))PositionY = dl->GetdoublePositionY() + Base::Block_Size / 2 + Height / 2 + Base::ForgiveValue;
		else PositionY += Speed * Base::step*fy;
		BaseWall *tu = GameMap->GetWhichBlock(-Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY);
		BaseWall *td = GameMap->GetWhichBlock(-Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY);
		BaseWall *lu = GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY);
		BaseWall *ld = GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY);
        if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall) || tu->IsOnType(Base::door) || td->IsOnType(Base::door)) PositionX = tu->GetdoublePositionX() + Base::Block_Size / 2 + Width / 2 + Base::ForgiveValue;
        else if (lu->IsOnType(Base::wall) || ld->IsOnType(Base::wall) || lu->IsOnType(Base::door) || ld->IsOnType(Base::door)) PositionX = lu->GetdoublePositionX() - Base::Block_Size / 2 - Width / 2 - Base::ForgiveValue;
		else PositionX += Speed * Base::step*fx;
	}
};

