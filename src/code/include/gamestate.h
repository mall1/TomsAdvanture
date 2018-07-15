#pragma once
#ifndef GAMESTATE
#define GAMESTATE
#include"gamestate.h"
enum operation { NewGame, Continue, Recovery, Setup, Stop, Home, Finish, ProcessFinish, Killed, GameOver };
enum state { HomePage, GamePage, GameOverPage, StopPage, Home_SetupPage,Game_SetupPage };

struct elements	/*记录各个组件是否显示*/
{
	bool background = 0;/*主界面的背景图*/
	bool home_setup_button = 0;/*主界面的设置按钮*/
	bool newgame = 0;/*“新游戏”按钮*/
	bool lifespan = 0;/*生命值栏*/
	bool bulletnum = 0;/*子弹数目栏*/
	bool stop_button = 0;	/*游戏界面的暂停按钮*/
	bool arm = 0;/*武器显示*/
	bool stop_popup = 0;/*暂停界面的弹窗*/
	bool home_button = 0;/*暂停界面的回到主页按钮*/
	bool recovery = 0;/*暂停界面的回到游戏按钮*/
	bool stop_setup = 0;/*暂停界面的设置按钮*/
	bool setup_popup = 0;/*设置界面弹窗*/
	bool voice = 0;/*暂停界面的音量设置*/
	bool speed = 0;/*暂停界面的速度设置*/
	bool finish = 0;/*设置界面的完成按钮*/
	bool continue_game = 0;/*有历史存档后的主界面的“继续游戏”按钮*/
	bool gameover = 0;/*死亡后的游戏结束界面背景图*/

};

class GameState
{
private:
	enum state Current_State;/*记录当前游戏状态*/
	bool played;/*记录是否有历史存档*/
public:
	GameState();
	GameState(enum state s,bool played);
	void StateChange(enum operation op);/*状态转换，在信号传入后进行游戏状态切换*/
	enum state Currentstate();/*返回当前状态*/
	struct elements display();
	void set_played(bool p);
	void set_CurrentState(enum state s);

};


#endif