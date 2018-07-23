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
        displaytom();
        displaymonster();
    }
    void displaymap(){
        int sub[3]={1,1,0};
        int map[MAXBLOCKSIZE*MAXBLOCKSIZE];
        int size;
        int ox=(lx+rx)/2;
        int oy=(ty+by)/2;
        unsigned int color;
        void *texture=0;
        gamestate->getMap(map,size);
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                switch (map[i+j*size]) {
                case 0:
                    texture=(void*)Graphic::textureLib.addTextureByName("../image/ground-orange.png");
                    break;
                case 1:
                    texture=(void*)Graphic::textureLib.addTextureByName("../image/wall-orange.png");
                    break;
                case 2:
                    texture=(void*)Graphic::textureLib.addTextureByName("../image/ground-orange.png");
                    break;
                case 3:
                    texture=(void*)Graphic::textureLib.addTextureByName("../image/door-orange.png");
                    break;
                default:break;
                }
                Graphic::drawBlock(20,ox+(i-size/2)*BLOCKLENGTH, ox+(i-size/2+1)*BLOCKLENGTH, oy+(size/2-j)*BLOCKLENGTH,  oy+(size/2-j-1)*BLOCKLENGTH, texture,color, sub);
            }
        }
    }
    void displaytom(){
        int sub[3]={1,1,0};
        int ox=(lx+rx)/2;
        int oy=(ty+by)/2;
        int tomx,tomy;
        void* texture=0;
        unsigned int color=0xffff0000;

        gamestate->getTom(tomx,tomy);
        Graphic::drawRect(ox+tomx-TOMHEIGHT/2, ox+tomx+TOMHEIGHT/2, oy+tomy+TOMHEIGHT/2,  oy+tomy-TOMHEIGHT/2, texture,color, sub);
    }
    void displaymonster(){
        int sub[3]={1,1,0};
        int ox=(lx+rx)/2;
        int oy=(ty+by)/2;
        std::vector<int>mxs;
        std::vector<int>mys;
        void* texture=0;
        unsigned int color=0xffff8800;

        gamestate->getMonster(mxs,mys);
        for(int i=0; i<mxs.size(); i++)
            Graphic::drawRect(ox+mxs[i]-TOMHEIGHT/2, ox+mxs[i]+TOMHEIGHT/2, oy+mys[i]+TOMHEIGHT/2,  oy+mys[i]-TOMHEIGHT/2, texture,color, sub);
    }
};

#endif // GAMESCANE_H
