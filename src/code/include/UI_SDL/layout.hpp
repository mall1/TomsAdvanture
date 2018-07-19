#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include "widget.hpp"
#include <vector>
#include <string>

class Layout;
class LayoutItem: public Widget{
public:
    Widget* item;
    double ratioSize;
    double fixedSize;
    LayoutItem(std::string name):
        Widget(name),
        item(0),
        ratioSize(1),
        fixedSize(0){}
    LayoutItem(std::string name, Widget* item, double ratioSize, double fixedSize):
        item(item),
        Widget(name),
        ratioSize(ratioSize),
        fixedSize(fixedSize){
        if(item)
            item->Parent=this;
        isDisplay=false;
    }
    void display(){
        if(!isHide){
            Widget::display();
            if(item)
                item->display();
        }
    }
    void updateCoord(){}
    bool mouseEvent(Control::MouseEventType type,int x, int y){
        bool clicked;
        updateCoord();
        clicked=Widget::mouseEvent(type,x,y);
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty){
                if(item)
                    item->mouseEvent(type,x,y);
            }
        return clicked;
    }
};

class Layout: public Widget{
public:
    enum Type{vertical, horizontal};
    Type type;
    int itemNum;
    std::vector<LayoutItem*>items;
    Layout(std::string name, Type type=Type::horizontal):
        Widget(name),
        type(type),
        itemNum(0){
        isDisplay=false;
    }
    void addItem(double ratioSize=1, double fixedSize=0, Widget* item=0){
        LayoutItem* layoutItem = new LayoutItem(name+"-item-"+std::to_string(itemNum),item, ratioSize, fixedSize);
        layoutItem->Parent=this;
        items.push_back(layoutItem);
        itemNum++;
    }
    Layout* addSubLayout(double ratioSize=1, double fixedSize=0, Layout::Type type=Layout::Type::horizontal, std::string subname=""){
        Layout* subLayout = new Layout(name+"-sublayout-"+std::to_string(itemNum)+subname);
        subLayout->type=type;
        LayoutItem* layoutItem = new LayoutItem(name+"-item-"+std::to_string(itemNum),subLayout, ratioSize, fixedSize);
        layoutItem->Parent=this;
        items.push_back(layoutItem);
        subLayout->Parent=layoutItem;
        itemNum++;
        return subLayout;
    }


    void updateItemCoord(){
        double sumRatio=0;
        int sumFixed=0;
        int curlx=lx, curty=ty;

        for(unsigned int i=0; i< items.size();i++){
            sumRatio+=items[i]->ratioSize;
            sumFixed+=items[i]->fixedSize;
        }
        if(type==Type::vertical)
            for(unsigned int i=0; i< items.size();i++){
                items[i]->lx=lx;
                items[i]->rx=rx;
                if(items[i]->fixedSize){
                    items[i]->ty=curty;
                    curty-=items[i]->fixedSize;
                    items[i]->by=curty;
                }
                else{
                    items[i]->ty=curty;
                    curty-=(items[i]->ratioSize/sumRatio)*(ty-by-sumFixed);
                    items[i]->by=curty;
                }
            }
        else
            for(unsigned int i=0; i< items.size();i++){
                items[i]->ty=ty;
                items[i]->by=by;
                if(items[i]->fixedSize){
                    items[i]->lx=curlx;
                    curlx+=items[i]->fixedSize;
                    items[i]->rx=curlx;
                }
                else{
                    items[i]->lx=curlx;
                    curlx+=(items[i]->ratioSize/sumRatio)*(rx-lx-sumFixed);
                    items[i]->rx=curlx;
                }
            }

    }
    void display(){
        if(!isHide){
            updateCoord();
            Widget::display();
            updateItemCoord();
            for(unsigned int i=0; i< items.size();i++)
                items[i]->display();
        }
    }
    bool mouseEvent(Control::MouseEventType type,int x, int y){
        bool clicked;
        updateCoord();
        clicked=Widget::mouseEvent(type,x,y);
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty)
                for(unsigned int i=0; i< items.size();i++)
                    items[i]->mouseEvent(type, x,y);
        return clicked;
    }
};



#endif // LAYOUT_HPP
