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
using Game_State::GameMap;
using Game_State::tom;
//using GameState::SMap;
//using GameState::TomX;

float move[2] = { 0,0 };
bool TomMove[4] = { false,false,false,false };
bool Shoot = false;
int bx;
int by;
int count = 0;
bool Pause=false;
//Tom* tom;
MiniMap* SMap;

void Init()
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
	//ReadMAPBmpFile();
	//ReadBmpFile();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Tom's Adventure");
	Base::Window_Width = 600;
	Base::Window_Height = 600;
	//Base::Block_Width = 30;
}
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
			if (tl->IsOnType(Base::wall) || tl->IsOnType(Base::door) || tr->IsOnType(Base::wall) || tr->IsOnType(Base::door)) tom->SetPositionY(tl->GetGLfloatPositionY() - Base::Block_Size / 2 - tom->GetHeight() / 2 - Base::ForgiveValue);
			else tom->SetPositionY( tom->GetPositionY()+ tom->GetSpeed() * Base::step);
			break;
		case Base::down:
			tl = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
			tr = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
			if (tl->IsOnType(Base::wall) || tl->IsOnType(Base::door) || tr->IsOnType(Base::wall) || tr->IsOnType(Base::door)) tom->SetPositionY(tl->GetGLfloatPositionY() + Base::Block_Size / 2 + tom->GetHeight() / 2 + Base::ForgiveValue);
			else tom->SetPositionY(tom->GetPositionY() - tom->GetSpeed() * Base::step);
			break;
		case Base::left:
			tu = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
			if (tu->IsOnType(Base::wall) || tu->IsOnType(Base::door) || td->IsOnType(Base::wall) || td->IsOnType(Base::door)) tom->SetPositionX( tu->GetGLfloatPositionX() + Base::Block_Size / 2 + tom->GetWidth() / 2 + Base::ForgiveValue);
			else tom->SetPositionX(tom->GetPositionX()- tom->GetSpeed() * Base::step);
			break;
		case Base::right:
			tu = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
			if (tu->IsOnType(Base::wall) || tu->IsOnType(Base::door) || td->IsOnType(Base::wall) || td->IsOnType(Base::door)) tom->SetPositionX(tu->GetGLfloatPositionX() - Base::Block_Size / 2 - tom->GetWidth() / 2 - Base::ForgiveValue);
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
			if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) tom->SetPositionY(tl->GetGLfloatPositionY() - Base::Block_Size / 2 - tom->GetHeight() / 2 - Base::ForgiveValue);
			else if (tl->IsOnType(Base::door) || tr->IsOnType(Base::door)) { tom->SetPositionY(tl->GetGLfloatPositionY() + Base::Block_Size / 2 + tom->GetHeight() / 2 + Base::ForgiveValue); tom->ChangeMapUnit(tom->GetNowMapUnit()->GetUpMap());EnemyGenerate(tom->GetNowMapUnit()->GetUpMap()); }
			else tom->SetPositionY(tom->GetPositionY() + tom->GetSpeed() * Base::step);
			break;
		case Base::down:
			tl = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
			tr = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX(), -tom->GetHeight() / 2 + tom->GetPositionY() - tom->GetSpeed() * Base::step);
			if (tl->IsOnType(Base::wall) || tr->IsOnType(Base::wall)) tom->SetPositionY(tl->GetGLfloatPositionY() + Base::Block_Size / 2 + tom->GetHeight() / 2 + Base::ForgiveValue);
			else if (tl->IsOnType(Base::door) || tr->IsOnType(Base::door)) { tom->SetPositionY(tl->GetGLfloatPositionY() - Base::Block_Size / 2 - tom->GetHeight() / 2 - Base::ForgiveValue);tom->ChangeMapUnit(tom->GetNowMapUnit()->GetDownMap());EnemyGenerate(tom->GetNowMapUnit()->GetDownMap());}
			else tom->SetPositionY(tom->GetPositionY() - tom->GetSpeed() * Base::step);
			break;
		case Base::left:
			tu = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(-tom->GetWidth() / 2 + tom->GetPositionX() - tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
			if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall))tom->SetPositionX(tu->GetGLfloatPositionX() + Base::Block_Size / 2 + tom->GetWidth() / 2 + Base::ForgiveValue);
			else if (tu->IsOnType(Base::door) || td->IsOnType(Base::door)) {
				tom->SetPositionX(tu->GetGLfloatPositionX() - Base::Block_Size / 2 - tom->GetWidth() / 2 - Base::ForgiveValue); tom->ChangeMapUnit(tom->GetNowMapUnit()->GetLeftMap());EnemyGenerate(tom->GetNowMapUnit()->GetLeftMap());
			}
			else tom->SetPositionX(tom->GetPositionX() - tom->GetSpeed() * Base::step);
			break;
		case Base::right:
			tu = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, tom->GetHeight() / 2 + tom->GetPositionY());
			td = GameMap->GetWhichBlock(tom->GetWidth() / 2 + tom->GetPositionX() + tom->GetSpeed() * Base::step, -tom->GetHeight() / 2 + tom->GetPositionY());
			if (tu->IsOnType(Base::wall) || td->IsOnType(Base::wall)) tom->SetPositionX(tu->GetGLfloatPositionX() - Base::Block_Size / 2 - tom->GetWidth() / 2 - Base::ForgiveValue);
			else if (tu->IsOnType(Base::door) || td->IsOnType(Base::door)) {
				tom->SetPositionX(tu->GetGLfloatPositionX() + Base::Block_Size / 2 + tom->GetWidth() / 2 + Base::ForgiveValue); tom->ChangeMapUnit(tom->GetNowMapUnit()->GetRightMap());EnemyGenerate(tom->GetNowMapUnit()->GetRightMap());
			}
			else tom->SetPositionX(tom->GetPositionX() + tom->GetSpeed() * Base::step);
			break;
		}
	}
}


