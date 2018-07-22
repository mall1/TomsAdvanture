#pragma once
#include"Base.hpp"
#include"Weapon.hpp"
class Living
{
protected:
	bool enable;
    double PositionX;
    double PositionY;

    double Height;
    double Width;
	
	int NowHp;
	int MaxHp;

	float Speed;

	Weapon* NowWeapon;

	//Base::Skill sk;//������
	//Base::Item it;//������

	//std::vector<Base::State> AllState;//״̬

	//int AttackAngle;//����ƫ��

public:

    void SetPositionX(double x) { PositionX = x; }
    void SetPositionY(double y) { PositionY = y; }
    double GetPositionX() { return PositionX; }
    double GetPositionY() { return PositionY; }

	float GetSpeed() { return Speed; }
    double GetWidth() { return Width; }
    double GetHeight() { return Height; }

	void ChangeWeapon(Weapon* n) { NowWeapon = n; }
	Weapon* GetNowWeapon() { return NowWeapon; }

    bool isCollision(double x,double y)
	{
        double f = Base::ForgiveValue;
		return ((x + f > PositionX - Width / 2) && (x - f < PositionX + Width / 2) && (y + f > PositionY - Height / 2) && (y - f < PositionY + Height / 2));
	}

	virtual void ReDraw() = 0;//�ػ溯��
	//virtual void MoveStep(Base::Rotate r) = 0;
	void Hurt(int d)
	{
		NowHp -= d;
		std::cout << "-" << d << std::endl;
	}
	virtual void IsDied() = 0;//�����ж�
	Living(){}
	~Living(){}
};


