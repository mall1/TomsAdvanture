#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "windowstate.hpp"
#include "widget.hpp"
#include "view.hpp"
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
        height=Graphic::initH;
        width=Graphic::initW;
        fixedH=true;
        fixedW=true;
        fixedR=true;
        curView=0;
        isDisplay=0;
    }
    void addView(std::string name, Layout::Type type=Layout::Type::horizontal){
        curView = new View(name, type);
        curView->Parent=this;
        curView->height=height;
        curView->width=width;
        views.push_back(curView);
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
            updateCoord();
            updateState();
            Widget::display();
            if(curView)
                curView->display();
        }
    }
    bool onclick(int x, int y){
        bool clicked;
        updateCoord();
        clicked=Widget::onclick(x,y);
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty)
                if(curView)
                    curView->onclick(x, y);
        return clicked;
    }
    void updateCoord(){
        lx=0;
        rx=width;
        ty=height;
        by=0;
    }
    void updateState(){
        switch(WindowState::getstate()){
        case WindowState::State::aa: break;
        default:break;
        }
    }
};
#endif // WINDOW_HPP
