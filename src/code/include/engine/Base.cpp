#include"Base.h"
#include"bullet.h"
#include"Enemy.h"
#include"Weapon.h"

int Base::Window_Width = 0;
int Base::Window_Height = 0;

int Base::CounterAll=0;
int Base::Clk=1000;

GLfloat Base::Block_Size=0.08;//>=0.1
int Base::FightMapWidth = 20;//<=20
GLfloat Base::step = 0.001;
GLfloat Base::ForgiveValue = 0.0001;
//GLint Base::Block_PixelLength = 0;
//GLint Base::Block_Width = 0;
//GLubyte* Base::PixelData[2];
Map* Base::GameMap;
MiniMap* Base::SMap;
Tom* Base::tom;

std::vector<bullet*> bullet::AllBullet;
std::vector<Enemy*> Enemy::AllEnemy;
std::vector<Weapon*> Weapon::AllWeapon;