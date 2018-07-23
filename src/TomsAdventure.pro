TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ./MVVM/app/app.cpp
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
    ./MVVM/common/event.hpp \
    MVVM/model/map.hpp \
    MVVM/model/game.hpp \
    MVVM/viewmodel/gamestate.hpp \
    MVVM/view/gamescane.hpp \
    MVVM/model/monster.hpp \
    MVVM/model/tool.hpp \
    MVVM/model/gun.hpp \
    MVVM/model/xml_operation.hpp \
    MVVM/model/tom.hpp \
    MVVM/model/living.h
