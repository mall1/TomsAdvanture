#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "widget.hpp"
#include "view.hpp"
#include <GL/glut.h>
#include <vector>
#include <string>

class Window:public Widget{
public:
    int handle;
    std::vector<View*> views;
    View* curView;
    void reshape(int width,int height){
        this->width=width;
        this->height=height;
    }

    Window(std::string name):Widget(name){
        glutInitWindowPosition(0, 0);
        glutInitWindowSize(WIDTH, HEIGHT);
        height=HEIGHT;
        width=WIDTH;
        fixedH=true;
        fixedW=true;
        fixedR=true;
        handle = glutCreateWindow(name.c_str());
        curView=0;
    }
    void addView(std::string name){
        curView = new View(name);
        curView->Parent=this;
        curView->height=height;
        curView->width=width;
    }
    View* findViewByName(std::string name){
        for(unsigned int i=0; i<views.size();i++)
            if(views[i]->name==name)
                return views[i];
    }
    bool changeViewByName(std::string name){
        for(unsigned int i=0; i<views.size();i++)
            if(views[i]->name==name){
                curView=views[i];
                return true;
            }
        return false;
    }
    void display(){
        if(!isHide){
            Widget::display();
            if(curView)
                curView->display();
        }
    }
    void onclick(int x, int y){
        updateCoord();
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty)
                if(curView)
                    curView->onclick(x, y);
    }
    void updateCoord(){
        lx=0;
        rx=width;
        ty=height;
        by=0;
    }
};
#endif // WINDOW_HPP