void TomReDraw()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.02);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.05);
	glVertex2f(tom->GetPositionX() + tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.05);
	glVertex2f(tom->GetPositionX() + tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.02);
	glEnd();
	/*glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.02);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2, tom->GetPositionY() + tom->GetHeight() / 2 + 0.05);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2 + tom->GetWidth() * 1.0*NowHp / MaxHp, tom->GetPositionY() + tom->GetHeight() / 2 + 0.05);
	glVertex2f(tom->GetPositionX() - tom->GetWidth() / 2 + tom->GetWidth() * 1.0*NowHp / MaxHp, tom->GetPositionY() + tom->GetHeight() / 2 + 0.02);
	glEnd();*/
	MapUnit*t = GameMap->GetWhichMapUnit(tom->GetPositionX(), tom->GetPositionY());
	if (tom->GetNowMapUnit() != t)
	{
		glTranslatef(-t->GetPositionX() + tom->GetNowMapUnit()->GetPositionX(), -t->GetPositionY() + tom->GetNowMapUnit()->GetPositionY(), 0);
		tom->SetNowMapUnit(t);
	}

	float R = tom->GetHeight() / 2;
	float Pi = 3.14159;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	for (int i = 0;i < 100;i++)
		glVertex2f(tom->GetPositionX() + R * cos(2 * Pi / 10 * i), tom->GetPositionY() + R * sin(2 * Pi / 10 * i));
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	//glTranslatef(move[0], move[1], 0);
	GameMap->ReDraw();
	TomReDraw();
	Enemy::AllReDraw();
	bullet::AllReDraw();
	//glPopMatrix();
	SMap->ReDraw();
	//glPopMatrix();
	glutSwapBuffers();
}

void reshape(int width,int height)
{
	int i;
}

void idle()
{
	if(Pause)
	{
		glutPostRedisplay();
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
	//tom->GetNowMapUnit()->NoneEnemyJudge();
	glutPostRedisplay();
}

void KeyBehavior(unsigned char key, int x, int y)
{
	std::cout << 1;
	switch (key)
	{
	case 'w':TomMove[0] = true;break;
	case 's':TomMove[1] = true;break;
	case 'a':TomMove[2] = true;break;
	case 'd':TomMove[3] = true;break;
    case 'p':Pause=!Pause;break;
	}
	//glutPostRedisplay();
}

void KeyUp(unsigned char key, int x, int y)
{
	std::cout << 2;
	switch (key)
	{
	case 'w':TomMove[0] = false;break;
	case 's':TomMove[1] = false;break;
	case 'a':TomMove[2] = false;break;
	case 'd':TomMove[3] = false;break;
	}
}

void MouseBehavior(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		std::cout << 3;
		Shoot = false;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Shoot = true;
		bx = x - Base::Window_Width / 2 - tom->GetPositionX()*Base::Window_Width / 2 + tom->GetNowMapUnit()->GetPositionX()*Base::Window_Width / 2;
		by = Base::Window_Height / 2 - y - tom->GetPositionY()*Base::Window_Height / 2 + tom->GetNowMapUnit()->GetPositionY()*Base::Window_Height / 2;
	}
}

void MouseMove(int x, int y)
{
	if (Shoot)
	{
		bx = x - Base::Window_Width / 2 - tom->GetPositionX()*Base::Window_Width / 2 + tom->GetNowMapUnit()->GetPositionX()*Base::Window_Width / 2;
		by = Base::Window_Height / 2 - y - tom->GetPositionY()*Base::Window_Height / 2 + tom->GetNowMapUnit()->GetPositionY()*Base::Window_Height / 2;
	}
}

int main(int argc, char* argv[]) 
{
	GameMap = new Map();
	GameMap->MapGenerate(6);
	SMap = new MiniMap(-0.8,0.8);
	tom = new Tom();
	tom->SetNowMapUnit(GameMap->GetWhichMapUnit(0, 0));
	HandGun* t = new HandGun();
	//RPG *t = new RPG();
	tom->ChangeWeapon(t);
	//MachineArmor* x = new MachineArmor(0.4, 0.4);
	for (int i = 0;i < 12;i++)
	{
		if (GameMap->ForeachMapUnit(i)->GetPositionX() == 0 && GameMap->ForeachMapUnit(i)->GetPositionY() == 0)
		{
			//Base::GameMap->ForeachMapUnit(i)->EnemyGenerate(4);
			break;
		}
	}
	//HandGunSoldier* m = new HandGunSoldier(0.4, 0);
	//Map* t = new Map(6);
	//Base::GameMap = t;
	//GameMap->ReadBlockFile();
	glutInit(&argc, argv);
	Init();
	glutReshapeFunc(reshape);
	glutMouseFunc(MouseBehavior);
	glutMotionFunc(MouseMove);
	glutKeyboardFunc(KeyBehavior);
	glutIgnoreKeyRepeat(1);//œûÓÃkeyrepeat
	glutKeyboardUpFunc(KeyUp);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutDisplayFunc(&display);
	glutIdleFunc(idle);
	glutMainLoop();
}
