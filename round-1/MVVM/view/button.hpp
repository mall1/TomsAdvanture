#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#include "../viewmodel/control.hpp"
#include <string>

class Button:public Widget{
    Control* control;
    enum ButtonState{pressed, released, above, none};
    enum ButtonState buttonState;
    static int MaxButtonId;
    int curButtonId;
    int signal;
public:
    Button(Control * control, std::string name):control(control),Widget(name),curButtonId(MaxButtonId){
        MaxButtonId++;
    }
    Button(Control * control,std::string name, std::string filename):control(control),Widget(name),curButtonId(MaxButtonId){
        MaxButtonId++;
        addTexture(filename);
        subRraphRule[0]=1;
        subRraphRule[1]=4;
        width=100;
        height=30;
        buttonState=ButtonState::none;
    }
    Button(Control * control,std::string name, std::string filename, int w,int h, int signal):
        control(control),
        Widget(name),
        curButtonId(MaxButtonId),
        signal(signal){
        MaxButtonId++;
        addTexture(filename);
        subRraphRule[0]=1;
        subRraphRule[1]=4;
        width=w;
        height=h;
        buttonState=ButtonState::none;
    }
    void display(){
        updateCoord();
        Widget::display();
        //Graphic::drawFont(lx,ty,name,"Meera.ttf",28,0);
        updateState();
    }
    bool mouseEvent(Event::EventType type,int x, int y){
        if(Widget::mouseEvent(type, x,y)){
            switch (type) {
            case Event::EventType::leftKeyUp :
                if(inRigion(x,y)){
                    buttonState=ButtonState::released;
                    onclick();
                }
                break;
            case Event::EventType::leftKeyDown :
                if(inRigion(x,y))
                    buttonState=ButtonState::pressed;
                break;
            case Event::EventType::move :
                if(inRigion(x,y))
                    buttonState=ButtonState::above;
                else
                    buttonState=ButtonState::none;
                break;
            default:
                break;
            }
            return true;
        }
        return false;
    }
    void updateState(){
        switch (buttonState) {
        case ButtonState::pressed:  subRraphRule[2]=2;break;
        case ButtonState::released: subRraphRule[2]=0;break;
        case ButtonState::above:    subRraphRule[2]=1;break;
        case ButtonState::none:     subRraphRule[2]=0;break;
        default: break;
        }
    }
    void onclick(){
        control->feedButtonClickSignal(signal);
    }
    bool inRigion(int x, int y){
        int gapx,gapy;
        gapx=(rx-lx-width)/2;
        gapy=(ty-by-height)/2;
        switch (align){
        case Align::lt: if(lx+0*gapx<x&&x<rx-2*gapx&&ty-0*gapy>y&&y>by+2*gapy) return true;
        case Align::lb: if(lx+0*gapx<x&&x<rx-2*gapx&&ty-2*gapy>y&&y>by+0*gapy) return true;
        case Align::rt: if(lx+2*gapx<x&&x<rx-0*gapx&&ty-0*gapy>y&&y>by+2*gapy) return true;
        case Align::rb: if(lx+2*gapx<x&&x<rx-0*gapx&&ty-2*gapy>y&&y>by+0*gapy) return true;
        case Align::t : if(lx+1*gapx<x&&x<rx-1*gapx&&ty-0*gapy>y&&y>by+2*gapy) return true;
        case Align::b : if(lx+1*gapx<x&&x<rx-1*gapx&&ty-2*gapy>y&&y>by+0*gapy) return true;
        case Align::l : if(lx+0*gapx<x&&x<rx-2*gapx&&ty-1*gapy>y&&y>by+1*gapy) return true;
        case Align::r : if(lx+2*gapx<x&&x<rx-0*gapx&&ty-1*gapy>y&&y>by+1*gapy) return true;
        case Align::c : if(lx+1*gapx<x&&x<rx-1*gapx&&ty-1*gapy>y&&y>by+1*gapy) return true;
        default: return false;
        }
        return false;
    }
};
int Button::MaxButtonId=1;
#endif // BUTTON_H
