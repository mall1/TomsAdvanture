#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "windowstate.hpp"
#include "../common/event.hpp"
#include <SDL/SDL.h>
namespace Control {
    int initY=720;
    int isQuit=0;
    SDL_Event sdlEvent;
    struct Keymap{
        char l;
        char r;
        char t;
        char b;
    }keymap;

    enum gameControlSignal{movelup, moverup, movetup, movebup, moveldown, moverdown, movetdown, movebdown, firedown,fireup};

    enum MouseEventType{leftKeyUp, leftKeyDown,rightKeyUp,rightKeyDown,move};
    enum KeyEventType{keyUp, keyDown};

    void (*gameControlFunc)(gameControlSignal);

    void feedButtonClickSignal(int id){
        WindowState::feedSignal((WindowState::Signal)id);
    }

    void feedGameControlSignal(int id){
        gameControlFunc((gameControlSignal)id);
    }

    void init();
    void handle_events();
    void bindGameControlFunc(void (*f)(gameControlSignal)){gameControlFunc=f;}
}

void Control::init(){
    keymap.l='a';
    keymap.r='d';
    keymap.t='w';
    keymap.b='s';
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
