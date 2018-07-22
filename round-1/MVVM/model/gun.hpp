#ifndef GUN_HPP
#define GUN_HPP
#include <string>
class Gun{
    std::string name;
    int atack;
    int energy;
    void* guntexture;
    int gunSubGraphRule[3];
    void* bulletTexture;
    int bulletSubGraphRule[3];
    int bulletSpeed;
    double restateTime;//ms after how many time can shot again

};

#endif // GUN_HPP
