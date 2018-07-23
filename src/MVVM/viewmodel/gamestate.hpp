#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "../model/game.hpp"
#define ATTACKR 10
class GameState{
    Game *game;
public:
    bool fire;
    bool toml, tomr, tomt, tomb;
    GameState(Game * game):game(game){

        toml=0;
        tomr=0;
        tomt=0;
        tomb=0;
    }

    void getTom(int &x,int &y){
        game->tom.getcoord(x,y);
    }

    void getMonster(std::vector<int> &mxs,std::vector<int> &mys){
        int x,y;
        mxs.clear();
        mys.clear();
        for(int i=0;i<game->monsters.size();i++){
            game->monsters[i]->getcoord(x,y);
            mxs.push_back(x);
            mys.push_back(y);
        }
    }

    void getMap(int *map, int &size){
        game->map.curSubMap(map,size);
    }
    void mouseEvent(){

    }

    void TomMove(){
        int x, y;
        game->tom.getcoord(x,y);
        x+=(tomr-toml)*3;
        y+=(tomt-tomb)*3;
        if(game->map.curSub->getBlock((x-15)/BLOCKLENGTH+game->map.curSub->getSize()/2, -(y+15)/BLOCKLENGTH+game->map.curSub->getSize()/2)==0)
            game->tom.setcoord(x,y);

        else if(game->map.curSub->getBlock((x-15)/BLOCKLENGTH+game->map.curSub->getSize()/2, -(y+15)/BLOCKLENGTH+game->map.curSub->getSize()/2)==2){
            game->map.changeMap(x,y);
            game->tom.setcoord(x,y);
        }
    }

    void monsterMove(Monster* m){
        int x, y;
        m->getcoord(x,y);
        x+=(rand()%3-1)*3;
        y+=(rand()%3-1)*3;
        if(game->map.curSub->getBlock((x-15)/BLOCKLENGTH+game->map.curSub->getSize()/2, -(y+15)/BLOCKLENGTH+game->map.curSub->getSize()/2)==0)
            m->setcoord(x,y);
    }

    void attackMonster(int x, int y){
        int dx,dy;
        for(int i=0; i<game->monsters.size();i){
            game->monsters[i]->getcoord(dx,dy);
            dx-=x;
            dy-=y;
            if(dx*dx+dy*dy<=ATTACKR*ATTACKR){
                game->monsters[i]=game->monsters[game->monsters.size()-1];
                game->monsters.pop_back();
            }
            else
                i++;
        }
    }

    void nextframe(){
        TomMove();
        for(int i=0; i<game->monsters.size();i++)
            monsterMove(game->monsters[i]);
        if(game->map.curSub->state==1){
            game->genMonster(4);
            game->map.curSub->state=2;
        }
        else if(game->map.curSub->state==2){
            if(game->monsters.size()==0)
                game->map.curSub->openDoor();
        }
        int x,y;
        game->tom.getcoord(x,y);
        attackMonster(x,y);
    }
};


#endif
