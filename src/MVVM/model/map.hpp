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
    int getSize(){return size;}
    int getBlock(int i, int j){
        if(0<=i&&i<size&&0<=j&&j<size)
            return blocks[i][j];
        else
            return -1;
    }
    SubMap(int size):size(size),l(0),r(0),t(0),b(0){
        for(int i=0;i<size;i++){
            for(int j=0; j<size; j++){
                if(i==0||j==0||i==size-1||j==size-1)
                    blocks[i][j]=1;
                else
                    blocks[i][j]=0;
            }
        }
    }

};

class Map{
public:
    std::string name;
    int curSubMapId;
    std::vector<SubMap*>subMaps;
    Map() {}
    SubMap* addSubMap(int size){
        SubMap* submap=new SubMap(size);
        subMaps.push_back(submap);
        curSubMapId=subMaps.size()-1;
        return submap;
    }
    SubMap* addSubMap(SubMap* submap){
        subMaps.push_back(submap);
        return submap;
    }
    void connectSubMap(int id1, int id2, int dir1, int dir2){
        if(id1<subMaps.size()&&id2<subMaps.size()){
            switch(dir1){
            case 1:subMaps[id1]->l=subMaps[id2];break;
            case 2:subMaps[id1]->r=subMaps[id2];break;
            case 3:subMaps[id1]->t=subMaps[id2];break;
            case 4:subMaps[id1]->b=subMaps[id2];break;
            }
            switch(dir2){
            case 1:subMaps[id2]->l=subMaps[id1];break;
            case 2:subMaps[id2]->r=subMaps[id1];break;
            case 3:subMaps[id2]->t=subMaps[id1];break;
            case 4:subMaps[id2]->b=subMaps[id1];break;
            }
        }
    }

    void curSubMap(int* map, int &size){
        if(subMaps.size()==0)return;
        size=subMaps[curSubMapId]->getSize();
        for(int i=0; i<MAXBLOCKSIZE; i++)
            for(int j=0; j<MAXBLOCKSIZE;j++)
                map[i+j*size]=subMaps[curSubMapId]->getBlock(i,j);
    }
};

#endif
