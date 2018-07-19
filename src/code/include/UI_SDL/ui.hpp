#ifndef UI_HPP
#define UI_HPP

#include "window.hpp"
#include "button.hpp"
#include "graphic.hpp"
namespace UI {
    double fps=30;
    SDL_Event event;
    Window *window;
    void handle_events(SDL_Event *event);
    Window * createWindow();
    bool init();
    bool nextFrame();
}
void UI::handle_events(SDL_Event *event)
{
    //If a key was pressed
    static int i=0;
    if( event->type == SDL_KEYUP )
    {
        //Set the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_RIGHT: i--; break;
            case SDLK_LEFT:  i++; break;
            default:break;
        }
        if(i<0)i=window->views.size()-1;
        if(i>=window->views.size()) i=0;
    }
    window->curView=window->views[i];
}



Window * UI::createWindow(){
    Window *window= new Window("Tom's Adventure");

/*BEGIN VIEW*/    /*将整个开始界面从上到下分为4层，分别占1/8，5/8，1/8，1/8，设置键放在第一层，新游戏键放在第三层*/
    //view
    window->addView("BEGIN",Layout::Type::vertical);
    //window->curView->addTexture("setup-background.png");
    //layer
    Layout *SetupLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal ,"SetupLayer");
    window->curView->layout.addItem(5);
    Layout *NewgameLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"NewgameLayer");
    window->curView->layout.addItem(1);
    //widgets
    SetupLayer->addItem(5);
    SetupLayer->addItem(1,0,new Button("Setup","setting-icon.png"));/*在第一层最右边插入按钮控件*/

    NewgameLayer->addItem(3);
    NewgameLayer->addItem(2,0,new Button("NewGame","new-game.png"));
    NewgameLayer->addItem(2);
    NewgameLayer->addItem(2,0,new Button("RestartGame","continue-game.png"));
    NewgameLayer->addItem(3);

/*游戏界面*/
    window->addView("InGame",Layout::Type::vertical);

    Layout *HeadLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"HeadLine");
    window->curView->layout.addItem(6);
    Layout *EndLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"Endline");

    HeadLayer->addItem(2);    //HeadLayer->items[0].item = new Lifespan("Lifespan");/*在第一层最左边插入血条控件*/
    HeadLayer->addItem(6);
    HeadLayer->addItem(1,0,new Button("Stop"));/*在第一层最右边插入暂停控件*/

    EndLayer->addItem(8);
    EndLayer->addItem(1,0,new Button("Arm"));

/*暂停界面*/
    window->addView("StopGame",Layout::Type::vertical);

    window->curView->layout.addItem(1);
    Layout *MiddleLayer = window->curView->layout.addSubLayout(1,0,Layout::Type::horizontal,"MiddleLine");
    window->curView->layout.addItem(1);

    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("Home"));
    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("ContinueGame"));
    MiddleLayer->addItem(1);
    MiddleLayer->addItem(1,0,new Button("Setup"));
    MiddleLayer->addItem(1);

/*设置界面*/
    window->addView("Setup",Layout::Type::vertical);
    window->curView->layout.addItem(1);
    Layout *FinishLayer = window->curView->layout.addSubLayout(6,0,Layout::Type::horizontal,"FinishLayer");
    window->curView->layout.addItem(1);

    FinishLayer->addItem(4);
    FinishLayer->addItem(1,0,new Button("Finish"));
    FinishLayer->addItem(4);

/*游戏结束界面*/
    window->addView("Gameover");

/*Initialize window with setup view*/
    window->curView=window->views[0];
    return window;
}

bool UI::init(){
    Graphic::init();
    window=createWindow();
    window->display();
    return true;
}
bool UI::nextFrame(){

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        handle_events(&event);
    }
    window->display();
    Graphic::drawFont(10,20,"Hello world", "lazy.ttf", 28, NULL);
    Graphic::drawFont(10,40,"Hello world", "lazy.ttf", 10, NULL);

    Graphic::nextFrame();
    return true;
}

#endif // UI_HPP
