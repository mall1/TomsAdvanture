TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ./MVVM/app/uitestmain.cpp
LIBS += -lSDL -lSDL_image -lSDL_ttf

HEADERS += \
    ./MVVM/common/graphic.hpp \
    ./MVVM/common/texture.hpp \
    ./MVVM/common/timer.hpp \
    ./MVVM/view/button.hpp \
    ./MVVM/view/layout.hpp \
    ./MVVM/view/ui.hpp \
    ./MVVM/view/view.hpp \
    ./MVVM/view/widget.hpp \
    ./MVVM/view/window.hpp \
    ./MVVM/viewmodel/control.hpp \
    ./MVVM/viewmodel/windowstate.hpp \
    ./MVVM/model/AcrossMap.hpp \
    ./MVVM/model/Base.hpp \
    ./MVVM/model/BaseWall.hpp \
    ./MVVM/model/bullet.hpp \
    ./MVVM/model/Door.hpp \
    ./MVVM/model/Enemy.hpp \
    ./MVVM/model/FightMap.hpp \
    ./MVVM/model/Floor.hpp \
    ./MVVM/model/HandGun.hpp \
    ./MVVM/model/HandGunSoldier.hpp \
    ./MVVM/model/Living.hpp \
    ./MVVM/model/MachineArmor.hpp \
    ./MVVM/model/Map.hpp \
    ./MVVM/model/MapUnit.hpp \
    ./MVVM/model/MiniMap.hpp \
    ./MVVM/model/NormalBullet.hpp \
    ./MVVM/model/RPG.hpp \
    ./MVVM/model/RPGBullet.hpp \
    ./MVVM/model/Tom.hpp \
    ./MVVM/model/Wall.hpp \
    ./MVVM/model/Weapon.hpp \
    ./MVVM/common/event.hpp \
    ./MVVM/model/gamestate.hpp \
    ./MVVM/model/Game_State.hpp \
    ./MVVM/model/living.hpp
