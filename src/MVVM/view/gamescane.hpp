#ifndef GAMESCANE_H
#define GAMESCANE_H
#include "widget.hpp"
#include "layout.hpp"
#include "../viewmodel/gamestate.hpp"
#include "../common/graphic.hpp"
#include <string>
class GameScane:public Widget{
public:
    GameState *gamestate;

    GameScane(std::string name, GameState *gamestate):Widget(name),gamestate(gamestate){}

    void display(){
        updateCoord();
        Widget::display();
        if(isDisplay)
            displayscane();
    }

    void displayscane(){
        if(gamestate==0) return;
        int sub[3]={1,1,0};
        int map[MAXBLOCKSIZE*MAXBLOCKSIZE];
        int size;
        int ox=(lx+rx)/2;
        int oy=(ty+by)/2;
        int tomx,tomy;
        unsigned int color;
        displaymap();

        gamestate->getTom(tomx,tomy);
        Graphic::drawRect(ox+tomx-TOMHEIGHT/2, ox+tomx+TOMHEIGHT/2, oy+tomy+TOMHEIGHT/2,  oy+tomy-TOMHEIGHT/2, texture,0xffff0000, sub);


    }
    void displaymap(){
        int sub[3]={1,1,0};
        int map[MAXBLOCKSIZE*MAXBLOCKSIZE];
        int size;
        int ox=(lx+rx)/2;
        int oy=(ty+by)/2;
        unsigned int color;
        gamestate->getMap(map,size);
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                switch (map[i+j*size]) {
                case 0: color=0xff00ff00;break;
                case 1: color=0xff0000ff;break;
                default:
                    //texture=(void*)Graphic::textureLib.addTextureByName("../image/ground-blue.bmp");
                    break;
                }
                Graphic::drawRect(ox+(i-size/2)*BLOCKLENGTH, ox+(i-size/2+1)*BLOCKLENGTH, oy+(size/2-j)*BLOCKLENGTH,  oy+(size/2-j-1)*BLOCKLENGTH, texture,color, sub);
            }
        }
    }
    void displaytom(){
        int sub[3]={1,1,0};
        int ox=(lx+rx)/2;
        int oy=(ty+by)/2;
        int tomx,tomy;
        unsigned int color=0xffff0000;

        gamestate->getTom(tomx,tomy);
        Graphic::drawRect(ox+tomx-TOMHEIGHT/2, ox+tomx+TOMHEIGHT/2, oy+tomy+TOMHEIGHT/2,  oy+tomy-TOMHEIGHT/2, texture,color, sub);
    }
};

#endif // GAMESCANE_H
