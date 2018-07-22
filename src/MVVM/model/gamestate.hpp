#include"Base.hpp"
#include"Game_State.hpp"
#include"Map.hpp"
#include"MiniMap.hpp"
#include"Tom.hpp"
#include"NormalBullet.hpp"
#include"HandGun.hpp"
#include"RPG.hpp"
#include"HandGunSoldier.hpp"
#include"MachineArmor.hpp"
#include"iostream"
#include"../viewmodel/control.hpp"
using Game_State::GameMap;
using Game_State::tom;
//using GameState::SMap;
//using GameState::TomX;

float move[2] = { 0,0 };
bool TomMove[4] = { false,false,false,false };
bool Shoot = false;
int bx=1;
int by=1;
int count = 0;
bool Pause=false;
//Tom* tom;
MiniMap* SMap;


void EnemyGenerate(MapUnit* t)
{
	if (t->IsonType(Base::acrossmap)||t->GetFightState()==Base::fightdone)return;
	int i = rand() % Base::FightMapWidth;
	int j = rand() % Base::FightMapWidth;
	if (t->GetEventKind() == Base::end)
	{
		while (t->MiniTurn[i][j] != Base::floorblock)
		{
			i = rand() % Base::FightMapWidth;
			j = rand() % Base::FightMapWidth;
		}
		t->MiniTurn[i][j] = Base::BlockLimit;
		for (i = 0;i < Base::FightMapWidth;i++)
		{
			for (j = 0;j < Base::FightMapWidth;j++)
			{
				if (t->MiniTurn[i][j] == Base::BlockLimit)
				{
					t->MiniTurn[i][j] = Base::floorblock;
						MachineArmor* m = new MachineArmor(t->GetPositionX() - Base::Block_Size*Base::FightMapWidth / 2 + Base::Block_Size / 2 + i * Base::Block_Size, t->GetPositionY() + Base::Block_Size*Base::FightMapWidth / 2 - Base::Block_Size / 2 - j * Base::Block_Size);
				}
			}
		}
	}
	else
	{
		for (int c = 0;c < 4;c++)
		{
			while (t->MiniTurn[i][j] != Base::floorblock)
			{
				i = rand() % Base::FightMapWidth;
				j = rand() % Base::FightMapWidth;
			}
			t->MiniTurn[i][j] = Base::BlockLimit;
			for (i = 0;i < Base::FightMapWidth;i++)
			{
				for (j = 0;j < Base::FightMapWidth;j++)
				{
					if (t->MiniTurn[i][j] == Base::BlockLimit)
					{
						t->MiniTurn[i][j] = Base::floorblock;
						HandGunSoldier* m = new HandGunSoldier(t->GetPositionX() - Base::Block_Size*Base::FightMapWidth / 2 + Base::Block_Size / 2 + i * Base::Block_Size, t->GetPositionY() + Base::Block_Size*Base::FightMapWidth / 2 - Base::Block_Size / 2 - j * Base::Block_Size);
					}
				}
			}
		}
	}
}


