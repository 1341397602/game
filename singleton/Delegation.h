//
//  Delegation.h
//  singleton
//
//  Created by chenyafei on 15-4-7.
//  Copyright (c) 2015年 cyf. All rights reserved.
//

#ifndef __singleton__Delegation__
#define __singleton__Delegation__

#include <iostream>
using namespace std;
class Delegate
{
public:
    virtual int Area()=0;
    
};

//
class Rectangle:public Delegate
{
public:
    Rectangle(int height,int width):_height(height),_width(width)
    {
    }
public:
    int Area()
    {
        return _height*_width;
    }
private:
    int _height;
    int _width;
};
//
class Window
{
private:
    Rectangle del;//组合
public:
    Window(int height,int width):del(height,width)
    {
        
    }
public:
    int Area()
    {
        return del.Area();
    }
};



#endif /* defined(__singleton__Delegation__) */
