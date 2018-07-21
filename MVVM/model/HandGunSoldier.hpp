#pragma once
#include "Enemy.hpp"
#include"Game_State.hpp"
#include"RPG.hpp"
using namespace Game_State;
class HandGunSoldier :
	public Enemy
{
private:
	int MoveRotate;
public:
    HandGunSoldier(double x,double y)
	{
		PositionX = x;
		PositionY = y;
		Height = Base::Block_Size*0.8;
		Width = Height;
		MaxHp = 5;
		NowHp = 5;
		Speed = 0.5;
		enable = true;
		HandGun* t = new HandGun();
		//RPG* t = new RPG();
		NowWeapon = t;
		AllEnemy.push_back(this);
	}
	~HandGunSoldier()
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
        float R = Height / 2;
        Graphic::gameDrawTom(PositionX, PositionY, R, 0xff00ffff);
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
        if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)||tl->IsOnType(Base::door) || tr->IsOnType(Base::door)) PositionY = tl->GetdoublePositionY() - Base::Block_Size / 2 - Height / 2 - Base::ForgiveValue;
        else if(dl->IsOnType(Base::wall) || dr->IsOnType(Base::wall)|| dl->IsOnType(Base::door) || dr->IsOnType(Base::door))PositionY = dl->GetdoublePositionY() + Base::Block_Size / 2 + Height / 2 + Base::ForgiveValue;
		else PositionY += Speed * Base::step*fy;
		BaseWall *tu = GameMap->GetWhichBlock(-Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY);
		BaseWall *td = GameMap->GetWhichBlock(-Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY);
		BaseWall *lu = GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step*fx, Height / 2 + PositionY);
		BaseWall *ld = GameMap->GetWhichBlock(Width / 2 + PositionX + Speed * Base::step*fx, -Height / 2 + PositionY);
        if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall)|| tu->IsOnType(Base::door) || td->IsOnType(Base::door)) PositionX = tu->GetdoublePositionX() + Base::Block_Size / 2 + Width / 2 + Base::ForgiveValue;
        else if (lu->IsOnType(Base::wall) || ld->IsOnType(Base::wall)|| lu->IsOnType(Base::door) || ld->IsOnType(Base::door)) PositionX = lu->GetdoublePositionX() - Base::Block_Size / 2 - Width / 2 - Base::ForgiveValue;
		else PositionX += Speed * Base::step*fx;
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
		for (float i = 0;i < x / (fx*Base::Block_Size/2);i++)
		{
			tx += fx * Base::Block_Size / 2;
			ty += fy * Base::Block_Size / 2;
			if (GameMap->IsBlockWall(tx,ty))
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
		if (Base::CounterAll%NowWeapon->GetAttackSpeed() == 0)
		NowWeapon->Shoot(PositionX + Width * x / (2 * sqrt(x * x + y * y)), PositionY + Width * y / (2 * sqrt(x * x + y * y)), x*Base::Window_Width, y*Base::Window_Height, true);
	}
};