void MoveStep(Base::Rotate r)
{
	BaseWall* tl, *tr, *tu, *td;
	if (tom->GetNowMapUnit()->GetFightState() == Base::fighting)
	{
		switch (r)
		{
		case Base::up:
			tl = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX(), tom->GetHeight() / 2 + tom->GetPositionY() + tom->GetSpeed() * Base::step);
			tr = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX(), tom->GetHeight() / 2 + tom->GetPositionY() + tom->GetSpeed() * Base::step);
            if (tl->IsOnType(Base::wall) || tl->IsOnType(Base::door) || tr->IsOnType(Base::wall) || tr->IsOnType(Base::door)) tom->SetPositionY(tl->GetdoublePositionY() - Base::Block_Size / 2 - tom->GetHeight() / 2 - Base::ForgiveValue);
			else tom->SetPositionY( tom->GetPositionY()+ tom->GetSpeed() * Base::step);
			break;
		case Base::down:
			tl = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
			tr = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
            if (tl->IsOnType(Base::wall) || tl->IsOnType(Base::door) || tr->IsOnType(Base::wall) || tr->IsOnType(Base::door)) tom->SetPositionY(tl->GetdoublePositionY() + Base::Block_Size / 2 + tom->GetHeight() / 2 + Base::ForgiveValue);
			else tom->SetPositionY(tom->GetPositionY() - tom->GetSpeed() * Base::step);
			break;
		case Base::left:
			tu = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
            if (tu->IsOnType(Base::wall) || tu->IsOnType(Base::door) || td->IsOnType(Base::wall) || td->IsOnType(Base::door)) tom->SetPositionX( tu->GetdoublePositionX() + Base::Block_Size / 2 + tom->GetWidth() / 2 + Base::ForgiveValue);
			else tom->SetPositionX(tom->GetPositionX()- tom->GetSpeed() * Base::step);
			break;
		case Base::right:
			tu = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
            if (tu->IsOnType(Base::wall) || tu->IsOnType(Base::door) || td->IsOnType(Base::wall) || td->IsOnType(Base::door)) tom->SetPositionX(tu->GetdoublePositionX() - Base::Block_Size / 2 - tom->GetWidth() / 2 - Base::ForgiveValue);
			else tom->SetPositionX(tom->GetPositionX() + tom->GetSpeed() * Base::step);
			break;
		}
	}
	else
	{
		switch (r)
		{
		case Base::up:
			tl = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX(), tom->GetHeight() / 2 + tom->GetPositionY() + tom->GetSpeed() * Base::step);
			tr = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX(), tom->GetHeight() / 2 + tom->GetPositionY() + tom->GetSpeed() * Base::step);
            if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) tom->SetPositionY(tl->GetdoublePositionY() - Base::Block_Size / 2 - tom->GetHeight() / 2 - Base::ForgiveValue);
            else if (tl->IsOnType(Base::door) || tr->IsOnType(Base::door))
			 { 
			 tom->SetPositionY(tl->GetdoublePositionY() + Base::Block_Size / 2 + tom->GetHeight() / 2 + Base::ForgiveValue); 
			 tom->ChangeMapUnit(tom->GetNowMapUnit()->GetUpMap());
			 EnemyGenerate(tom->GetNowMapUnit()->GetUpMap()); 
			 Base::BaseY -= Base::FightMapWidth*Base::Block_Size;
			 }
			else tom->SetPositionY(tom->GetPositionY() + tom->GetSpeed() * Base::step);
			break;
		case Base::down:
			tl = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
			tr = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
            if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) tom->SetPositionY(tl->GetdoublePositionY() + Base::Block_Size / 2 + tom->GetHeight() / 2 + Base::ForgiveValue);
            else if (tl->IsOnType(Base::door) || tr->IsOnType(Base::door)) 
			{ 
			tom->SetPositionY(tl->GetdoublePositionY() - Base::Block_Size / 2 - tom->GetHeight() / 2 - Base::ForgiveValue);
			tom->ChangeMapUnit(tom->GetNowMapUnit()->GetDownMap());
			EnemyGenerate(tom->GetNowMapUnit()->GetDownMap());
			Base::BaseY += Base::FightMapWidth*Base::Block_Size;
			}
			else tom->SetPositionY(tom->GetPositionY() - tom->GetSpeed() * Base::step);
			break;
		case Base::left:
			tu = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
            if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall))tom->SetPositionX(tu->GetdoublePositionX() + Base::Block_Size / 2 + tom->GetWidth() / 2 + Base::ForgiveValue);
			else if (tu->IsOnType(Base::door) || td->IsOnType(Base::door))
			 {
                tom->SetPositionX(tu->GetdoublePositionX() - Base::Block_Size / 2 - tom->GetWidth() / 2 - Base::ForgiveValue);
				 tom->ChangeMapUnit(tom->GetNowMapUnit()->GetLeftMap());
				 EnemyGenerate(tom->GetNowMapUnit()->GetLeftMap());
				 Base::BaseX += Base::FightMapWidth*Base::Block_Size;
			}
			else tom->SetPositionX(tom->GetPositionX() - tom->GetSpeed() * Base::step);
			break;
		case Base::right:
			tu = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
            if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall)) tom->SetPositionX(tu->GetdoublePositionX() - Base::Block_Size / 2 - tom->GetWidth() / 2 - Base::ForgiveValue);
			else if (tu->IsOnType(Base::door) || td->IsOnType(Base::door)) 
			{
                tom->SetPositionX(tu->GetdoublePositionX() + Base::Block_Size / 2 + tom->GetWidth() / 2 + Base::ForgiveValue);
				 tom->ChangeMapUnit(tom->GetNowMapUnit()->GetRightMap());
				 EnemyGenerate(tom->GetNowMapUnit()->GetRightMap());
				 Base::BaseX -= Base::FightMapWidth*Base::Block_Size;
			}
			else tom->SetPositionX(tom->GetPositionX() + tom->GetSpeed() * Base::step);
			break;
		}
	}
}


