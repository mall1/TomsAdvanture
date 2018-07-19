#include"Base.h"
#include"Map.h"
#include"MiniMap.h"
#include"Tom.h"
#include"NormalBullet.h"
#include"HandGun.h"
#include"RPG.h"
#include"HandGunSoldier.h"
#include"MachineArmor.h"
#include"iostream"


float move[2] = { 0,0 };
bool TomMove[4] = { false,false,false,false };
bool Shoot = false;
int bx;
int by;
int count = 0;

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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	//glTranslatef(move[0], move[1], 0);
	Base::GameMap->ReDraw();
	Base::tom->ReDraw();
	Enemy::AllReDraw();
	bullet::AllReDraw();
	//glPopMatrix();
	Base::SMap->ReDraw();
	//glPopMatrix();
	glutSwapBuffers();
}

void reshape(int width,int height)
{
	int i;
}

void idle()
{
	if (Base::CounterAll == Base::Clk)
		Base::CounterAll = 0;
	else Base::CounterAll++;
	if (Shoot)
	{
		if (count % Base::tom->GetNowWeapon()->GetAttackSpeed() == 0)
			Base::tom->Shoot(bx, by);
		count++;
	}
	else count = 0;
	bullet::AllMoveJudge();
	Enemy::AllIsDied();
	Enemy::AllJudge();
	if(TomMove[0])
		Base::tom->MoveStep(Base::up);
	if(TomMove[1])
		Base::tom->MoveStep(Base::down);
	if(TomMove[2])
		Base::tom->MoveStep(Base::left);
	if(TomMove[3])
		Base::tom->MoveStep(Base::right);
	Base::tom->GetNowMapUnit()->NoneEnemyJudge();
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
		bx = x - Base::Window_Width / 2 - Base::tom->GetPositionX()*Base::Window_Width / 2 + Base::tom->GetNowMapUnit()->GetPositionX()*Base::Window_Width / 2;
		by = Base::Window_Height / 2 - y - Base::tom->GetPositionY()*Base::Window_Height / 2 + Base::tom->GetNowMapUnit()->GetPositionY()*Base::Window_Height / 2;
	}
}

void MouseMove(int x, int y)
{
	if (Shoot)
	{
		bx = x - Base::Window_Width / 2 - Base::tom->GetPositionX()*Base::Window_Width / 2 + Base::tom->GetNowMapUnit()->GetPositionX()*Base::Window_Width / 2;
		by = Base::Window_Height / 2 - y - Base::tom->GetPositionY()*Base::Window_Height / 2 + Base::tom->GetNowMapUnit()->GetPositionY()*Base::Window_Height / 2;
	}
}

int main(int argc, char* argv[]) 
{
	Base::GameMap = new Map();
	Base::GameMap->MapGenerate(6);
	Base::SMap = new MiniMap(-0.8,0.8);
	Base::tom = new Tom();
	HandGun* t = new HandGun();
	//RPG *t = new RPG();
	Base::tom->ChangeWeapon(t);
	//MachineArmor* x = new MachineArmor(0.4, 0.4);
	for (int i = 0;i < 12;i++)
	{
		if (Base::GameMap->ForeachMapUnit(i)->GetPositionX() == 0 && Base::GameMap->ForeachMapUnit(i)->GetPositionY() == 0)
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
	glutIgnoreKeyRepeat(1);//½ûÓÃkeyrepeat
	glutKeyboardUpFunc(KeyUp);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutDisplayFunc(&display);
	glutIdleFunc(idle);
	glutMainLoop();
}