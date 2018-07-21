#ifndef UI_HPP
#define UI_HPP

#include "window.hpp"
#include "button.hpp"
#include "../common/event.hpp"
#include "../common/graphic.hpp"
#include "../viewmodel/control.hpp"
#include "../model/gamestate.hpp"

#define BW 150
#define BH 50
namespace UI {
    double fps=30;
    Window *window;
    Window *createWindow();
    bool init();
    bool nextFrame();
    bool isQuit(){return Event::isQuit;}
    void keyboard(Event::EventType type, char key);
    void mouse(Event::EventType type, int x, int y);
}

bool UI::init(){
    fps=30;
    Graphic::init();
    Control::init();
    Event::bindKeyboardFunc(keyboard);
    Event::bindMouseFunc(mouse);
    window=createWindow();
    gameinit();
    window->display();
    return true;
}
bool UI::nextFrame(){

    Event::handle_events();
    window->display();
    gamenextframe();
    Graphic::nextFrame();
    return true;
}

void UI::keyboard(Event::EventType type, char key){
    if(type==Event::EventType::keyUp){
        if(key==Control::keymap.l)Control::feedGameControlSignal((int)Control::gameControlSignal::movelup);
        if(key==Control::keymap.r)Control::feedGameControlSignal((int)Control::gameControlSignal::moverup);
        if(key==Control::keymap.t)Control::feedGameControlSignal((int)Control::gameControlSignal::movetup);
        if(key==Control::keymap.b)Control::feedGameControlSignal((int)Control::gameControlSignal::movebup);
    }
    else if(type==Event::EventType::keyDown){
        if(key==Control::keymap.l)Control::feedGameControlSignal((int)Control::gameControlSignal::moveldown);
        if(key==Control::keymap.r)Control::feedGameControlSignal((int)Control::gameControlSignal::moverdown);
        if(key==Control::keymap.t)Control::feedGameControlSignal((int)Control::gameControlSignal::movetdown);
        if(key==Control::keymap.b)Control::feedGameControlSignal((int)Control::gameControlSignal::movebdown);
    }
}

void UI::mouse(Event::EventType type, int x, int y){
    //if(type==Event::EventType::leftKeyDown)
        //Control::feedGameControlSignal((int)Control::gameControlSignal::firedown);
    //if(type==Event::EventType::leftKeyUp)
        //Control::feedGameControlSignal((int)Control::gameControlSignal::fireup);
    window->mouseEvent(type,x,y);
}

Window * UI::createWindow(){
    Window *window= new Window("Tom's Adventure");

//BEGIN VIEW
    //view
    window->addView("BEGIN",Layout::Type::vertical);
    window->curView->addTexture("../image/UI/begin-background.png");
    //layer
    Layout *SetupLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal ,"SetupLayer");
    window->curView->layout.addItem(3.5);
    Layout *NewgameLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"NewgameLayer");
    window->curView->layout.addItem(1.5);
    //widgets
    SetupLayer->addItem(5);
    SetupLayer->addItem(1,0,new Button("Setup","../image/UI/setting-icon.png",100,100,(int)WindowState::Signal::Setup));//在第一层最右边插入按钮控件
    NewgameLayer->addItem(1);
    NewgameLayer->addItem(2,0,new Button("NewGame","../image/UI/new-game.png",BW,BH,(int)WindowState::Signal::NewGame));
    NewgameLayer->addItem(2,0,new Button("RestartGame","../image/UI/continue-game.png",BW,BH,(int)WindowState::Signal::Continue));
    NewgameLayer->addItem(7);

//游戏界面
    window->addView("InGame",Layout::Type::vertical);

    Layout *HeadLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"HeadLine");
    window->curView->layout.addItem(6);
    //Layout *EndLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"Endline");

    HeadLayer->addItem(2);    //HeadLayer->items[0].item = new Lifespan("Lifespan");//在第一层最左边插入血条控件
    HeadLayer->addItem(3);
    HeadLayer->addItem(1,0,new Button("Stop","../image/UI/stop.png",100,100,(int)WindowState::Signal::Stop));//在第一层最右边插入暂停控件

    //EndLayer->addItem(8);
    //EndLayer->addItem(1,0,new Button("Arm","../image/UI/arm.png",));

//暂停界面
    window->addView("StopGame",Layout::Type::vertical);
    window->curView->addTexture("../image/UI/stop-background.png");

    window->curView->layout.addItem(1);
    Layout *MiddleLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"MiddleLine");
    window->curView->layout.addItem(1);

    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("Home","../image/UI/home.png",BW,BH,(int)WindowState::Signal::Home));
    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("ContinueGame","../image/UI/return.png",BW,BH,(int)WindowState::Signal::Recovery));
    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("Setting","../image/UI/setting.png",BW,BH,(int)WindowState::Signal::Setup));
    MiddleLayer->addItem(1);

//设置界面
    window->addView("Home-Setup",Layout::Type::vertical);
    window->curView->addTexture("../image/UI/setup-background.png");
    window->curView->layout.addItem(6);
    Layout *FinishLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"FinishLayer");
    window->curView->layout.addItem(1);

    FinishLayer->addItem(4);
    FinishLayer->addItem(1,0,new Button("Finish","../image/UI/ok.png",BW,BH,(int)WindowState::Signal::Finish));
    FinishLayer->addItem(4);

//设置界面
    window->addView("Game-Setup",Layout::Type::vertical);
    window->curView->addTexture("../image/UI/setup-background.png");
    window->curView->layout.addItem(6);
    Layout *GSFinishLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"FinishLayer");
    window->curView->layout.addItem(1);

    GSFinishLayer->addItem(4);
    GSFinishLayer->addItem(1,0,new Button("Finish","../image/UI/ok.png",BW,BH,(int)WindowState::Signal::ProcessFinish));
    GSFinishLayer->addItem(4);

//游戏结束界面
    window->addView("Gameover");
    window->curView->addTexture("../image/UI/gameover-background.png");

//Initialize window with setup view
    window->curView=window->views[0];
    return window;
}


#endif // UI_HPP