void TomReDraw()
{
    MapUnit*t = GameMap->GetWhichMapUnit(tom->GetPositionX(), tom->GetPositionY());
	if (tom->GetNowMapUnit() != t)
	{
		
        //glTranslatef(-t->GetPositionX() + tom->GetNowMapUnit()->GetPositionX(), -t->GetPositionY() + tom->GetNowMapUnit()->GetPositionY(), 0);
        //!!!!what's the fuck!!!!!!!!!!!!!!!
		tom->SetNowMapUnit(t);
	}
	double x = tom->GetPositionX() + Base::BaseX;
	double y = tom->GetPositionY() + Base::BaseY;
    Graphic::gameDrawRect(x - tom->GetWidth() / 2,
                          x + tom->GetWidth() / 2,
                          y + tom->GetHeight() / 2 + 0.05,
                          y + tom->GetHeight() / 2 + 0.02,
                          0,
                          0xffffffff);
	/*glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.02);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.05);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2 + tom->GetWidth() * 1.0*NowHp / MaxHp, tom->GetPositionY() + tom->GetHeight() / 2 + 0.05);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2 + tom->GetWidth() * 1.0*NowHp / MaxHp, tom->GetPositionY() + tom->GetHeight() / 2 + 0.02);
	glEnd();*/
	

	float R = tom->GetHeight() / 2;
    Graphic::gameDrawTom(x,y,R,0xff000000);
}

void display()
{
	GameMap->ReDraw();
	TomReDraw();
	Enemy::AllReDraw();
    bullet::AllReDraw();
    SMap->ReDraw();
}


void gamenextframe()
{
	if(Pause)
	{
        //glutPostRedisplay();
		return;
	}
	if (Base::CounterAll == Base::Clk)
		Base::CounterAll = 0;
	else Base::CounterAll++;
	if (Shoot)
	{
		if (count % tom->GetNowWeapon()->GetAttackSpeed() == 0)
			tom->Shoot(bx, by);
		count++;
	}
	else count = 0;
	bullet::AllMoveJudge();
	Enemy::AllIsDied();
	Enemy::AllJudge();
	if(TomMove[0])
		MoveStep(Base::up);
	if(TomMove[1])
		MoveStep(Base::down);
	if(TomMove[2])
		MoveStep(Base::left);
	if(TomMove[3])
		MoveStep(Base::right);
	for (int i = 0;i < 12;i++)
	{
		if (GameMap->ForeachMapUnit(i) != NULL)
		{
			if (GameMap->ForeachMapUnit(i)->GetFightState() == Base::fighting)
			{
				if (Enemy::AllEnemy.size() == 0)
					GameMap->ForeachMapUnit(i)->SetFightState(Base::fightdone);
			}
		}
    }
    display();
}

void TomControl(Control::gameControlSignal signal)
{
    switch(signal){
    case::Control::gameControlSignal::movetdown: TomMove[0]=true; break;
    case::Control::gameControlSignal::movebdown: TomMove[1]=true; break;
    case::Control::gameControlSignal::moveldown: TomMove[2]=true; break;
    case::Control::gameControlSignal::moverdown: TomMove[3]=true; break;
    case::Control::gameControlSignal::movetup:   TomMove[0]=false;break;
    case::Control::gameControlSignal::movebup:   TomMove[1]=false;break;
    case::Control::gameControlSignal::movelup:   TomMove[2]=false;break;
    case::Control::gameControlSignal::moverup:   TomMove[3]=false;break;
    case::Control::gameControlSignal::fireup:    Shoot=false;     break;
    case::Control::gameControlSignal::firedown:  Shoot=true;      break;
    default:break;
    }
}

void MouseBehavior(Control::MouseEventType type,int x, int y)
{
    if (type == Control::MouseEventType::leftKeyUp)
	{
		std::cout << 3;
		Shoot = false;
	}
    if (type == Control::MouseEventType::leftKeyDown)
	{
		Shoot = true;
		bx = x - Base::Window_Width / 2 - tom->GetPositionX()*Base::Window_Width / 2 + tom->GetNowMapUnit()->GetPositionX()*Base::Window_Width / 2;
		by = Base::Window_Height / 2 - y - tom->GetPositionY()*Base::Window_Height / 2 + tom->GetNowMapUnit()->GetPositionY()*Base::Window_Height / 2;
	}
    if (type == Control::MouseEventType::move)
    {
        bx = x - Base::Window_Width / 2 - tom->GetPositionX()*Base::Window_Width / 2 + tom->GetNowMapUnit()->GetPositionX()*Base::Window_Width / 2;
        by = Base::Window_Height / 2 - y - tom->GetPositionY()*Base::Window_Height / 2 + tom->GetNowMapUnit()->GetPositionY()*Base::Window_Height / 2;
    }
}

void gameinit()
{
	GameMap = new Map();
	GameMap->MapGenerate(6);
	SMap = new MiniMap(-0.8,0.8);
	tom = new Tom();
	tom->SetNowMapUnit(GameMap->GetWhichMapUnit(0, 0));
    HandGun* t = new HandGun();
    tom->ChangeWeapon(t);
	for (int i = 0;i < 12;i++)
	{
		if (GameMap->ForeachMapUnit(i)->GetPositionX() == 0 && GameMap->ForeachMapUnit(i)->GetPositionY() == 0)
        {
			break;
		}
    }
    Control::bindGameControlFunc(TomControl);
}
