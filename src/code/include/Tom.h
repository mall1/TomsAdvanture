#pragma once
#include "Living.h"
class Tom :
	public Living
{
private:
	
public:
	void Shot(int x, int y){}//·¢Éä×Óµ¯
	//void 
	//void MoveJudge(){}
	Tom();
	Tom(GLfloat x, GLfloat y, int hp, int ad)
	{
		PositionX = x;
		PositionY = y;
		MaxHp = hp;
		NowHp = hp;
		MaxAD = ad;
		NowAD = ad;
		enable = true;
	}
	~Tom();
};

