#ifndef MAP_HPP
#define MAP_HPP
#include <vector>
#include <string>
#define MAXBLOCKSIZE 20
#define BLOCKLENGTH 30
//map.xml can contain some 1. data and 2. location of some submap.xml 3. connection between submaps
enum SubMapType{begin, end, fight, boss, store, box};
enum BlockType{poison, fire, ice, bomb, none, wall, ground};
class SubMap{
    SubMapType submaptype;
    int size;//even number !!! not odd
    int blocks[MAXBLOCKSIZE][MAXBLOCKSIZE]; // blocks[i][j]=(int) some BlockType
public:
    SubMap *l,*r,*t,*b;
    int state;//1 first 2 opened
    int getSize(){return size;}
    int getBlock(int i, int j){
        if(0<=i&&i<size&&0<=j&&j<size)
            return blocks[i][j];
        else
            return -1;
    }
    SubMap(int size):size(size),l(0),r(0),t(0),b(0),state(1){
        for(int i=0;i<size;i++){
            for(int j=0; j<size; j++){
                if(i==0||j==0||i==size-1||j==size-1)
                    blocks[i][j]=1;
                else
                    blocks[i][j]=0;
            }
        }
    }
    void createDoor(int dir){
        switch(dir){
        case 1: blocks[0][size/2-2]     =blocks[0][size/2-1]     =blocks[0][size/2]     =blocks[0][size/2+1]=3;     break;
        case 2: blocks[size-1][size/2-2]=blocks[size-1][size/2-1]=blocks[size-1][size/2]=blocks[size-1][size/2+1]=3;break;
        case 3: blocks[size/2-2][0]     =blocks[size/2-1][0]     =blocks[size/2][0]     =blocks[size/2+1][0]=3;     break;
        case 4: blocks[size/2-2][size-1]=blocks[size/2-1][size-1]=blocks[size/2][size-1]=blocks[size/2+1][size-1]=3;break;
        default:break;
        }
    }

    void openDoor(){
        if(l) blocks[0][size/2-2]     =blocks[0][size/2-1]     =blocks[0][size/2]     =blocks[0][size/2+1]=2;
        if(r) blocks[size-1][size/2-2]=blocks[size-1][size/2-1]=blocks[size-1][size/2]=blocks[size-1][size/2+1]=2;
        if(t) blocks[size/2-2][0]     =blocks[size/2-1][0]     =blocks[size/2][0]     =blocks[size/2+1][0]=2;
        if(b) blocks[size/2-2][size-1]=blocks[size/2-1][size-1]=blocks[size/2][size-1]=blocks[size/2+1][size-1]=2;
    }

};

class Map{
public:
    std::string name;
    SubMap* curSub;
    std::vector<SubMap*>subMaps;
    Map() {}
    SubMap* addSubMap(int size){
        SubMap* submap=new SubMap(size);
        subMaps.push_back(submap);
        curSub=submap;
        return submap;
    }
    SubMap* addSubMap(SubMap* submap){
        subMaps.push_back(submap);
        curSub=submap;
        return submap;
    }
    void connectSubMap(int id1, int id2, int dir1, int dir2){
        if(id1<subMaps.size()&&id2<subMaps.size()){
            switch(dir1){
            case 1:subMaps[id1]->l=subMaps[id2];subMaps[id1]->createDoor(1); break;
            case 2:subMaps[id1]->r=subMaps[id2];subMaps[id1]->createDoor(2); break;
            case 3:subMaps[id1]->t=subMaps[id2];subMaps[id1]->createDoor(3); break;
            case 4:subMaps[id1]->b=subMaps[id2];subMaps[id1]->createDoor(4); break;
            }
            switch(dir2){
            case 1:subMaps[id2]->l=subMaps[id1];subMaps[id2]->createDoor(1); break;
            case 2:subMaps[id2]->r=subMaps[id1];subMaps[id2]->createDoor(2); break;
            case 3:subMaps[id2]->t=subMaps[id1];subMaps[id2]->createDoor(3); break;
            case 4:subMaps[id2]->b=subMaps[id1];subMaps[id2]->createDoor(4); break;
            }
        }
    }

    void curSubMap(int* map, int &size){
        if(subMaps.size()==0)return;
        size=curSub->getSize();
        for(int i=0; i<size; i++)
            for(int j=0; j<size;j++)
                map[i+j*size]=curSub->getBlock(i,j);
    }

    void changeMap(int &x, int &y){
        int i= (x-15)/BLOCKLENGTH+curSub->getSize()/2;
        int j=-(y+15)/BLOCKLENGTH+curSub->getSize()/2;
        if(curSub->getBlock(i,j)==2){
            if(j==0){
                curSub=curSub->t;
                y=-(curSub->getSize()/2-1)*BLOCKLENGTH+16;
            }
            else if(j==curSub->getSize()-1){
                curSub=curSub->b;
                y=(curSub->getSize()/2-1)*BLOCKLENGTH-16;
            }
            else if(i==0){
                curSub=curSub->l;
                x=(curSub->getSize()/2-1)*BLOCKLENGTH-16;
            }

            else if(i==curSub->getSize()-1){
                curSub=curSub->r;
                x=-(curSub->getSize()/2-1)*BLOCKLENGTH+16;
            }
        }
    }
};

#endif
