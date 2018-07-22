#ifndef EVENT_HPP
#define EVENT_HPP
#include <SDL/SDL.h>
#include <vector>
namespace Event{
    int initY=720;
    SDL_Event sdlEvent;
    int isQuit=0;
    enum EventType{leftKeyUp, leftKeyDown,rightKeyUp,rightKeyDown,move,keyUp, keyDown};

    std::vector<void (*)(EventType,int, int)>mouseFuncs;
    std::vector<void (*)(EventType,char)>keyboardFuncs;

    void handle_events();
    void bindMouseFunc(void (*f)(EventType,int, int)){mouseFuncs.push_back(f);}
    void bindKeyboardFunc(void (*f)(EventType,char)){keyboardFuncs.push_back(f);}
}

void Event::handle_events()
{
    EventType type;
    char key;
    int x, y;
    bool mouse=0;
    bool keyboard=0;
    while (SDL_PollEvent(&sdlEvent)) {
        x=sdlEvent.button.x;
        y=initY-sdlEvent.button.y;
        key=sdlEvent.key.keysym.sym;
        switch (sdlEvent.type) {
        case SDL_MOUSEBUTTONUP:
            mouse=1;
            if(sdlEvent.button.button==SDL_BUTTON_LEFT)
                type=EventType::leftKeyUp;
            else if(sdlEvent.button.button==SDL_BUTTON_RIGHT)
                type=EventType::rightKeyUp;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mouse=1;
            if(sdlEvent.button.button==SDL_BUTTON_LEFT)
                type=EventType::leftKeyDown;
            else if(sdlEvent.button.button==SDL_BUTTON_RIGHT)
                type=EventType::rightKeyDown;
            break;
        case SDL_MOUSEMOTION:
            mouse=1;
            type=EventType::move;
            break;
        case SDL_KEYDOWN:
            keyboard=1;
            type=EventType::keyDown;
            break;
        case SDL_KEYUP:
            keyboard=1;
            type=EventType::keyUp;
            break;
        case SDL_QUIT:
            isQuit=1;
        default: break;
        }
        if(mouse)
            for(int i=0;i<mouseFuncs.size();i++)
                mouseFuncs[i](type,x,y);
        if(keyboard)
            for(int i=0;i<keyboardFuncs.size();i++)
                keyboardFuncs[i](type,key);
        mouse=0;
        keyboard=0;
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



#endif // EVENT_HPP
