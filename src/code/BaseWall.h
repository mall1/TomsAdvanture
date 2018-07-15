#pragma once
#include"Base.h"



class BaseWall
{
protected:
	Base::Block BlockName;
	GLfloat PositionX;
	GLfloat PositionY;
	bool CanDestroy;//是否能被摧毁
public:
	void SetPositionX(GLfloat x) { PositionX = x; }
	void SetPositionX(int x) { PositionX = 2 * x / Base::Window_Width; }
	GLfloat GetGLfloatPositionX() { return PositionX; }
	int GetIntPositionX() { return PositionX * Base::Window_Width / 2; }

	void SetPositionY(GLfloat y) { PositionY = y; }
	void SetPositionY(int y) { PositionY = 2 * y / Base::Window_Height; }
	GLfloat GetGLfloatPositionY() { return PositionY; }
	int GetIntPositionY() { return PositionY * Base::Window_Height / 2; }

	virtual void ReDraw() = 0;
	bool IsInBlock(GLfloat x,GLfloat y)
	{
		return x >= PositionX - Base::Block_Width && x <= PositionX + Base::Block_Width && y >= PositionY - Base::Block_Width && y <= PositionY + Base::Block_Width;
	}
	bool IsInBlock(int x, int y)
	{
		x = 2 * x / Base::Window_Width;
		y = 2 * y / Base::Window_Height;
		return x >= PositionX - Base::Block_Width && x <= PositionX + Base::Block_Width && y >= PositionY - Base::Block_Width && y <= PositionY + Base::Block_Width;
	}
	//中心为坐标原点
	BaseWall() {};
	~BaseWall() {};
};

