#include"Base.h"
#include"Map.h"


//static Map* GameMap;

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
	Base::GameMap->ReDraw();
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

int main(int argc, char* argv[]) 
{
	Map*t = new Map();
	Base::GameMap = t;
	//GameMap->ReadBlockFile();
	glutInit(&argc, argv);
	Init();
	glutReshapeFunc(reshape);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutDisplayFunc(&display);
	glutIdleFunc(idle);
	glutMainLoop();
}