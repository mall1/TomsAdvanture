#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "bmptexture.hpp"
#include <string>
#include <GL/glut.h>

static BmpTexture bmpTexture;

#define WIDTH 1280
#define HEIGHT 720

double X( int x){
    return (double)x*2/WIDTH-1;
}
double Y( int x){
    return (double)x*2/HEIGHT-1;
}


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
    unsigned int texture;
    double color[4];
    Widget *Parent;
    virtual void display(){
        glDisable(GL_DEPTH_TEST);
        updateCoord();
        if(!isHide){
            glColor4dv(color);
            if(texture){
                glColor4d(1,1,1,1);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D , texture);
                glBegin(GL_POLYGON);
                glTexCoord2i(0 , 1) ;
                glVertex2d(X(lx), Y(ty));
                glTexCoord2i(1 , 1) ;
                glVertex2d(X(rx), Y(ty));
                glTexCoord2i(1 , 0) ;
                glVertex2d(X(rx), Y(by));
                glTexCoord2i(0 , 0) ;
                glVertex2d(X(lx), Y(by));
                glEnd();
            }
            else{
                glBegin(GL_POLYGON);
                glVertex2d(X(lx), Y(ty));
                glVertex2d(X(rx), Y(ty));
                glVertex2d(X(rx), Y(by));
                glVertex2d(X(lx), Y(by));
                glEnd();
            }
        }
    }
    virtual void onclick(int x, int y){}
    //void updateCoord();
    virtual void updateCoord(){}
    void addBmpTexture(std::string bmpName){
        if(bmpName!="")
            texture=bmpTexture.getTextureByName(bmpName);
        else
            texture=0;
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
        texture(0),
        color({1,1,1,1}),
        Parent(0){
        maxid++;
    }
    ~Widget(){}
};

int Widget::maxid=0;
#endif // WIDGET_HPP
