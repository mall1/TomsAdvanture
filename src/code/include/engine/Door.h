#pragma once
#include "BaseWall.h"
class Door :
	public BaseWall
{
public:
	void ReDraw()
	{
		float R = Base::Block_Size / 2;
		float Pi = 3.14159;
		glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);
		glVertex2f(PositionX + R, PositionY + R);
		glVertex2f(PositionX + R, PositionY - R);
		glVertex2f(PositionX - R, PositionY - R);
		glVertex2f(PositionX - R, PositionY + R);
		glEnd();
	}
	Door();
	Door(GLfloat x, GLfloat y);
	~Door();
};

