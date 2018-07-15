#include "bmp32.h"

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
        if(pixels[i].R!=255){
            pixels[i].A=255;
        }
    }
    fclose(fp);
}

Bmp::Bmp(char* filename){
    freadBmp(filename);
}

Bmp::Bmp(std::string filename){
    char* tmp=new char(filename.size()+1);
    for(int i=0; i< filename.size();i++)
        tmp[i]=filename[i];
    tmp[filename.size()]=0;
    freadBmp(tmp);
}

Bmp::Bmp(){
}

Bmp::~Bmp(){
    free(pixels);
}
