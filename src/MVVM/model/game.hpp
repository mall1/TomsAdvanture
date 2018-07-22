#ifndef GAME_HPP
#define GAME_HPP
#include "map.hpp"
#include "tom.hpp"
#include "../viewmodel/control.hpp"
class Game {
public:
    Map map;
    Tom tom;
    Game(){
        map.addSubMap(20);

    }

};


#endif // GAME_HPP
