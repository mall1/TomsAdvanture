#pragma once
#include "Living.h"
class Enemy :
	public Living
{
public:
	static std::vector<Enemy*> AllEnemy;
	static void AllReDraw()
	{
		for (int i = 0;i < AllEnemy.size();i++)
			AllEnemy[i]->ReDraw();
	}
	static void AllIsDied()
	{
		for (int i = 0;i < AllEnemy.size();i++)
			AllEnemy[i]->IsDied();
	}
	static void AllJudge()
	{
		for (int i = 0;i < AllEnemy.size();i++)
			AllEnemy[i]->AIJudge();
	}
	//static AllCollisionTest(GLfloat x,)
	virtual void AIJudge() = 0;
	Enemy(){}
	~Enemy(){}
};

