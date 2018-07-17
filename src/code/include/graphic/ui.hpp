#ifndef UI_HPP
#define UI_HPP

#include "window.hpp"
#include "text.hpp"
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
    /*double color[7][4]={1,1,1,1,
                 1,0,1,1,
                 0,1,1,1,
                 1,1,0,1,
                 1,0,0,1,
                 0,1,0,1,
                 0,0,1,1};*/

    window= new Window("Tom's Adventure");
    window->addView("BEGIN");
	window->curView->layout.type = Layout::Type::vertical;
    window->curView->layout.addItem(1);
    window->curView->layout.addItem(6);
    window->curView->layout.addItem(1);
    Layout Setup("Setup");
    window->curView->layout.items[0].item=&Setup;
    Setup.Parent=&window->curView->layout.items[0];
	Button
	Setup.type = Layout::Type::horizontal;
	Setup.addItem(1);
	Setup.addItem(4);
	Setup.addItem(1);
    //window->curView->layout.items[2].isHide=1;
    for(unsigned int j=0;j<window->curView->layout.items.size();j++)
        for(int i=0;i<4;i++)
            window->curView->layout.items[j].color[i]=color[j][i];
    for(unsigned int j=0;j<lll.items.size();j++)
        for(int i=0;i<4;i++)
            lll.items[j].color[i]=color[j][i];

    window->curView->layout.items[0].addBmpTexture("wall-gray.bmp");
    /*window->curView->layout.items[1].addBmpTexture("wall-green.bmp");
    window->curView->layout.items[2].addBmpTexture("wall-gray.bmp");
    window->curView->layout.items[3].addBmpTexture("wall-green.bmp");
    window->curView->layout.items[4].addBmpTexture("wall-gray.bmp");
    //window->curView->layout.items[1].isHide=1;*/



    glClearColor(0, 0, 0, 0);
    //glShadeModel(GL_FLAT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //指定混合函数
    glEnable(GL_BLEND);

    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();


}

#endif // UI_HPP
