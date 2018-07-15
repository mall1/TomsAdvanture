#include"Base.h"
#include"Map.h"
#include"MiniMap.h"


float move[2] = { 0,0 };

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
	//glPopMatrix();
	glutSwapBuffers();
}

void reshape(int width,int height)
{
	int i;
}

void idle()
{
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
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]) 
{
	Base::GameMap = new Map();
	Base::GameMap->MapGenerate(6);
	Base::SMap = new MiniMap(-0.8,0.8);
	//Map* t = new Map(6);
	//Base::GameMap = t;
	//GameMap->ReadBlockFile();
	glutInit(&argc, argv);
	Init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyBehavior);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutDisplayFunc(&display);
	glutIdleFunc(idle);
	glutMainLoop();
}