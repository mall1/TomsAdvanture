#pragma once
#include "Base.hpp"

class BaseWall
{
protected:
	Base::Block BlockName;
	GLfloat PositionX;
	GLfloat PositionY;
	bool CanDestroy;//�Ƿ��ܱ��ݻ�
public:
	void SetPositionX(GLfloat x) { PositionX = x; }
	void SetPositionX(int x) { PositionX = 2 * x / Base::Window_Width; }
	GLfloat GetGLfloatPositionX() { return PositionX; }
	int GetIntPositionX() { return PositionX * Base::Window_Width / 2; }

	void SetPositionY(GLfloat y) { PositionY = y; }
	void SetPositionY(int y) { PositionY = 2 * y / Base::Window_Height; }
	GLfloat GetGLfloatPositionY() { return PositionY; }
	int GetIntPositionY() { return PositionY * Base::Window_Height / 2; }

	bool IsOnType(Base::Block t) { return (BlockName == t); }

	virtual void ReDraw() = 0;
	bool IsInBlock(GLfloat x,GLfloat y)
	{
		GLfloat f = Base::ForgiveValue;
		return ((x + f > PositionX - Base::Block_Size / 2) && (x - f < PositionX + Base::Block_Size / 2) && (y + f > PositionY - Base::Block_Size / 2) && (y - f < PositionY + Base::Block_Size / 2));
	}
	/*bool IsInBlock(int x, int y)
	{
		GLfloat a = 2.0 * x / Base::Window_Width;
		GLfloat b = 2.0 * y / Base::Window_Height;
		return IsInBlock(a, b);
    }*/
    BaseWall() {}
    ~BaseWall() {}
};


