#ifndef UI_HPP
#define UI_HPP

#include "window.hpp"
#include "button.hpp"
#include "graphic.hpp"
#include "control.hpp"
namespace UI {
    double fps=30;
    Window *window;
    Window * createWindow();
    bool init();
    bool nextFrame();
    bool isQuit(){return Control::isQuit;}
    void keyboard(Control::KeyEventType type, char key);
    void mouse(Control::MouseEventType type, int x, int y);
}

Window * UI::createWindow(){
    Window *window= new Window("Tom's Adventure");

/*BEGIN VIEW*/    /*将整个开始界面从上到下分为4层，分别占1/8，5/8，1/8，1/8，设置键放在第一层，新游戏键放在第三层*/
    //view
    window->addView("BEGIN",Layout::Type::vertical);
    window->curView->addTexture("../image/UI/begin-background.png");
    //layer
    Layout *SetupLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal ,"SetupLayer");
    window->curView->layout.addItem(5);
    Layout *NewgameLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"NewgameLayer");
    window->curView->layout.addItem(1);
    //widgets
    SetupLayer->addItem(5);
    SetupLayer->addItem(1,0,new Button("Setup","../image/UI/setting-icon.png",(int)WindowState::Signal::Setup));/*在第一层最右边插入按钮控件*/

    NewgameLayer->addItem(3);
    NewgameLayer->addItem(2,0,new Button("NewGame","../image/UI/new-game.png",(int)WindowState::Signal::NewGame));
    NewgameLayer->addItem(2);
    NewgameLayer->addItem(2,0,new Button("RestartGame","../image/UI/continue-game.png",(int)WindowState::Signal::Continue));
    NewgameLayer->addItem(3);

/*游戏界面*/
    window->addView("InGame",Layout::Type::vertical);

    Layout *HeadLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"HeadLine");
    window->curView->layout.addItem(6);
    //Layout *EndLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"Endline");

    HeadLayer->addItem(2);    //HeadLayer->items[0].item = new Lifespan("Lifespan");/*在第一层最左边插入血条控件*/
    HeadLayer->addItem(6);
    HeadLayer->addItem(1,0,new Button("Stop","../image/UI/stop.png",(int)WindowState::Signal::Stop));/*在第一层最右边插入暂停控件*/

    /*EndLayer->addItem(8);
    EndLayer->addItem(1,0,new Button("Arm","../image/UI/arm.png",));*/

/*暂停界面*/
    window->addView("StopGame",Layout::Type::vertical);
    //window->curView->addTexture("../image/UI/stop-background.png");

    window->curView->layout.addItem(1);
    Layout *MiddleLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"MiddleLine");
    window->curView->layout.addItem(1);

    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("Home","../image/UI/home.png",(int)WindowState::Signal::Home));
    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("ContinueGame","../image/UI/continue.png",(int)WindowState::Signal::Recovery));
    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("Setup","../image/UI/set.png",(int)WindowState::Signal::Setup));
    MiddleLayer->addItem(1);

/*设置界面*/
    window->addView("Home-Setup",Layout::Type::vertical);
    //window->curView->addTexture("../image/UI/setup-background.png");
    window->curView->layout.addItem(1);
    Layout *FinishLayer = window->curView->layout.addSubLayout(6,0,Layout::Type::horizontal,"FinishLayer");
    window->curView->layout.addItem(1);

    FinishLayer->addItem(4);
    FinishLayer->addItem(1,0,new Button("Finish","../image/UI/ok.png",(int)WindowState::Signal::Finish));
    FinishLayer->addItem(4);

/*设置界面*/
    window->addView("Game-Setup",Layout::Type::vertical);
    //window->curView->addTexture("../image/UI/setup-background.png");
    window->curView->layout.addItem(1);
    Layout *GSFinishLayer = window->curView->layout.addSubLayout(6,0,Layout::Type::horizontal,"FinishLayer");
    window->curView->layout.addItem(1);

    GSFinishLayer->addItem(4);
    GSFinishLayer->addItem(1,0,new Button("Finish","../image/UI/ok.png",(int)WindowState::Signal::ProcessFinish));
    GSFinishLayer->addItem(4);

/*游戏结束界面*/
    window->addView("Gameover");
    window->curView->addTexture("../image/UI/gameover.png");

/*Initialize window with setup view*/
    window->curView=window->views[0];
    return window;
}

bool UI::init(){
    fps=30;
    Graphic::init();
    Control::init();
    Control::bindKeyboardFunc(keyboard);
    Control::bindMouseFunc(mouse);
    window=createWindow();
    window->display();
    return true;
}
bool UI::nextFrame(){

    Control::handle_events();
    window->display();
    Graphic::drawFont(10,20,"Hello world", "Meera.ttf", 28, NULL);
    Graphic::drawFont(10,40,"Hello world", "Meera.ttf", 10, NULL);

    Graphic::nextFrame();
    return true;
}

void UI::keyboard(Control::KeyEventType type, char key){

}

void UI::mouse(Control::MouseEventType type, int x, int y){
    window->mouseEvent(type,x,y);
}

#endif // UI_HPP
