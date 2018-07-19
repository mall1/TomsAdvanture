#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#include "control.hpp"
#include <string>

class Button:public Widget{
    enum ButtonState{pressed, released, above, none};
    enum ButtonState buttonState;
    static int MaxButtonId;
    int curButtonId;
    int signal;
    //void (*onclick)();
    //int reset;
public:
    Button(std::string name):Widget(name),curButtonId(MaxButtonId){
        MaxButtonId++;
    }
    Button(std::string name, std::string filename):Widget(name),curButtonId(MaxButtonId){
        MaxButtonId++;
        addTexture(filename);
        subRraphRule[0]=1;
        subRraphRule[1]=4;
        buttonState=ButtonState::none;
    }
    Button(std::string name, std::string filename, int signal):
        Widget(name),
        curButtonId(MaxButtonId),
        signal(signal){
        MaxButtonId++;
        addTexture(filename);
        subRraphRule[0]=1;
        subRraphRule[1]=4;
        buttonState=ButtonState::none;
    }
    void display(){
        updateCoord();
        Widget::display();
        Graphic::drawFont(lx,ty,name,"Meera.ttf",28,0);
        updateState();
    }
    bool mouseEvent(Control::MouseEventType type,int x, int y){
        if(Widget::mouseEvent(type, x,y)){
            switch (type) {
            case Control::MouseEventType::leftKeyUp :
                buttonState=ButtonState::released;
                onclick();
                break;
            case Control::MouseEventType::leftKeyDown :
                buttonState=ButtonState::pressed;
                break;
            //case Control::MouseEventType::move :
                //buttonState=ButtonState::above;
                //reset=10;
                //break;
            default:
                break;
            }
        }
    }
    bool updateState(){
        /*if(reset>0)reset--;
        else if(reset==0){
            buttonState=ButtonState::none;
            reset--;
        }*/
        switch (buttonState) {
        case ButtonState::pressed:  subRraphRule[2]=2;break;
        case ButtonState::released: subRraphRule[2]=0;break;
        case ButtonState::above:    subRraphRule[2]=1;break;
        case ButtonState::none:     subRraphRule[2]=0;break;
        default: break;
        }
    }
    void onclick(){
        Control::feedButtonClickSignal(signal);
    }
};
int Button::MaxButtonId=1;
#endif // BUTTON_H
