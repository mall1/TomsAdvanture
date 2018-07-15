#pragma once
#ifndef GAMESTATE
#define GAMESTATE
#include"gamestate.h"
enum operation { NewGame, Continue, Recovery, Setup, Stop, Home, Finish, ProcessFinish, Killed, GameOver };
enum state { HomePage, GamePage, GameOverPage, StopPage, Home_SetupPage,Game_SetupPage };

struct elements	/*��¼��������Ƿ���ʾ*/
{
	bool background = 0;/*������ı���ͼ*/
	bool home_setup_button = 0;/*����������ð�ť*/
	bool newgame = 0;/*������Ϸ����ť*/
	bool lifespan = 0;/*����ֵ��*/
	bool bulletnum = 0;/*�ӵ���Ŀ��*/
	bool stop_button = 0;	/*��Ϸ�������ͣ��ť*/
	bool arm = 0;/*������ʾ*/
	bool stop_popup = 0;/*��ͣ����ĵ���*/
	bool home_button = 0;/*��ͣ����Ļص���ҳ��ť*/
	bool recovery = 0;/*��ͣ����Ļص���Ϸ��ť*/
	bool stop_setup = 0;/*��ͣ��������ð�ť*/
	bool setup_popup = 0;/*���ý��浯��*/
	bool voice = 0;/*��ͣ�������������*/
	bool speed = 0;/*��ͣ������ٶ�����*/
	bool finish = 0;/*���ý������ɰ�ť*/
	bool continue_game = 0;/*����ʷ�浵���������ġ�������Ϸ����ť*/
	bool gameover = 0;/*���������Ϸ�������汳��ͼ*/

};

class GameState
{
private:
	enum state Current_State;/*��¼��ǰ��Ϸ״̬*/
	bool played;/*��¼�Ƿ�����ʷ�浵*/
public:
	GameState();
	GameState(enum state s,bool played);
	void StateChange(enum operation op);/*״̬ת�������źŴ���������Ϸ״̬�л�*/
	enum state Currentstate();/*���ص�ǰ״̬*/
	struct elements display();
	void set_played(bool p);
	void set_CurrentState(enum state s);

};


#endif