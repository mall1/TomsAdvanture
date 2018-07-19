#include <iostream>
#include "ui.hpp"
#include "timer.hpp"
int main(int argc, char* argv[])
{
    UI::init();
    Timer timer;
    timer.start();
    while (1) {
        UI::nextFrame();
        //printf("flush");

        if( timer.get_ticks() < 1000. / UI::fps )
        {
            SDL_Delay( ( 1000. / UI::fps ) - timer.get_ticks() );
        }
    }
}
