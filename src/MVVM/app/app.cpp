#include <iostream>
#include "../view/ui.hpp"
#include "../common/timer.hpp"
UI *uiptr;
void keyboard(Event::EventType type, char key){
    if(uiptr)
        uiptr->keyboard(type, key);
}

void mouse(Event::EventType type, int x, int y){
    if(uiptr)
        uiptr->mouse(type,x,y);
}
int main()
{
    Timer timer;
    timer.start();
    GameState* gamestate=new GameState(new Game);
    UI ui(gamestate, new Control(gamestate));
    uiptr=&ui;
    Event::bindKeyboardFunc(keyboard);
    Event::bindMouseFunc(mouse);

    while (!ui.isQuit()) {
        ui.nextFrame();
        if( timer.get_ticks() < 1000. / ui.getfps() )
        {
            SDL_Delay( ( 1000. / ui.getfps() ) - timer.get_ticks() );
        }
    }
}

