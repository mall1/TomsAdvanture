#ifndef UI_HPP
#define UI_HPP

#include "window.hpp"
#include "text.hpp"
#include"button.hpp"
#include <GL/glut.h>

extern BmpTexture bmpTexture;
Window *window;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(window)
        window->display();
    glutSwapBuffers();
}

void reshape(int width,int height)
{
    if(window){
        window->reshape(width, height);
    }
}

void mouse(int a, int b, int x, int y){
    if(window)
        window->onclick(x,y);
}

void idle()
{
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{

}
void init(int argc, char* argv[]){

    glutInit(&argc, argv);

    window= new Window("Tom's Adventure");

	/*将整个开始界面从上到下分为4层，分别占1/8，5/8，1/8，1/8，设置键放在第一层，新游戏键放在第三层*/
    window->addView("BEGIN");
	window->curView->layout.type = Layout::Type::vertical;
    window->curView->layout.addItem(1);
    window->curView->layout.addItem(5);
	window->curView->layout.addItem(1);
    window->curView->layout.addItem(1);

    /*Layout SetupLayer("SetupLayer");
	//开始界面的“设置”布局
    window->curView->layout.items[0].item=&SetupLayer;
	SetupLayer.Parent=&window->curView->layout.items[0];
	SetupLayer.type = Layout::Type::horizontal;
	SetupLayer.addItem(5);
	SetupLayer.addItem(1);
	SetupLayer.items[1].item = new Button("Setup");/*在第一层最右边插入按钮控件*/

	Layout NewgameLayer("NewgameLayer");/*开始界面的“新游戏”按钮布局*/
	window->curView->layout.items[2].item = &NewgameLayer;
	NewgameLayer.Parent = &window->curView->layout.items[2];
	NewgameLayer.type = Layout::Type::horizontal;
	NewgameLayer.addItem(3);
	NewgameLayer.addItem(1);
	NewgameLayer.addItem(1);
	NewgameLayer.addItem(3);
	NewgameLayer.items[1].item = new Button("NewGame");/*在第三层中间插入“NewGame”按钮控件*/
	NewgameLayer.items[2].item = new Button("RestartGame");/*Restart*/

/*布局游戏界面*/
	window->addView("InGame");
	window->curView->layout.type = Layout::Type::vertical;
	window->curView->layout.addItem(1);
	window->curView->layout.addItem(6);
	window->curView->layout.addItem(1);

	Layout HeadLayer("HeadLine");
	window->curView->layout.items[0].item = &HeadLayer;
	HeadLayer.Parent = &window->curView->layout.items[0];
	HeadLayer.type = Layout::Type::horizontal;
	HeadLayer.addItem(2);
	HeadLayer.addItem(6);
	HeadLayer.addItem(1);
	HeadLayer.items[0].item = new Lifespan("Lifespan");/*在第一层最左边插入血条控件*/
	HeadLayer.items[2].item = new Button("Stop");/*在第一层最右边插入暂停控件*/

	Layout EndLayer("Endline");
	window->curView->layout.items[2].item = &EndLayer;
	EndLayer.Parent = &window->curView->layout.items[2];
	EndLayer.type = Layout::Type::horizontal;
	EndLayer.addItem(8);
	EndLayer.addItem(1);
	EndLayer.items[1].item = new Button("Arm");/*在第一层最右边插入武器控件*/

	//暂停界面布局
	window->addView("StopGame");
	window->curView->layout.type = Layout::Type::vertical;
	window->curView->layout.addItem(1);
	window->curView->layout.addItem(1);
	window->curView->layout.addItem(1);

	Layout MiddleLayer("MiddleLine");
	window->curView->layout.items[1].item = &MiddleLayer;
	MiddleLayer.Parent = &window->curView->layout.items[1];
	MiddleLayer.type = Layout::Type::horizontal;
	MiddleLayer.addItem(1);
	MiddleLayer.addItem(1);
	MiddleLayer.addItem(1);
	MiddleLayer.addItem(1);
	MiddleLayer.addItem(1);
	
	MiddleLayer.items[1].item = new Button("Home");/*home控件*/
	MiddleLayer.items[3].item = new Button("ContinueGame");/*“继续游戏”控件*/

	//设置界面
	window->addView("Setup");
	window->curView->layout.type = Layout::Type::vertical;
	window->curView->layout.addItem(1);
	window->curView->layout.addItem(6);
	window->curView->layout.addItem(1);

	Layout FinishLayer("Finish");
	FinishLayer.addItem(4);
	FinishLayer.addItem(1);
	FinishLayer.addItem(4);
	FinishLayer.items[1].item = new Button("Finish");/*home控件*/

	//游戏结束界面
	window->addView("Gameover");

    /*glClearColor(0, 0, 0, 0);
    //glShadeModel(GL_FLAT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //指定混合函数
    glEnable(GL_BLEND);

    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();*/


}

#endif // UI_HPP
