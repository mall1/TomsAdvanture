#pragma once
class bullet
{
private:
	int BulletAngle;//�ӵ��˶��Ƕ�
	int Damage;//�˺�
public:
	void MoveJudge(){}//�ӵ��˶��жϣ�ײǽdelete��ײ��delete
	bullet();
	//bullet(GLfloat x,GLfloat y,int b,int d){}
	~bullet();
};

