#include"include/Base.h"
#include"include/Map.h"
#include"include/MiniMap.h"
#include"include/Tom.h"
#include"include/bullet.h" 


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
	Base::Block_Width = 30;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glTranslatef(move[0], move[1], 0);
	Base::GameMap->ReDraw();
	Base::SMap->ReDraw();
	Base::tom->ReDraw();
	bullet::AllReDraw();
	//glPopMatrix();
	glutSwapBuffers();
}

void reshape(int width,int height)
{
	int i;
}

void idle()
{
	if (Shoot)
	{
		if (count % 100 == 0)
			Base::tom->Shoot(bx, by);
		count++;
	}
	else count = 0;
	for (int i = 0;i < bullet::AllBullet.size();i++)
		bullet::AllBullet[i]->MoveJudge();
	if(TomMove[0])
		Base::tom->MoveStep(Base::up);
	if(TomMove[1])
		Base::tom->MoveStep(Base::down);
	if(TomMove[2])
		Base::tom->MoveStep(Base::left);
	if(TomMove[3])
		Base::tom->MoveStep(Base::right);
	glutPostRedisplay();
}

void KeyBehavior(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':move[1] -= 0.2;break;
	case 's':move[1] += 0.2;break;
	case 'a':move[0] += 0.2;break;
	case 'd':move[0] -= 0.2;break;
	case 'i':TomMove[0] = true;break;
	case 'k':TomMove[1] = true;break;
	case 'j':TomMove[2] = true;break;
	case 'l':TomMove[3] = true;break;
	}
	//glutPostRedisplay();
}

void KeyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'i':TomMove[0] = false;break;
	case 'k':TomMove[1] = false;break;
	case 'j':TomMove[2] = false;break;
	case 'l':TomMove[3] = false;break;
	}
}

void MouseBehavior(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		Shoot = false;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Shoot = true;
		bx = x - Base::Window_Width / 2 - Base::tom->GetPositionX()*Base::Window_Width / 2;
		by = Base::Window_Height / 2 - y - Base::tom->GetPositionY()*Base::Window_Height / 2;
	}
}

void MouseMove(int x, int y)
{
	if (Shoot)
	{
		bx = x - Base::Window_Width / 2 - Base::tom->GetPositionX()*Base::Window_Width / 2;
		by = Base::Window_Height / 2 - y - Base::tom->GetPositionY()*Base::Window_Height / 2;
	}
}

int main(int argc, char* argv[]) 
{
	Base::GameMap = new Map();
	Base::GameMap->MapGenerate(6);
	Base::SMap = new MiniMap(-0.8,0.8);
	Base::tom = new Tom();
	glutInit(&argc, argv);
	Init();
	glutReshapeFunc(reshape);
	lutMouseFunc(MouseBehavior);
	glutMotionFunc(MouseMove);
	glutKeyboardFunc(KeyBehavior);
	glutIgnoreKeyRepeat(1);//½ûÓÃkeyrepeat
	glutKeyboardUpFunc(KeyUp);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutDisplayFunc(&display);
	glutIdleFunc(idle);
	glutMainLoop();
}
