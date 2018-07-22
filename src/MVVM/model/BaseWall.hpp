#pragma once
#include "Base.hpp"

class BaseWall
{
protected:
	Base::Block BlockName;
    double PositionX;
    double PositionY;
	bool CanDestroy;//�Ƿ��ܱ��ݻ�
public:
    void SetPositionX(double x) { PositionX = x; }
	void SetPositionX(int x) { PositionX = 2 * x / Base::Window_Width; }
    double GetdoublePositionX() { return PositionX; }
	int GetIntPositionX() { return PositionX * Base::Window_Width / 2; }

    void SetPositionY(double y) { PositionY = y; }
	void SetPositionY(int y) { PositionY = 2 * y / Base::Window_Height; }
    double GetdoublePositionY() { return PositionY; }
	int GetIntPositionY() { return PositionY * Base::Window_Height / 2; }

	bool IsOnType(Base::Block t) { return (BlockName == t); }

	virtual void ReDraw() = 0;
    bool IsInBlock(double x,double y)
	{
        double f = Base::ForgiveValue;
		return ((x + f > PositionX - Base::Block_Size / 2) && (x - f < PositionX + Base::Block_Size / 2) && (y + f > PositionY - Base::Block_Size / 2) && (y - f < PositionY + Base::Block_Size / 2));
	}
	/*bool IsInBlock(int x, int y)
	{
        double a = 2.0 * x / Base::Window_Width;
        double b = 2.0 * y / Base::Window_Height;
		return IsInBlock(a, b);
    }*/
    BaseWall() {}
    ~BaseWall() {}
};


