#pragma once
#include"Base.h"
#include"Map.h"
class MiniMap
{
private:
	GLfloat PositionX;
	GLfloat PositionY;
	GLfloat Height;
	GLfloat Width;
	GLfloat MapUnitSize;
	GLfloat TomSize;
	GLfloat TomX;
	GLfloat TomY;

	int Size;
public:
	void ReDraw()
	{
		int count=0;
		glPopMatrix();
		glColor3f(1, 1, 1);
		//glBegin(GL_LINE_LOOP);
		//glVertex2f(PositionX - Width / 2, PositionY - Height / 2);
		//glVertex2f(PositionX + Width / 2, PositionY - Height / 2);
		//glVertex2f(PositionX + Width / 2, PositionY + Height / 2);
		//glVertex2f(PositionX - Width / 2, PositionY + Height / 2);
		//glEnd();
		MapUnit* t=Base::GameMap->ForeachMapUnit(count);
		while (t != NULL)
		{
			GLfloat x = PositionX + Width * t->GetPositionX() / (Size * 2);
			GLfloat y = PositionY + Height * t->GetPositionY() / (Size * 2);
			count++;
			if (t->IsonType(Base::fightmap))
			{
				glBegin(GL_POLYGON);
				glVertex2f(x - MapUnitSize / 2, y - MapUnitSize / 2);
				glVertex2f(x - MapUnitSize / 2, y + MapUnitSize / 2);
				glVertex2f(x + MapUnitSize / 2, y + MapUnitSize / 2);
				glVertex2f(x + MapUnitSize / 2, y - MapUnitSize / 2);
				glEnd();
			}
			else
			{
				if (t->GetUpMap() != NULL)
				{
					glLineWidth(3.0f);
					glBegin(GL_LINE_LOOP);
					glVertex2f(x, y + MapUnitSize / 2);
					glVertex2f(x, y - MapUnitSize / 2);
					glEnd();
					glLineWidth(1.0f);
				}
				else
				{
					glLineWidth(3.0f);
					glBegin(GL_LINE_LOOP);
					glVertex2f(x + MapUnitSize / 2, y);
					glVertex2f(x - MapUnitSize / 2, y);
					glEnd();
					glLineWidth(1.0f);
				}
			}
			t = Base::GameMap->ForeachMapUnit(count);
		}
	}
	MiniMap();
	MiniMap(GLfloat x, GLfloat y)
	{
		PositionX = x;
		PositionY = y;
		Height = 0.3;
		Width = 0.3;
		MapUnitSize = 0.025;
		TomSize = 0.025;
		Size = 12;
	}
	~MiniMap();
};

