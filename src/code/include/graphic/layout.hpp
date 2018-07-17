#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include "widget.hpp"
#include <vector>
#include <string>


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
    }
    void display(){
        if(!isHide){
            Widget::display();
            if(item)
                item->display();
        }
    }
    void onclick(int x, int y){
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty){
                if(item)
                    item->onclick(x,y);
                std::cout<<name<<"clicked"<<std::endl;
            }

    }
    void updateCoord(){}
};

class Layout: public Widget{
public:
    enum Type{vertical, horizontal};
    Type type;
    int itemNum;
    std::vector<LayoutItem>items;
    Layout(std::string name):
        Widget(name),
        type(Type::horizontal),
        itemNum(0){}
    void addItem(double ratioSize=1, double fixedSize=0, Widget* item=0){
        LayoutItem layoutItem(name+"-item-"+std::to_string(++itemNum),item, ratioSize, fixedSize);
        layoutItem.Parent=this;
        items.push_back(layoutItem);
    }

    void updateCoord(){
        lx=Parent->lx;
        by=Parent->by;

        rx=Parent->rx;
        ty=Parent->ty;
        double sumRatio=0;
        int sumFixed=0;
        int curlx=lx, curty=ty;

        for(unsigned int i=0; i< items.size();i++){
            sumRatio+=items[i].ratioSize;
            sumFixed+=items[i].fixedSize;
        }
        if(type==Type::vertical)
            for(unsigned int i=0; i< items.size();i++){
                items[i].lx=lx;
                items[i].rx=rx;
                if(items[i].fixedSize){
                    items[i].ty=curty;
                    curty-=items[i].fixedSize;
                    items[i].by=curty;
                }
                else{
                    items[i].ty=curty;
                    curty-=(items[i].ratioSize/sumRatio)*(ty-by-sumFixed);
                    items[i].by=curty;
                }
            }
        else
            for(unsigned int i=0; i< items.size();i++){
                items[i].ty=ty;
                items[i].by=by;
                if(items[i].fixedSize){
                    items[i].lx=curlx;
                    curlx+=items[i].fixedSize;
                    items[i].rx=curlx;
                }
                else{
                    items[i].lx=curlx;
                    curlx+=(items[i].ratioSize/sumRatio)*(rx-lx-sumFixed);
                    items[i].rx=curlx;
                }
            }

    }
    void display(){
        if(!isHide){
            Widget::display();
            for(unsigned int i=0; i< items.size();i++)
                items[i].display();
        }
    }
    void onclick(int x, int y){
        if(!isHide)
            if(lx<=x&&x<=rx&&by<=y&&y<=ty)
                for(unsigned int i=0; i< items.size();i++)
                    items[i].onclick(x,y);
        //-----------------------------
    }
};



#endif // LAYOUT_HPP
