#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "../viewmodel/control.hpp"
#include "../common/graphic.hpp"
#include <string>
#include <iostream>
class Widget{
protected:
    enum Align{lt,lb,rt,rb,t,b,l,r,c};
    Align align;
public:
    static int maxid;
    int id;
    std::string name;
    int height;
    int width;
    int lx,rx;
    int ty,by;
    bool fixedH;
    bool fixedW;
    bool fixedR;
    bool matchPH;
    bool matchPW;
    bool isHide;
    bool isDisplay;
    void* texture;
    int subRraphRule[3];
    unsigned int color;
    Widget *Parent;
    Widget(std::string name):
        id(maxid),
        name(name),
        align(Align::c),
        lx(0),
        rx(0),
        ty(0),
        by(0),
        fixedH(false),
        fixedW(false),
        fixedR(false),
        matchPH(true),
        matchPW(true),
        isHide(false),
        isDisplay(true),
        texture(0),
        color(0xffffffff),
        subRraphRule({1,1,0}),
        Parent(0){
        height=rx-lx;
        width=ty-by;
        maxid++;
    }
    ~Widget(){}
    virtual void display(){
        int gapx,gapy;
        gapx=(rx-lx-width)/2;
        gapy=(ty-by-height)/2;
        if(isDisplay&&!isHide){
            switch (align) {
            case Align::lt: Graphic::drawRect(lx+0*gapx,rx-2*gapx,ty-0*gapy,by+2*gapy,texture,color,subRraphRule); break;
            case Align::lb: Graphic::drawRect(lx+0*gapx,rx-2*gapx,ty-2*gapy,by+0*gapy,texture,color,subRraphRule); break;
            case Align::rt: Graphic::drawRect(lx+2*gapx,rx-0*gapx,ty-0*gapy,by+2*gapy,texture,color,subRraphRule); break;
            case Align::rb: Graphic::drawRect(lx+2*gapx,rx-0*gapx,ty-2*gapy,by+0*gapy,texture,color,subRraphRule); break;
            case Align::t : Graphic::drawRect(lx+1*gapx,rx-1*gapx,ty-0*gapy,by+2*gapy,texture,color,subRraphRule); break;
            case Align::b : Graphic::drawRect(lx+1*gapx,rx-1*gapx,ty-2*gapy,by+0*gapy,texture,color,subRraphRule); break;
            case Align::l : Graphic::drawRect(lx+0*gapx,rx-2*gapx,ty-1*gapy,by+1*gapy,texture,color,subRraphRule); break;
            case Align::r : Graphic::drawRect(lx+2*gapx,rx-0*gapx,ty-1*gapy,by+1*gapy,texture,color,subRraphRule); break;
            case Align::c : Graphic::drawRect(lx+1*gapx,rx-1*gapx,ty-1*gapy,by+1*gapy,texture,color,subRraphRule); break;
            default: break;
            }
        }
    }
    virtual bool mouseEvent(Event::EventType type, int x, int y){
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty){
                switch(type){
                case Event::EventType::leftKeyUp: std::cout<<"left key up ";break;
                case Event::EventType::leftKeyDown: std::cout<<"left key down ";break;
                case Event::EventType::move: std::cout<<" move "<<x<<","<<y;break;
                default:break;
                }
                //std::cout<<name<<"clicked"<<std::endl;
                return true;
            }
        return false;
    }
    void updateCoord(){
        if(Parent){
            //lx=Parent->lx+5;
            //by=Parent->by+5;
            //rx=Parent->rx-5;
            //ty=Parent->ty-5;
            lx=Parent->lx;
            by=Parent->by;
            rx=Parent->rx;
            ty=Parent->ty;
        }
    }
    void addTexture(std::string filename){
        isDisplay=true;
        texture=Graphic::addTexture(filename);
    }
};

int Widget::maxid=0;
#endif // WIDGET_HPP
