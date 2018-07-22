#ifndef TIMER_HPP
#define TIMER_HPP
#include <SDL/SDL.h>
class Timer
{
private:
    int startTicks;
    int pausedTicks;
    bool paused;
    bool started;
public:
    Timer():
        startTicks(0),
        pausedTicks(0),
        paused(false),
        started(false){}

    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();
    bool is_started(){return started;}
    bool is_paused(){return paused;}
};
void Timer::start(){
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void Timer::stop(){
    started = false;
    paused = false;
}

void Timer::pause(){
    if( ( started == true ) && ( paused == false ) )
    {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause(){
    if( paused == true )
    {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

int Timer::get_ticks(){
    if( started == true ){
        if( paused == true )
            return pausedTicks;
        else
            return SDL_GetTicks() - startTicks;
    }
    return 0;
}

#endif // TIMER_H
