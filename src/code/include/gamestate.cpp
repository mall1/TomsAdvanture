#include<iostream>
#include"gamestate.h"
using namespace std;

GameState::GameState()
	:Current_State(HomePage),played(0) {}  /*³õÊŒœçÃæÔÚÖ÷œçÃæ*/

GameState::GameState(enum state s,bool played)
	: Current_State(s),played(played) {}

void GameState::set_played(bool p)
{
	played = p;
}
void GameState::set_CurrentState(enum state s)
{
	Current_State = s;
}

void GameState::StateChange(enum operation op)
{
	
	switch (Current_State)
	{
	case HomePage:
		switch (op)
		{
		case NewGame: Current_State = GamePage; break;
		case Setup: Current_State = Home_SetupPage; break;
		case Continue:Current_State = GamePage; break;
		default: Current_State = HomePage; break;
		}
		break;

	case GamePage:
		switch (op)
		{
		case Stop:Current_State = StopPage; break;
		case Killed:Current_State = GameOverPage; break;
		default:Current_State = GamePage; break;
		}
		break;

	case StopPage:
		switch (op)
		{
		case Recovery:Current_State = GamePage; break;
		case Home:Current_State = HomePage; break;
		case Setup:Current_State = Game_SetupPage; break;
		default:Current_State = StopPage; break;
		}
		break;

	case Home_SetupPage:
		switch (op)
		{
		case Finish:Current_State = HomePage; break;
		default:Current_State = Home_SetupPage; break;
		}
		break;

	case Game_SetupPage:
		switch (op)
		{
		case ProcessFinish:Current_State = StopPage; break;
		default:Current_State = Game_SetupPage; break;
		}
		break;

	case GameOverPage:
		switch (op)
		{
		case GameOver:Current_State = HomePage; break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

enum state GameState::Currentstate()
{
	return Current_State;
}


struct elements GameState::display()
{
	struct elements c;
	switch (Current_State)
	{
	case HomePage:
		c.background = 1;
		c.home_setup_button = 1;
		c.newgame = 1;
		if (played)c.continue_game = 1;
		break;

	case GamePage:
		c.arm = 1;
		c.bulletnum = 1;
		c.lifespan = 1;
		c.stop_button = 1;
		break;

	case StopPage:
		c.arm = 1;
		c.bulletnum = 1;
		c.lifespan = 1;
		c.stop_button = 1;

		c.stop_popup = 1;
		c.stop_setup = 1;
		c.recovery = 1;
		c.home_button = 1;
		break;

	case Home_SetupPage:
		c.background = 1;
		c.home_setup_button = 1;
		c.newgame = 1;

		c.finish = 1;
		c.speed = 1;
		c.voice = 1;
		break;

	case Game_SetupPage:
		c.arm = 1;
		c.bulletnum = 1;
		c.lifespan = 1;
		c.stop_button = 1;

		c.stop_popup = 1;
		c.stop_setup = 1;
		c.recovery = 1;
		c.home_button = 1;

		c.finish = 1;
		c.speed = 1;
		c.voice = 1;
		break;

	case GameOverPage:
		c.gameover = 1;
		break;
	default:
		break;
	}
	return c;
}
