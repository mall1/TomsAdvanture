#include"Base.h"
#include"Map.h"


//static Map* GameMap;
float eye[3] = { 0,0,0 };
float center[3] = { 0,0,0 };
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
	//glLoadIdentity();
	//gluLookAt(0, 0, 1,0, 0, 0,0, 1, 0);
	glPushMatrix();
	glTranslatef(move[0], move[1], 0);
	Base::GameMap->ReDraw();
	glPopMatrix();
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
	case 'w':eye[1] -= 0.1;center[1] -= 0.1;move[1] += 0.1;break;
	case 's':eye[1] += 0.1;center[1] += 0.1;move[1] -= 0.1;break;
	case 'a':eye[0] += 0.1;center[0] += 0.1;move[0] -= 0.1;break;
	case 'd':eye[0] -= 0.1;center[0] -= 0.1;move[0] += 0.1;break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]) 
{
	Base::GameMap = new Map();
	Base::GameMap->MapGenerate(6);
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