#ifndef WINDOWSTATE_HPP
#define WINDOWSTATE_HPP
namespace WindowState{
    enum Signal{aa};
    enum State{aaaa};
    State curState;
    void feedSignal(Signal signal){
        switch(signal){
        case Signal::aa: break;
        default:break;
        }
    }

    State getstate(){return curState;}
}
#endif // WINDOWSTATE_HPP
