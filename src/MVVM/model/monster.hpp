#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "living.h"
class Monster:public Living{
    int AlertRadius;
public:
    bool isDead;
    Monster():Living(){isDead=0;}
    Monster(std::string filename):Living(filename){
        readFromFile(filename);
        isDead=0;
    }
    void dead(){isDead=1;}
};

#endif // MONSTER_HPP
