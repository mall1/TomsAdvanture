#ifndef BMPTEXTURE_H
#define BMPTEXTURE_H

#include "bmp32.h"
#include "GL/glut.h"
#include <vector>
#include <string>

class BmpTexture_{
public:
    std::string filename;
    unsigned int textureNum;
    Bmp bmp;
    BmpTexture_(std::string filename, unsigned int textureNum):filename(filename),textureNum(textureNum), bmp(filename){}
};

class BmpTexture{
    std::vector<BmpTexture_> texture;

public:
    unsigned int getTextureByName(std::string filename);
    unsigned int addTextureByName(std::string filename);
    bool findTextureByName(std::string filename, unsigned int &textureNum);
};

static BmpTexture bmpTexture;

#endif // BMPTEXTURE_H
