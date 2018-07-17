#ifndef BMP32_HPP
#define BMP32_HPP

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#define UINT16 uint16_t
#define WORD uint16_t
#define DWORD uint32_t
#define LONG int32_t
#define BYTE uint8_t

typedef struct tagBITMAPFILEHEADER
{
    UINT16 bfType;
    DWORD bfSize;
    UINT16 bfReserved1;
    UINT16 bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
    DWORD biSize; //指定此结构体的长度
    LONG biWidth; //位图宽
    LONG biHeight; //位图高
    WORD biPlanes; //平面数，为1
    WORD biBitCount; //采用颜色位数，可以是1，2，4，8，16，24，新的可以是32
    DWORD biCompression; //压缩方式，可以是0，1，2，其中0表示不压缩
    DWORD biSizeImage; //实际位图数据占用的字节数
    LONG biXPelsPerMeter; //X方向分辨率
    LONG biYPelsPerMeter; //Y方向分辨率
    DWORD biClrUsed; //使用的颜色数，如果为0，则表示默认值(2^颜色位数)
    DWORD biClrImportant; //重要颜色数，如果为0，则表示所有颜色都是重要的
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
//public:
    BYTE rgbBlue; //该颜色的蓝色分量
    BYTE rgbGreen; //该颜色的绿色分量
    BYTE rgbRed; //该颜色的红色分量
    BYTE rgbReserved; //保留值
} RGBQUAD;

typedef struct tagRGB32 {
//public:
    BYTE B; //该颜色的蓝色分量
    BYTE G; //该颜色的绿色分量
    BYTE R; //该颜色的红色分量
    BYTE A;
} RGB32;




class Bmp{

public:
    BITMAPFILEHEADER bmph;
    BITMAPINFOHEADER bmpi;
    RGB32* pixels;
    Bmp();
    Bmp(char * filename);
    Bmp(std::string filename);
    ~Bmp();
    void freadBmpi(FILE *fp);
    void freadBmph(FILE *fp);
    void freadBmp(char* filename);
};


void Bmp::freadBmph(FILE * fp){
    fread((void*)&bmph.bfType, 2, 1, fp);
    fread((void*)&bmph.bfSize, 4, 1, fp);
    fread((void*)&bmph.bfReserved1, 2, 1, fp);
    fread((void*)&bmph.bfReserved2, 2, 1, fp);
    fread((void*)&bmph.bfOffBits, 4, 1, fp);
}

void Bmp::freadBmpi(FILE * fp){
    fread((void*)&bmpi.biSize, 4, 1, fp);
    fread((void*)&bmpi.biWidth, 4, 1, fp);
    fread((void*)&bmpi.biHeight, 4, 1, fp);
    fread((void*)&bmpi.biPlanes, 2, 1, fp);
    fread((void*)&bmpi.biBitCount, 2, 1, fp);
    fread((void*)&bmpi.biCompression, 4, 1, fp);
    fread((void*)&bmpi.biSizeImage, 4, 1, fp);
    fread((void*)&bmpi.biXPelsPerMeter, 4, 1, fp);
    fread((void*)&bmpi.biYPelsPerMeter, 4, 1, fp);
    fread((void*)&bmpi.biClrUsed, 4, 1, fp);
    fread((void*)&bmpi.biClrImportant, 4, 1, fp);
}

void Bmp::freadBmp(char *filename){
    FILE *fp;

    if((fp=fopen(filename, "r"))==NULL){
        printf("%s can not be opened.\n",filename);
        return;
    }
    freadBmph(fp);
    freadBmpi(fp);
    int size=bmpi.biWidth*bmpi.biHeight;
    pixels=new RGB32[size];
    fread((void*)pixels, bmpi.biSize-40, 1, fp);
    for(int i=0; i<size; i++){
        fread((void*)&pixels[i].A, 1, 1, fp);
        fread((void*)&pixels[i].R, 1, 1, fp);
        fread((void*)&pixels[i].G, 1, 1, fp);
        fread((void*)&pixels[i].B, 1, 1, fp);
    }
    fclose(fp);
}

Bmp::Bmp(char* filename){
    freadBmp(filename);
}

Bmp::Bmp(std::string filename){
    char* tmp=new char(filename.size()+1);
    for(unsigned int i=0; i< filename.size();i++)
        tmp[i]=filename[i];
    tmp[filename.size()]=0;
    freadBmp(tmp);
}

Bmp::Bmp(){
}

Bmp::~Bmp(){
    //free(pixels);
}

#endif
