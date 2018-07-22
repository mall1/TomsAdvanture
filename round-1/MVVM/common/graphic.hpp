#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "texture.hpp"
#define COLERSSIZE 7

namespace Graphic{

    static TextureLib textureLib;
    int initH=720;
    int initW=1280;

    struct Font{
        std::string fontName;
        int fontSize;
        TTF_Font *font;
    };

    std::vector<Font*> fontLib;

    TTF_Font * getFont(std::string fontName, int fontSize);
    void drawRect(int lx, int rx, int ty, int by,void * texture, unsigned int color, int subGraphRule[3]);
    void drawFont(int lx, int ty, std::string text, std::string fontName, int fontSize, unsigned int color);
    void* addTexture(std::string filename);
    bool init();
    SDL_Surface* screen = NULL;
    void nextFrame();

    void gameDrawRect(double lx, double rx, double ty, double by, void* texture, unsigned int color){
        texture=textureLib.addTextureByName("../image/wall-green.bmp");
        SDL_Rect t;
        t.x=(lx+1)*360+280;
        t.y=initH-(ty+1)*360;
        t.w=(rx-lx)*360;
        t.h=(ty-by)*360;
        if(texture){
            SDL_BlitSurface((SDL_Surface*)texture,0, screen, &t);
        }
        else{
            SDL_FillRect(screen, &t, color);
        }
    }

    void gameDrawTom(double x, double y, double R, unsigned int color){
        gameDrawRect(x-R, x+R, y+R, y-R, 0, color);
    }

    void gameDrawBullet(double x, double y, double R, unsigned int color){
        gameDrawRect(x-R, x+R, y+R, y-R, 0, color);
    }
}


TTF_Font * Graphic::getFont(std::string fontName, int fontSize){
    for(int i=0; i<fontLib.size();i++)
        if(fontLib[i]->fontName==fontName&&fontLib[i]->fontSize==fontSize){
            return fontLib[i]->font;
        }
    Font * newFont = new Font;
    newFont->fontName=fontName;
    newFont->fontSize=fontSize;
    newFont->font=TTF_OpenFont(fontName.c_str(), fontSize);
    fontLib.push_back(newFont);
    return newFont->font;
}

void Graphic::nextFrame()
{
    SDL_Rect t;
    t.x=0;
    t.y=0;
    t.w=initW;
    t.h=initH;
    SDL_Flip(screen);
    SDL_FillRect(screen, &t, 0xff000000);
}
void* Graphic::addTexture(std::string filename){
    return (void*)textureLib.addTextureByName(filename);

}
void Graphic::drawRect(int lx, int rx, int ty, int by, void * texture, unsigned int color, int subGraphRule[3]){//color functions
    SDL_Rect s,t;
    t.x=lx;
    t.y=initH-ty;
    t.w=rx-lx;
    t.h=ty-by;
    if(texture){
        s.x=0;
        s.y=0;
        s.h=((SDL_Surface*)texture)->h;
        s.w=((SDL_Surface*)texture)->w;
        s.x=subGraphRule[2]%subGraphRule[0];
        s.y=subGraphRule[2]/subGraphRule[0];
        s.w/=subGraphRule[0];
        s.h/=subGraphRule[1];
        s.x*=s.w;
        s.y*=s.h;
        s.w=rx-lx;
        s.h=ty-by;
        SDL_BlitSurface((SDL_Surface*)texture,&s, screen, &t);
    }
    else{
        SDL_FillRect(screen, &t, color);
    }
}


void Graphic::drawFont(int lx, int ty, std::string text, std::string fontName, int fontSize, unsigned int color){

    TTF_Font *font = getFont( fontName.c_str(), fontSize );
    SDL_Color textColor = {(color>>16)%256, (color>>8)%256, color%256};
    SDL_Rect t;
    t.x=lx;
    t.y=initH-ty;
    SDL_Surface* message = TTF_RenderText_Solid( font,text.c_str(), textColor );
    SDL_BlitSurface(message,NULL, screen, &t);
    SDL_FreeSurface(message);
}

bool Graphic::init()
{

    SDL_Init( SDL_INIT_EVERYTHING );
    if( TTF_Init() == -1 )
        return false;
    screen = SDL_SetVideoMode( initW, initH, 32, SDL_SWSURFACE );

    return true;
}
#endif // GRAPHIC_HPP
