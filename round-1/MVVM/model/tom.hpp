#ifndef TOM_HPP
#define TOM_HPP
#define TOMHEIGHT 20
#include <string>
#include "../common/graphic.hpp"
class Tom{
    std::string name;
    int x,y; //coord, initial as (0,0)
    double speed;//pixels per ms
    int blood;
    int height,width;//pixel
    void *texture; // texture=(void*)Graphic::textureLib.getTextureByName(filename)  ../param/xx.xml
    int subGraphRule[3]; //x graph num ,y graphnum ,cur graph num
    unsigned int color;//when the texture not exits, display as color rectangle
public:
    Tom():x(0),y(0),texture(0){}
    Tom(std::string filename):x(0),y(0),texture(0){
        readFromFile(filename);
    }
    void getcoord(int &x, int &y){x=this->x;y=this->y;}
    void setcoord(int x, int y){this->x=x;this->y=y;}
    void readFromFile(std::string filename);// string -> char[]: str.c_str();
};

#endif // TOM_HPP
