#ifndef VIEW_HPP
#define VIEW_HPP
#include "widget.hpp"
#include "layout.hpp"
#include <string>
class View:public Widget{
public:
    Layout layout;
    View(std::string name, Layout::Type type=Layout::Type::horizontal):
        Widget(name),
        layout(name+"-layout",type){
        layout.Parent=this;
        isDisplay=0;
    }
    void display(){
        if(!isHide){
            updateCoord();
            Widget::display();
            layout.display();
        }
    }
    bool mouseEvent(Event::EventType type,int x, int y){
        bool clicked;
        updateCoord();
        clicked=Widget::mouseEvent(type, x,y);
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty)
                layout.mouseEvent(type, x, y);
        return clicked;
    }
};


#endif // VIEW_HPP
