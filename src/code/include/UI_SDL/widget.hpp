#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphic.hpp"
#include <string>

 class Widget{
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
    double color[4];
    Widget *Parent;
    virtual void display(){
        if(isDisplay&&!isHide)
            Graphic::drawRect(lx,rx,ty,by,texture,color,subRraphRule);
    }
    virtual bool onclick(int x, int y){
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty){
                std::cout<<name<<"clicked"<<std::endl;
                return true;
            }
        return false;
    }
    //virtual void updateCoord();
    void updateCoord(){
        if(Parent){
        lx=Parent->lx+5;
        by=Parent->by+5;

        rx=Parent->rx-5;
        ty=Parent->ty-5;}
    }
    void addTexture(std::string filename){
        isDisplay=true;
        texture=Graphic::addTexture(filename);
    }
    Widget(std::string name):
        id(maxid),
        name(name),
        height(0),
        width(0),
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
        color({1,1,1,1}),
        subRraphRule({1,1,0}),
        Parent(0){
        maxid++;
    }
    ~Widget(){}
};

int Widget::maxid=0;
#endif // WIDGET_HPP
