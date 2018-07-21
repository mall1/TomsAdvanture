#pragma once
#include "../common/graphic.hpp"
#include "ctime"
#include <vector>
#include <math.h>
#include <iostream>

namespace Base{
    int Window_Width=0;
    int Window_Height=0;

    int CounterAll=0;
    int Clk=1000;


    double Block_Size=0.08;//>=0.1
    int FightMapWidth = 20;//<=20

    double step = 0.001;
    double ForgiveValue = 0.0001;

	enum Skill { a1, b1 ,SkillLimit};
	enum Item { c1, d1 ,ItemLimit};
	enum State { e1, f1 ,StateLimit};
	enum Block { wall, floorblock, door, BlockLimit };
	enum MapType{fightmap,acrossmap,MapLimit};
	enum WeaponType{handgun,rpg,WeaponLimit};
	enum Rotate{up,down,left,right,RotateLimit};
	enum MapUnitEventKind{start,fight,end,MapUnitKindLimit};
	enum MapUnitState{fightbefore,fighting,fightdone,MapUnitStateLimit};

}





