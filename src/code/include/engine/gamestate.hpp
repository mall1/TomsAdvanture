#pragma once
#ifndef GAMESTATE
#define GAMESTATE
#include <iostream>
using namespace std;
enum operation { NewGame, Continue, Recovery, Setup, Stop, Home, Finish, ProcessFinish, Killed, GameOver };
enum state { HomePage, GamePage, GameOverPage, StopPage, Home_SetupPage,Game_SetupPage };

struct elements	/*ŒÇÂŒž÷žö×éŒþÊÇ·ñÏÔÊŸ*/
{
	bool background = 0;/*Ö÷œçÃæµÄ±³Ÿ°ÍŒ*/
	bool home_setup_button = 0;/*Ö÷œçÃæµÄÉèÖÃ°ŽÅ¥*/
	bool newgame = 0;/*¡°ÐÂÓÎÏ·¡±°ŽÅ¥*/
	bool lifespan = 0;/*ÉúÃüÖµÀž*/
	bool bulletnum = 0;/*×Óµ¯ÊýÄ¿Àž*/
	bool stop_button = 0;	/*ÓÎÏ·œçÃæµÄÔÝÍ£°ŽÅ¥*/
	bool arm = 0;/*ÎäÆ÷ÏÔÊŸ*/
	bool stop_popup = 0;/*ÔÝÍ£œçÃæµÄµ¯Ž°*/
	bool home_button = 0;/*ÔÝÍ£œçÃæµÄ»ØµœÖ÷Ò³°ŽÅ¥*/
	bool recovery = 0;/*ÔÝÍ£œçÃæµÄ»ØµœÓÎÏ·°ŽÅ¥*/
	bool stop_setup = 0;/*ÔÝÍ£œçÃæµÄÉèÖÃ°ŽÅ¥*/
	bool setup_popup = 0;/*ÉèÖÃœçÃæµ¯Ž°*/
	bool voice = 0;/*ÔÝÍ£œçÃæµÄÒôÁ¿ÉèÖÃ*/
	bool speed = 0;/*ÔÝÍ£œçÃæµÄËÙ¶ÈÉèÖÃ*/
	bool finish = 0;/*ÉèÖÃœçÃæµÄÍê³É°ŽÅ¥*/
	bool continue_game = 0;/*ÓÐÀúÊ·ŽæµµºóµÄÖ÷œçÃæµÄ¡°ŒÌÐøÓÎÏ·¡±°ŽÅ¥*/
	bool gameover = 0;/*ËÀÍöºóµÄÓÎÏ·œáÊøœçÃæ±³Ÿ°ÍŒ*/

};

class GameState
{
private:
	enum state Current_State;/*ŒÇÂŒµ±Ç°ÓÎÏ·×ŽÌ¬*/
	bool played;/*ŒÇÂŒÊÇ·ñÓÐÀúÊ·Žæµµ*/
public:
	GameState();
	GameState(enum state s,bool played);
	void StateChange(enum operation op);/*×ŽÌ¬×ª»»£¬ÔÚÐÅºÅŽ«ÈëºóœøÐÐÓÎÏ·×ŽÌ¬ÇÐ»»*/
	enum state Currentstate();/*·µ»Øµ±Ç°×ŽÌ¬*/
	struct elements display();
	void set_played(bool p);
	void set_CurrentState(enum state s);

};


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

#endif

