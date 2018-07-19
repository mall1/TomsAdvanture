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
            Widget::display();
            if(curView)
                curView->display();
            updateState();
        }
    }
    bool mouseEvent(Control::MouseEventType type, int x, int y){
        bool clicked;
        updateCoord();
        clicked=Widget::mouseEvent(type,x,y);
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty)
                if(curView)
                    curView->mouseEvent(type, x, y);
        return clicked;
    }
    void updateCoord(){
        lx=0;
        rx=width;
        ty=height;
        by=0;
    }
    void updateState() {
        switch (WindowState::getstate()) {
        case WindowState::State::HomePage:
            curView = views[0];
            break;
        case WindowState::State::GamePage:
            curView = views[1];
            break;
        case WindowState::State::StopPage:
            curView = views[2];
            break;
        case WindowState::State::Home_SetupPage:
            curView = views[3];
            break;
        case WindowState::State::Game_SetupPage:
            curView = views[4];
            break;
        case WindowState::State::GameOverPage:
            curView = views[5];
            break;
        default:break;
        }
    }
};
#endif // WINDOW_HPP
