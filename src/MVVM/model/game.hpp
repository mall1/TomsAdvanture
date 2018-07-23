#ifndef GAME_HPP
#define GAME_HPP
#include "map.hpp"
#include "tom.hpp"
#include "monster.hpp"
#include "../viewmodel/control.hpp"
#include <vector>
class Game {
public:
    Map map;
    Tom tom;
    std::vector<Monster*>monsters;
    Game(){
        map.addSubMap(20);
        map.addSubMap(14);
        map.connectSubMap(0,1,4,3);
        map.addSubMap(18);
        map.connectSubMap(0,2,2,1);
        map.addSubMap(14);
        map.connectSubMap(0,3,3,4);
        map.curSub->openDoor();
        map.curSub->state=2;
    }
    void genMonster(int num){
        monsters.clear();
        for(int i=0; i<num; i++){
            Monster *m = new Monster();
            monsters.push_back(m);
        }
    }

};


#endif // GAME_HPP
