#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "windowstate.hpp"
#include "../common/event.hpp"
#include "gamestate.hpp"
#include <SDL/SDL.h>

struct Keymap{
    char l;
    char r;
    char t;
    char b;
};

class Control {
public:
    GameState* gamestate;

    int initY;
    int isQuit;
    SDL_Event sdlEvent;
    Keymap keymap;
    enum gameControlSignal{movelup, moverup, movetup, movebup, moveldown, moverdown, movetdown, movebdown, firedown,fireup, nextframe};

    enum MouseEventType{leftKeyUp, leftKeyDown,rightKeyUp,rightKeyDown,move};
    enum KeyEventType{keyUp, keyDown};

    Control(GameState* gamestate);
    void (*gameControlFunc)(gameControlSignal);

    void feedButtonClickSignal(int id){
        WindowState::feedSignal((WindowState::Signal)id);
    }

    void feedGameControlSignal(int id){
        //game control
        switch((gameControlSignal)id){
        case movelup:   gamestate->toml=0;break;
        case moverup:   gamestate->tomr=0;break;
        case movetup:   gamestate->tomt=0;break;
        case movebup:   gamestate->tomb=0;break;

        case moveldown: gamestate->toml=1;break;
        case moverdown: gamestate->tomr=1;break;
        case movetdown: gamestate->tomt=1;break;
        case movebdown: gamestate->tomb=1;break;

        }
    }

    void init();
    void handle_events();
};

Control::Control(GameState *gamestate){
    initY=720;
    isQuit=0;
    this->gamestate=gamestate;
    gameControlFunc=0;
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
