#include <iostream>
#include "../view/ui.hpp"
#include "../common/timer.hpp"

int main()
{
    UI::init();
    Timer timer;
    timer.start();
    while (!UI::isQuit()) {
        UI::nextFrame();
        //printf("flush");

        if( timer.get_ticks() < 1000. / UI::fps )
        {
            SDL_Delay( ( 1000. / UI::fps ) - timer.get_ticks() );
        }
    }

}

