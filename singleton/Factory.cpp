//
//  Factory.cpp
//  singleton
//
//  Created by chenyafei on 15-4-7.
//  Copyright (c) 2015年 cyf. All rights reserved.
//

#include "Factory.h"


using namespace std;

static const double PI= 3.14;
class Shape//形状
{
public:
    virtual double Area() = 0;//纯虚函数
    virtual ~Shape(){}
};
#pragma mark - 矩形
class Rectangle1 : public Shape///矩形
{
public:
    Rectangle1(int width,int height);
public:
    double Area();
private:
    int _width;
    int _height;
    
};
Rectangle1::Rectangle1(int width,int height)
{
    _width=width;
    _height=height;
}
double Rectangle1::Area()
{
    return _height * _width;
}
#pragma mark - 圆
class Circle1:public Shape//圆
{
public:
    Circle1(int radius):_radius(radius){}
public:
    double Area();
private:
    int _radius;
};
double Circle1::Area()
{
    return PI*_radius*_radius;
}



#pragma mark - 创造者
class Creator//
{
public:
    virtual Shape* CreateShape()=0;//矩形默认构造  纯虚函数
    virtual ~Creator(){}
};
#pragma mark - 创造矩形
class RectCreator:public Creator//
{
public:
    Shape* CreateShape()
    {
        Rectangle1* rect = new Rectangle1(10,20);
        return rect;
    }
};
#pragma mark - 创造圆
class CircleCreator:public Creator//圆
{
public:
    Shape* CreateShape()
    {
        Circle1* circle = new Circle1(10);
        return circle;
    }
};


//普通函数，非成员函数
void Create(Creator* pCreator)
{
    Shape* pShape = pCreator->CreateShape();
    pShape->Area();
    delete pShape;
    pShape = NULL;
}


int main(int argc, const char * argv[])
{
    
    //        CSystemControl* p1 = CSystemControl::Instance();
    //        CSystemControl* p2 = CSystemControl::Instance();
    //        p1->print();
    //        p2->print();
    //        //
    //        Window win (100,200);
    //        cout<< win.Area()<<endl;
    //        //
    //        AppUI* pUI = new AppUI;
    //        pUI->start();
    //        delete pUI;
    /////
    
    CircleCreator cs;
    RectCreator rs;
    Create(&cs);
    Create(&rs);
    cout<<"@@@@@@@@@@@@@@@"<<endl;
    return 0;
}

