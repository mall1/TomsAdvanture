#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include "../model/game.hpp"
class GameState{
    Game *game;
public:

    int toml, tomr, tomt, tomb;
    GameState(Game * game):game(game){

        toml=0;
        tomr=0;
        tomt=0;
        tomb=0;
    }

    void getTom(int &x,int &y){
        game->tom.getcoord(x,y);
    }

    void getMap(int *map, int &size){
        game->map.curSubMap(map,size);
    }
    void mouseEvent(){

    }

    void nextframe(){
        int x, y;
        game->tom.getcoord(x,y);
        game->tom.setcoord(x+(tomr-toml)*3,y+(tomt-tomb)*3);
    }
};


#endif
