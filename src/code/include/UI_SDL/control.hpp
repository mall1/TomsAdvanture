#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "windowstate.hpp"
#include <SDL/SDL.h>
namespace Control {
    int initY=720;
    int isQuit=0;
    SDL_Event sdlEvent;
    enum MouseEventType{leftKeyUp, leftKeyDown,rightKeyUp,rightKeyDown,move};
    enum KeyEventType{keyUp, keyDown};
    void (*mouseFunc)(MouseEventType,int, int);
    void (*keyboardFunc)(KeyEventType,char);

    void feedButtonClickSignal(int id){
        WindowState::feedSignal((WindowState::Signal)id);
    }

    void init();
    void handle_events();
    void bindMouseFunc(void (*f)(MouseEventType,int, int)){mouseFunc=f;}
    void bindKeyboardFunc(void (*f)(KeyEventType,char)){keyboardFunc=f;}
}

void Control::init(){
    //-----------------------------------
}
void Control::handle_events()
{
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
        case SDL_MOUSEBUTTONUP:
            if(sdlEvent.button.button==SDL_BUTTON_LEFT)
                mouseFunc(MouseEventType::leftKeyUp, sdlEvent.button.x, initY-sdlEvent.button.y);
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(sdlEvent.button.button==SDL_BUTTON_LEFT)
                mouseFunc(MouseEventType::leftKeyDown, sdlEvent.button.x, initY-sdlEvent.button.y);
            break;
        case SDL_MOUSEMOTION:
            //if(sdlEvent.motion.state==// )
                mouseFunc(MouseEventType::move, sdlEvent.motion.x, initY-sdlEvent.motion.y);
            break;

        case SDL_QUIT: isQuit=true;break;
        default: break;
        }
    }
}


/*SDL_ACTIVEEVENT	SDL_ActiveEvent
SDL_KEYDOWN/UP	SDL_KeyboardEvent
SDL_MOUSEMOTION	SDL_MouseMotionEvent
SDL_MOUSEBUTTONDOWN/UP	SDL_MouseButtonEvent
SDL_JOYAXISMOTION	SDL_JoyAxisEvent
SDL_JOYBALLMOTION	SDL_JoyBallEvent
SDL_JOYHATMOTION	SDL_JoyHatEvent
SDL_JOYBUTTONDOWN/UP	SDL_JoyButtonEvent
SDL_QUIT	SDL_QuitEvent
SDL_SYSWMEVENT	SDL_SysWMEvent
SDL_VIDEORESIZE	SDL_ResizeEvent
SDL_VIDEOEXPOSE	SDL_ExposeEvent
SDL_USEREVENT	SDL_UserEvent*/

#endif // CONTROL_HPP
