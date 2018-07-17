#ifndef VIEW_HPP
#define VIEW_HPP
#include "widget.hpp"
#include "layout.hpp"
#include <string>
class View:public Widget{
public:
    Layout layout;
    View(std::string name):
        Widget(name),
        layout(name+"-layout"){
        layout.Parent=this;
    }
    void display(){
        if(!isHide){
            Widget::display();
            layout.display();
        }
    }
    void onclick(int x, int y){
        updateCoord();
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty)
                layout.onclick(x, y);
    }
    void updateCoord(){
        lx=Parent->lx;
        by=Parent->by;

        rx=Parent->rx;
        ty=Parent->ty;
    }
};


#endif // VIEW_HPP
