#pragma once
#include"Base.hpp"
#include"Game_State.hpp"
#include"Map.hpp"
#include"Tom.hpp"
//using namespace Game_State;
//using GameState::TomNowMapUnit;
//using GameState::TomX;
//using GameState::TomY;
class MiniMap
{
private:
    double PositionX;
    double PositionY;
    double Height;
    double Width;
    double MapUnitSize;
    double TomSize;
    double TomX;
    double TomY;

	int Size;
public:
	void ReDraw()
	{
		int count=0;
        //glPopMatrix();
		//glBegin(GL_LINE_LOOP);
		//glVertex2f(PositionX - Width / 2, PositionY - Height / 2);
		//glVertex2f(PositionX + Width / 2, PositionY - Height / 2);
		//glVertex2f(PositionX + Width / 2, PositionY + Height / 2);
		//glVertex2f(PositionX - Width / 2, PositionY + Height / 2);
		//glEnd();
		MapUnit* t= Game_State::GameMap->ForeachMapUnit(count);
		while (t != NULL)
		{
            double x = PositionX + Width * t->GetPositionX() / (Size*Base::Block_Size*Base::FightMapWidth);
            double y = PositionY + Height * t->GetPositionY() / (Size*Base::Block_Size*Base::FightMapWidth);
			x += Game_State::tom->GetNowMapUnit()->GetPositionX()+Base::BaseX;
			y += Game_State::tom->GetNowMapUnit()->GetPositionY()+Base::BaseY;
			count++;
			if (t->IsonType(Base::fightmap))
			{
                Graphic::gameDrawRect(x-MapUnitSize / 2, x+MapUnitSize / 2, y+MapUnitSize / 2, y-MapUnitSize / 2,0,0xffffffff);
			}
			else
			{
                /*if (t->GetUpMap() != NULL)
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
                }*/
			}
			t = Game_State::GameMap->ForeachMapUnit(count);
		}
//		glColor3f(0, 0, 0);
		t = Game_State::tom->GetNowMapUnit();
        double x = PositionX + Width * t->GetPositionX() / (Size*Base::Block_Size*Base::FightMapWidth);
        double y = PositionY + Height * t->GetPositionY() / (Size*Base::Block_Size*Base::FightMapWidth);
		x += Game_State::tom->GetNowMapUnit()->GetPositionX()+Base::BaseX;
		y += Game_State::tom->GetNowMapUnit()->GetPositionY()+Base::BaseY;
		if (t->IsonType(Base::fightmap))
        {
            Graphic::gameDrawRect(x-MapUnitSize / 2, x+MapUnitSize / 2, y+MapUnitSize / 2, y-MapUnitSize / 2,0,0xff000000);
		}
		else
		{
            /*if (t->GetUpMap() != NULL)
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
            }*/
		}
	}
	MiniMap(){}
    MiniMap(double x, double y)
	{
		PositionX = x;
		PositionY = y;
		Height = 0.3;
		Width = 0.3;
		MapUnitSize = 0.025;
		TomSize = 0.025;
		Size = 12;
	}
	~MiniMap(){}
};


