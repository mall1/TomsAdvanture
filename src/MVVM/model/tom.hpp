#ifndef TOM_HPP
#define TOM_HPP
#define TOMHEIGHT 20
#include <string>
#include "living.h"
#include "../common/graphic.hpp"
class Tom:public Living{

public:
    Tom():Living(){}
    Tom(std::string filename):Living(filename){
        readFromFile(filename);
    }
};

#endif // TOM_HPP
