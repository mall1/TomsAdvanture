#ifndef WINDOWSTATE_HPP
#define WINDOWSTATE_HPP
namespace WindowState {
	enum Signal { NewGame, Continue, Recovery, Setup, Stsignal, Home, Finish, ProcessFinish, Killed, GameOver };
	enum State { HomePage, GamePage, GameOverPage, StsignalPage, Home_SetupPage, Game_SetupPage };
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
			case Stsignal:curState = StsignalPage; break;
			case Killed:curState = GameOverPage; break;
			default:curState = GamePage; break;
			}
			break;

		case StsignalPage:
			switch (signal)
			{
			case Recovery:curState = GamePage; break;
			case Home:curState = HomePage; break;
			case Setup:curState = Game_SetupPage; break;
			default:curState = StsignalPage; break;
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
			case ProcessFinish:curState = StsignalPage; break;
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
