#ifndef WINDOWSTATE_HPP
#define WINDOWSTATE_HPP
namespace WindowState {
    enum Signal { NewGame=1, Continue=2, Recovery=3, Setup=4, Stop=5, Home=6, Finish=7, ProcessFinish=8, Killed=9, GameOver=10 };
    enum State { HomePage, GamePage, GameOverPage, StopPage, Home_SetupPage,Game_SetupPage };
    State curState;
    void feedSignal(Signal signal) {
        switch (curState)
        {
        case HomePage:
            switch (signal)
            {
            case NewGame: curState = GamePage; break;
            case Setup: curState = Home_SetupPage; break;
            case Continue:curState = GamePage; break;
            default: curState = HomePage; break;
            }
            break;

        case GamePage:
            switch (signal)
            {
            case Stop:curState = StopPage; break;
            case Killed:curState = GameOverPage; break;
            default:curState = GamePage; break;
            }
            break;

        case StopPage:
            switch (signal)
            {
            case Recovery:curState = GamePage; break;
            case Home:curState = HomePage; break;
            case Setup:curState = Game_SetupPage; break;
            default:curState = StopPage; break;
            }
            break;

        case Home_SetupPage:
            switch (signal)
            {
            case Finish:curState = HomePage; break;
            default:curState = Home_SetupPage; break;
            }
            break;

        case Game_SetupPage:
            switch (signal)
            {
            case ProcessFinish:curState = StopPage; break;
            default:curState = Game_SetupPage; break;
            }
            break;

        case GameOverPage:
            switch (signal)
            {
            case GameOver:curState = HomePage; break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }

    State getstate() { return curState; }
}
#endif // WINDOWSTATE_HPP
