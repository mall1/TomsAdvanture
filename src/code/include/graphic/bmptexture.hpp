#ifndef BMPTEXTURE_HPP
#define BMPTEXTURE_HPP

#include "bmp32.hpp"
#include <GL/glut.h>
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


bool BmpTexture::findTextureByName(std::string filename, unsigned int &textureNum){
    for(unsigned int i=0; i< texture.size();i++){
        if(texture[i].filename==filename){
            textureNum=texture[i].textureNum;
            return true;
        }
    }
    return false;
}

unsigned int BmpTexture::getTextureByName(std::string filename){
    unsigned int textureNum;
    if(findTextureByName(filename, textureNum))
        return textureNum;
    else
        return addTextureByName(filename);
}

unsigned int BmpTexture::addTextureByName(std::string filename){
    unsigned int textureNum;
    if(findTextureByName(filename,textureNum))
        ;
    else{
        glGenTextures(1 , &textureNum);
        BmpTexture_ bmpTexture_(filename, textureNum);
        glBindTexture(GL_TEXTURE_2D , textureNum);
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);//--------
        glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);//--------
        //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexImage2D(GL_TEXTURE_2D ,
              0 ,    // m ipmap 层次(通常为 0 , 表示最上层)
              GL_RGBA , //希望该纹理有红 、 绿 、 蓝数据
              bmpTexture_.bmp.bmpi.biWidth, //纹理宽带 , 必须是 2 n , 若有边框 + 2
              bmpTexture_.bmp.bmpi.biHeight , //纹理高度 , 必须是 2 n , 若有边框 + 2
              0 , //边框(0 = 无边框 , 1 = 有边框)
              GL_RGBA , //bitmap 数据的格式
              GL_UNSIGNED_BYTE , //每个颜色数据的类型
              (BYTE*)bmpTexture_.bmp.pixels) ;
        texture.push_back(bmpTexture_);
    }
    return textureNum;
}

#endif // BMPTEXTURE_H