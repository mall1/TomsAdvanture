#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#include <string>

class Button:public Widget{
    enum ButtonState{pressed, released, above, none};
    enum ButtonState buttonState;
public:
    Button(std::string name):Widget(name){}
    Button(std::string name, std::string filename):Widget(name){
        addTexture(filename);
        subRraphRule[0]=1;
        subRraphRule[1]=4;
        buttonState=ButtonState::none;
    }
    void display(){
        switch (buttonState) {
        case ButtonState::pressed:  subRraphRule[2]=2;break;
        case ButtonState::released: subRraphRule[2]=0;break;
        case ButtonState::above:    subRraphRule[2]=1;break;
        case ButtonState::none:     subRraphRule[2]=0;break;
        default:                   break;
        }
        updateCoord();
        Widget::display();
    }

};

#endif // BUTTON_H
