#pragma once
class bullet
{
private:
	int BulletAngle;//子弹运动角度
	int Damage;//伤害
public:
	void MoveJudge(){}//子弹运动判断：撞墙delete，撞人delete
	bullet();
	//bullet(GLfloat x,GLfloat y,int b,int d){}
	~bullet();
};

