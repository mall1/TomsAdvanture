#pragma once
#ifndef GAMESTATE
#define GAMESTATE
#include"gamestate.h"
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


#endif
