#pragma once
#include"Base.hpp"
class bullet
{
protected:
    double PositionX;
    double PositionY;
	//float BulletAngle;//�ӵ��˶��Ƕ�tan
	int AngleX;
	int AngleY;
	int countjump;
	float Speed;
	int Damage;//�˺�
    double BulletSize;
	bool isEnemy;
	
public:
	static std::vector<bullet*>AllBullet;
	/*void JumpInfinite()
	{
        if ((Map*)Base::GameMap->IsBlockWall(PositionX, PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			AngleY = -AngleY;
		else if (Base::GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY))
			AngleX = -AngleX;
		else
		{
			PositionX += Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY));
			PositionY += Base::step*Speed *AngleY / (abs(AngleX) + abs(AngleY));
		}
	}
	void JumpTwice()
	{
		if (countjump == 0)delete this;
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
		}
	}
	void Normal()
	{
		if (Base::GameMap->IsBlockWall(PositionX + Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY)), PositionY + Base::step*Speed * AngleY / (abs(AngleX) + abs(AngleY))))
			delete this;
		else
		{
			PositionX += Base::step*Speed*AngleX / (abs(AngleX) + abs(AngleY));
			PositionY += Base::step*Speed *AngleY / (abs(AngleX) + abs(AngleY));
		}
	}*/
	virtual void MoveJudge()
	{
		//JumpInfinite();
		//JumpTwice();
		//Normal();
	}
	//�ӵ��˶��жϣ�ײǽdelete��ײ��delete
	virtual void ReDraw()
	{
		float R = BulletSize / 2;
        Graphic::gameDrawBullet(PositionX,PositionY,R,0xffffffff);
	}
	static void AllReDraw()
	{
		for (int i = 0;i < AllBullet.size();i++)
			AllBullet[i]->ReDraw();
	}
	static void AllMoveJudge()
	{
		for (int i = 0;i < bullet::AllBullet.size();i++)
			AllBullet[i]->MoveJudge();
	}
	bullet(){}
    //bullet(double x,double y,int b,int d){}
	~bullet(){}
};

std::vector<bullet*> bullet::AllBullet;

